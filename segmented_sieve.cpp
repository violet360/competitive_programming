#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll n = 1000001;

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

void segmented_sieve(ll l, ll r)
{
	ll fa;
	bool is_prime[r-l+1];
	std::fill (is_prime, is_prime + (r-l)+1, true);
	
	// // cout<<l<<" "<<r<<endl;
	for(ll p:Prime)
	{
		if(p*p>r) break;
		
		
		fa = (l/p)*p;
		
		if(fa<l)
			fa+=p;
			
			
		for(ll x=fa; x<=r; x+=p)
		{
			is_prime[x-l] = false;
			// cout<<x<<endl;
		}
		
		if(fa == p)
			is_prime[fa-l] = true;
	}

		
	for(ll idx =0; idx<r-l+1; idx++)
	{
		if(is_prime[idx]) cout<<idx+l<<endl;
	}
}


int main() 
{

	linear_sieve();
	
	ll t, l, r;
	cin>>t;
	
	while(t--)
	{
		cin>>l>>r;
		segmented_sieve(l, r); // prints all primes between l and r (inclusive of l and r)
	}
	
	return 0;
}