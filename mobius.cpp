#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll n = 100001;

vector<ll>spf(n, 0);
vector<ll>mobius(n, 0);


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


void mobius_func()
{
  
    for (ll i = 1; i < n; i++) { 
  
        // If number is one 
        if (i == 1) 
            mobius[i] = 1; 
        else { 
  
            // If number has a squared prime factor 
            if (spf[i / spf[i]] == spf[i]) 
                mobius[i] = 0; 
  
            // Multiply -1 with the previous number 
            else
                mobius[i] = -1 * mobius[i / spf[i]]; 
        } 
    } 
}


int main() 
{
	
	smallest_prime_f();
	mobius_func();
	
	for(ll x=1; x<=100; x++)
	{
		cout<<x<<" "<<spf[x]<<" "<<mobius[x]<<endl;
	}
	return 0;
}