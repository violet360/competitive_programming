#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
	ll n, t, r;
	cin>>t>>n;
	ll dp[n+1][n+1];
	for(ll c=0; c<=n; c++)
	{
		dp[0][c] = 1;
	}
	
	for(ll c=1; c<=n; c++)
	{
		for(ll r=c; r<=n; r++)
		{
			dp[r][c-1] = 0;
		}
	}
	
	ll cnt[n+1];

	for(ll i=1; i<=n; i++)
	{
		cin>>cnt[i];
	}
	
	for(ll r=1; r<=n; r++)
	{
		for(ll c=r; c<=n; c++)
		{
			dp[r][c] = dp[r][c-1] + dp[r-1][c-1]*cnt[c];
		}
	}
	
	while(t--)
	{
		
		cin>>r;
		cout<<dp[r][n]<<endl;
		
	}
	return 0;
}