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

int seq[size];
int curcnt[size];
int sumcnt[size];
int n, m;

int main()
{
	freopen("prediction.in","r",stdin);
	freopen("prediction.out","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}	
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++)
			curcnt[j] = 0;
		int mx = 0;
		for (int j = i; j < n; j++) {
			curcnt[seq[j]]++;
			if (curcnt[seq[j]] > curcnt[mx])
				mx = seq[j];
			if (curcnt[mx] * 2 > (j - i + 1))
				ans++;
		}
	}

	cout << ans << endl;

    return 0;
}
