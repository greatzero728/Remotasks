#pragma comment(linker,"/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <algorithm>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first

#define FOR(i,k,n) for(int i=(k); i<=(n); i++)
#define DFOR(i,k,n) for(int i=(k); i>=(n); i--)
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a, 0, sizeof(a))

#define LL long long
#define VI  vector<int>
#define PAR pair<int ,int>
#define o_O 1000000000

void __never(int a){printf("\nOPS %d", a);}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();abort();}}

struct INFO
{
	int color;
	int delta;
	INFO( int _color=0, int _delta=0 )
	{
		color = _color;
		delta = _delta;
	}
};

bool le( const INFO & A, const INFO & B )
{
	return A.color < B.color;
}

int n;
int p[500500];
LL ans = 0;

INFO suff[500500], pref[500500];
int suff_sz, pref_sz;

int delta[500500], cnt[1000500];
int cnt2[500500];

void do_pref( int i, int j )
{
	int cur_mx = -1;
	int cur_color = -1;
	pref_sz=0;
	int ii=0;
	FOR(a,i,j)
	{
		cnt2[p[a]]++;
		ii++;
		if (cnt2[p[a]] > cur_mx)
		{
			cur_color = p[a];
			cur_mx = cnt2[p[a]];
		}
		if (cur_mx*2 > ii)
			pref[pref_sz++] = INFO( cur_color, cur_mx - (ii-cur_mx) );
	}
	FOR(a,i,j) cnt2[p[a]] = 0;
}

void do_suff( int i, int j )
{
	int cur_mx = -1;
	int cur_color = -1;
	suff_sz = 0;
	int ii=0;
	DFOR(a,j,i)
	{
		cnt2[p[a]]++;
		ii++;
		if (cnt2[p[a]] > cur_mx)
		{
			cur_color = p[a];
			cur_mx = cnt2[p[a]];
		}
		if (cur_mx*2 > ii)
			suff[suff_sz++] = INFO( cur_color, cur_mx - (ii-cur_mx) );
	}
	FOR(a,i,j) cnt2[p[a]] = 0;
}

void do_it( int i, int j )
{
	int d = (i+j)/2;
	do_suff( i, d );
	do_pref( d+1, j );

	map< int, int > colors;

	sort( pref, pref+pref_sz, le );
	sort( suff, suff+suff_sz, le );

	int delta_sz;
	pref[pref_sz].color = -1;
	int ii = 0;
	FOR(z,0,pref_sz-1) if (pref[z].color != pref[z+1].color)
	{
		delta_sz = 0;
		int cur_d = 0;
		DFOR(a,d,i)
		{
			if (p[a]==pref[z].color) cur_d++;
			else cur_d--;
			delta[delta_sz++] = cur_d;
		}
		FOR(a,0,delta_sz*2) cnt[a] = 0;
		FOR(a,0,delta_sz-1) cnt[delta_sz+delta[a]]++;
		int iii=0;
		FOR(a,0,delta_sz*2) FOR(b,1,cnt[a]) delta[iii++] = a-delta_sz;

		FOR(a,ii,z)
		{
			int ind = lower_bound( delta, delta + delta_sz, -pref[a].delta+1 ) - delta;
			ans += delta_sz - ind;
		}

		colors[pref[z].color] = z-ii+1;
		ii = z+1;
	}

	suff[suff_sz].color = -1;
	ii = 0;
	FOR(z,0,suff_sz-1) if (suff[z].color != suff[z+1].color)
	{
		delta_sz = 0;
		int cur_d = 0;
		FOR(a,d+1,j)
		{
			if (p[a]==suff[z].color) cur_d++;
			else cur_d--;
			delta[delta_sz++] = cur_d;
		}
		FOR(a,0,delta_sz*2) cnt[a] = 0;
		FOR(a,0,delta_sz-1) cnt[delta_sz+delta[a]]++;
		int iii=0;
		FOR(a,0,delta_sz*2) FOR(b,1,cnt[a]) delta[iii++] = a-delta_sz;

		FOR(a,ii,z)
		{
			int ind = lower_bound( delta, delta + delta_sz, -suff[a].delta+1 ) - delta;
			ans += delta_sz - ind;
		}

		//colors[suff[z].color] = z-ii+1;
		ans -= (LL)colors[suff[z].color] * (z-ii+1);
		ii = z+1;
	}
}

void do_it2( int i, int j )
{
	FOR(z,i,j)
	{
		int cur_mx = -1;
		int cur_color = -1;
		int ii=0;
		FOR(a,z,j)
		{
			cnt2[p[a]]++;
			ii++;
			if (cnt2[p[a]] > cur_mx)
			{
				cur_color = p[a];
				cur_mx = cnt2[p[a]];
			}
			if (cur_mx*2 > ii)
				ans++;
		}
		FOR(a,z,j) cnt2[p[a]] = 0;
	}
}

void dfs( int i, int j )
{
	if (j-i<30)
	{
		do_it2(i,j);
		return;
	}

	do_it(i,j);
	int d = (i+j)/2;
	dfs(i,d);
	dfs(d+1,j);
}

LL stupid()
{
	int ans = 0;
	FOR(a,1,n) FOR(b,a,n)
	{
		map< int, int > Map;
		FOR(c,a,b) Map[p[c]] ++;
		for (map< int, int >::iterator it = Map.begin(); it != Map.end(); it++)
			if (it->SE*2 > b-a+1)
				ans++;
	}
	//cout << ans << "\n";
	return ans;
}

LL sol()
{
	ans = 0;
	dfs( 1, n );
	//cout << ans << "\n";
	return ans;
}

void stress()
{
	int ii = 0;
	while(1)
	{
		ii++;
		cerr << ii << " ";
		n = rand()%500+1;
		FOR(a,1,n) p[a] = rand()%2+1;
		cerr << "n=" << n << " ";
		LL ans1 = sol();
		LL ans2 = stupid();
		if (ans1 != ans2)
		{
			cerr << "error!!!";
			cout << n << "\n";
			FOR(a,1,n) cout << p[a] << " ";
			cout << "\n";
			cout << ans1 << "\n";
			cout << ans2 << "\n";
			return;
		}
		cerr << "ans=" << ans1 << " ok!\n";
	}
}

int main()
{
	freopen("prediction.in","r",stdin);
	freopen("prediction.out","w",stdout);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	//stress();

	RE("%d%*d", &n);
	FOR(a,1,n) RE("%d", &p[a]);

	cout << sol() << "\n";
	//cout << stupid() << "\n";


	return 0;
}
