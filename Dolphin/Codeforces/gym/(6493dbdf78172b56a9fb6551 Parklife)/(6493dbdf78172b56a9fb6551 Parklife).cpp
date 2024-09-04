// #include <bits/stdc++.h>
#include <vector>
#include <iostream>

#include <queue>

using namespace std;
const int N = 2.5e5 + 5;
typedef long long LL;
typedef vector<int> vi;
#define pb push_back
int n, stk[N], tp;
vi e[N];
struct dat
{
    int l, r;
    LL w;
} a[N];
bool cmp(const dat &i, const dat &j)
{
    return (i.l != j.l) ? (i.l < j.l) : (i.r > j.r);
}
priority_queue<LL> q[N];
void dfs(int u, int ff)
{
    for (int v : e[u])
    {
        if (v == ff)
            continue;
        dfs(v, u);
        if (q[u].empty())
            swap(q[u], q[v]);
        else
        {
            vector<LL> f;
            if (q[u].size() < q[v].size())
                swap(q[u], q[v]);
            while (!q[v].empty())
            {
                LL a = q[u].top();
                LL b = q[v].top();
                f.pb(a + b);
                q[u].pop();
                q[v].pop();
            }
            for (LL x : f)
                q[u].push(x);
        }
    }
    q[u].push(a[u].w);
}
int main() {
    ios ::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].w;
    }
    
	++n, a[n].l = 1, a[n].r = 1e6, a[n].w = 0;
    sort(a + 1, a + n + 1, cmp);
    stk[++tp] = 1;
    for (int i = 2, f; i <= n; i++){
        f = stk[tp];
        while (a[i].r > a[f].r) f = stk[--tp];
        e[f].pb(i), e[i].pb(f);
        stk[++tp] = i;
    }
    dfs(1, 0);
    LL ans = 0;
    for (int i = 1; i < n; i++){
        if (!q[1].empty()){
            ans += q[1].top(), q[1].pop();
        }
        cout << ans << " ";
    }
    cout << "\n";
    return 0;
}