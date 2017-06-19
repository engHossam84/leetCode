/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
	static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> concatinatedVector = nums1;
		double median = 0;
		if (nums1.size() == 0 && nums2.size() == 0)
			return median;
		concatinatedVector.insert(concatinatedVector.end(), nums2.begin(), nums2.end());
		sort(concatinatedVector.begin(), concatinatedVector.end());
		if (concatinatedVector.size() % 2 != 0)
		{
			median = concatinatedVector[concatinatedVector.size() / 2];
		}
		else
			median = (concatinatedVector[concatinatedVector.size() / 2] + concatinatedVector[(concatinatedVector.size() / 2) - 1]) / 2.0;

		return median;

	}
};



void main()
{
	vector<int> vec1={ 4, 5, 6, 8, 9 };
	vector<int> vec2 = {  };
	cout << Solution::findMedianSortedArrays(vec1, vec2) << endl;

	vector<int> vec3 = { 1,3 };
	vector<int> vec4 = {2};
	cout << Solution::findMedianSortedArrays(vec3, vec4) << endl;


	vector<int> vec5 = { 1,2 };
	vector<int> vec6 = {3,4};
	cout << Solution::findMedianSortedArrays(vec5, vec6) << endl;

	vector<int> vec7 = {  };
	vector<int> vec8 = {  };
	cout << Solution::findMedianSortedArrays(vec7, vec8) << endl;

	vector<int> vec9 = {2,2};
	vector<int> vec10 = {1};
	cout << Solution::findMedianSortedArrays(vec9, vec10) << endl;
	
}