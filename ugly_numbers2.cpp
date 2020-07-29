//https://leetcode.com/problems/ugly-number-ii/


class Solution {
public:
    int nthUglyNumber(int n) {
    int ugly[n];
    int i1 = 0;
    int i2 = 0;
    int i3 = 0;
    int next2 = 2;
    int next3 = 3;
    int next5 = 5;
    int next = 1;
        ugly[0] = next;
    for(int i = 1; i < n ; i++)
    {
        next = min(next2,min(next3,next5));
        ugly[i] = next;
        
        if(next2 == next)
        {
            i1++;
            next2 = ugly[i1]*2;
        }
        if(next3 == next)
        {
            i2++;
            next3 = ugly[i2]*3;
        }
        if(next5 == next)
        {
            i3++;
            next5 = ugly[i3]*5;
        }
    }
        return next;
        
    }
};
