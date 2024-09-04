#pragma comment(linker,"/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
#include <ctime>
#include <memory.h>

#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first
#define MP make_pair

#define FOR(i,Be,En) for(int (i)=(Be);(i)<=(En);++(i))
#define DFOR(i,Be,En) for(int (i)=(Be);(i)>=(En);--(i))
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a,0,sizeof(a))

#define LL  long long
#define VI  vector<int>
#define PAR pair<int ,int> 

using namespace std;
void __never(int a){printf("\nOPS %d", a);}
void __die(int a){printf("%d",(a*a)/(a+a));}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();__die(0);}}


#define MN 500500

int n, k;

map<int,int> ids;
int m[MN];
VI dif[MN];

int tmp[MN];
int id(int a){
	if (ids.find(a) == ids.end()){
		int res = SZ(ids);
		return ids[a] = res;
	}
	return ids[a];
}

int Max(int a, int b){
	if (a > b) return a;
	return b;
}
void init()
{
	freopen("prediction.in","r",stdin);
	freopen("prediction.out","w",stdout);
}
LL solve(int ty) {
	int n = SZ(dif[ty]);
	FOR(i,0,n-1) tmp[i] = dif[ty][i];
	LL res = 0;
	FOR(i,0,n-1) FOR(j,i,n-1) {
		int Main = j-i+1;
		int len = tmp[j]-tmp[i]+1;
		int max_length = Main * 2 - 1;
		if (len <= max_length){
			int rest = max_length - len;
			int ML = max(tmp[i] - rest, (i == 0 ? 0 : tmp[i-1] + 1));
			int MR = (j == n-1 ? (::n-1) : tmp[j+1]-1);
			FOR(k,ML,tmp[i]) {
				int R = k + max_length - 1;
				if (R >= MR) {
					res += (MR - tmp[j] + 1) * (tmp[i] - k + 1);
					break;
				} else {
					res += R - tmp[j] + 1;
				}
			}
		}
	}
	//cout << res << endl;
	return res;
}
void sol(){	
	RE("%d %d",&n,&k);
	int h;
	FOR(i,0,n-1) {
		RE("%d",&m[i]);
		//m[i] = id(h);
	}
	//FOR(i,0,n-1) WR("%d",m[i]);WR("\n");
	//k = SZ(ids);
	FOR(i,0,n-1) dif[m[i]].PB(i);
	
	LL ans = 0;
	FOR(i,1,k) ans += solve(i);
	cout << ans;
}
int main()
{
	init();
	sol();
	return 0;
}