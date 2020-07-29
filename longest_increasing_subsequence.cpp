//https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for( int i = 0 ; i < nums.size() ; i++)
        {
            auto x = lower_bound(v.begin() , v.end() , nums[i]);
            if( x != v.end())
            {
                int pos = x - v.begin();
                v[pos] = nums[i];
            }
            else
            {
                v.push_back(nums[i]);
            }
        }
        
        return v.size();
    }
};
