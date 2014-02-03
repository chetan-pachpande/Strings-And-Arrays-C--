/*
============================================================================
Author         : Chetan Pachpande
Email          : chetandpachpande@gmail.com
Description    : Program to perform following string functions
                 1> to check uniqueness of string
				 2> to reverse a string
				 3> to remove duplicates from string
				 4> to check if two strings are anagrams of each other
				 5> to replace space in a string with %20
				 6> to check if a string rotation of another
Last Modified  : 12/17/2013
============================================================================
*/

#include <iostream>
#include <string>
#include "StringFunction.h"

using namespace std;

int main()
{
	StringFunction sf;

	//--------------------------------------------------------------------------------------
	// Unique check

	string s1 = "abcdefg";
	string s2 = "AbcdEfS";
	char s3[] = "chetan";

	bool flag = sf.IsUnique(s1);

	if (flag)
	{
		cout << "Success: String Contains unique Characters" << endl;
	}
	else
		cout << "Failed: String Doesnot Contains unique Characters!!" << endl;

	flag = sf.IsUnique2(s2);

	if (flag)
	{
		cout << "Success: String Contains unique Characters" << endl;
	}
	else
		cout << "Failed: String Doesnot Contains unique Characters!!" << endl;

	//--------------------------------------------------------------------------------------
	// String Reverse

	sf.reverse_string(s3);
	cout << "String after reverse: " << s3  << endl;

	//--------------------------------------------------------------------------------------
	// String Reverse

	char s4[] = "aabbccssds";
	cout << "Before removing Duplicates s4 [using duplicate 1] : " << s4 << endl;
	sf.removeDuplicates(s4);
	cout << "After removing Duplicates s4: [using duplicate 1] " << s4 << endl;

	//--------------------------------------------------------------------------------------
	// String Reverse

	char s5[] = "aabbccgjdtwssds";
	cout << "Before removing Duplicates s5 [using duplicate 2 : " << s5 << endl;
	sf.removeDuplicatesEff(s5);
	cout << "After removing Duplicates s5: [using duplicate 2] " << s5 << endl;

	//--------------------------------------------------------------------------------------
	// ANAGRAM
	//--------------------------------------------------------------------------------------
	char test1[] = "abcdefghijk";
	char test2[] = "jghakbedcid";

	bool result1 = sf.anagram(test1, test2);
	bool result2 = sf.anagram2(test1, test2);

	cout << "Result of anagram for strings " << test1 << " and " 
		 << test2 << " using anagram function: " << result1
		 << " and using anagram2 function is: " << result2 << endl;
	//--------------------------------------------------------------------------------------
    // REPLACE SPACE WITH %20

	//char test_space[] = "Hi My Name is Chetan";

	//cout << "String Before replacing Space: " << test_space << endl;
	//int str_len = std::strlen(test_space);
	////char space_result[];
	//string space1_result = sf.replaceSpace(test_space, str_len);
	//cout << "String After replacing Space: " << test_space << endl;

	//--------------------------------------------------------------------------------------
	// REPLACE SPACE WITH %20

	char str[100] = " aa bb cc !";

	cout << "before replace :" << str << endl;

	sf.replace_space(str);

	cout << "after replace :" << str << endl;

	//--------------------------------------------------------------------------------------
	// IsRotation test
	string r_s1 = "apple";
	string r_s2 = "pleap";

	bool rotate_result;
	rotate_result = sf.IsRotation(r_s1, r_s2);
	
	if (rotate_result)
		cout << r_s1 << " is rotation of " << r_s2 << endl;
	else
		cout << r_s1 << " is not a rotation of " << r_s2 << endl;
	//--------------------------------------------------------------------------------------

	return 0;
}