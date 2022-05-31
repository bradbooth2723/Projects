# Array_Class
Array Class for C++

## Template Peramaters
T: Type of element contained in the Array Class \
Length: Size of initial array when object is declared

## Declarations
Array objName<T, Length>();  //Creates an empty array of type T of length Length. \
Array objName(otherArray);  //Creates a new array objName that is a copy of otherArray \
auto objName = otherArray;  //Creates a new array objName then makes it a copy of otherArray \

## Member Functions
//Returns length of the array\
std::size_t size() const;               

//Returns const reference to first element in array\
const T& front() const;

//Returns const reference to last element in array\
const T& back() const;

//Returns reference to value at the given index\
T& at(std::size_t index);

//Returns const reference to value in array at given index\
const T& at(std::size_t index);

## Overloaded Class Operators
==  Returns a true LH operator is equal to RH operator, and returns false if LH operator does not equal RH operator \
!=  Returns a false LH operator is equal to RH operator, and returns true if LH operator does not equal RH operator \
= Makes LH operator a copy of RH operator.

## Overloaded Operator
<< Prints each element of the array.  This is not a class operator.

## Non-member Function
//returns const reference and non const reference of array passed to function\
T& get(Array arr);\
const T& get(const Array arr);\
