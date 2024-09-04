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

int n;
int p[1000500];
LL ans = 0;

vector< INFO > get_pref( int i, int j )
{
	map< int, int > Map;
	set< PAR > Set;
	vector< INFO > re;
	int ii = 0;
	FOR(a,i,j)
	{
		if (Map.find( p[a] ) != Map.end())
			Set.erase( make_pair( -Map[p[a]], p[a] ) );
		Map[ p[a] ]++;
		Set.insert( make_pair( -Map[ p[a] ], p[a] ) );
		ii++;
		int c1 = -(*Set.begin()).first;
		int c2 = ii - c1;
		if (c1*2 > ii)
			re.push_back( INFO( (*Set.begin()).second, c1-c2 ) );
	}
	return re;
}

vector< INFO > get_suff( int i, int j )
{
	map< int, int > Map;
	set< PAR > Set;
	vector< INFO > re;
	int ii = 0;
	DFOR(a,j,i)
	{
		if (Map.find( p[a] ) != Map.end())
			Set.erase( make_pair( -Map[p[a]], p[a] ) );
		Map[ p[a] ]++;
		Set.insert( make_pair( -Map[ p[a] ], p[a] ) );
		ii++;
		int c1 = -(*Set.begin()).first;
		int c2 = ii - c1;
		if (c1*2 > ii)
			re.push_back( INFO( (*Set.begin()).second, c1-c2 ) );
	}
	return re;
}

void do_it( int i, int j )
{
	if (i==j)
	{
		ans++;
		return;
	}

	int d = (i+j)/2;
	vector< INFO > suff = get_suff( i, d );
	vector< INFO > pref = get_pref( d+1, j );

	map< int, vector< INFO > > suff_c, pref_c;
	set< int > colors;
	FA(a,suff)
	{
		suff_c[ suff[a].color ].push_back( suff[a] );
		colors.insert( suff[a].color );
	}
	FA(a,pref)
	{
		pref_c[ pref[a].color ].push_back( pref[a] );
		colors.insert( pref[a].color );
	}

	vector< int > delta;

	for (map< int, vector< INFO > >::iterator it = pref_c.begin(); it != pref_c.end(); it++)
	{
		delta.clear();
		int cur_d = 0;
		DFOR(a,d,i)
		{
			if (p[a]==it->first) cur_d++;
			else cur_d--;
			delta.push_back( cur_d );
		}
		//sort( delta.begin(), delta.end() );
		VI cnt(SZ(delta)*2+1);
		FA(a,delta) cnt[SZ(delta)+delta[a]]++;
		int iii=0;
		FA(a,cnt) FOR(b,1,cnt[a]) delta[iii++] = a-SZ(delta);

		FA(a,it->second)
		{
			int ind = lower_bound( delta.begin(), delta.end(), -it->second[a].delta+1 ) - delta.begin();
			ans += SZ(delta) - ind;
		}
	}

	for (map< int, vector< INFO > >::iterator it = suff_c.begin(); it != suff_c.end(); it++)
	{
		delta.clear();
		int cur_d = 0;
		FOR(a,d+1,j)
		{
			if (p[a]==it->first) cur_d++;
			else cur_d--;
			delta.push_back( cur_d );
		}
		//sort( delta.begin(), delta.end() );
		VI cnt(SZ(delta)*2+1);
		FA(a,delta) cnt[SZ(delta)+delta[a]]++;
		int iii=0;
		FA(a,cnt) FOR(b,1,cnt[a]) delta[iii++] = a-SZ(delta);

		FA(a,it->second)
		{
			int ind = lower_bound( delta.begin(), delta.end(), -it->second[a].delta+1 ) - delta.begin();
			ans += SZ(delta) - ind;
		}
	}

	for (set< int >::iterator it = colors.begin(); it != colors.end(); it++)
		ans -= (LL)SZ(suff_c[*it]) * SZ(pref_c[*it]);

	do_it( i, d );
	do_it( d+1, j );
}

void stupid()
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
	cout << ans << "\n";
}

void sol()
{
	do_it( 1, n );
	cout << ans << "\n";
}

int main()
{

	freopen("prediction.in","r",stdin);
	freopen("prediction.out","w",stdout);
		//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	RE("%d%*d", &n);
	FOR(a,1,n) RE("%d", &p[a]);

	sol();
	//stupid();


	return 0;
}
