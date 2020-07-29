//https://leetcode.com/problems/longest-palindromic-subsequence/


class Solution {
public:
    int dp[1010][1010];
    string s1;
    
    int solve(int i,int j)
    {
        
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s1[j]) return dp[i][j] = 2+solve(i+1,j-1);
        
        return dp[i][j] = max(solve(i+1,j),solve(i,j-1));
        
    }
    int longestPalindromeSubseq(string s) {
        s1 = s;
        memset(dp,-1,sizeof(dp));
        return solve(0,s1.length()-1);
        
    }
};
