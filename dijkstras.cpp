#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int SIZE = 1e5 + 5;
#define int long long

vector < pair < int , int > > adj [SIZE];   // each vertex has all the connected vertices with the edges weights
int dist [SIZE], n, m;
bool vis [SIZE];
int parent[SIZE];

void dijkstra(int src, int destination)
{
	for(int i=1;i<=n;i++)
	{
		dist[i]=1e18;
	}
                                                // set the vertices distances as infinity
    memset(vis, false , sizeof vis);            // set all vertex as unvisited
    dist[src] = 0;
    multiset < pair < int , int > > s;          // multiset do the job as a min-priority queue

    s.insert({0 , src});                         // insert the source node with distance = 0

    while(!s.empty())
    {

        pair <int , int> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());

        int x = p.second; 
        int wei = p.first;
        // if( vis[x] ) continue;                  // check if the popped vertex is visited before
        //although you can skip this line because once a node is visited you are 
         vis[x] = true;

        for(int i = 0; i < adj[x].size(); i++)
        {
            int e = adj[x][i].second; int w = adj[x][i].first;
            if(dist[x] + w < dist[e]  )
            {            // check if the next vertex distance could be minimized
            	s.erase({dist[e], e});
                dist[e] = dist[x] + w;
                s.insert({dist[e],  e} );           // insert the next vertex with the updated distance
                parent[e] = x; 
            }
        }
    }
    
    if(!vis[destination])
	{
		cout<<"-1";
		return;
	}
	
	int ver =destination;
	vector<int> ans;
	while(parent[ver])
	{
		ans.push_back(ver);
		ver=parent[ver];
	}
	
	ans.push_back(src);
	
	reverse(ans.begin(), ans.end());
	
	for(auto it:ans)
		cout<<it<<" ";
	
}

int32_t main()
{
	
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].push_back({w, v});
		adj[v].push_back({w, u});
	}
	
	dijkstra(1, n);
	
	return 0;
}