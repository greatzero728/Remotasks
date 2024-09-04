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
int bar;

bool fat[size];
int seq[size];
int cnt[size], cnts[size];
int curcnt[size];
int sumcnt[2 * size];
int n, m;
int ops = 1000000000;

int main()
{
    freopen("prediction.in","r",stdin);
    freopen("prediction.out","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &seq[i]);
        cnts[++cnt[seq[i]]]++;
    }
    for (int i = 1; i <= m; i++) {
        if (ops > cnts[i] + i * 2) {
            ops = cnts[i] + i * 2;
            bar = i;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++)
        fat[i] = cnt[i] >= bar;
    for (int i = 0; i < n; i++) {
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
    }

    for (int i = 1; i <= m; i++)
        if (fat[i]) {
            sumcnt[n] = 1;
            long long curunder = 0;
            int cur = n;
            int mn = n;
            int mx = n;
            for (int j = 0; j < n; j++) {
                if (seq[j] == i) {
                    curunder += sumcnt[cur];
                    cur++;
                    sumcnt[cur]++;
                } else {
                    curunder -= sumcnt[cur - 1];
                    cur--;
                    sumcnt[cur]++;
                }
                if (mn > cur) {
                    mn = cur;
                }
                if (mx < cur) {
                    mx = cur;
                }
                ans += curunder;
            }
            memset(sumcnt + mn, 0, sizeof(int) * (mx - mn + 1));
        }

    cout << ans << endl;

    return 0;
}
