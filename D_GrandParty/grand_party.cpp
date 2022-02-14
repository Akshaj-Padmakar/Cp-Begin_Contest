#include<bits/stdc++.h>
using namespace std;
#define int long long


int rand(int  a, int b) {
	// x = [a,b]
	return a + rand() % (b - a + 1);
}

ifstream fin;
ofstream fout;

void solve(int x) {
	string a = to_string(x);
	if (a.size() < 2) {
		a = '0' + a;
	}

	fout.open("input" + a + ".txt");

	int T = 1;

	// fout << T << "\n";

	for (int i = 0; i < T; i++) {
		int n, m, k;
		if (x < 10) {
			n = rand(1e5, 2 * 1e5);
			m = rand(1e2, 2e2);
			k = rand(1e2, 2e2);
		} else if (x < 15) {
			n = rand(1e5, 2 * 1e5);
			m = rand(1e3, 1e4);
			k = rand(1, 1e2);
		} else if (x < 20) {
			n = rand(1e5, 2 * 1e5);
			m = rand(1e5, 2 * 1e5);
			k = rand(1e4, 2e5);
		} else if (x < 25) {
			n = rand(1e5, 2 * 1e5);
			m = rand(1e3, 2e3);
			k = rand(1e3, 2e3);
		} else {
			n = rand(1e5, 2 * 1e5);
			m = rand(1e4, 2e4);
			k = rand(1, 10);
		}
		fout << n << " " << m << " " << k << "\n";
	}
	fout.close();
}

signed main() {
	srand (time (0));  // needs ctime header
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;

	cin >> t;

	for (int i = 0; i < t; i++) {
		solve(i);
	}

}



