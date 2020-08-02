#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maxi[15][15];
ll mini[15][15];


pair<ll,ll> min_max(vector<int> &digits,vector<char> &opr,int i, int j)
{
	ll minimum = LLONG_MAX;
	ll maximum = LLONG_MIN;

	ll a,b,c,d;
	for(int k = i ; k <= j-1 ;k++)
	{
		if(opr[k-1] == '+')
		{
			 a = maxi[i][k] + maxi[k+1][j];
			 b = maxi[i][k] + mini[k+1][j];
			 c = mini[i][k] + maxi[k+1][j];
			 d = mini[i][k] + mini[k+1][j];


			minimum = min({a,b,c,d,minimum});
			maximum = max({a,b,c,d,maximum});
		}
		else if(opr[k-1] == '-')
		{
			 a = maxi[i][k] - maxi[k+1][j];
			 b = maxi[i][k] - mini[k+1][j];
			 c = mini[i][k] - maxi[k+1][j];
			 d = mini[i][k] - mini[k+1][j];


			minimum = min({a,b,c,d,minimum});
			maximum = max({a,b,c,d,maximum});
		}
		if(opr[k-1] == '*')
		{
			 a = maxi[i][k] * maxi[k+1][j];
			 b = maxi[i][k] * mini[k+1][j];
			 c = mini[i][k] * maxi[k+1][j];
			 d = mini[i][k] * mini[k+1][j];

			minimum = min({a,b,c,d,minimum});
			maximum = max({a,b,c,d,maximum});
		}

	}
			return make_pair(minimum,maximum);

}


void  parenthesis(vector<int> &digits, vector<char> &opr)
{
	int n = digits.size();
	

	for(int i = 1 ; i <= n ; i++)
	{
		maxi[i][i] = digits[i-1];
		mini[i][i] = digits[i-1];
	}


	for(int s = 1 ; s <= n-1 ; s++)
	{
		for(int i = 1 ; i <= n-s ; i++)
		{
			int j = i+s;
			pair<ll,ll> res = min_max(digits,opr,i,j);
			mini[i][j] = res.first;
			maxi[i][j] = res.second;
		}
	}
	
}

int main()
{
	string s;
	cin >> s;
	vector<int> digits;
	vector<char> opr;
	int n = s.length();
	for(int i = 0 ; i < n ; i += 2)
	{
		digits.push_back(s[i]-'0');
	}
	for(int i = 1 ; i < n ; i += 2)
	{
		opr.push_back(s[i]);
	}
	// for(int i = 0; i < 100; i++){
 //        for(int j = 0; j < 100; j++){
 //            maxi[i][j] = LLONG_MAX;
 //            mini[i][j] = LLONG_MIN;
 //        }
 //    }
	parenthesis(digits,opr);
	
	cout<< maxi[1][digits.size()];
	return 0;
}
