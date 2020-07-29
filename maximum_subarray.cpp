//https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int local = 0;
        int best = 0;
        for( int i = 0 ; i < nums.size() ; i++ )
        {
         local = max(nums[i],local+nums[i]);
            best = max(local,best);
        }
        
        return best == 0 ? *max_element(nums.begin(),nums.end()) : best;
        
    }
};
