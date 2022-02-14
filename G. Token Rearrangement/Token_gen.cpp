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
		int n;
		if (x < 15) {
			n = rand(1000, 5000);
		} else {
			n = rand(4000, 5000);
		}
		fout << n << "\n";

		set<int> s;
		while (s.size() != n) {
			s.insert(rand(1ll, (int)1e9));
		}

		s.insert(0);

		vector<int> v(n + 1);

		int j = 0;

		for (auto x : s) {
			v[j++] = x;
		}

		auto shuffle = [&](vector<int> &x) {
			int sz = x.size();
			for (int i = 0; i < sz - 1; i++) {
				int j = i + rand() % (sz - i);
				swap(x[i], x[j]);
			}

			return;
		};

		shuffle(v);

		for (auto x : v) {
			fout << x << " ";
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



