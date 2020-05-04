#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define M 32
vector<ll>adj[1000];
bitset<M>used;
ll parent[1000];
ll c = 1;
//  warning this is not a rule of thumb often you have to make necessary changes
// to get get proper flat[] in[] and out[] arrays inoccordance to the question
// generally if subtree queries flat[] has inorder dfs route and if path queries flat[] has eulerian route and that too
// has 2-3 variants depending on your needs so use it wisely :)
void dfs(ll src, ll in[], ll out[], ll flat[])
{
	used[src] = true;
	in[src] = c;
	flat[c] = src;
	c++;
	for(ll children:adj[src])
	{
		if(!used[children])
		{
			cout<<children<<endl;
			parent[children] = src;
			dfs(children, in, out, flat);
		}
	}
	out[src] = c;
	flat[c] = src;
	c++;
}
 
int main() 
{
	ll n, a, b;
	cin>>n;
	ll n1 = n;
	ll in[n] = {0};
	ll out[n] = {0};
	ll flat[2*n + 1] = {0};
	n--;
	while(n--)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	parent[1] = -1;
	dfs(1, in, out, flat);
 
	cout<<"***************"<<endl;
	ll node;
	cin>>node;
	for(ll v = node; v!=-1; v = parent[v])
	{
		cout<<v<<" ";
	}
	cout<<"***************"<<endl;
	
	for(ll i=1; i<=n1; i++)
	{
		cout<<in[i]<<" ";
	}
	
	cout<<"*****************"<<endl;
	
	for(ll i=1; i<=n1; i++)
	{
		cout<<out[i]<<" ";
	}
	cout<<"*****************"<<endl;
	
	for(ll i=1; i<=2*n1; i++)
	{
		cout<<flat[i]<<" ";
	}
	
	return 0;
}
