#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#pragma warning (disable : 4996)

using namespace std;

vector <int> bus[100];
bool used[100];


const int N = 1100, INF = 1e9;


int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
	freopen("buses.in", "r", stdin);
	freopen("buses.out", "w", stdout);
#endif
	
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int cur_m;
		scanf("%d", &cur_m);
		for (int j = 0; j < cur_m; j++)
		{
			int x;
			scanf("%d", &x);
			used[x] = true;
			bus[i].push_back(x);
		}
	}
	int p;
	scanf("%d", &p);
	for (int i = 0; i < p; i++)
	{
		int start, cur_m;
		scanf("%d %d", &start, &cur_m);
		if (!used[start])
		{
			printf("0 0\n");
			for (int j = 0; j < cur_m; j++)
			{
				int non;
				scanf("%d", &non);
			}
			continue;
		}
		int t = 0, cur_stop = start;
		for (int j = 0; j < cur_m; j++)
		{
			int c;
			scanf("%d", &c);
			for (; ; t++)
			{
				bool f = false;
				for (int jj = 0; jj < m; jj++)
				{
					if (cur_stop == bus[jj][t % bus[jj].size()])
					{
						cur_stop = bus[jj][(t + c) % bus[jj].size()];
						t += c + 1;
						f = true;
						break;
					}
				}
				if (f)
				{
					break;
				}
			}
		}
		if (t == 0)
		{
			printf("%d %d", 0, cur_stop);
			continue;
		}
		printf("%d %d\n", t - 1, cur_stop);
	}
	return 0;
}