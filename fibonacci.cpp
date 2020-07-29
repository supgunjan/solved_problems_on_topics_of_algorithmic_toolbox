//https://practice.geeksforgeeks.org/problems/nth-fibonacci-number/0

#include <bits/stdc++.h>
using namespace std;
int dp[1002];
const int k = 1e9+7;
int solve(int n)
{
    dp[1] = 1;
    dp[2] = 1;
    if(dp[n] != -1) return dp[n]%k;
    
    
    return dp[n] = (solve(n-1)%k+solve(n-2)%k)%k;
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    memset(dp,-1,sizeof(dp));
	    int n;
	    cin >> n;
	    cout <<solve(n)<<endl;
	}
	return 0;
}
