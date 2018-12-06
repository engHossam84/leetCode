
#include <ctype.h>
#include <stdio.h>
#include <unordered_map>

class Solution {
public:
    bool isMatch(string s, string p) {

        if (s.length() != 0 && p.length() == 0) {
            return false;
        }
        
        int m = s.length(), n = p.length(); 
        vector<vector<bool> > dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
    
        for (int i = 0; i < p.length(); i++) {
            if (p.at(i) == '*' && dp[0][i-1]) {
                dp[0][i+1] = true;
            }
        }
// i is the text index
//j is the pattern index
        for (int i = 0 ; i < s.length(); i++) {
            for (int j = 0; j < p.length(); j++) {
                if (p.at(j) == '.') {
                    dp[i+1][j+1] = dp[i][j];
                }
                if (p.at(j) == s.at(i)) {
                    dp[i+1][j+1] = dp[i][j];
                }
                if (p.at(j) == '*') {
                    if (p.at(j-1) != s.at(i) && p.at(j-1) != '.') {
                        dp[i+1][j+1] = dp[i+1][j-1];
                    } else {
                        dp[i+1][j+1] = (dp[i+1][j] || dp[i][j+1] || dp[i+1][j-1]);
                    }
                }
            }
        }
    return dp[s.length()][p.length()];
}
    
    
};
