#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for (int i = (a); i <= (b); i++)

typedef long long ll;
typedef long double dbl;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("sweets.in", "r", stdin);
    freopen("sweets.out", "w", stdout);
#endif
	
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int x0 = n / (3 * a);
	int y0 = n / (3 * b);
	int z0 = n / (3 * c);
	int res[] = { x0, y0, z0 };
	dbl best = (ll)x0 * y0 * z0, tmp;
	int best_shift = 0;

	int p[] = { 0, 1, 2 };
	int A[] = { a, b, c };
	do
	{
		const int M = 500;
		int a = A[p[0]], b = A[p[1]], c = A[p[2]];
		int x0 = n / (3 * a);
		forab(x, x0 - M, x0 + M)
			if (1 <= x && (ll)x * a <= n)
			{
				int n0 = n - x * a;
				int y0 = n0 / (2 * b);
				forab(y, y0 - M, y0 + M)
					if (1 <= y && (ll)y * b <= n0)
					{
						int z = (n0 - y * b) / c;
						int shift = max(abs(x - x0), abs(y - y0));
						if ((tmp = (dbl)x * y * z) > best || (tmp == best && best_shift > shift))
						{
							best = tmp;
							best_shift = shift;
							res[p[0]] = x;
							res[p[1]] = y;
							res[p[2]] = z;
						}
					}
			}
	} while (next_permutation(p, p + 3));

	cout << a * res[0] << " " << b* res[1] << " " << c* res[2] << '\n';
	return 0;
}