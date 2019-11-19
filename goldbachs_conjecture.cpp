#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll n = 100001;

bool prime[n];

void sieve_of_eratosthenes()
{
	
	for(ll x=0; x<=n ;x++)
	{
		prime[x] = true;
	}
	
	
	for(ll x=2; x<=n; x+=2)
	{
		prime[x] = false;
	}
	
	for(ll x=3; x<=n; x+=2)
	{
		if(prime[x])
		{
			for(ll y=x*x; y<=n; y+=x)
			{
				prime[y] = false;
			}
		}
	}
}


ll goldbachs_conjecture(ll n)
{
	ll res = 1;
	for(ll x=1; x<=n/2; x++)
	{
		if(prime[x] && prime[n-x])
			res++;
	}
	
	return res;
}

int main() 
{

	sieve_of_eratosthenes();
	
	cout<<goldbachs_conjecture(100)<<endl;
	
	return 0;
}