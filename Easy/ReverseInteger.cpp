/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
*/


#include <stack>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
	static int reverse2(int x) {
		stack<int> reverseStack;
		
		int tmpNum = 0;
		int sum = 0, power = 0;
		double tmpSum = 0;
		bool negativeSign = false;
		if (x < 0)
		{
			negativeSign = true;
			tmpNum = x * -1;
		}
		else
		{
			negativeSign = false;
			tmpNum = x ;
		}
		int length = log10(tmpNum) + 1;
		for (int i = 0; i < length; i++)
		{
			int digit = tmpNum / 10;
			int mod = tmpNum % 10;
			reverseStack.push(mod);
			tmpNum = digit;
		}
		while(!reverseStack.empty())
		{
			if (reverseStack.size() > 10)
				return 0;
			else 
			{
				tmpSum += reverseStack.top() * pow(10, power);
				reverseStack.pop();
				power++;
				if (tmpSum > INT32_MAX)
					return 0;
				else
					sum = tmpSum;
			}
			
		}

		if (negativeSign)
			return sum * -1;
		else
			return sum;

	}

	static int reverse(int x) {
		long long r = 0;
		long long t = x;
		t = t > 0 ? t : -t;
			for (; t > 0 ; t /= 10)
				r = r * 10 + t % 10;
		bool sign = x > 0 ? false : true;
		if (r > 2147483647 || (sign && r > 2147483648)) {
			return 0;
		}
		else {
			if (sign) {
				return -r;
			}
			else {
				return r;
			}
		}
	}

};

void main()
{
	cout << "MAX_INT = " << INT32_MAX << endl;
	cout << Solution::reverse(1234) << endl;
	cout << Solution::reverse(10000000) << endl;
	cout << Solution::reverse(-1) << endl;
	cout << Solution::reverse(-01) << endl;
	cout << Solution::reverse(-10) << endl;
	cout << Solution::reverse(-12) << endl;
	cout << Solution::reverse(-102) << endl;
	cout << Solution::reverse(-123) << endl;
	cout << Solution::reverse(-1234) << endl;
	cout << Solution::reverse(-12345) << endl;
	cout << Solution::reverse(-123456) << endl;
	cout << Solution::reverse(-1234567) << endl;
	cout << Solution::reverse(-12345678) << endl;
	cout << Solution::reverse(-123456789) << endl;
	cout << Solution::reverse(-1534236469) << endl;
	cout << Solution::reverse(1) << endl;
	cout << Solution::reverse(01) << endl;
	cout << Solution::reverse(10) << endl;
	cout << Solution::reverse(12) << endl;
	cout << Solution::reverse(102) << endl;
	cout << Solution::reverse(123) << endl;
	cout << Solution::reverse(1234) << endl;
	cout << Solution::reverse(12345) << endl;
	cout << Solution::reverse(123456) << endl;
	cout << Solution::reverse(1234567) << endl;
	cout << Solution::reverse(12345678) << endl;
	cout << Solution::reverse(123456789) << endl;
	cout << Solution::reverse(1534236469) << endl;
	cout << Solution::reverse(2147483647) << endl;

}