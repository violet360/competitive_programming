/*
MO’s algorithm is quite general. It’s applicable anytime where you have a static array, a lot of
overlapping queries known in advance (offline) and where the can easily add/remove the contribution of an element easily.
It’s particularly useful when you work with an operation that is complicated enough to make segment trees hard/impossible to use.

Perhaps a bit outside the scope of your question, but from my experience when it comes to tasks with queries in general my mental checklist is

- Can queries be done analytically? If so just process the queries online.
- Is the function a good fit for a segment tree? Use a segment tree to solve queries online.
- Is the function weird but fits the requirements for MO? Use MO if O(n.sqrt(n)) will do.
- Investigate other solutions, specific data structures related to the operation at hand.


You have an array Arr of N numbers ranging from 0 to 99. Also you have Q queries [L, R]. For each such query you must print
V([L, R]) = ∑i=0..99 count(i)2 * i
where count(i) is the number of times i occurs in Arr[L..R].

test case:

18 7
0 1 1 0 2 3 4 1 3 5 1 5 3 5 4 0 2 2
0 8
2 5
2 11
16 17
13 14
1 17
17 17

*/

#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
typedef long long ll;
typedef long double ld;
# define FAST_CODE ios_base::sync_with_stdio(false); cin.tie(NULL);
# define pb push_back
#define MOD 1e+9
using namespace std;


ll N, Q;

// Variables, that hold current "state" of computation
ll current_answer;
ll cnt[1000001];

// Array to store answers (because the order we achieve them is messed up)
ll answers[200501];
ll BLOCK_SIZE;
ll arr[1005000];

// We will represent each query as three numbers: L, R, idx. Idx is 
// the position (in original order) of this query.
pair< pair<ll, ll>, ll> queries[200500];


// Essential part of Mo's algorithm: comparator, which we will
// use with std::sort. It is a function, which must return True
// if query x must come earlier than query y, and False otherwise.
inline bool mo_cmp(const pair< pair<ll, ll>, ll> &x,
        const pair< pair<ll, ll>, ll> &y)
{
    ll block_x = x.first.first / BLOCK_SIZE;
    ll block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

// When adding a number, we first nullify it's effect on current
// answer, then update cnt array, then account for it's effect again.
inline void add(ll x)
{
    current_answer -= cnt[x] * cnt[x] * x;
    cnt[x]++;
    current_answer += cnt[x] * cnt[x] * x;
}

// Removing is much like adding.
inline void remove(ll x)
{
    current_answer -= cnt[x] * cnt[x] * x;
    cnt[x]--;
    current_answer += cnt[x] * cnt[x] * x;
}

int main()
{
    FAST_CODE;
    cin >> N >> Q;
    BLOCK_SIZE = sqrt(N);

    // Read input array
    for(ll i = 0; i < N; i++)
        cin >> arr[i];

    // Read input queries, which are 0-indexed. Store each query's 
    // original position. We will use it when printing answer.
    ll A, B;
    for(ll i = 0; i < Q; i++) 
    {
    	cin>>A>>B;
        queries[i].first.first = A-1;
        queries[i].first.second = B-1;
        queries[i].second = i;
    }

    // Sort queries using Mo's special comparator we defined.
    std::sort(queries, queries + Q, mo_cmp);

    // Set up current segment [mo_left, mo_right].
    ll mo_left = 0, mo_right = -1;

    for(ll i = 0; i < Q; i++) {
        // [left, right] is what query we must answer now.
        ll left = queries[i].first.first;
        ll right = queries[i].first.second;

        // Usual part of applying Mo's algorithm: moving mo_left
        // and mo_right.
        while(mo_right < right) {
            mo_right++;
            add(arr[mo_right]);
        }
        while(mo_right > right) {
            remove(arr[mo_right]);
            mo_right--;
        }

        while(mo_left < left) {
            remove(arr[mo_left]);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            add(arr[mo_left]);
        }

        // Store the answer into required position.
        answers[queries[i].second] = current_answer;
    }

    // We output answers *after* we process all queries.
    for(ll i = 0; i < Q; i++)
        cout << answers[i] << "\n";
    return 0;
}
