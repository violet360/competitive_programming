#include <bits/stdc++.h>

using namespace std;

vector<int>adj [100];
int parent[100];
bool used[100];
stack<int>S;

void dfs(int source)
{
    used[source] = true;
    for(int vertex:adj[source])
    {
        if(!used[vertex])
        {
            parent[vertex] = source;
            dfs(vertex);
        }
    }
    S.push(source);
}

int main()
{
    int a, b, n1, n2;
    cin>>n1>>n2;

    for(int x=1 ;x<=n2; x++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }

    for(int x=1; x<=n1; x++)
    {
        if(!used[x])
            dfs(x);
    }

    while(!S.empty())
    {
        cout<<S.top()<<" ";
        S.pop();
    }

    return 0;
}
