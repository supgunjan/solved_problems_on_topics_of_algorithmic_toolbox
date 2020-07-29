//https://practice.geeksforgeeks.org/problems/subset-sum-problem/0

#include <bits/stdc++.h>
using namespace std;
int dp[100001][101];
bool solve(vector<int> &v, int n,int sm,int i)
{
    dp[0][i] = true;
    if(i >= n) return false;
    
    if(dp[sm][i] != -1) return dp[sm][i];
    
    if(v[i] <= sm)
    {
        return dp[sm][i] = (solve(v,n,sm-v[i],i+1) || solve(v,n,sm,i+1));
    }
    else return dp[sm][i] = false;
    
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
	    vector<int> v(n);
	    int sm = 0;
	    for(int i = 0 ; i < n ; i++) 
	    {
	        cin >> v[i];
	        sm += v[i];
	    }
	    if(sm%2) cout <<"NO"<<endl;
	    else if(solve(v,n,sm/2,0)) cout <<"YES"<<endl;
	    else cout << "NO"<<endl;
	}
	return 0;
}
