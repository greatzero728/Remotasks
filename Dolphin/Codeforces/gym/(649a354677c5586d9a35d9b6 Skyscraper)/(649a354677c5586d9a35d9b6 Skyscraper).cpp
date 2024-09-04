#include<cstdio>
typedef long long ll;
const int N=100010;
int Case,n,m,i,op,x,y;ll z,a[N],b[N],f[N],g[N];
inline void ins(ll*f,int x,ll p){for(;x<=n;x+=x&-x)f[x]+=p;}
inline ll ask(ll*f,int x){ll t=0;for(;x;x-=x&-x)t+=f[x];return t;}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(i=1;i<=n;i++)b[i]=a[i]-a[i-1];
    for(i=1;i<=n;i++)f[i]=g[i]=0;
    for(i=1;i<=n;i++){
      ins(f,i,b[i]);
      if(b[i]>0)ins(g,i,b[i]);
    }
    while(m--){
      scanf("%d%d%d",&op,&x,&y);
      if(op==1){
        y++;
        scanf("%lld",&z);
        ins(f,x,z);
        ins(f,y,-z);
        if(b[x]>0)ins(g,x,-b[x]);
        if(b[y]>0)ins(g,y,-b[y]);
        b[x]+=z;
        b[y]-=z;
        if(b[x]>0)ins(g,x,b[x]);
        if(b[y]>0)ins(g,y,b[y]);
      }else{
        printf("%lld\n",ask(f,x)+ask(g,y)-ask(g,x));
      }
    }
  }
}