#ifndef __GNUC__
#pragma comment(linker, "/STACK:1000000000")
#endif
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

const int size = 500 * 1000 + 100;
const int bar = 1;

bool fat[size];
int seq[size];
int cnt[size];
int curcnt[size];
int n, m;
int fen[2 * size];

void fenchange(int ps) {
	while (ps <= 2 * n + 1) {
		fen[ps]++;
		ps = ps | (ps + 1);
	}
}

int fensum(int ps ) {
	int res = 0;
	while (ps > 0) {
		res += fen[ps];
		ps = ps & (ps + 1);
	}

	return res;
}

int main()
{
	
	freopen("prediction.in","r",stdin);
	freopen("prediction.out","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
		cnt[seq[i]]++;
	}	
	long long ans = 0;
	for (int i = 1; i <= m; i++)
		fat[i] = cnt[i] >= bar;
	/*for (int i = 0; i < n; i++) {
		int mx = 0;
		for (int j = i; j < min(n, i + 2 * bar); j++) {
			curcnt[seq[j]]++;
			if (curcnt[seq[j]] > curcnt[mx])
				mx = seq[j];
			if (!fat[mx] && curcnt[mx] * 2 > (j - i + 1))
				ans++;
		}
		for (int j = i; j < min(n, i + 2 * bar); j++)
			curcnt[seq[j]] = 0;
	} */

	for (int i = 1; i <= m; i++)
		if (fat[i]) {
			for (int j = 0; j <= 2 * n + 2; j++)
				fen[j] = 0;
			int cur = 0;
			for (int j = 0; j < n; j++) {
				cur += -1 + 2 * (seq[j] == i);
				ans += fensum(cur + n - 1);
				fenchange(cur + n);
			}
		}	

	cout << ans << endl;

    return 0;
}
