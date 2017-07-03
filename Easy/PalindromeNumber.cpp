/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

#include <iostream>
using namespace std;

class Solution {
public:
	static bool isPalindrome(int x) {
		int tmp;
		long long mirror = 0;
		if (x < 0)
			return false;
		else
			tmp = x;

		for (; tmp > 0; tmp /= 10)
		{
			mirror = mirror * 10 + tmp % 10;
			if (mirror > INT32_MAX)
				return false;
		}

		if ( x == mirror)
			return true;
		else
			return false;
		 
	}
};


void main()
{
	cout << Solution::isPalindrome(1234) << endl;
	cout << Solution::isPalindrome(1) << endl;
	cout << Solution::isPalindrome(11) << endl;
	cout << Solution::isPalindrome(121) << endl;
	cout << Solution::isPalindrome(1212) << endl;
	cout << Solution::isPalindrome(1234) << endl;
	cout << Solution::isPalindrome(-121) << endl;
	cout << Solution::isPalindrome(0) << endl;
	cout << Solution::isPalindrome(123456789) << endl;


}