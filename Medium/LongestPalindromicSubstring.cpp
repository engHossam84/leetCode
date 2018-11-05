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
	
	//run time 1644 ms
	string longestPalindrome4(string s) {
        unordered_map<char,vector<int>> charList;
        int forwardIdx;
        int backwardIdx;
        string output="";
        bool isMatched = false;
        if(s.length() < 2)
            return s;
        else
        {
            for(int i = 0 ; i < s.length() ; i ++)
            {
                //cout << "insert " << s.at(i) << endl;
                charList[s.at(i)].push_back(i);
            }
            for(int i = 0 ; i < s.length() ; i ++)
            {
                auto got = charList.find(s.at(i));
                vector<int> matches = got->second ;
                int matchSize = matches.size() - 1;
               /* if(matchSize == 0)
                {
                    break;
                }*/
                //cout << "matchSize of " << s.at(i) << " = " << matchSize << endl;
                for(int j = matchSize  ; j >= 0 ; j --)
                {
                    if(matches[j] > i )
                    {
                        //cout << "i = " << i << " , matches[j] = " << matches[j] <<endl;
                        if((matches[j]  - i + 1) % 2 != 0 )
                        {
                            int mid = ((matches[j] - i) / 2) + i;
                            forwardIdx = mid +1;
                            backwardIdx = mid - 1;
                            while(forwardIdx  <= matches[j] && backwardIdx >= i)
                            {
                                //cout << "forwardIdx = " << forwardIdx << ", backwardIdx = " << backwardIdx <<endl;
                               // cout << "s.at(forwardIdx) = " << s.at(forwardIdx) <<", s.at(backwardIdx) = " << s.at(backwardIdx) <<endl;
                                if(s.at(backwardIdx) == s.at(forwardIdx) )
                                {
                                    isMatched = true;
                                    forwardIdx ++;
                                    backwardIdx --;
                                    
                                }
                                else
                                {
                                    isMatched = false;
                                    break;
                                }
                            }
                            if(isMatched && output.length() <= (matches[j] - i + 1))
                            {
                                output = s.substr(i,matches[j] - i + 1 );
                                isMatched = false;
                                break;
                            }
                            
                        }
                        else
                        {
                            int mid1 = ((matches[j] - i) / 2) + i;
                            int mid2 = mid1 + 1;
                            forwardIdx = mid2;
                            backwardIdx = mid1;
                            //cout << "forwardIdx2 = " << forwardIdx << ", backwardIdx2 = " << backwardIdx << endl;
                           //cout << "s.at(forwardIdx2) = " << s.at(forwardIdx) <<", s.at(backwardIdx2) = " << s.at(backwardIdx) <<endl;
                             while(forwardIdx  <= matches[j] && backwardIdx >= i)
                            {
                                if(s.at(backwardIdx) == s.at(forwardIdx) )
                                {
                                    isMatched = true;
                                    forwardIdx ++;
                                    backwardIdx --;
                                    
                                }
                                else
                                {
                                    isMatched = false;
                                    break;
                                }
                            }
                            if(isMatched && output.length() <= (matches[j] - i + 1))
                            {
                                output = s.substr(i,matches[j] - i + 1 );
                                isMatched = false;
                                break;
                            }
                        }
                    }
                    else
                        break;
                }
                 
            }
            if(output.length() > 0)
                return output;
            else
            {
                output = s.at(s.length() -1);
                return output;
            }
        }
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
