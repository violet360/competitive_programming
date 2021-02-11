/*
https://codeforces.com/contest/375/problem/D
altho this solution will fail at 13th test case 
this problem can also be solved with dp on trees but i deliberately 
used Mo's algo with tree flattening, because i wanted to implement it:)
altho you can make it pass if you perform line-160 func with fenwick tree
*/

#include <bits/stdc++.h>
typedef long long ll;
# define FAST_CODE ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
constexpr ll N = 1e6+1;
# define fr(a, b, j) for(ll i =a; i<=b; i+=j)
# define Fr(a, b, j) for(ll i=b; i>=a; i-=j)
vector<ll>adj[N];
bool used[N];
ll parent[N];
ll c = 0, in[N+1], out[N+1];
ll flat[2*N+2];
ll f_cnt[N];
 
ll current_answer;
ll cnt[1000001];
 
// Array to store answers (because the order we achieve them is messed up)
ll answers[200501];
ll BLOCK_SIZE;
ll arr[1005000];
 
// We will represent each query as three numbers: L, R, idx. Idx is 
// the position (in original order) of this query.
struct Query
{
    ll l, r, idx, k;
}queries[200500];
 
bool cmp(Query p, Query q)
{
    if (p.l / BLOCK_SIZE != q.l / BLOCK_SIZE)
        return p.l < q.l;
    return (p.l / BLOCK_SIZE & 1) ? (p.r < q.r) : (p.r > q.r);
}
 
inline void add(ll x, ll co)
{
	f_cnt[cnt[x]]--;
	cnt[x]++;
	f_cnt[cnt[x]]++;
}
 
inline void remove(ll x, ll co)
{
	f_cnt[cnt[x]]--;
	cnt[x]--;
	f_cnt[cnt[x]]++;
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
			parent[children] = src;
			dfs(children, val);
		}
	}
	out[src] = c-1;
}
 
 
int main() 
{
	FAST_CODE
	ll n, a, b, q;
	cin>>n>>q;
	BLOCK_SIZE = sqrt(N);
 
	ll val[n+1] = {0};
 
	for(ll o=0; o<=n-1; o++)
	{
		cin>>val[o];
	}
 
	ll n1 = n;
	n--;
 
	ll idx[n1+1] = {0};
 
	while(n--)
	{
		cin>>a>>b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
 
 
	parent[0] = -1;
	dfs(0, val);
 
	for(ll i=0; i<q; i++)
	{
		ll v, ki;
		cin>>v>>ki;
		// cout<<in[v-1]<<" "<<out[v-1]<<" -- "<<endl;
		queries[i].l = in[v-1];
		queries[i].r = out[v-1];
		queries[i].idx = i;
		queries[i].k = ki;// cout<<in[i]<<" "<<out[i]<<endl;
	}
 
	// Sort queries using Mo's special comparator we defined.
    std::sort(queries, queries + q, cmp);
 
    // Set up current segment [mo_left, mo_right].
    ll mo_left = 0, mo_right = -1;
 
    for(ll i = 0; i < q; i++) 
    {
        // [left, right] is what query we must answer now.
        ll left = queries[i].l;
        ll right = queries[i].r;
        ll k = queries[i].k;
		// cout<<left<<" "<<right<<" "<<queries[i].idx<<" "<<k<<endl;
        // Usual part of applying Mo's algorithm: moving mo_left
        // and mo_right.
        while(mo_right < right)
        {
            mo_right++;
            add(flat[mo_right], k);
        }
        while(mo_right > right)
        {
            remove(flat[mo_right], k);
            mo_right--;
        }
 
        while(mo_left < left)
        {
            remove(flat[mo_left], k);
            mo_left++;
        }
        while(mo_left > left)
		{
			mo_left--;
			add(flat[mo_left], k);
		}
 
		ll ctr = 0;
 
		fr(k, n1, 1)
		{
			ctr+=f_cnt[i];
		}
		answers[queries[i].idx] = ctr;
    }
 
    // // We output answers *after* we process all queries.
    for(ll i = 0; i < q; i++)
        cout << answers[i] << "\n";
    return 0;
}
