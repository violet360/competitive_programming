#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
# define FAST_CODE ios_base::sync_with_stdio(false); cin.tie(NULL);
# define pb push_back
using namespace std;

void totient(vector<ll>&phi, ll n)
{
	for(ll i=0; i<=n; ++i)
	{
		phi[i] = i;
	}
	/*
	
	
	for(ll i=2; i<=n; i++)
	{
		if(phi[i] == i)
		{
			for(ll j=i; j<=n; j+=i)
			{
				phi[j] = phi[j]/i;
				phi[j] *= (i-1);
			}
		}
	}
}


int main() 
{
	FAST_CODE;
	ll n = 1000002;
	vector<ll>phi(n+1);
	
	totient(phi, n);
	
	cout<<phi[7]<<"\n";
	
	return 0;
}
