#include <bits/stdc++.h>

using namespace std;

bool visited[100];
vector<int>adj[100];
int V;
int p[100];
int start_cycle, end_cycle;

/*
the basically you start from a source node, travel to the adjacent node which is not visited by dfs and keep assigning
parents in an array p[] and pass parent of each node as an argument too, if come across a node which you have already
visited but is not the parent of the current node, then you have cycle
*/
bool dfsutil(int cur, bool visited[], int parent)
{
    visited[cur] = true;  //mark the current node as visited

    for(int v: adj[cur])  //traverse the adjacent nodes of the current nodes...
    {
        if(!visited[v]) //if any adjacent node is not visited then reach that node...
        {
            p[v] = cur;  //assign current node 'cur' as a parent of the node you are reach out to 'v'...

            if(dfsutil(v, visited, cur))  // now pass the arguments as if 'v' is current node in which case 'cur' node
                                            // becomes your parent...
                return true;
        }

        else if(v!=parent)  //if you are at any 'cur' node and you find out that one of the adjacent node 'v' is already
        {                   //visited and is not the parent of the current node 'cur' then clearly their is a cycle
                            //hence this case should return true...


            start_cycle = v;  //so your current node 'cur' is the end of the of the cycle and the adjacent node which
            end_cycle = cur;  //is not the parent node but is visited is the start of the cycle
            return true;
        }
    }
    return false;
}

bool cycle()
{
    for(int i=1; i<=V; i++)
    {
        visited[i] = false;
    }

    for(int y=1; y<=V; y++)
    {
        if(!visited[y]) //check only for nodes which are not visited...
            if(dfsutil(y, visited, -1))
                return true;
    }

    return false;
}
int main()
{
    int E, a, b;
    cin>>V>>E;
    for(int x=0; x<E; x++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfsutil(1,visited, -1);



    for(int f=end_cycle; f!=start_cycle; f=p[f])
    {
        cout<<f;
    }

    cout<<start_cycle;
    return 0;
}
