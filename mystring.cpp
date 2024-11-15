/*
///////////////////////////////////////////////////////////////////////////////
file name: mystring.cpp
///////////////////////////////////////////////////////////////////////////////
 

Write a string class. To avoid conflicts with other similarly named classes
MyString. This object is designed to make working with sequences of characters
a little more convenient and less error-prone than handling raw c-strings,
(although it will be implemented as a c-string behind the scenes). The MyString
class will handle constructing strings, reading/printing, and accessing characters.
In addition, the MyString object will have the ability to make a full deep-copy
of itself when copied. Use operator overload to print a MyString to a stream with
an overloaded insertion (<<) operator, this project implemented an overloaded
extraction (>>) operator and read() function. Also, Overload concatenation + 
operator and Combined Concatenation/Assignment Operator (+=), the shorthand +=, 
operator is implemented. All six of the relational operators (<,<=,>,>=,==,!=)
operators are required overload operators. Also, this class must have only one
data member, a c-string implemented as a dynamic array. In particular, must not
use a data member to keep track of the size or length of the MyString. A length
member function that returns the number of characters in the string is implemented.


Class Invariant: a MyString class must have only one data member, a c-string
				implemented as a dynamic array. In particular, must not use a
				data member to keep track of the size or length of the MyString.
private:
		char* cstrDynArr;
*/


//Visual C++ will, under its default settings, report an error when use strcpy()
//or strcat(), even though they are standard C++. To prevent this by adding this 
//line as the first line in the file :
//#pragma warning(disable:4996)

#include <iostream>
#include <cassert>//#include "assert.h
#include <cctype> 
#include <cstring> 
#include <fstream> 
#include "mystring.h"
using namespace std;


namespace cs_mystring
{
	//Default constructor, constructing a MyString with no parameters, creates an
	//empty MyString object(i.e. ""). It is required that a c-string implemented
	//as a dynamic array. In particular, must not use a data member to keep track
	//of the size or length of the MyString. Must use new operator. POST:creates
	//an empty MyString object, data member is a dynamic array on the heap.
	MyString::MyString()
	{
		cstrDynArr = new char[1];//null charster
		//*cstrDynArr = '\0';
		//cstrDynArr[0] = '\0';
		strcpy(cstrDynArr, ""); //Use double quotes
	}







	//This is a parameterized constructor (construction of a MyString) takes one
	//parameter, which is a cstring. The private member cstrDynArr must allocate
	//enough memory on the heap as required to be implemented as a dynamic array;
	//and it must be able to fit the parameter object newCharArray. Must use
	//strlen() + 1, because the null character \0 is needed in the end of the
	//character. POST: creates an MyString object, assigns parameter newCharArray
	//object�s cstring value to MyString object as required that a c - string 
	//implemented as a dynamic array. In particular, must not use a data member
	//to keep track of the size or length of the MyString. Must use new operator.
	//creates MyString object, data member as a dynamic array on the heap.
	MyString::MyString(const char* newCharArray)
	{
		cstrDynArr = new char[strlen(newCharArray) + 1];//must plus 1
		strcpy(cstrDynArr, newCharArray);
	}







	//3 member functions must be included in any class that uses dynamic memory.
	//These three functions are commonly referred to as the "big-3". one of the
	//3 member functions must be included in any class that uses dynamic memory
	//is this deep Copy Constructor. This construction of a MyString copies the
	//exact string data on the heap, not just store a pointer to an argument passed
	//to the constructor. This deep copy constructor is used when C++ has to make
	//a copy of an object in situations where the assignment operator is not being
	//used. (1)don't need to delete anything, because it's creating an object from
	//nothing rather than modifying an existing object, (2) don't need to check
	//for self-assignments (3) don't need to return anything. 
	//Reemphasize: copy constructor does NOT require a delete statement! 
	//POST: creates an MyString object, assigns values to MyString object 
	MyString::MyString(const MyString& right)
	{
		cstrDynArr = new char[strlen(right.cstrDynArr) + 1];//+1 for \0
		strcpy(cstrDynArr, right.cstrDynArr);
	}







	//3 member functions must be included in any class that uses dynamic memory.
	//These three functions are commonly referred to as the "big-3". one of
	//the three member functions that must be included in any class that uses
	//dynamic memory is this Destructor. a destructor that is called automatically
	//when an object on the stack is deallocated (this normally happens when
	//execution reaches the end of a function). POST: deallocated MyString object 
	MyString::~MyString()
	{
		delete[] cstrDynArr;
	}







	//3 member functions must be included in any class that uses dynamic memory.
	//These three functions are commonly referred to as the "big-3". one of
	//these three is this assignment operator =. The = assignment operator overload
	//performs a deep copy. It also can handle a statement like "item1 = item1;". 
	//This is called self-assignment. To compare the addresses of the two objects
	//for equality. If the addresses are equal, then it is a self-assignment situation. 
	//when the calling object and right are really the same object, the value of the
	//calling object does not get destryoed. otherwise, use delete. POST: returns
	//MyString object, the value that was assigned to, ie calling object(*this).
	//(overloaded assignment operator = is used exclusively for situations where
	//the actual assignment operator is used in a client program.)
	MyString MyString::operator=(const MyString& right)
	{
		if (this != &right) //check self-assignment
		{
			delete[] cstrDynArr; //value of the calling object gets destryoed
			cstrDynArr = new char[strlen(right.cstrDynArr) + 1];//+1 for \0
			strcpy(cstrDynArr, right.cstrDynArr); //deep copy
		}

		return *this;//return object, use star*, do not return memory address
	}







	//overload square brackets operator, the left bracket appearing between the
	//two operands, and a right bracket appearing AFTER the right operand. So 
	//in the expression item1[1], the left operand (or calling object) is item1 
	//and the right operand is 1. In addition to returning the appropriate
	//character, the square brackets operator needs range checking by an assert
	//statement to make sure that the right - side operand (the integer index)
	//is in the appropriate range; that is, between 0 and one less than the length
	//of the private member  cstrDynArr. POST: This overloaded square - brackets
	//operator, returns a copy of the char at the index (a copy of the variable,
	//This way, the calling function can use it for client program to work.)  
	char MyString::operator[](int index) const
	{
		//to cast strlen() to int becasue it returns size_t, aka, long unsigned int
		assert(index >= 0 && index < static_cast<int>(strlen(cstrDynArr)));
		return cstrDynArr[index];
	}







	//overload square brackets operator, the left bracket appearing between the
	//two operands, and a right bracket appearing AFTER the right operand. So 
	//in the expression item1[1], the left operand (or calling object) is item1 
	//and the right operand is 1. In addition to returning the appropriate
	//character, the square brackets operator needs range checking by an assert
	//statement to make sure that the right - side operand (the integer index)
	//is in the appropriate range; that is, between 0 and one less than the length
	//of the private member cstrDynArr. POST: This overloaded square - brackets
	//operator, returns a REFERENCE to a variable (which is actually the memory
	//address of a variable). put an & after the word "char" so that the function
	//returns a REFERENCE to(or memory address of) a variable instead of a copy
	//of the variable. This way, the calling function will be able to use it as
	//an lvalue (left value) for client program to work.  
	char& MyString::operator[](int index)
	{
		//cast strlen() to int since it returns size_t
		assert(index >= 0 && index < static_cast<int>(strlen(cstrDynArr)));
		return cstrDynArr[index];
	}







	//overloaded insertion(<< ) operator. It prints out MyString object right.
	//POST: Prints a MyString object's private member cstrDynArr to a stream.
	ostream& operator<<(ostream& out, const MyString& right)
	{
		out << right.cstrDynArr;
		return out;
	}







	//POST: returns the number of characters in the string. use strlen
	int MyString::length() const
	{
		return strlen(cstrDynArr); //strlen returns size_t
	}







	//relational operator (>). It's operator overload. All math logic apply. 
	//compares MyStrings to other MyStrings, as well as MyStrings to c-strings.
	//Either MyStrings or c-strings can appear on either side of the binary
	//comparison operator. The ordering will be based on ASCII values. 
	//POST: returns true if left MyString object (or an c-string) is greater
	//than right MyString object (or c-string)
	bool operator>(const MyString& left, const MyString& right)
	{
		return (strcmp(left.cstrDynArr, right.cstrDynArr) > 0);
	}







	//relational operator (>=). It's operator overload. All math logic apply. 
	//compares MyStrings to other MyStrings, as well as MyStrings to c-strings.
	//Either MyStrings or c-strings can appear on either side of the binary
	//comparison operator. The ordering will be based on ASCII values. 
	//POST: returns true if left MyString object (or an c-string) is greater
	//than or equal to right MyString object (or c-string)
	bool operator>=(const MyString& left, const MyString& right)
	{
		return (strcmp(left.cstrDynArr, right.cstrDynArr) >= 0);
	}







	//relational operator (<). It's operator overload. All math logic apply. 
	//compares MyStrings to other MyStrings, as well as MyStrings to c-strings.
	//Either MyStrings or c-strings can appear on either side of the binary
	//comparison operator. The ordering will be based on ASCII values. 
	//POST: returns true if left MyString object (or an c-string) is smaller
	//than right MyString object (or c-string)
	bool operator<(const MyString& left, const MyString& right)
	{
		return (strcmp(left.cstrDynArr, right.cstrDynArr) < 0);
	}







	//relational operator (<=). It's operator overload. All math logic apply. 
	//compares MyStrings to other MyStrings, as well as MyStrings to c-strings.
	//Either MyStrings or c-strings can appear on either side of the binary
	//comparison operator. The ordering will be based on ASCII values. 
	//POST: returns true if left MyString object (or an c-string) is smaller
	//than or equal to right MyString object (or c-string)
	bool operator<=(const MyString& left, const MyString& right)
	{
		return (strcmp(left.cstrDynArr, right.cstrDynArr) <= 0);
	}







	//relational operator (==). It's operator overload. All math logic apply. 
	//compares MyStrings to other MyStrings, as well as MyStrings to c-strings.
	//Either MyStrings or c-strings can appear on either side of the binary
	//comparison operator. The ordering will be based on ASCII values. 
	//POST: returns true if left MyString object (or an c-string) is equal
	//to right MyString object (or c-string)
	bool operator==(const MyString& left, const MyString& right)
	{
		return (strcmp(left.cstrDynArr, right.cstrDynArr) == 0);
	}







	//relational operator (!=). It's operator overload. All math logic apply. 
	//compares MyStrings to other MyStrings, as well as MyStrings to c-strings.
	//Either MyStrings or c-strings can appear on either side of the binary
	//comparison operator. The ordering will be based on ASCII values. 
	//POST: returns true if left MyString object (or an c-string) is NOT equal
	//to right MyString object (or c-string)
	bool operator!=(const MyString& left, const MyString& right)
	{
		return (strcmp(left.cstrDynArr, right.cstrDynArr) != 0);
	}







	//Extraction Operator just ike the >> operator that reads C - strings, the 
	//>> operator skips any leading spacesand then read characters into the string
	//up to the first whitespace character. Just like the >> operator that reads
	//C - strings, this >> operator skips any leading spacesand then read characters
	//into the string up to the first whitespace character. For reasons of
	//convenience, this project imposes a limit of 127 on the number of characters
	//this function will read. This function  temporarily reads into a non-dynamic
	//array and then copy that into the data member cstrDynArr, which is a dynamic
	//array. Note that this does not mean that all MyStrings will always have a
	//maximum of 127 characters. For example, it might get a MyString with more 
	//than 127 characters by using the MyString constructor or by concatenating
	//two MyStrings. A constant for the maximum input size is created and declared
	//in the public area of the class. It is static. (Hint : Do not try to read 
	//character by character in a loop. Use the extraction operator to read the
	//input into a non dynamic array, then use strcpy() to copy it into the data
	//member cstrDynArr. Must allocate the correct amount of memory. (Hint: use
	//the extraction operator as suggested, it does not have to skip leading
	//whitespace, because the extraction operator does that for this purpose.
	//POST: overloaded extraction (>>) operator. reads a MyString from a stream.
	istream& operator>>(istream& in, MyString& right)
	{
		//NO need, because the extraction operator >> already ignored leading spaces
		//while (in && isspace(in.peek()))//ignore leading spaces
		//{
		//	in.ignore();
		//}

		char oneWord[MyString::MAX_INPUT_SIZE + 1];//Must +1, the last char is \0
		
		in >> oneWord; //can read MyString::MAX_INPUT_SIZE for this project

		delete[] right.cstrDynArr; //Must deallocate
		right.cstrDynArr = new char[strlen(oneWord) + 1];//Must dynamic memory in heap
		strcpy(right.cstrDynArr, oneWord);//must use strcpy for c-string
		
		return in;
	}

	




	
	//a void function, it takes two parameters, a streamand and the delimiting
	//character. It does NOT skip leading spaces.This function allows the client
	//programmer to specify the delimiting character (the character at which 
	//reading will stop). It works just like the getline() function works for 
	//c - strings; that is, it places everything up to but not including the
	//delimiting character into the calling object, and it also consumes (and
	//discards) the delimiting character.  The limit of 127 characters
	//imposed on the >> function also applies to this function. (Do not try
	//to read character by character in a loop. Use the in.getline() function
	//to read the input into a non dynamic array, then use strcpy() to copy it
	//into the data member.) POST: read text data from a file line by line delimited
	//by char delimiter from stream into MyString object.
	void MyString::read(istream& in, char delimiter)
	{
		char oneLine[MyString::MAX_INPUT_SIZE + 1];//Must +1, the last char is \0

		in.getline(oneLine, MyString::MAX_INPUT_SIZE, delimiter);

		delete[] cstrDynArr; //Must deallocate
		cstrDynArr = new char[strlen(oneLine) + 1];//Must dynamic memory in heap
		strcpy(cstrDynArr, oneLine);//must use strcpy for c-string
	}

	 



	

	//operator overload function. Overloads concatenation + operator to do MyString
	//concatenation. The operator is able to handle either MyString objects or 
	//C-strings on either side of the operator. Either MyStrings or c-strings
	//can appear on either side of the + operator. memory management is important
	//to allocate enough memory for holding the new MyString. (using strcpy()
	//to get the left operand into the result MyString, and then strcat() to
	//append the right operand.) POST: concatenats MyStrings to other MyStrings
	//as well as MyStrings to c-strings. returns MyString object after concatenation
	MyString operator+(const MyString& l, const MyString& r)
	{
		MyString concat;

		concat.cstrDynArr = new char[strlen(l.cstrDynArr) + strlen(r.cstrDynArr) + 1];
		strcpy(concat.cstrDynArr, l.cstrDynArr);
		strcat(concat.cstrDynArr, r.cstrDynArr);

		return concat;
	}




 


	//Combined Concatenation/Assignment Operator (+=). Overload the shorthand
	//operator += to combine concatenation and assignment. Only MyStrings can
	//be on the left-hand side of a += operation, but either MyStrings or
	//C-strings may appear on the right side. POST: concatenats MyStrings to
	//other MyStrings as well as MyStrings to C-strings. returns MyString object
	//after Concatenation/ Assignment.
	MyString MyString::operator+=(const MyString& right)
	{
		*this = *this + right;
		
		return *this;
	}

}
