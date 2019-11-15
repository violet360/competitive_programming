#include <bits/stdc++.h>

using namespace std;

vector<int>comp;
vector<int> adj[100];
bool used[100];
int n;


//this program prints the connected components separately

/*
for example

consider the graph

    1-----2         4----5----6
     .    |
      .   |
       .  |
        . 3


input:

6 5
1 2
2 3
3 1
4 5
5 6

output:
 1 2 3
 4 5 6

*/

void dfs(int source)
{
    used[source]=true;
    comp.push_back(source);

    for(int i:adj[source])
    {
        if(!used[i])
        {
            dfs(i);
        }
    }
}


void dfsutil()
{
    for(int x=1 ;x<=n; x++)
    {
        used[x] = false;
    }
    for(int x=1 ;x<=n ;x++)
    {
        if(!used[x])
        {
            comp.clear();
            dfs(x);
            for(int x=0; x<comp.size(); x++)
            {
                cout<<" "<<comp[x];
            }

            cout<<endl;
        }
    }
}

int main()
{
    int a, b, m;
    cin>>n>>m;
    for(int x=0; x<m; x++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    dfsutil();
    return 0;
}
