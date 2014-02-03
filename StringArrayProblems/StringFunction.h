#pragma once

#include <iostream>
#include <string>

using namespace std;

class StringFunction
{
public:
	StringFunction();
	~StringFunction();

	//Implement an algorithm to determine if a string has all unique characters.
	bool IsUnique(string testString);
	
	//Implement an algorithm to determine if a string has all unique characters, you can not use additional data structures
	bool IsUnique2(string testString);

	// Reverse string c-style
	void reverse_string(char* str);

	// Code to remove the duplicate characters in a string without using any additional buffer.
	void removeDuplicates(char str[]);

	// efficient program with additional memory
	void removeDuplicatesEff(char str[]);

	// method to decide if two strings are anagrams or not (easiest way sort both and compare)
	bool anagram(char *str1, char *str2);
	// method to decide if two strings are anagrams or not, using single buffer
	bool anagram2(char *str1, char *str2); // using single buffer

	// A method to replace all spaces in a string with ‘%20’. (used in URLs)
	char* replaceSpace(char *str, int length);

	// Another method to replace all spaces in a string with ‘%20’
	void replace_space(char* str);

	// To check if a string is rotation of other string.
	bool IsRotation(string s1, string s2);

};

