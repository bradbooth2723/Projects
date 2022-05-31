from mimetypes import init
import socket
import time
import math
import select

#Sources:   'Host-to-Host Congestion Control for TCP' by Alexander Afanasyev, Neil Tilley, Peter Reiher, and Leonard Kleinrock
#           'TCP Vegas: End to End Congestion Avoidance on a Global Internet' by Lawrence S. Brakmo, Student Member, IEEE and Larry L. Peterson
#           'http://www.mathcs.emory.edu/~cheung/Courses/558/Syllabus/02-transport/vegas.html' by Unknown Author

class TimeOutException(Exception):
    pass

#Initializes text file into packets
def initializePackets():
    packets = []
    cap = 2408280
    seq = 1
    text = ""
    initial = 0
    limiter = 1000

    # open file to read into a string variable for easy parsing
    with open("message.txt") as file:
        for line in file:
            text = text + line

    # parse 1000 bytes of the message file and add sequence header
    # store the parsed item into a packets array to return
    while initial < cap:
        encoded = text[initial:limiter].encode()
        initial = limiter
        limiter = limiter + 1000
        packet = (str(seq) + "|").encode() + encoded
        packets.append(packet)
        seq = seq + 1
    print("Number of packets:", len(packets))
    return packets

#Prints packets window, ack number received, widnow size, and RTT of packet that was acknowledged 
def printMetrics(base, ceil, sent, ackNum, window, delay = 0):
    temp = "["
    for i in range(base, ceil + 1):
        if i == base:
            temp = temp + format(i)
            continue
        else:
            temp = temp + "," + format(i)
    temp = temp + "]"
    print("Current Window: " + temp)
    print("Current Window Size:",window)
    for i in sent:
        print("Sequence Number of Packet Sent: {}".format(i))
    print("Ack Received: {}".format(ackNum))
    if delay != 0:
        print("Delay of Packet {}: {} ms".format(ackNum, delay * 1000))
    print('\n')

port = int(input("Enter Port Number to run: "))
cs = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
packets = initializePackets()

adjustedTimeout = 5
timeoutInterval = 0
estimatedRTT = 0
timeout = 0
devRTT = 0

windowSize = 1
windowBase = 1
windowCeil = 1
maxWindow = 1

lastAckDup = False
lastAckDupCount = 0
maxAck = 0
lastSent = 1
quadAckNumber = 0

delay = []
ackNum = 0
sent = []
ackCount = [0] * 2409
transmissionRate = [0]*2409
dupAckArray = [0]*2409

alpha = 2
beta = 4
delta = 0
RTTm = .5

everyOther = False
doubleAck = (0, 0)
timeoutCount = 0
doubleAckCount = 0
receiveBufferTimeoutCount = 0


slowStart = True  #If True: in slow start phase.  If False: in congestion control
congControl = 0  #When in congestion control. When window is increased, congControl is assigned the ceiling of the window.  

totalTime = time.time()

delay.append(time.time())
cs.sendto(packets[0], ("127.0.0.1", port))

pollerObject = select.poll()
pollerObject.register(cs, select.POLLIN)

cs.settimeout(5)
while True:
    if windowSize > maxWindow:
        maxWindow = windowSize

    try:
        if time.time() - delay[windowBase - 1] > adjustedTimeout:
            raise TimeOutException() #If delay is greater than our timeout value, raise exception to retransmit

        ackNum = -1
        try:
            cs.settimeout(adjustedTimeout)
            ack, add = cs.recvfrom(2048)
            ackNum = int(ack.decode())
        except socket.timeout:
            receiveBufferTimeoutCount += 1 #Stats tracked.  I feel that it takes a lot longer if the recvfrom() blocks rather than throwing exception above.
            raise TimeOutException()

        maxAck = ackNum  #This assignment is because I don't feel like changing all maxAck back to ackNum...A relic of a bigone era 

        #If maxAck less than windowBase, then it is a duplicate acknowledgement
        if maxAck < windowBase:
            dupAckArray[maxAck] += 1  #Used at one point in time to map number of duplicate ack per packet.  Kept in case I need to reference later.
            
            #Tuple doubleAck was used for a fast retransmit approach used in TCP Vegas.  Removed feature as I feel it was retransmitting to much, but kept the tuple because
            #it is used a lot in other places.
            if maxAck == doubleAck[1]:
                doubleAck = (doubleAck[0] + 1, maxAck)
            else:
                doubleAck = (1, maxAck)
            
            #Resending a duplicate packet only happens after 3 duplicate ack in a row.
            if(doubleAck[0] == 3):  
                doubleAckCount += 1
                windowSize -= 1
                print("Triple Acknowledgement--- Window Size is:", windowSize)
                print("Resending packet:", maxAck + 1)
                cs.sendto(packets[maxAck], ("127.0.0.1", port))

                sent.append(maxAck + 1)
                printMetrics(windowBase, windowCeil, sent, maxAck, windowSize)
                sent = []
                lastAckDup = True
                lastAckDupCount = 0
            #If more than 3 duplicate ack are received in a row, only 1 packet is sent for that whole group. 
            elif(doubleAck[0] > 3):
                printMetrics(windowBase, windowCeil, sent, maxAck, windowSize)
                continue
            
            #lastAckDup = True
            #lastAckDupCount = 0
            continue
        
        delay[maxAck - 1] = time.time() - delay[maxAck - 1] #RTT of packet received
        #Setting the minimum RTT for congestion control below
        if delay[maxAck - 1] < RTTm:
            RTTm = delay[maxAck - 1]

        #Timeout function as per the book    
        estimatedRTT = .875 * estimatedRTT + .125 * delay[maxAck - 1]
        devRTT = .75 * devRTT + .25 * abs(delay[maxAck - 1] - estimatedRTT)
        timeoutInterval = estimatedRTT + 4 * devRTT
        adjustedTimeout = timeoutInterval
        
        #Sets delay for all packets in window below last Ack received
        for i in range(windowBase - 1, maxAck):
                delay[i] = delay[maxAck - 1]
        
        #Ack for last packet...done sending packets
        if(maxAck >= len(packets)):
            break

        #windowCeil cannot be larger than the total number of packets
        if windowCeil >= len(packets):
            windowCeil = len(packets)
            continue
        
        if(slowStart == True):  
            #Increases window size every other Ack received while in slow start.
            if(windowSize * (delay[maxAck - 1] - RTTm) / delay[maxAck - 1] > 3):
                slowStart = False
            else:
                offset = maxAck - windowBase + 1
                if offset % 2 != 0 and everyOther == False:
                    everyOther = True
                    windowSize += int(math.ceil(offset / 2))
                elif offset % 2 != 0:
                    everyOther = False
                    windowSize += int(math.floor(offset / 2))
                else:
                    windowSize += offset / 2

        else:
            #CONGESTION CONTROL.  alpha = 2 beta = 4  delta is function of latest RTT and minimum RTT.  Window size only changes when delta is smaller than alpha or greater than beta
            delta = windowSize * (delay[maxAck - 1] - RTTm) / delay[maxAck - 1]
            if delta < alpha:
                windowSize += 1
            elif delta > beta:
                windowSize -= 1
            
        #Setting new window
        windowBase = maxAck + 1
        windowCeil = int(windowBase + windowSize - 1)
        
        #Sends the first two packets after triple dup ack if their delay is greater than adjustedTimeout
        if lastAckDup == True:
            if windowBase - 1 >= lastSent:
                pass
            elif lastAckDupCount == 0  and time.time() - delay[windowBase - 1] > adjustedTimeout:
                cs.sendto(packets[windowBase - 1], ("127.0.0.1", port))
                lastAckDupCount += 1
                #continue
            elif lastAckDupCount == 1 and time.time() - delay[windowBase - 1] > adjustedTimeout:
                cs.sendto(packets[windowBase - 1], ("127.0.0.1", port))
                lastAckDup == False
                #continue

        #Don't send new packets when window decreases
        if(lastSent > windowCeil):
            continue
        
        #Sends all unsent packets in window
        for send in range(lastSent, windowCeil):
            if(send >= 2409):
                cs.sendto(packets[2408], ("127.0.0.1", port))
                break
            transmissionRate.append(windowSize)
            delay.append(time.time())
            cs.sendto(packets[send], ("127.0.0.1", port))
            sent.append(send + 1)
            lastSent = send + 1
        
        printMetrics(windowBase, windowCeil, sent, ackNum, windowSize, delay[ackNum - 1])
        sent = []

    except TimeOutException:
        #Timeout can occur 2 ways.  One is if recv buffer is empty and it blocks.  The other is if windowBase packet delay is greater than adjusted timeout.
        doubleAck = (0, maxAck)
        windowSize -= 1

        adjustedTimeout = 2 * adjustedTimeout
        cs.sendto(packets[windowBase - 1], ("127.0.0.1", port))

        timeoutCount += 1
      

throughput = []
for n in range(0, len(packets)):
    throughput.append(len(packets[n]) / delay[n])
avgThroughput = (sum(throughput) / len(throughput)) * 8

print("-------------------The Stats-------------------")
print("Average RTT: {} ms".format(round((sum(delay) / len(delay) * 1000))))
print("Program Run Time: {} seconds".format(time.time()-totalTime))
print("Average Throughput: {} bits per second".format(avgThroughput))
print("Max RTT: {}".format(round(max(delay) * 1000)))
print("Performance: {}".format(math.log(avgThroughput, 10) - math.log(sum(delay) / len(delay) *1000, 10)))
print("Timeout Count: {}".format(timeoutCount - receiveBufferTimeoutCount))
print("Empty Receive Buffer Timeout: {}".format(receiveBufferTimeoutCount))
print("Double Ack Count: {}".format(doubleAckCount))
print("----------This is the end of the stats----------")
