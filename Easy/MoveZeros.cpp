/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

#include <vector>
using namespace std;

class Solution {
public:

	void swap(int & a, int & b)
	{
		int tmp = a;
		a = b;
		b = tmp;

	}
	void moveZeroes(vector<int>& nums) {
		if (nums.size() > 1)
		{
			int fast = 1;
			int slow = 0;

			while (fast < nums.size())
			{
				if (nums[slow] == 0)
				{
					if (nums[fast] != 0)
					{
						swap(nums[slow], nums[fast]);
						slow++;
						fast++;
					}
					else
					{
						fast++;
					}
				}
				else
				{
					slow++;
					fast++;
				}
			}
		}

	}
};
