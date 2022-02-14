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

	int T = 2;

	fout << T << "\n";

	for (int i = 0; i < T; i++) {
		int n = rand(1, 1e5), k = rand(1, 300);
		fout << n << " " << k << "\n";

		for (int j = 0; j < n; j++) {
			fout << rand(1ll, (int)1e6) << " ";
		}
		fout << "\n";
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



