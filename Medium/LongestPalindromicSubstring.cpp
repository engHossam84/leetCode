/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
	//https://www.youtube.com/watch?v=nbTSfrEfo6M
public:
	// Transform S into T.
	// For example, S = "abba", T = "^#a#b#b#a#$".
	// ^ and $ signs are sentinels appended to each end to avoid bounds checking
	static	string preProcess(const string& s) {
		int n = s.length();
		if (n == 0) return "^$";
		string ret = "^";
		for (int i = 0; i < n; i++) ret += "#" + s.substr(i, 1);
		ret += "#$";
		return ret;
	}
	static 	string longestPalindrome(string s) {
		string T = preProcess(s);
		const int n = T.length();

		vector<int> Pal;
		Pal.reserve(n);
		for (int i = 0; i < n; i++)
			Pal.push_back(0);
		int C = 0, R = 0;
		for (int i = 1; i < n - 1; i++) {
			int i_mirror = 2 * C - i; // equals to i' = C - (i-C)
			if ((R > i))
			{
				Pal[i] = min(R - i, Pal[i_mirror]);
			}

			// Attempt to expand palindrome centered at i
			while (T[i + 1 + Pal[i]] == T[i - 1 - Pal[i]])
				Pal[i]++;
			// If palindrome centered at i expand past R,
			// adjust center based on expanded palindrome.
			if (i + Pal[i] > R) {
				C = i;
				R = i + Pal[i];
			}
		}
		// Find the maximum element in P.
		int max_len = 0;
		int center_index = 0;
		for (int i = 1; i < n - 1; i++) {
			if (Pal[i] > max_len) {
				max_len = Pal[i];
				center_index = i;
			}
		}
		return s.substr((center_index - 1 - max_len) / 2, max_len);
	}

	static string longestPalindrome2(string s) {
		int leftIndex, rightIndex;
		string result="";
		if (s.length() <= 1)
			return s;
		if (s.length() == 2 && s[0] == s[1])
			return s;
		int maxLength = 0;
		for (int i = 0; i < s.length() - 2; i++)
		{
			maxLength = 0;
			if (s[i] == s[i + 2])
			{
				leftIndex = i;
				rightIndex = i + 2;
				maxLength += 1;
				while (s[leftIndex] == s[rightIndex])
				{
					maxLength += 2;
					if (maxLength > result.length())
						result = s.substr(leftIndex, rightIndex - leftIndex + 1);
					if (leftIndex - 1 >= 0 && rightIndex + 1 <= s.length())
					{
						leftIndex--;
						rightIndex++;
					}
					else if (leftIndex == 0 && rightIndex + 1 <= s.length())
					{
						rightIndex++;
					}
					else
						break;
				}
			}
			else if (s[i] == s[i + 1])
			{
				leftIndex = i ;
				rightIndex = i + 1;
				while (s[leftIndex] == s[rightIndex] )
				{
					maxLength += 2;
					if(maxLength > result.length())
						result = s.substr(leftIndex, rightIndex - leftIndex + 1);
					if (leftIndex - 1 >= 0 && rightIndex + 1 <= s.length())
					{
						leftIndex--;
						rightIndex++;
					}
					else if (leftIndex == 0 && rightIndex + 1 <= s.length())
					{
						rightIndex++;
					}
					else
						break;
				}

			}
		}
		return result;
	}

	static string longestPalindrome3(string s) {
		int leftIndex, rightIndex, maxLength = 0, tempLength = 0;
		string result = string(1,s[0]);
		if (s.length() == 1)
			return result;
		for (int i = 0; i < s.length(); i++)
		{
			leftIndex = i;
			size_t position = s.rfind(s[i]);
			while (position != i)
			{
				rightIndex = position;
				while (s[leftIndex] == s[rightIndex])
				{
					if (leftIndex != rightIndex && (leftIndex + 2 < rightIndex))
					{
						leftIndex++;
						rightIndex--;
						tempLength += 2;
					}
					else if (leftIndex != rightIndex && (rightIndex - leftIndex <=2 ))
					{
						if(rightIndex - leftIndex == 2)
							tempLength += 3;
						else
							tempLength += 2;
						if (tempLength > maxLength)
						{
							result = s.substr(i, position - i + 1);
						//	i = position - 1;
							maxLength = tempLength;
							tempLength = 0;
							break;
						}
						else
							break;
					}
					else
					{
						if (tempLength > maxLength)
						{
							result = s.substr(i, position - i);
							maxLength = tempLength;
						}
					}
				}
				position = s.rfind(s[i], position - 1);
				leftIndex = i;
				tempLength = 0;
			}

		}
		return result;

	}
};

void main()
{
	cout << Solution::longestPalindrome("abb") << endl;
	cout << Solution::longestPalindrome("babad") << endl;
	cout << Solution::longestPalindrome("babaddda") << endl;
	cout << Solution::longestPalindrome("aaabaaaa") << endl;

	cout << Solution::longestPalindrome("aaaabaaa") << endl;

	cout << Solution::longestPalindrome("dfsbabababsfgter") << endl;
	cout << Solution::longestPalindrome("") << endl;
	cout << Solution::longestPalindrome("a") << endl;
	cout << Solution::longestPalindrome("babad") << endl;

	cout << Solution::longestPalindrome("cbbd") << endl;
}