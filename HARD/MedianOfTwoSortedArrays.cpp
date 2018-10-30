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
    
    // Function to find max 
    int maximum(int a, int b)  
    { 
        return a > b ? a : b; 
    } 

    // Function to find minimum 
    int minimum(int a, int b)  
    { 
        if(a != NULL && b != NULL)
            return a < b ? a : b;  
        else if(a == NULL)
            return b;
        else if(b == NULL)
            return a;
    } 
    
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n,m;
        vector<int> smallVec;
        vector<int> bigVec;
        if(a.size() <= b.size())
        {
            smallVec = a;
            bigVec = b;  
        }
        else
        {
            smallVec = b;
            bigVec = a;
        }
        n = smallVec.size();
        m = bigVec.size();
        int min_index = 0, max_index = n, i, j, median; 
        
        if(n != 0 && m !=0)
        {
      
            while (min_index <= max_index) 
            { 
                i = (min_index + max_index) / 2; 
                j = ((n + m + 1) / 2) - i; 

                cout << "i = " << i << " , j = " << j << endl;
                //cout << "n = " << n << " , m = " << m << endl;
                // if i = n, it means that Elements from a[] in 
                // the second half is an empty set. and if j = 0, 
                // it means that Elements from b[] in the first 
                // half is an empty set. so it is necessary to 
                // check that, because we compare elements from 
                // these two groups.  
                // Searching on right 
                if (i < n && j > 0 && bigVec[j - 1] > smallVec[i])   
                {
                    cout << "Enter IF" << endl;
                    min_index = i + 1; 
                }
                // if i = 0, it means that Elements from a[] in 
                // the first half is an empty set and if j = m, 
                // it means that Elements from b[] in the second 
                // half is an empty set. so it is necessary to 
                // check that, because we compare elements  
                // from these two groups. 
                // searching on left 
                else if (i > 0 && j < m && bigVec[j] < smallVec[i - 1])   
                {
                    cout << "Enter ELSE IF" << endl;
                    max_index = i - 1; 
                }
                // we have found the desired halves. 
                else
                { 
                    cout << "Enter ELSE" << endl;
                    
                    // this condition happens when we don't have any 
                    // elements in the first half from a[] so we 
                    // returning the last element in b[] from  
                    // the first half. 
                    
                    if (i == 0)             
                        median = bigVec[j - 1];             

                    // and this condition happens when we don't 
                    // have any elements in the first half from 
                    // b[] so we returning the last element in  
                    // a[] from the first half. 
                    else if (j == 0)             
                        median = smallVec[i - 1];             
     /*               else if ((smallVec.size()+ bigVec.size()) % 2 == 0)  
                    { 
                        cout << "max = " <<maximum(smallVec[i - 1], bigVec[j - 1]) <<" / "<< smallVec[i - 1] << ", " << bigVec[j - 1]<< endl;
                        cout << "min = " <<minimum(smallVec[i], bigVec[j]) << endl;
                        median = (maximum(smallVec[i - 1], bigVec[j - 1]) + minimum(smallVec[i], bigVec[j])); 
                    }*/
                    else
                        median = maximum(smallVec[i - 1], bigVec[j - 1]); 
                    break; 
                } 
            } 

            // calculating the median. 
            // If number of elements is odd there is  
            // one middle element. 
            if ((n + m) % 2 == 1) 
                return (double)median; 

            // Elements from a[] in the second half is an empty set.     
            if (i == n) 
                return (median+bigVec[j]) / 2.0; 

            // Elements from b[] in the second half is an empty set. 
            if (j == m) 
                return (median + smallVec[i]) / 2.0; 

            return (median + minimum(smallVec[i], bigVec[j])) / 2.0; 
        }
        else
        {
            if(a.size() == 0 && b.size() != 0)
            {
                if(b.size() % 2 == 0)
                    return (double)(b[b.size()/2]+b[b.size()/2 - 1]) /2 ;
                else
                    return b[b.size()/2];
            }
            else if (b.size() == 0 && a.size() != 0)
            {
                if(a.size() % 2 == 0)
                    return (double)(a[a.size()/2]+a[a.size()/2 - 1]) /2 ;
                else
                    return a[a.size()/2];
            }
            else return 0;
        }
    }
};

class Solution2 {
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
