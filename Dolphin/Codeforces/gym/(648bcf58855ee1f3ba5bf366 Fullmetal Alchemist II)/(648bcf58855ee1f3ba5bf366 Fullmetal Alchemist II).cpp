#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 12, INF = 1000000009;

int n;
string a[N];

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

bool contains(string a, string b)
{
    int sb = sz(b);
    int s = sz(b);
    b += a;
    int f = sz(b);
    vector<int> z = z_function(b);
    for (int i = s; i < f; ++i)
    {
        if (z[i] >= sb)
            return true;
    }
    return false;
}

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int maxinter(string a, string b)
{
    reverse(all(a));
    reverse(all(b));
    a += '#';
    a += b;
    return prefix_function(a).back();
}

int q[N][N];

void solv()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<string> v;
    for (int i = 0; i < n; ++i)
        v.push_back(a[i]);
    while (1)
    {
        bool z = false;
        for (int i = 0; i < sz(v); ++i)
        {
            for (int j = 0; j < sz(v); ++j)
            {
                if (i == j)
                    continue;
                if (contains(v[j], v[i]))
                {
                    z = true;
                    break;
                }
            }
            if (z)
            {
                vector<string> nv;
                for (int j = 0; j < sz(v); ++j)
                {
                    if (i == j)
                        continue;
                    nv.push_back(v[j]);
                }
                v = nv;
                break;
            }
        }
        if (!z)
            break;
    }

    n = sz(v);
    for (int i = 0; i < n; ++i)
        a[i] = v[i];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            q[i][j] = maxinter(a[i], a[j]);
        }
    }

    int s = 0;
    for (int i = 0; i < n; ++i)
        s += sz(a[i]);
    int ans = s;
    vector<int> p;
    for (int i = 0; i < n; ++i)
        p.push_back(i);
    do
    {
        int yans = s;
        for (int i = 0; i < n - 1; ++i)
            yans -= q[p[i]][p[i + 1]];
        ans = min(ans, yans);
    } while (next_permutation(all(p)));

    cout << ans << "\n";
}

int main()
{
    freopen("in.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}
