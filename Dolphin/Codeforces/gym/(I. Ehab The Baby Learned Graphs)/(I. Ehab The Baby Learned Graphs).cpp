#include <bits/stdc++.h>
using namespace std;
bool vis[105];
vector<pair<int,int> > ans;
vector<int> s[2];
int n,m,c[105],mat[105][105];
bool dfs(int node,int cc)
{
    if (c[node]!=-1)
    return (c[node]==cc);
    c[node]=cc;
    s[cc].push_back(node);
    bool ok=1;
    for (int i=1;i<=n;i++)
    {
        if (mat[node][i])
        ok&=dfs(i,!cc);
    }
    return ok;
}
void add(int a,int b)
{
    ans.push_back({a,b});
    mat[a][b]^=1;
    mat[b][a]^=1;
}
void star(int r)
{
    for (int i=1;i<=n;i++)
    {
        if (i!=r)
        add(r,i);
    }
}
void star(int r,int a,int b)
{
    for (int i=1;i<=n;i++)
    {
        if (i!=r && i!=b)
        add(r,i);
    }
    add(a,b);
}
int getleaf(int node)
{
    vis[node]=1;
    for (int i=1;i<=n;i++)
    {
        if (mat[node][i] && !vis[i])
        return getleaf(i);
    }
    return node;
}
void solve(int node,int p)
{
    vis[node]=1;
    for (int i=1;i<=n;i++)
    {
        if (mat[node][i] && !vis[i])
        solve(i,node);
    }
    int cur=0;
    for (int i=1;i<=n;i++)
    {
        if (i==p)
        continue;
        if (mat[node][i])
        {
            if (!cur)
            cur=i;
            else
            {
                star(node,cur,i);
                star(node,i,cur);
                cur=0;
            }
        }
    }
    if (mat[node][p] && cur)
    {
        star(node,cur,p);
        star(node,p,cur);
    }
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
    freopen("xot.in", "r", stdin);
#endif
	
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            scanf("%d",&mat[i][j]);
            m+=mat[i][j];
        }
    }
    m/=2;
    if (n%2 && m%2)
    {
        printf("-1");
        return 0;
    }
    memset(c,-1,sizeof(c));
    if (dfs(1,0) && s[0].size()*s[1].size()==m)
    {
        for (int i:s[0])
        star(i);
        goto out;
    }
    if (m%2)
    star(getleaf(1));
    memset(vis,0,sizeof(vis));
    solve(1,0);
    out:
    printf("%d\n",ans.size()/(n-1));
    for (auto p:ans)
    printf("%d %d\n",p.first,p.second);
}