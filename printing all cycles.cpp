#include <bits/stdc++.h>

using namespace std;

vector<int>adj[100];
bool visited[100];
vector<int>comp;
int n1;
int coun_t = 0;
bool decide = false;

void dfs(int source)
{
    comp.push_back(source);

    visited[source] = true;
    for(int vertex:adj[source])
    {
        if(!visited[vertex])
        {
            //comp.push_back(vertex);  you cannot write this line here because it will not add first source node
            //in comp
            dfs(vertex);
        }
    }
}

void dfutil()
{
    for(int i=0; i<100; i++)
    {
        visited[i] = false;
    }
    for(int x=1; x<=n1; x++)
    {
        if(!visited[x])
        {
            comp.clear();
            dfs(x);

            decide = false;


            for(int point:adj[comp[0]])
            {
                if(point == comp[comp.size()-1])
                    decide = true;
            }

            if(decide)
                for(int v:comp)
                cout<<v<<" ";
            cout<<endl;
        }
    }
}


int main()
{
    int a, b, n2;
    cin>>n1>>n2;

    for(int x=1; x<=n2; x++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfutil();
    return 0;
}
