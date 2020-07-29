//https://leetcode.com/problems/minimum-falling-path-sum/


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        
        int dp[n][m];
        
        for(int i = 0 ; i < m ; i++)
        {
            dp[n-1][i] = A[n-1][i];
        }
        for(int i = n-2 ; i >= 0 ; i--)
        {
            for(int j = 0 ; j < m ; j++)
            {
                dp[i][j] = A[i][j];
                
                int mn = dp[i+1][j];
                if( j-1 >= 0  && mn > dp[i+1][j-1] ) mn = dp[i+1][j-1];
                if( j+1 < m && mn > dp[i+1][j+1])   mn = dp[i+1][j+1];
                
                dp[i][j] += mn;
            }
        }
        
        int mn = INT_MAX;
        for(int i = 0 ; i < m ; i++)
        {
            mn = min(mn,dp[0][i]);
        }
        return mn;
        
    }
};
