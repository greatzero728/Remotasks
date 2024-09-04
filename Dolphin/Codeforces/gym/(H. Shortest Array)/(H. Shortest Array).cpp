#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v[200005];
long long s[200005];
bool adj[200005];
int cnt[200005];
int main()
{
    
    freopen("hide.in", "r", stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%I64d",&s[i]);
        adj[i]=1;
    }
    while (m--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if (s[a]+c<s[b] || s[b]+c<s[a])
        {
            printf("-1\n");
            return 0;
        }
        adj[a]&=(s[b]+c!=s[a]);
        adj[b]&=(s[a]+c!=s[b]);
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    int tot=0;
    for (int i=1;i<=n;i++)
    {
        if (adj[i])
        {
            tot++;
            for (auto p:v[i])
            cnt[p.first]+=(p.second==s[i]);
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (cnt[i]==tot)
        {
            bool ok=1;
            for (auto p:v[i])
            ok&=(p.second>=s[p.first]);
            if (ok)
            {
                printf("%d",i);
                return 0;
            }
        }
    }
    printf("-1");
}