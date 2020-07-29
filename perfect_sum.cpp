//https://practice.geeksforgeeks.org/problems/perfect-sum-problem/0

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9+7;
int solve(vector<int> &v,int n,int sm)
{
   int dp[1001][1001];
   memset(dp,0,sizeof(dp));
   for(int i = 0 ; i <= n ; i++)
   {
       dp[i][0] = 1;
   }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= sm ; j++)
        {
            if(j >= v[i])
            {
                   int need = j-v[i];
                  dp[i][j] = (dp[i-1][need] + dp[i-1][j])%inf; 
            }
            else    dp[i][j] = dp[i-1][j];
        
        }
    }
    return dp[n][sm];
}


int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int> v(n+1);
	    for(int i = 1 ; i <= n ; i++) cin >> v[i];
	    int sm;
	    cin >> sm;
	    cout << solve(v,n,sm)<<endl;
	    
	}
	return 0;
}
