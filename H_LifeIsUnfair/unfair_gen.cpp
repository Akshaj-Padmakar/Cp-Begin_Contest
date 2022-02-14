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
		/*
		Print a particular testcase
		*/
		int n;
		if (x < 5) {
			n = rand(1, 5);
		} else if (x < 10) {

			n = rand(6, 10);
		} else if (x < 15) {
			n = rand(11, 16);
		} else {
			n = 18;
		}

		fout << n << "\n";

		for (int i = 0; i < n; i++) {
			fout << rand(1, 1e6) << " ";
		}
		fout << "\n";

		for (int i = 0; i < n; i++) {
			fout << rand(1, 1e6) << " ";
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
	/*
	the number of files you want
	*/

	for (int i = 0; i < t; i++) {
		solve(i);
	}

}



