/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


/*
Solution using set
*/

#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>


using namespace std;

class Solution {
public:
	
	static int lengthOfLongestSubstring(string s) {
		string tmpStr = "",singleChar = "";
		int index = 0;
		int longestSubstring = 0;
		for (int i = 0; i < s.length(); i++)
		{
			auto got = tmpStr.find(s.at(i));
			if (got == string::npos)
			{
				singleChar = s.at(i);
				tmpStr.insert(index, singleChar);
				index++;
			}
			else
			{	
				longestSubstring = max((int)tmpStr.size(), longestSubstring);
				tmpStr.erase(0, got+1);
				index = tmpStr.size();
				singleChar = s.at(i);
				tmpStr.insert(index, singleChar);
				index++;
			}
		}
		return max((int)tmpStr.size(), longestSubstring);
	}

	static int lengthOfLongestSubstring3(string s) {  //model answer, execution = 16 ms
		const int ASCII_MAX = 255;
		int last[ASCII_MAX]; 
		int start = 0; 
		fill(last, last + ASCII_MAX, -1); 
		int max_len = 0;
		for (int i = 0; i < s.size(); i++) {
			if (last[s[i]] >= start) {
				max_len = max(i - start, max_len);
				start = last[s[i]] + 1;
			}
			last[s[i]] = i;
		}
			return max((int)s.size() - start, max_len); 
	}
	
	//new answer by me, execution = 20ms
	 int lengthOfLongestSubstring(string s) {
        queue<char> charQueue;
        int count = 0;
        int maxCount = 0;
        int charSet[128] = {0};
        
        if(s.length() > 1)
        {
        for(int i = 0 ; i < s.length() ; i ++)
        {
            if(charQueue.empty())
            {
               charQueue.push(s.at(i)) ;
               count++;
               charSet[s.at(i)]++;
            }
            else
            {
                if(charSet[s.at(i)] == 0)
                {
                    //cout << "Insert1 " << s.at(i) << endl;
                    charQueue.push(s.at(i)) ;
                    count++;
                    charSet[s.at(i)]++;
                    if(count > maxCount)
                        maxCount = count;
                }
                else
                {
                    char tmp = charQueue.front();
                    //cout << "tmp = " << tmp <<endl;
                    if(count > maxCount)
                        maxCount = count;
                    while(tmp != s.at(i))
                    {    
                        charQueue.pop();
                        charSet[tmp]--;
                        count--;
                        tmp = charQueue.front();
                    }
                    charQueue.pop();
                    //cout << "Insert2 " << s.at(i) << endl;
                    //cout << "count = " << count <<endl;
                    charQueue.push(s.at(i)) ;
                }
            }
        }
        }
        else
           maxCount = s.length(); 
        return maxCount;
    }

};

void main()
{
	cout << Solution::lengthOfLongestSubstring3("bpfbhmipx") << endl;
	cout << Solution::lengthOfLongestSubstring3("dvdf") << endl;
	cout << Solution::lengthOfLongestSubstring3("pwwkew") << endl;
	
	cout << Solution::lengthOfLongestSubstring3("au") << endl;
	cout << Solution::lengthOfLongestSubstring3("c") << endl;
	cout << Solution::lengthOfLongestSubstring3("abcabcbb") << endl;
	cout << Solution::lengthOfLongestSubstring3("bbbbb") << endl;
	cout << Solution::lengthOfLongestSubstring3("") << endl;

}
