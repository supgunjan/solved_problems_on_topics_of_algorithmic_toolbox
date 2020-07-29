//https://practice.geeksforgeeks.org/problems/subset-with-sum-divisible-by-m/0


#include <bits/stdc++.h>
using namespace std;
 vector<int> v(1000);
 int n,m;
 int dp[1000][10000];
 
bool solve(int i,int sm)
 {
     if(sm%m == 0) return true;
     if(i >= n ) return false;
     if(dp[i][sm] != -1) return dp[i][sm];
     
     return dp[i][sm] = (solve(i+1,sm+v[i]) || solve(i+1,sm));
    
     
 }
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	   memset(dp,-1,sizeof(dp));
	    cin >> n >> m;
	 
	    for(int i = 0 ; i < n ; i++)
	    {
	        cin >> v[i];
	    }
	    if(n == 0) cout<<"0"<<endl;
	    else
	    cout<<solve(0,v[0])<<endl;
	}
	return 0;
}
