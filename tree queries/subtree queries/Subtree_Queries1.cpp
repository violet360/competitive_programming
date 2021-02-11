/*
https://www.hackerearth.com/problem/algorithm/subtree-queries/
in this the flat[] has been made using inorder traversal
*/ 

#include <bits/stdc++.h>
typedef long long ll;
# define FAST_CODE ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
constexpr ll N = 1e6+1;

vector<ll>adj[N];
bool used[N];
ll parent[N];
 ll c = 1, in[N+1], out[N+1];
 ll flat[2*N+2];
 
 ll gcd(ll a,ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b); 
}
 
void dfs(ll src, ll val[])
{
	used[src] = true;
	in[src] = c;
	flat[c] = val[src];
	c++;
	for(ll children:adj[src])
	{
		if(!used[children])
		{
			// cout<<children<<endl;
			parent[children] = src;
			dfs(children, val);
		}
	}
	out[src] = c-1;
}

// segment tree

// ll tree[(4*n)+1];

void build(ll tree[], ll a[], ll node, ll L, ll R)
{
	if (L == R)
	{
		// cout<<node<<"----"<<a[L]<<endl;
		tree[node] = a[L];
	}
	else
	{
		ll M = (L + R)/2;
		build(tree, a, node*2, L, M);
		build(tree, a, node*2+1, M+1, R);
		tree[node] = gcd(tree[node*2] , tree[node*2+1]);
	}
}

ll query(ll tree[], ll node, ll L, ll R, ll l, ll r)
{
    if (l > r) 
        return 0;
        
    if (l == L && r == R) 
    {
    	// cout<<"----"<<tree[node<<endl;
        return tree[node];
    }
    ll M = (L + R) / 2;
    return gcd(query(tree, node*2, L, M, l, min(r, M)) , query(tree, node*2+1, M+1, R, max(l, M+1), r));
}

void update(ll tree[], ll node, ll L, ll R, ll pos, ll new_val) 
{
    if (L == R) 
    {
    	// cout<<tree[node]<<"--"<<node<<endl;
    	// cout<<tree[node]<<"---";
        tree[node] = new_val;
        flat[pos] = new_val;
        
    }
    else 
    {
        ll M = (L + R) / 2;
        if (pos <= M)
            update(tree, node*2, L, M, pos, new_val);
        else
            update(tree, (node*2)+1, M+1, R, pos, new_val);
            
        tree[node] = gcd(tree[node*2] , tree[node*2+1]);
    }
}

// segment tree
 
int main() 
{
	FAST_CODE
	ll n, a, b, q;
	cin>>n>>q;
	ll val[n+1] = {0};
	for(ll o=1; o<=n; o++)
	{
		cin>>val[o];
	}
	
	ll n1 = n;
	n--;
	
	ll idx[n1+1] = {0};
	
	while(n--)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	
	parent[1] = -1;
	dfs(1, val);
	ll tree[4*n1 + 1];
	build(tree, flat, 1, 1, n1);
	
	while(q--)
	{
		ll type;
		cin>>type;
		if(type == 1)
		{
			ll i, X;
			cin>>i>>X;
			update(tree, 1, 1, n1, in[i], X);
		}
	
		else
		{
			ll i;
			cin>>i;
			cout<<query(tree, 1, 1, n1, in[i], out[i])<<endl;
		}
		
	}
	return 0;
}
