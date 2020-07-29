//https://practice.geeksforgeeks.org/problems/ncr/0

#include <iostream>
using namespace std;
int mod = 1e9+7;

int solve(int n,int r)
{
    int dp[1001][801];
    dp[0][0] = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= n ; j++)
        {
            if(j == 0 || j == i)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = (dp[i-1][j-1]%mod+dp[i-1][j]%mod)%mod;;
            }
        }
    }
    return dp[n][r];
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n,r;
	    cin >> n>>r;
	    cout<<solve(n,r)<<endl;
	}
	return 0;
}
