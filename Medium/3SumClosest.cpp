class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = INT_MAX;
        int total = 0;
        int output = 0;
        int diff = 0;
        for(int i = 0 ; i < nums.size() ; i ++)
        {
            int first  = nums[i];
            int start = i+1;
            int end = nums.size() - 1;
            
            while(start < end)
            {
                total = first + nums[start] + nums[end];
                diff = target - total;
                if(diff == 0 )
                    return total;
                
                else if(total < target )
                {
                    diff = target - total;
                    if(diff < sum)
                    {
                        sum = diff;
                        output = total;
                    }
                    
                    start++;
                }
                
                else if(total > target )
                {
                    diff =  total - target;
                    if(diff < sum)
                    {
                        sum = diff;
                        output = total;
                    }
                    end--;
                }
            }
        }
        return output;
        
    }
};
