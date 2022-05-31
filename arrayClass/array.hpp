#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <ostream>
#include <cassert>
#include <iostream>
/**
 * Array of a fixed length.
 */
/**
 * std::size_t is a C++ alternative to the size_t type from C.
 * size_t is typically used when referring to anything that is a quantity
 * related to memory, such as the length of an array (which is in memory).
 * It is an unsigned integer type and is typically (but not always) a typedef
 * for something like unsigned or long unsigned.
 * (If you think this is complicated, then you should look up size_type.)
 */
template <typename T, std::size_t Length>
class Array
{
public:
    /**
     * TODO: Provide a static assertion here that will prohibit arrays
     * of length 0.
     */


    Array()
    {
	    //static_assert(Length > 0);
	    length = Length;
	    pa = new T[length];
    }
    ~Array()
    {
	    delete [] pa;
    }
    Array(const Array& other)
    {
	    length = other.size();
	    pa = new T[length];

	    for (std::size_t i = 0; i < length; ++i)
	    {
		    pa[i] = other.at(i);
	    }
    }

    Array& operator=(const Array& other)
    {
	    delete [] pa;
	    length = other.size();
	    pa = new T[length];

	    for (std::size_t i = 0; i < length; ++i)
	    {
		    pa[i] = other.at(i);
	    }
	    return *this;
    }

    /**
     * Returns the size of the array
     */
    std::size_t size() const
    {
	    return length;
    }

    /**
     * Returns the first or last element of the array.
     *
     * Ideally, there would be non-const overloads for these too.
     */
    const T& front() const
    {
	    return pa[0];
    }

    const T& back() const
    {
	    return pa[length - 1];
    }

    /**
     * Returns the element of the array that is at the given index.
     * Throws std::out_of_range if index is out of range.
     */
    T& at(std::size_t index)
    {
	    return pa[index];
    }

    const T& at(std::size_t index) const
    {
	    return pa[index];
    };

    /**
     * Equality checking, i.e. checking if two arrays contain the exact
     * same elements.
     */
    bool operator==(const Array& other) const
    {
	    if (Length != other.size())
	    {
		    return 0;
	    } else
	    {
		    for(std::size_t i=0; i < length; i++)
		    {
			    if (pa[i] != other.at(i))
				    return 0;
		    }
	    }
	    return 1;
    }
		    

    bool operator!=(const Array& other) const
    {
	    if (Length != other.size())
	    {
		    return 1;
	    } else
	    {		 
		    for (std::size_t i = 0; i < length; i++)
		    {
			    if (pa[i] == other.at(i))
				    return 1;
		    }
	    }
	    return 0;
    }


private:
    // TODO: Your member variables and helper methods go here.
    std::size_t length;
    T *pa;
    
};

/**
 * Returns the element of the array that is at the given index.
 * Causes compilation to fail (with a static assertion) if index is out
 * of range.
 */
template <std::size_t Index, typename T, std::size_t Length>
T& get(Array<T, Length>& array)
{
	static_assert(Index < Length && Index >= 0);
	return array.at(Index);
}



template <std::size_t Index, typename T, std::size_t Length>
const T& get(const Array<T, Length>& array)
{
	static_assert(Index < Length && Index >= 0);
	return array.at(Index);
}
/**
 * Prints each element of the array.
 */
template <typename T, std::size_t Length>
std::ostream& operator<<(std::ostream& os, const Array<T, Length>& array)
{
	for (std::size_t i = 0; i < Length; i++)
	{
		os << array.at(i) << std::endl;
	}
	return os;
}

//#include "array.inl"
#endif  // ARRAY_HPP
