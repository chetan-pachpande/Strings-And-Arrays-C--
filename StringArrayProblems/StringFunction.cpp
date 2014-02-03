#include "StringFunction.h"
#include <algorithm>
#include <iostream>
#include <string>

# define NO_OF_CHARS 256

using namespace std;

StringFunction::StringFunction()
{
}


StringFunction::~StringFunction()
{
}

#pragma region Problem 1.1.a: Check String for Unique Characters
/// <summary>
/// Determines whether the specified test string is unique.
/// </summary>
/// <param name="testString">The test string.</param>
/// <returns></returns>
bool StringFunction::IsUnique(string testString)
{
	bool char_set[256] = { 0 };

	for (int i = 0; i < (int)testString.length(); i++)
	{
		int val = testString.at(i);

		if (char_set[val]) return false;
		char_set[val] = true;

	}

	return true;
}
#pragma endregion

#pragma region Problem 1.1.b: Check String for Unique Characters (no extra data structure)

bool StringFunction::IsUnique2(string testString)
{	
	// 32 bit array
	int checker = 0;

	for (int i = 0; i < (int)testString.length(); ++i)
	{
		// Ascii value calculation
		int val = testString.at(i) - 'a';
		 
		// anding and left shift operation
		if ((checker & (1 << val)) > 0) 
			return false;

		 checker |= (1 << val);
		
	}
	return true;	
}
#pragma endregion

#pragma region Problem 1.2: Reverse String C-style
void StringFunction::reverse_string(char* str)
{
	char * end = str;
	char tmp;
	if (str) {
		while (*end) {
			++end;
		}
		--end;
		while (str < end) {
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}
}
#pragma endregion

// No (Large) Additional Memory
#pragma region Problem 1.3.a: Remove Duplicates in string

	void StringFunction::removeDuplicates(char str[]) 
	{
		if (str == NULL) return;
		int len = strlen(str);
		if (len < 2) return;

		int tail = 1;

		for (int i = 1; i < len; ++i) {
			int j;
			for (j = 0; j < tail; ++j) {
				if (str[i] == str[j]) break;
			}
			if (j == tail) {
				str[tail] = str[i];
				++tail;
			}
		}
		str[tail] = 0;
	}

#pragma endregion

#pragma region Problem 1.3.b: Remove Duplicates in string (efficient + additional memory)
	
	void StringFunction::removeDuplicatesEff(char str[])
	{
		if (str == NULL) return;
		int len = strlen(str);
		if (len < 2) return;
		bool hit[256];

		for (int i = 0; i < 256; ++i) 
		{
			hit[i] = false;
		}

		hit[str[0]] = true;
		
		int tail = 1;
		
		for (int i = 1; i < len; ++i) {
			if (!hit[str[i]]) {
				str[tail] = str[i];
				++tail;
				hit[str[i]] = true;
			}
		}
		
		str[tail] = 0;
	}

#pragma endregion

#pragma region Problem 1.4.a: To check if two strings are anagram of each other

	bool StringFunction::anagram(char *str1, char *str2)
	{
		// Create two count arrays and initialize all values as 0
		int count1[NO_OF_CHARS] = { 0 };
		int count2[NO_OF_CHARS] = { 0 };
		int i;

		// For each character in input strings, increment count in
		// the corresponding count array
		for (i = 0; str1[i] && str2[i]; i++)
		{
			count1[str1[i]]++;
			count2[str2[i]]++;
		}

		// If both strings are of different length. Removing this condition
		// will make the program fail for strings like "aaca" and "aca"
		if (str1[i] || str2[i])
			return false;

		// Compare count arrays
		for (i = 0; i < NO_OF_CHARS; i++)
		if (count1[i] != count2[i])
			return false;

		return true;
	}
	

#pragma endregion

#pragma region Problem 1.4.b: To Check if two strings are anagrams of each other - using single buffer
	
	bool StringFunction::anagram2(char *str1, char *str2)
	{
		// Create two count arrays and initialize all values as 0
		int count[NO_OF_CHARS] = { 0 };
		int i;

		// For each character in input strings, increment count in
		// the corresponding count array
		for (i = 0; str1[i] && str2[i]; i++)
		{
			count[str1[i]]++;
			count[str2[i]]--;
		}

		// If both strings are of different length. Removing this condition
		// will make the program fail for strings like "aaca" and "aca"
		if (str1[i] || str2[i])
			return false;

		// See if there is any non-zero value in count array
		for (i = 0; i < NO_OF_CHARS; i++)
		if (count[i])
			return false;
		return true;
	}

#pragma endregion

// TODO: This code gives corrupted string (debug this program)
#pragma region Problem 1.5.a: A method to replace space in a string with %20

	char* StringFunction::replaceSpace(char *str, int length)
	{
		int spaceCount = 0, newLength, i = 0;
		for (i = 0; i < length; i++)
		{
			if (str[i] == ' ')
			{
				spaceCount++;
			}
		}

		newLength = length + spaceCount * 2;
		str[newLength] = '\0';

		for (i = length - 1; i >= 0; i--)
		{
			if (str[i] == ' ')
			{
				str[newLength - 1] = '0';
				str[newLength - 2] = '2';
				str[newLength - 3] = '%';
				newLength = newLength - 3;
			}
			else
			{
				str[newLength - 1] = str[i];
				newLength = newLength - 1;
			}
		}

		return str;
	}

#pragma endregion

#pragma region Problem 1.5.b: A method to replace space in a string with %20
	void StringFunction::replace_space(char* str)
	{
		char *space = "%20";

		int len = strlen(str);
		if (len == 0){
			return;
		}

		int i;

		int space_num = 0;

		for (i = 0; i < (int)strlen(str); i++){
			if (str[i] == ' ' || str[i] == '\t'){
				space_num++;
			}
		}

		if (space_num == 0)
			return;

		int len_after;
		len_after = len + space_num * 2;

		str[len_after] = '\0';

		for (i = len - 1; i >= 0; i--){
			if (str[i] == ' ' || str[i] == '\t'){
				str[len_after--] = '0';
				str[len_after--] = '2';
				str[len_after--] = '%';
			}
			else{
				str[len_after--] = str[i];
			}
		}
	}
#pragma endregion

#pragma region Problem 1.8: To check if a string is rotation of other string.
	bool StringFunction::IsRotation(string s1, string s2)
	{

		int len = s1.length();
		/* check that s1 and s2 are equal length and not empty */
		if (len == s2.length() && len > 0) {
			/* concatenate s1 and s1 within new buffer */

			static const basic_string <char>::size_type npos = -1;

			string str3 = s1 + s2;

			if (str3.find(s2) != npos)
				return true;
			else
				return false;

		}		
		return false;		
	}

#pragma endregion

#pragma region Code Not Working
	//bool StringFunction::anagram(string s, string t)
	//{
	//	string s1;
	//	s1 = s;
	//	string t1;
	//	t1 = t;

	//	sort(s1.begin(), s1.end());
	//	sort(t1.begin(), t1.end());

	//	if (s1 == t1)
	//	{
	//		cout << "anagram using sort : True";
	//	}
	//	else
	//		cout << "anagram using sort : False";

	//	if (s.length() != t.length()) return false;


	//	int letters[256];
	//	int num_unique_chars = 0;
	//	int num_completed_t = 0;
	//	char s_array[] = "";

	//	//std::strcpy(s_array, s.c_str());

	//	int lengthOfString = s.length;
	//	s.copy(s_array, lengthOfString);
	//	//str.copy(characters, lengthOfString)
	//	//strncpy(s_array, s.c_str(), sizeof(s_array));
	//	//s_array[sizeof(s_array)-1] = 0;

	//	for (char c : s_array) { // count number of each char in s.
	//		if (letters[c] == 0) ++num_unique_chars;
	//		++letters[c];
	//	}
	//	for (int i = 0; i < t.length(); ++i) {
	//		int c = t.at(i);
	//		if (letters[c] == 0) { // Found more of char c in t than in s.
	//			return false;
	//		}
	//		--letters[c];
	//		if (letters[c] == 0) {
	//			++num_completed_t;
	//			if (num_completed_t == num_unique_chars) {
	//				// it’s a match if t has been processed completely
	//				return i == t.length() - 1;
	//			}
	//		}
	//	}
	//	return false;

	//}
#pragma endregion













