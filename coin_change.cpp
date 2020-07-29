//https://practice.geeksforgeeks.org/problems/coin-change/0




#include<bits/stdc++.h> 

using namespace std; 

int count( int S[], int m, int n ) 
{ 
	 
	if (n == 0) 
		return 1; 

	if (n < 0) 
		return 0; 

	if (m <=0 && n >= 1) 
		return 0; 

	return count( S, m - 1, n ) + count( S, m, n-S[m-1] ); 
} 

 

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int m;
	    cin >> m;
	    int s[m];
	    for(int i = 0 ; i < m ; i++) cin >> s[i];
	    int n;
	    cin >> n;
	    cout << count(s,m,n)<<endl;
	}
	return 0;
}
