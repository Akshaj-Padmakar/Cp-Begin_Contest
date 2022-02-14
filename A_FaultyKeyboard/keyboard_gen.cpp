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

	int T = 100;
	fout << T << "\n";

	for (int i = 0; i < T; i++) {
		/*
		Print a particular testcase
		*/
		int n = 100;

		fout << n << "\n";
		for (int j = 0; j < n; j++) {
			int y = rand(0, 25);
			fout << (char)('A' + y);
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



