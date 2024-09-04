#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define mx 500010

struct track{
    int id;
    LL x , y ;
    bool operator < (const track &a) const{
        return x * a.y > y * a.x;
    }
}T[mx];

struct  rifle{
    LL x , y;
    int id;
    bool operator < (const rifle &a) const{
         if(x != a.x) return x < a.x;
         return y < a.y;
    }
}R[mx] , con[mx];


int n ,m;
LL ans[mx];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>n;
    for(int i = 1 ; i <= n ; i++ ){
        cin>>T[i].x>>T[i].y;
        T[i].id = i;
    }
    cin>>m;
    for(int i = 1 ; i <= m ; i ++ ){
        cin>>R[i].x>>R[i].y;
        R[i].id = i;
    }
    sort(T+1 , T+n+1);
    sort(R+1 , R+m+1);
    int cnt = 1 , now = 1;
    con[1] = R[1];
    for(int i = 2 ; i <= m ; i++ ){
        if(R[i].x == con[cnt].x) continue;
        if(R[i].y >= con[cnt].y) continue;
        con[++cnt] = R[i];
   }
   
   memset(R , 0 , sizeof (R));
   
   R[1] = con[1] , R[2] = con[2];
   int len = 2;
   for(int i = 3 ; i <= cnt ; i++ ){
        while((len > 1) && ((R[len].y - R[len-1].y) * (R[len].x - con[i].x) < (R[len-1].x - R[len].x) * (con[i].y - R[len].y))) len--;
        R[++len] = con[i];
   }
   
   if(cnt == 1) len = 1;
   
   for(int i = 1 ; i <= n ; i++ ){
    while((now < len) && ((T[i].x * R[now].x + T[i].y * R[now].y) > (T[i].x * R[now+1].x + T[i].y * R[now+1].y))) now++;
    ans[T[i].id] = T[i].x * R[now].x + T[i].y * R[now].y;
   }
   
   for(int i = 1 ; i <= n ; i++ ) cout<<ans[i]<<" \n"[i == n];
   return 0;
}