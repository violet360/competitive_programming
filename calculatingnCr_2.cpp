#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N = 10000001;

ll p = 998244353;

ll factorialNumInverse[N + 1]; 
 
ll naturalNumInverse[N + 1]; 
 
ll fact[N + 1]; 

void InverseofNumber(ll p) 
{ 
	naturalNumInverse[0] = naturalNumInverse[1] = 1; 
	for (ll i = 2; i <= N; i++) 
		naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
} 

void InverseofFactorial(ll p) 
{ 
	factorialNumInverse[0] = factorialNumInverse[1] = 1; 
 
	for (ll i = 2; i <= N; i++) 
		factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
} 

 
void factorial(ll p) 
{ 
	fact[0] = 1; 

	for (int i = 1; i <= N; i++) { 
		fact[i] = (fact[i - 1] * i) % p; 
	} 
} 


ll nCr(ll N, ll R, ll p) 
{ 
		ll ans = ((fact[N] * factorialNumInverse[R]) 
			% p * factorialNumInverse[N - R]) 
			% p; 
		return ans;
} 

void init()
{
	InverseofNumber(p); 
	InverseofFactorial(p); 
	factorial(p);
}


int main() 
{
	init();
	ll t;
	cin>>t;
	while(t--)
	{
		ll n, r;
		cin>>n>>r;
		if(r > n)
		{
			cout<<"noob"<<"\n";
			continue;
		}
		
		else
		{
			cout<<nCr(n, r, p)<<"\n";
		}
	}
	return 0;
}
