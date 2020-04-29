#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
# define FAST_CODE ios_base::sync_with_stdio(false); cin.tie(NULL);
# define pb push_back
# define f(a, b, jump) for(ll i=a; i<=b; i+=jump)
using namespace std;
constexpr ll n = 4e6;

ll tree[n+1];

void build(ll a[], ll node, ll L, ll R)
{
	if (L == R)
	{
		tree[node] = a[L];
	}
	else
	{
		ll M = (L + R)/2;
		build(a, node*2, L, M);
		build(a, node*2+1, M+1, R);
		tree[node] = tree[node*2] + tree[node*2+1];
	}
}

ll query(ll node, ll L, ll R, ll l, ll r)
{
    if (l > r) 
        return 0;
        
    if (l == L && r == R) 
    {
        return tree[node];
    }
    ll M = (L + R) / 2;
    return query(node*2, L, M, l, min(r, M)) + query(node*2+1, M+1, R, max(l, M+1), r);
}

void update(ll node, ll L, ll R, ll pos, ll new_val) 
{
    if (L == R) 
    {
        tree[node] = new_val;
    }
    else 
    {
        ll M = (L + R) / 2;
        if (pos <= M)
            update(node*2, L, M, pos, new_val);
        else
            update(node*2+1, M+1, R, pos, new_val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

int main() 
{
	FAST_CODE;
	// ld a = 7;
	// ld b = 3;
	// ld x = b/a;
	// cout << setprecision(6)<< fixed<<ld(x);
	ll n;
	cin>>n;
	ll a[n];
	f(0, (n-1), 1) cin>>a[i];
	
	build(a, 1, 0, 6);
	cout<<query(1, 0, n-1, 1, 3)<<endl;
	update(1, 0, n-1, 2, 10);
	cout<<query(1, 0, n-1, 1, 3);
	return 0;
}
