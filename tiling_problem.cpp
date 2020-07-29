
//https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor/0


#include <bits/stdc++.h>
using namespace std;
long long  dp[71];
long long solve(int n)
{
    dp[1] = 1;
    dp[2] = 2;
    if(dp[n] != -1) return dp[n];
    
    
    return dp[n] = solve(n-1)+solve(n-2);
}
int main() {
	//code
	int t;
    memset(dp,-1,sizeof(dp));

	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    cout<<solve(n)<<endl;
	}
	return 0;
}
