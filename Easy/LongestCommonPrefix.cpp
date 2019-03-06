#include <unordered_map>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string output = "";
        if(strs.size() == 0)
            return output;
        else if(strs.size() == 1)
        {
            return strs[0];
        }
        
        unordered_map<int,char> strChars;
        string str1 = strs[0];
        int minLength = 0 ;
        int length = str1.length();
        
        if(length == 0)
            return output;
       // cout << "str1  = " << str1 << endl;
        for(int  i = 0 ; i < str1.length() ; i ++)
        {
            strChars[i] = str1[i];
        }
        
        
        for(int j = 1 ; j < strs.size() ; j ++)
        {
            //cout << "j = " << j << endl;
            string temp = strs[j];
            //cout << "temp = " << temp << endl;
            for(int k = 0 ; k < temp.length() ; k++)
            {
                char c = strChars[k];
                if(c == temp[k])
                {
                    minLength++;
                }
                else
                    break;
            }
         // cout << "minLength " << minLength << endl;
            if(minLength < length)
            {
                length = minLength;
                minLength = 0;
            }
            else
                minLength = 0;
        }
                
        for(int i = 0 ; i < length ; i ++)
        {
            output += strChars[i];
        }
        return output;
        
    }
};
