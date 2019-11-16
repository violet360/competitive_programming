#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll n = 100001;

vector<ll>spf(n, 0);


void smallest_prime_f()
{
	spf[1] = 1;
	
	for(ll x=2; x<=n; x+=2)
	{
		spf[x] = 2;
	}
	
	for(ll x=3; x<=n; x+=2)
	{
		if(spf[x] == 0)
		{
			for(ll y = x; y<=n ; y+=x)
			{
				if(spf[y] == 0) spf[y] = x;
			}
		}
	}
}


int main() 
{
	
	smallest_prime_f();
	
	for(ll x=1; x<=100; x++)
	{
		cout<<x<<" "<<spf[x]<<endl;
	}
	return 0;
}