#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

int k;
int n, s, t;
vector<int> vertex;
long long len, l, r, old;


void quit(bool t)
{
	cout << "answer " << (!t ? "impossible" : "ok") << endl;
	exit(0);
}

long long quary(bool t, int i, int j, long long w)
{
	cout << (t ? "add " : "delete ") << vertex[i] << " " << vertex[j] << " " << w << endl;
	long long ans = 0;
	cin >> ans;
	return ans;
}


int main()
{
	cin >> n >> s >> t;
	cin >> l >> r;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		vertex.push_back(x);
	}
	len = quary(1, 0, 1, r);
	if (len < l) quit(0);
	if (len <= r) quit(1);
	len = quary(0, 0, 1, r);
	for (int i = 1; i < k; i++)
	{
		len = quary(1, 0, i, 0);
		if (l <= len && len <= r) quit(1);
	}
	if (len > r) quit(0);
	old = len;
	for (int i = 1; i < k; i++)
	{
		len = quary(0, 0, i, 0);
		if (l <= len && len <= r) quit(1);
		len = quary(1, 0, i, r);
		if (l <= len && len <= r) quit(1);
		if (len > r) 
		{
			len = quary(0, 0, i, r);
			len = quary(1, 0, i, l - old);
			if (l <= len && len <= r) quit(1);
		}
		old = len;  
	}
}
