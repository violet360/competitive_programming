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


int main() 
{
	
	sieve_of_eratosthenes();
	
	for(ll x=1; x<=100; x++)
	{
		cout<<x<<" "<<spf[x]<<" "<<mobius[x]<<" "<<phi[x]<<" "<<prime[x]<<endl;
	}
	
	
	return 0;
}