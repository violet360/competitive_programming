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
	/*if n = p1^k1 * p2^k2 * p3^k3 * ..... * pn^kn
phi[n] = n *((p1-1)/p1)*((p2-1)/p2)*((p3-1)/p3)* ... *((pn-1)/pn)
so when u see a prime just travel to it's multiples and change it accordingly , 
let us say ' i ' is a multiple of ' p ' so when reach ' i ' via ' p ' then i * (p-1)/p ....and repeat this process for every prime divisor of i
i * ((p-1)/p)*((p1 - 1)/p1)*((p2 - 1)/p2)*....*((ps - 1)/ps)
*/
	
	
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
