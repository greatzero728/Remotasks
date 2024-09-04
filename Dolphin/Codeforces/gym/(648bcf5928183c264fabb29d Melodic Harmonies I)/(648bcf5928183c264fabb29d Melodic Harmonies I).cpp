#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;
using DO = long double;

DO s = powl(2, 1./12), eps = 1e-4;

int calc(DO x) {
	if(219 < x && x < 221) return 1;
	if(232 < x && x < 234) return 2;
	if(245 < x && x < 247) return 3;
	if(260 < x && x < 262) return 4;
	if(276 < x && x < 278) return 5;
	if(292 < x && x < 294) return 6;
	if(310 < x && x < 312) return 7;
	if(328 < x && x < 330) return 8;
	if(348 < x && x < 350) return 9;
	if(368 < x && x < 370) return 10;
	if(390 < x && x < 392) return 11;
	if(414 < x && x < 416) return 12;
	if(439 < x && x < 441) return 13;
	if(465 < x && x < 467) return 14;
	if(492 < x && x < 494) return 15;
	if(522 < x && x < 524) return 16;
	if(553 < x && x < 555) return 17;
	if(586 < x && x < 588) return 18;
	if(621 < x && x < 623) return 19;
	if(658 < x && x < 660) return 20;
	if(698 < x && x < 699) return 21;
	if(738 < x && x < 740) return 22;
	if(782 < x && x < 784) return 23;
	if(829 < x && x < 831) return 24;
	if(879 < x && x < 881) return 25;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int ans = 0, n; scanf("%d", &n);
	while(n--) {
		DO x, y; cin>>x>>y;
		ans += abs(calc(x) - calc(y));
	}
	printf("%d\n", ans);
}