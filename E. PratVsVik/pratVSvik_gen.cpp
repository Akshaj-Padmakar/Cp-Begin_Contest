#include<bits/stdc++.h>
using namespace std;
#define int long long


int rand(int  a, int b) {
	// x = [a,b]
	return a + rand() % (b - a + 1);
}

ifstream fin;
ofstream fout;

vector<int> pw2;

void solve(int x) {
	string a = to_string(x);
	if (a.size() < 2) {
		a = '0' + a;
	}

	fout.open("input" + a + ".txt");

	int T = 1e5;

	fout << T << "\n";

	for (int i = 0; i < T; i++) {
		int swi = rand(0, 1);

		if (swi) {
			fout << pw2[rand(0ll, 59)] << "\n";
		} else {
			fout << rand(1, 1e9)*rand(1, 1e9) << "\n";
		}
	}
	fout.close();
}

signed main() {
	srand (time (0));  // needs ctime header
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 60; i++) {
		pw2.push_back((1ll << i));
	}

	int t = 1;

	cin >> t;

	for (int i = 0; i < t; i++) {
		solve(i);
	}

}



