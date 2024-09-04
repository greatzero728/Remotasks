#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using UINT = unsigned long long;
using pii = pair<int, int>;

unsigned long long k1, k2;
unsigned long long CoronavirusBeats() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

const int NN = 101010;

struct Data {
	UINT x, y, z; int id;
	Data(UINT x = 0, UINT y = 0, UINT z = 0, int id = 0) : x(x), y(y), z(z), id(id) {}
} ;

Data p[NN];
int ans[NN], vst[NN], runs;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, N;
	scanf("%d %I64u %I64u", &n, &k1, &k2), N = n;
	for(int i = n; i--; ) {
		p[i].x = CoronavirusBeats();
		p[i].y = CoronavirusBeats();
		p[i].z = CoronavirusBeats();
		p[i].id = i;
	}
	
	sort(p, p + n, [&](Data a, Data b) {
		return (a.x >> 2) + (a.y >> 2) + (a.z >> 2) < (b.x >> 2) + (b.y >> 2) + (b.z >> 2);
	});
	
	int step = 0;
	for(; ; step++) {
		runs++;
		for(int i = 0; i < n; i++) {
			bool can_survive = 0;
			for(int j = 0, ed = min(i, 100000); j < ed; j++) if(p[j].x <= p[i].x && p[j].y <= p[i].y && p[j].z <= p[i].z) {
				if(p[j].x < p[i].x || p[j].y < p[i].y || p[j].z < p[i].z) {
					can_survive = 1; break;
				}
			}
//			if(!can_survive) for(int k = 0, ed = min(i, 1000), j; j = i - 1 - k, k < ed; k++) if(p[j].x <= p[i].x && p[j].y <= p[i].y && p[j].z <= p[i].z) {
//				if(p[j].x < p[i].x || p[j].y < p[i].y || p[j].z < p[i].z) {
//					can_survive = 1; break;
//				}
//			}
			if(can_survive) vst[i] = runs;
			else ans[p[i].id] = step;
		}
		
		int nn = 0;
		for(int i = 0; i < n; i++) {
			if(vst[i] == runs) p[nn++] = p[i];
		}
		if(!nn) break;
		n = nn;
	}
	printf("%d\n", step + 1);
	for(int i = N; i--; ) printf("%d ", ans[i]);
	return 0;
}