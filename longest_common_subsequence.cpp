//https://leetcode.com/problems/longest-common-subsequence/


class Solution {
public:
    int dp[1010][1010];
    int longestCommonSubsequence(string a, string b) {
        memset(dp,0,sizeof(dp));
        int l1 = 1,l2 = 1;
        
        for( l1 = 1 ; l1 <= a.length() ; l1++)
        {
            for( l2 = 1; l2 <= b.length() ; l2++ )
            {
             
                if(a[l1-1] == b[l2-1])  dp[l1][l2] = 1+dp[l1-1][l2-1];
                else
                {
                    dp[l1][l2] = max(dp[l1-1][l2] , dp[l1][l2-1]);
                }
            }
        }
        return dp[a.length()][b.length()];
      
         
        
       
        
    }
};
