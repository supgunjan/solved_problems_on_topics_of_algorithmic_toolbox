//https://leetcode.com/problems/longest-palindromic-substring/



class Solution {
public:
    string longestPalindrome(string s) {

    int n = s.length();
 
     string res = ""; 
    if(n == 0)  return res;
    bool dp[n][n];
    for( int i = s.length()-1 ; i>= 0 ; i-- )
    {
        for( int j = i ; j < s.length() ; j++ )

        {
            if(j-i < 3) dp[i][j] = s[i] == s[j];
            
            else dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
            
            if(dp[i][j] && j-i+1 > res.length())    res = s.substr(i,j-i+1);
        }
        
    }
        return res;
        
    }
};
