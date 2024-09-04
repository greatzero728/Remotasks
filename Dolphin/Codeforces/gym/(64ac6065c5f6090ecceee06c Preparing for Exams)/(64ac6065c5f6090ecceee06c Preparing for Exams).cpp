#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

using DO = double;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) {
		DO oa, od, oda, obc; scanf("%lf %lf %lf %lf", &oa, &od, &oda, &obc);
		DO sin_al = 2 * oda / oa / od;
		DO oc_ob = 2 * obc / sin_al;
		DO oc = sqrt(oc_ob * oa / od);
		DO ob = oc * od / oa;
		printf("%.7lf %.7lf\n", oc - od, ob - oa);
	}
	return 0;
}
