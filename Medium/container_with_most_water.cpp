class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0, l = 0, r = height.size() - 1;
        while(l < r)
        {
            int length = r - l;
            int width = min(height[l], height[r]);
            int newArea = length * width;
            maxarea = max(maxarea, newArea); 
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        
        
        return maxarea;
    }
    
    int maxArea2(vector<int>& height) {
        int len = height.size();
        int area = 0;
        for(int i = 0 ; i < len  ; i ++)
        {
            for(int j = i + 1 ; j < len ; j++)
            {
                int length = j - i;
                int width = min(height[i], height[j]);
                int newArea = length * width;
                area = max(area, newArea);
            }
        }
        return area;
    }
};
