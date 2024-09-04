#include <bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ve vector
#define all(x) x.begin(),x.end()
#define endl '\n'
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
const ll INF = 1e18+2;

ve<ll> gr[1002];
pll arr[1002];
ll mt[1002],cnt[1002],pos[1002],ans[1002];
char vis[1002];

bool dfs(ll s)
{
    if(vis[s]) return 0;
    vis[s]=1;

    for(ll i:gr[s])
    {
        if(mt[i]==-1||dfs(mt[i]))
        {
            mt[i]=s;
            return 1;
        }
    }

    return 0;
}

void solve()
{
    ll n,m;
    cin>>n>>m;

    for(ll i=0;i<n;i++)
    {
        cin>>arr[i].F>>arr[i].S;
        arr[i].F--, arr[i].S--;
    }

    for(ll i=0;i<m;i++)
        cin>>cnt[i];

    for(ll i=1;i<m;i++)
        pos[i]=pos[i-1]+cnt[i-1];

    pos[m]=INF;

    for(ll i=0;i<n;i++)
    {
        ll a,b;
        tie(a,b)=arr[i];

        for(ll j=pos[a];j<pos[a]+cnt[a];j++)
            gr[i].PB(j);

        for(ll j=pos[b];j<pos[b]+cnt[b];j++)
            gr[i].PB(j);
    }

    fill(mt,mt+n,-1);
    ll c=0;

    for(ll i=0;i<n;i++)
    {
        fill(vis,vis+n,0);
        if(dfs(i)) c++;
    }

    if(c<n)
    {
        cout<<-1;
        return;
    }

    ll j=0;

    for(ll i=0;i<n;i++)
    {
        while(i==pos[j+1]) j++;
        ans[mt[i]]=j+1;
    }

    for(ll i=0;i<n;i++)
        cout<<ans[i]<<' ';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
    freopen("experimental.in","r",stdin);
    freopen("experimental.out","w",stdout);
#endif
	
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

	solve();
	
    return 0;
}
