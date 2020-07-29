//https://practice.geeksforgeeks.org/problems/edit-distance/0


#include<bits/stdc++.h>
using namespace std;



int solve(string s1, string s2)
{
	int res[s1.length()+1][s2.length()+1];

	for(int i = 0 ; i <= s1.length() ; i++)
	{
		res[i][0] = i;
	} 
	for(int j = 0 ; j <= s2.length() ; j++)
	{
		res[0][j] = j;
	}

	for(int i = 1 ; i <= s1.length() ; i++)
	{
		for(int j = 1 ; j <= s2.length() ; j++)
		{
			if(s1[i-1] == s2[j-1])
			{
				res[i][j] = min(res[i-1][j]+1,min(res[i][j-1]+1,res[i-1][j-1]));
			}
			else
			{
				res[i][j] = min(res[i-1][j],min(res[i][j-1],res[i-1][j-1]))+1;
			}
		}
	}


	return res[s1.length()][s2.length()];
}

int main()
 {
 	string s1,s2;
// 	cin >> s1 >> s2;
// 	cout<<solve(s1,s2)<<endl;

	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		cin >> s1 >> s2;

	cout<<solve(s1,s2)<<endl;
	}


	return 0;
}
