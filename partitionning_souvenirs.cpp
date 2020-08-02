#include<bits/stdc++.h>
using namespace std;
int dp[602][201][201];
int solve(int p1, int p2, int p3,int i,int n,vector<int> &v)
{
	if(i == n){
		return (p1 == p2 && p2 == p3);
	}
	if(dp[p1][p2][p3] != -1 ) return dp[p1][p2][p3];
	int ans = 0;
	for(int j = i ; j < n ; j++)
	{
		if(p1-v[i] >= 0)
		{
			bool a = solve(p1-v[i],p2+v[i],p3,i+1,n,v);
			bool b = solve(p1-v[i],p2,p3+v[i],i+1,n,v);
			bool c = solve(p1,p2,p3,i+1,n,v);
			if(a || b || c)
			{
				 ans = 1;
			}
		}
	}
	return dp[p1][p2][p3] = ans;
}

int main()
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
	if(sm % 3) cout<<"0";
	else
	{
		cout<<solve(sm,0,0,0,n,v);
	}
}
