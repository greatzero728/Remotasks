#include <bits/stdc++.h>

using namespace std;

vector<int> alturas, v1, v2;
vector<int> seg;
int n;

void preprocess() {
	v1 = vector<int>(alturas.size());
	v2 = vector<int>(alturas.size());
	vector<int> stackTubos;
	stackTubos.push_back(0);
	int litrosActuales = alturas[0];
	v1[0] = alturas[0];
	int siguienteTubo = 1;
	int nivelAgua = 0;
	while(stackTubos.size()) {
		int tuboActual = stackTubos[stackTubos.size()-1];
		
		if (siguienteTubo == n-1 || alturas[tuboActual] < alturas[siguienteTubo]) {
			stackTubos.pop_back();
			
			int numVasos = siguienteTubo-tuboActual;
			litrosActuales += (alturas[tuboActual] - nivelAgua)*numVasos;
			nivelAgua = alturas[tuboActual];
			v2[tuboActual] = litrosActuales;
			
			if (stackTubos.empty() && siguienteTubo < n-1) {
				litrosActuales = (siguienteTubo+1) * alturas[siguienteTubo];
				nivelAgua = 0;
				v1[siguienteTubo] = litrosActuales;
				stackTubos.push_back(siguienteTubo);
				siguienteTubo++;
			}
		}
		else if (alturas[tuboActual] == alturas[siguienteTubo]) {
			stackTubos.pop_back();
			stackTubos.push_back(siguienteTubo);
			
			int numVasos = siguienteTubo-tuboActual;
			litrosActuales += (alturas[tuboActual] - nivelAgua) * numVasos;
			nivelAgua = 0;
			
			v2[tuboActual] = v1[siguienteTubo] = litrosActuales;
			siguienteTubo++;
		}
		else {
			stackTubos.push_back(siguienteTubo);
			
			int numVasos = siguienteTubo-tuboActual;
			litrosActuales += (alturas[siguienteTubo] - nivelAgua) * numVasos;
			nivelAgua = 0;
			v1[siguienteTubo] = litrosActuales;
			siguienteTubo++;
		}
	} 
}

void makeTree(int x, int L, int R) {
	if (L < R) {
		int mid = L + (R-L)/2;
		makeTree(2*x, L, mid);
		makeTree(2*x+1, mid+1, R);
		if (v2[seg[2*x]] >= v2[seg[2*x+1]]) seg[x] = seg[2*x];
		else seg[x] = seg[2*x+1];
	}
	else seg[x] = L;
}

int tuboIzquierdaRec(int x, int L, int R, int vasoUB, int aguaEchada) {
	if (L >= vasoUB || v2[seg[x]] <= aguaEchada) return -1;
	if (L == R) {
		if (v2[seg[x]] > aguaEchada) return seg[x];
		return -1;
	}
	int mid = L + (R-L)/2;
	int rInd = tuboIzquierdaRec(2*x+1, mid+1, R, vasoUB, aguaEchada);
	if (rInd != -1) return rInd;
	return tuboIzquierdaRec(2*x, L, mid, vasoUB, aguaEchada);
}

int tuboIzquierda(int vasoUB, int aguaEchada) {
	return tuboIzquierdaRec(1, 0, n-2, vasoUB, aguaEchada);
}

int tuboDerechaRec(int x, int L, int R, int vasoLB, int aguaEchada) {
	if (R < vasoLB || v2[seg[x]] <= aguaEchada) return -1;
	if (L == R) {
		if (v2[seg[x]] > aguaEchada) return seg[x];
		return -1;
	}
	int mid = L + (R-L)/2;
	int lInd = tuboDerechaRec(2*x, L, mid, vasoLB, aguaEchada);
	if (lInd != -1) return lInd;
	return tuboDerechaRec(2*x+1, mid+1, R, vasoLB, aguaEchada);
}

int tuboDerecha(int vasoLB, int aguaEchada) {
	return tuboDerechaRec(1, 0, n-2, vasoLB, aguaEchada);
}

int cantidadEnElVaso(int aguaEchada, int vaso) {
	if (aguaEchada == 0) return 0;
	if ((vaso == 0 && aguaEchada == 0) || (vaso > 0 && v1[vaso-1] > aguaEchada)) return 0;
	int tuboDer = tuboDerecha(vaso, aguaEchada);
	if (tuboDer != -1 && v1[tuboDer] <= aguaEchada) return alturas[tuboDer];
	else {
		int tuboIzq = tuboIzquierda(vaso, aguaEchada);
		if (tuboIzq == -1) {
			if (tuboDer == -1) return aguaEchada/n;
			else return aguaEchada/(tuboDer+1);
		}
		else if (tuboDer == -1) {
			return (aguaEchada - v1[tuboIzq])/(n - tuboIzq - 1);
		}
		else {
			return (aguaEchada - v1[tuboIzq])/(tuboDer - tuboIzq);
		}
	}
}

int main() {
	int q, x, j, F;
	cin >> n;
	alturas = vector<int>(n-1);
	for (int i = 0; i < n-1; i++) cin >> alturas[i];
	preprocess();
	seg = vector<int>(4*n);
	makeTree(1, 0, n-2);
	cin >> q >> F;
	int C = 0;
	while(q--) {
		cin >> x >> j;
		if (F == 2) x -= C;
		C = cantidadEnElVaso(x, j-1);
		cout << C << '\n';
	}
	return 0; 
}