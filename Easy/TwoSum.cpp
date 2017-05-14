/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <vector>
#include <iostream>
#include <map>
using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) { 
		vector<int> result;
		if(nums.size() > 1)
		{
			for(int i = 0 ; i < nums.size()-1 ; i ++)
			{
					for(int j = i+1 ; j < nums.size() ; j ++)
					{
						if(nums[i] + nums [j] == target)
						{
							result.push_back(i);
							result.push_back(j);
						}
					}
				if(!result.empty())
					break;
			}
		}
		return result; 
	}

	vector<int> twoSum2(vector<int>& nums, int target) { 
		map<int, int> myMap;
		vector<int> result;
		int complement;
		for(int i = 0 ; i < nums.size() ; i ++)
		{
			complement = target - nums[i];
			auto it = myMap.find(complement);
			if (it != myMap.end())
			{
				result.push_back(i);
				result.push_back(it->second);
				break;
			}
			else
			{
				myMap.insert(std::pair<int,int>(nums[i], i));
			}
		}
		return result;

	}
};


void main()
{
	vector<int> input;
	input.push_back(9);
	input.push_back(-1);
	input.push_back(3);
	input.push_back(-7);
	input.push_back(10);
	input.push_back(11);
	input.push_back(15);

	for(int i = 0 ; i < input.size() ; i ++)
		cout << input[i] <<endl;


	cout <<endl << endl;
	Solution s;
	vector<int> output = s.twoSum(input,-8);

	for(int i = 0 ; i < output.size() ; i ++)
		cout << output[i] <<endl;


	cout <<"twoSum 2"  << endl << endl;
	vector<int> output2 = s.twoSum(input,-8);

	for(int i = 0 ; i < output2.size() ; i ++)
		cout << output2[i] <<endl;

}