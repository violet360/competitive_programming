#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define M 32
vector<ll>adj[1000];
bitset<M>used;
ll parent[1000];
 
void dfs(ll src)
{
	used[src] = true;
	for(ll children:adj[src])
	{
		if(!used[children])
		{
			cout<<children<<endl;
			parent[children] = src;
			dfs(children);
		}
	}
}
 
int main() 
{
	ll n, a, b;
	cin>>n;
	n--;
	while(n--)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	parent[1] = -1;
	dfs(1);
 
	cout<<"***************"<<endl;
	ll node;
	cin>>node;
	for(ll v = node; v!=-1; v = parent[v])
	{
		cout<<v<<endl;
	}
 
	return 0;
}
