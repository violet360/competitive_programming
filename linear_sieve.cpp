#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll n = 100001;

vector <ll> Prime;

bool is_composite[n];

void linear_sieve ()
{
	std::fill (is_composite, is_composite + n, false);
	for (ll i = 2; i < n; ++i) 
	{
		if (!is_composite[i]) Prime.push_back (i);
		for (ll j = 0; j < Prime.size () && i * Prime[j] < n; ++j) 
		{
			is_composite[i * Prime[j]] = true;
			if (i % Prime[j] == 0) break;
		}
	}
}

int main() 
{

	linear_sieve();
	
	for(ll x=0; x<=100; x++)
	{
		cout<<Prime[x]<<endl;
	}
	
	return 0;
}