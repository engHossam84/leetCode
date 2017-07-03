/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	static string convert(string s, int numRows) {
		string result = "";
		int count = 0, step1, step2;
		if (numRows == 1)
		{
			return s;
		}

				
		for (int i = 0; i < numRows; i++)
		{
			step1 = (2 * numRows )- (2 *(i+1));
			step2 = 2 * i;
			if (i == 0 || i == numRows - 1)
			{
				count = i;
				while (count < s.size())
				{
					result.push_back(s.at(count));
					count = count + (2 * numRows) - 2;
				}
			}
			else 
			{
				count = i;
				while (count < s.size())
				{
					result.push_back(s.at(count));
					count = count + step1;
					if (count < s.size())
					{
						result.push_back(s.at(count));
						count = count + step2;
					}
				}
				
			}
		}

		return result;
	}

	string convert2(string s, int nRows) {
			if (nRows <= 1 || s.size() <= 1) return s;
			string result;
			for (int i = 0; i < nRows; i++) {
				for (int j = 0, index = i; index < s.size();
					j++, index = (2 * nRows - 2) * j + i) {
					result.append(1, s[index]); 
					if (i == 0 || i == nRows - 1) continue; 
					if (index + (nRows - i - 1) * 2 < s.size())
						result.append(1, s[index + (nRows - i - 1) * 2]);
				}
			}
			return result;
		}
	}
};


void main()
{
	cout << Solution::convert("A", 1) << endl;
	cout << Solution::convert("AbA", 2) << endl;
	cout << Solution::convert("PAYPALISHIRING", 3) << endl;
}