#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3005;

char s[maxn];
bool can[maxn][maxn];
int match[300], match2[300];
int n;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
    freopen("semipal.in", "r", stdin);
    freopen("semipal.out", "w", stdout);
#endif
	
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) can[i][i] = true;
    for (int i = 0; i < n; i++)
    {
        for (int t = 'a'; t <= 'z'; t++)
        {
            match[t] = -1;
            match2[t] = -1;
        }
        match[s[i]] = s[i];
        match2[s[i]] = s[i];
        bool ok = true;
        for (int j = 1; i - j >= 0 && i + j < n; j++)
        {
            if (match[s[i - j]] != -1 && match[s[i - j]] != s[i + j]) ok = false;
            if (match2[s[i + j]] != -1 && match2[s[i + j]] != s[i - j]) ok = false;
            match[s[i - j]] = s[i + j];
            match2[s[i + j]] = s[i - j];
            can[i - j][i + j] = ok;
        }
        for (int t = 'a'; t <= 'z'; t++)
        {
            match[t] = -1;
            match2[t] = -1;
        }
        ok = true;
        for (int j = 0; i - j >= 0 && i + 1 + j < n; j++)
        {
            if (match[s[i - j]] != -1 && match[s[i - j]] != s[i + 1 + j]) ok = false;
            if (match2[s[i + 1 + j]] != -1 && match2[s[i + 1 + j]] != s[i - j]) ok = false;
            match[s[i - j]] = s[i + 1 + j];
            match2[s[i + 1 + j]] = s[i - j];
            can[i - j][i + 1 + j] = ok;
        }
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len <= n; i++)
        {
            int j = i + len - 1;
            if (len != 2) can[i][j] = can[i][j] && can[i][i + len / 2 - 1] && can[j - len / 2 + 1][j];
        }
    }
    int answer = 0;
    int ansi, ansj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) if (can[i][j] && j - i + 1 > answer)
        {
            answer = j - i + 1;
            ansi = i;
            ansj = j;
        }
    }
    for (int i = ansi; i <= ansj; i++) printf("%c", s[i]);
    return 0;
}
