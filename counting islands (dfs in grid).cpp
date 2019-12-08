#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool used[5][5];
ll islands[5][5];

ll row[] = {-1, -1, -1, 0, 0, 1, 1, 1 };
ll col[] = {-1, 0, 1, -1, 1, -1, 0, 1 };

bool is_safe(ll r, ll c)
{
	return ((r >= 0) & (r < 5) & (c >= 0) & (c < 5));
}

void dfs(ll r, ll c)
{
	used[r][c] = true;

	for(ll i=0; i<8; i++)
	{
		if(!used[r + row[i]][c + col[i]] & is_safe((r + row[i]), (c + col[i])) & islands[r + row[i]][c + col[i]] == 1)
		{
			// cout<<r+row[i]<<" "<<c + col[i]<<endl;
			dfs(r + row[i] , c + col[i]);
		}
	}
}


int main() 
{
	memset(used, 0, sizeof(used)); 
	
	for(ll r=0; r<5; r++)
	{
		for(ll c=0; c<5; c++)
		{
			cin>>islands[r][c];
		}
	}
	
	// for(ll r=0; r<5; r++)
	// {
	// 	for(ll c=0; c<5; c++)
	// 	{
	// 		cout<<used[r][c]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	
	// dfs(0, 0);
	ll count =0;
	
	for(ll r=0; r<5; r++)
	{
		for(ll c=0; c<5; c++)
		{
			if((islands[r][c] == 1) & (!used[r][c]))
			{
				// cout<<r<<" "<<c<<endl;
				dfs(r, c);
				count++;
			}
		}
	}
	
	cout<<count;
	
	return 0;
}