/*
///////////////////////////////////////////////////////////////////////////////
file name: mystring.h												   
///////////////////////////////////////////////////////////////////////////////


Write a string class. To avoid conflicts with other similarly named classes
MyString. This object is designed to make working with sequences of characters
a little more convenient and less error-prone than handling raw c-strings,
(although it will be implemented as a c-string behind the scenes). The MyString
class will handle constructing strings, reading/printing, and accessing characters.
In addition, the MyString object will have the ability to make a full deep-copy
of itself when copied. Makes the following refinements to the class in the last 
assignment. All the requirements from that class are still in force. For example,
all MyStrings must always be stored in a dynamic array that is exactly the correct
size to store the string. (score on this assignment will take into consideration
on both the previous assignment and this assignment.)

This MyString class must have only one data member, a c-string implemented as a
dynamic array. In particular, must not use a data member to keep track of the
size or length of the MyString. A full documentation is required for theis part.

In MyStrings class, Overload extraction Operator >> is implemented. Just like
the >> operator that reads C-strings, this >> operator will skip any leading
spaces and then read characters into the string up to the first whitespace character.
For convenience, impose a limit of 127 on the number of characters it can read. 
(Note that this does not mean that all MyStrings will always have a maximum of 127
characters. For example, you might get a MyString with more than 127 characters
by using the MyString constructor or by concatenating two MyStrings.)

This MyStrings class has a constant for the maximum input size and is declared
it in the public area of the class. It is static.

Read ability is also implemented, allows the client programmer to specify the
delimiting character (the character at which reading will stop). It works just
like the getline() function works for c-strings; that is, it places everything
up to but not including the delimiting character into the calling object, and it
also consumes (and discards) the delimiting character. It does not skip leading
spaces. The limit of 127 characters.

In MyStrings class, overload concatenation Operator + is implemented to do MyString
concatenation. The operator is able to handle either MyString objects or C-strings
on either side of the operator.  

In MyStrings class, the combined Concatenation/Assignment Operator is implemented.
Overload the shorthand += is to combine concatenation and assignment. Only MyStrings
can be on the left-hand side of a += operation, but either MyStrings or C-strings
may appear on the right side.  

In MyStrings class, a length member function that returns the number of characters
in the string is implemented.

In MyStrings class, construction of a MyString from a const c-string is implemented.
it deep copies the string data, not just store a pointer to an argument passed to
the constructor. 

In MyStrings class, default constructor is implemented, constructing a MyString
with no arguments creates an empty MyString object (i.e. ""). A MyString object
is implemented efficiently (space-wise), which does not have a fixed-size buffer
of chars, but instead allocate space for chars on an as-needed basis.
 
In MyStrings class, overload insertion operator << is implemented, which
printing a MyString to a stream. The overloaded << (insertion) operator, 
is simply print outits characters. 

In MyStrings class, MyString object can overload the square brackets [ ] operator
to allow direct access to the individual characters of the string. This operation
does range-check and assert if the index is out of bounds. two versions of the [ ]
operator are implemented. one is a const version that allows read access to the
chars, and another is a non-const version that returns the client a reference to
the char so they can change the value.

All six of the relational operators (<, <=, >, >=, ==, !=) are supported. They
are able to compare MyStrings to other MyStrings as well as MyStrings to c-string.
The ordering will be based on ASCII values. ASCII values are defined as uppercase
letters will always come before lowercase letters. Either MyStrings or c-string
can appear on either side of the binary comparison operator.


///////////////////below are Class declarations documention////////////////////

public:

static const int MAX_INPUT_SIZE = 127;
//POST: A constant for the maximum input size is created and declared in the public
//area of the class. It is static.



MyString();
//Default constructor, constructing a MyString with no parameters, creates an empty
//MyString object. POST: creates an empty MyString object. It is required that a
//c-string implemented as a dynamic array.



MyString(const char* newCharArray);
//This is a parameterized constructor, takes one parameter, which is a cstring.
//c-string must be implemented as a dynamic array on the heap as required;
//POST: creates an MyString object, assigns MyString object�s cstring value
//as required that a c - string must be implemented as a dynamic array.



MyString(const MyString& right);
//one of the big-3 member functions must be included in any class that uses dynamic
//memory. this is Copy Constructor. This construction of a MyString copies the
//exact string data on the heap, not just store a pointer to an argument passed
//to the constructor. This deep copy constructor is used when C++ has to make
//a copy of an object in situations where the assignment operator is not being
//used. POST: creates an MyString object, assigns values to MyString object



~MyString();
//one of the big-3 member functions that must be included in any class that uses
//dynamic memory. This is Destructor. a destructor that is called automatically
//when an object on the stack is deallocated (this normally happens when
//execution reaches the end of a function). POST: deallocated MyString object



MyString operator=(const MyString& right);
//one of the big-3 member functions must be included in any class that uses dynamic
//memory. this is assignment operator =. The = assignment operator overload
//performs a deep copy. It also can handle self-assignment. POST: returns
//MyString object, (overloaded assignment operator = is used exclusively for
//situations where the actual assignment operator is used in a client program.)



char operator[](int index) const;
//overload square brackets operator, the left bracket appearing between the two
//operands, and a right bracket appearing AFTER the right operand. So in the
//expression item1[1], the left operand (or calling object) is item1 and the right
//operand is 1. POST: This overloaded square - brackets operator, returns a copy
//of the char at the index



char& operator[](int index);
//overload square brackets operator, the left bracket appearing between the two
//operands, and a right bracket appearing AFTER the right operand. So in the
//expression item1[1], the left operand (or calling object) is item1 and the right
//operand is 1. POST: This overloaded square - brackets operator, returns a
//REFERENCE to a char (which is actually the memory address of a variable) for
//the calling function to be able to use it as an lvalue (left value) for client
//program to work.



friend std::ostream& operator<<(std::ostream& out, const MyString& right);
//overloaded insertion(<< ) operator. It prints out MyString object right.
//POST: Prints a MyString to a stream with an overloaded insertion(<<) operator.



int length() const;
//POST: returns the number of characters in the string.



friend bool operator>(const MyString& left, const MyString& right);
//relational operator (>). It's operator overload. compares MyStrings to other
//MyStrings, as well as MyStrings to c-strings. Either MyStrings or c-strings
//can appear on either side of the binary comparison operator. POST: returns
//true if left MyString object (or an c-string) is greater than right MyString
//object (or c-string)



friend bool operator>=(const MyString& left, const MyString& right);
//relational operator (>=). It's operator overload. compares MyStrings to other
//MyStrings, as well as MyStrings to c-strings. Either MyStrings or c-strings
//can appear on either side of the binary comparison operator. POST: returns
//true if left MyString object (or an c-string) is greater than or equal to
//right MyString object (or c-string)



friend bool operator<(const MyString& left, const MyString& right);
//relational operator (<). It's operator overload. compares MyStrings to other
//MyStrings, as well as MyStrings to c-strings. Either MyStrings or c-strings
//can appear on either side of the binary comparison operator. POST: returns
//true if left MyString object (or an c-string) is smaller than right MyString
//object (or c-string)



friend bool operator<=(const MyString& left, const MyString& right);
//relational operator (<=). It's operator overload. compares MyStrings to other
//MyStrings, as well as MyStrings to c-strings. Either MyStrings or c-strings
//can appear on either side of the binary comparison operator. POST: returns
//true if left MyString object (or an c-string) is smaller than or equal to
//right MyString object (or c-string)



friend bool operator==(const MyString& left, const MyString& right);
//relational operator (==). It's operator overload. compares MyStrings to other
//MyStrings, as well as MyStrings to c-strings. Either MyStrings or c-strings
//can appear on either side of the binary comparison operator. POST: returns
//true if left MyString object (or an c-string) is equal to right MyString
//object (or c-string)



friend bool operator!=(const MyString& left, const MyString& right);
//relational operator (!=). It's operator overload. compares MyStrings to other
//MyStrings, as well as MyStrings to c-strings. Either MyStrings or c-strings
//can appear on either side of the binary comparison operator. POST: returns
//true if left MyString object (or an c-string) is NOT equal to right MyString
//object (or c-string)



friend std::istream& operator>>(std::istream& in, MyString& right);
//Extraction Operator overload, this >> operator skips any leading spaces and
//then read characters into the string up to the first whitespace character. It
//imposes a limit of 127 on the number of characters this function will read. 
//Note that this does not mean that all MyStrings will always have a maximum of
//127 characters. it might get a MyString with more than 127 characters by using
//the MyString constructor or by concatenating two MyStrings.
//POST: overloaded extraction (>>) operator. reads a MyString from a stream.



void read(std::istream& in, char delimiter);
//a void function, it takes two parameters, a stream and the delimiting
//character. It does NOT skip leading spaces.This function allows the client
//programmer to specify the delimiting character (the character at which the
//reading will stop). It works just like the getline() function works for c-
//strings; ie, it places everything up to but not including the delimiting
//character into the calling object, and it also consumes (and discards) the
//delimiting character.  The limit of 127 characters imposed on the >> function
//also applies to this function. POST: read text data from a file line by line
//delimited by the char parameter delimiter from stream into MyString object.



friend MyString operator+(const MyString& left, const MyString& right);
//Overload concatenation + operator to do MyString concatenation. The operator
//is able to handle either MyString objects or C-strings on either side of
//the operator. Either MyStrings or c-strings can appear on either side of
//the + operator.  POST: concatenats MyStrings to other MyStrings as well as
//MyStrings to c-strings. returns MyString object after concatenation



MyString operator+=(const MyString& right);
//Combined Concatenation/Assignment Operator (+=). Overload the shorthand += to
//combine concatenation and assignment. Only MyStrings can be on the left-hand side
//of a += operation, but either MyStrings or C-strings may appear on the right side.
//POST: concatenats MyStrings to other MyStrings as well as MyStrings to C-strings.
//returns MyString object after Concatenation/ Assignment
*/

#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
//using namespace std;//for ostream, without it, it won't work

namespace cs_mystring
{
	class MyString
	{
	public:
		static const int MAX_INPUT_SIZE = 127;
		MyString();
		MyString(const char* newCharArray);
		MyString(const MyString& right);
		~MyString();
		MyString operator=(const MyString& right);
		char operator[](int index) const;
		char& operator[](int index);
		friend std::ostream& operator<<(std::ostream& out, const MyString& right);
		int length() const;
		friend bool operator>(const MyString& left, const MyString& right);
		friend bool operator>=(const MyString& left, const MyString& right);
		friend bool operator<(const MyString& left, const MyString& right);
		friend bool operator<=(const MyString& left, const MyString& right);
		friend bool operator==(const MyString& left, const MyString& right);
		friend bool operator!=(const MyString& left, const MyString& right);
		friend std::istream& operator>>(std::istream& in, MyString& right);
		void read(std::istream& in, char delimiter);
		friend MyString operator+(const MyString& left, const MyString& right);
		MyString operator+=(const MyString& right);
		 
		
	private:
		char* cstrDynArr;
	};
}

#endif

