//https://practice.geeksforgeeks.org/problems/gold-mine-problem/0

#include <bits/stdc++.h>
using namespace std;
int solve(int a[][20],int n,int m)
{
    int dp[n][m];
    memset(dp,0,sizeof(dp));
    for(int j= m-1; j >= 0 ; j--)
    {
        for(int i = 0 ; i < n ; i++)
        {
            int right = (j == m-1) ? 0 : dp[i][j+1];
            int right_up = (j == m-1  || i == 0) ? 0 : dp[i-1][j+1];
            int right_d = (j == m-1 || i == n-1) ? 0 : dp[i+1][j+1];
            
            dp[i][j] = a[i][j] + max(right,max(right_up,right_d));
        }
    }

    int mx = -1;
    for(int i = 0 ; i < n ; i++)
    {
        mx = max(mx,dp[i][0]);
    }
    return mx;
    
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n,m;
	    cin >> n >> m;
	    int a[20][20];
	    for(int i = 0 ; i < n ; i++)
	    {
	        for(int j = 0 ; j < m ; j++)
	        {
	            cin >> a[i][j];
	        }
	    }
	    cout << solve(a,n,m)<<endl;
	}
	return 0;
}
