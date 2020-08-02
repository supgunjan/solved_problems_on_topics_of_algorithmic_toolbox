//https://leetcode.com/problems/word-break-ii/

class Solution {
public:
    unordered_map<string,vector<string>> dp;
    
    
    vector<string> helper(string s, vector<string> &wordDict)
    {
        vector<string> finalstr,substr;
        if(s.length() == 0)
        {
            return {""};
        }
        if(dp.count(s) != 0) return dp[s];
        
        for(auto i : wordDict)
        {
            int len = i.length();
            string tmp = s.substr(0,len);
           
            
            if(tmp == i)
            {
                substr = helper(s.substr(len),wordDict);
                 // cout<<s<<"----------"<<endl;

                for(auto j : substr)
                {
                    string space = j.length() > 0 ? " " : "";
                    // cout<<tmp<<" "<<j<<endl;
                    finalstr.push_back(tmp+space+j);
                }
                
            }
           
        }
        return dp[s] = finalstr;
    }
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
      
        return helper(s,wordDict);
        
    }
};
