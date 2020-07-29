//https://leetcode.com/problems/climbing-stairs/


class Solution {
public:
  
    
    int helper(int n,vector<int> &v)
    {
        if(n <= 2) return n;
        v[1] = 1;
        v[2] = 2;
        
        if(v[n] != -1) return v[n];
        return v[n] = helper(n-1,v)+helper(n-2,v);
    }
    int climbStairs(int n) {
          vector<int> v(46,-1);
      
     return helper(n,v);        
    }
};
