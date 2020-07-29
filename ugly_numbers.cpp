//https://practice.geeksforgeeks.org/problems/ugly-numbers/0

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n)
{
   ll dp[n+1];
   dp[1] = 1;
   int i2 = 1;
   int i3 = 1;
   int i5 = 1;
   
   for(int i = 2 ; i <= n ; i++)
   {
       ll next_2 = 2*dp[i2];
       ll next_3 = 3*dp[i3];
       ll next_5 = 5*dp[i5];
       
       ll nxt_ugly = min(next_2,min(next_3,next_5));
       dp[i] = nxt_ugly;
       if(nxt_ugly == next_2)   i2++;
       if(nxt_ugly == next_3)   i3++;
       if(nxt_ugly == next_5)   i5++;
   }
   return dp[n];
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    cout << solve(n)<<endl;
	}
	return 0;
	
}
