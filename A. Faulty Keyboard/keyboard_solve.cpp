#include<bits/stdc++.h>
using namespace std;
#define int long long


int rand(int  a, int b) {
	// x = [a,b]
	return a + rand() % (b - a + 1);
}

ifstream fin;
ofstream fout;

void solve2() {
	/*
	The logic of the problem
	*/
	int n;
	fin >> n;

	string s;
	fin >> s;

	for (int i = 0; i < n; i++) {
		int z = (s[i] - 'A');
		fout << (char)('A' + (25 - z));
	}
	fout << "\n";
}


void solve(int x) {
	string a = to_string(x);
	if (a.size() < 2) {
		a = '0' + a;
	}

	fin.open("input" + a + ".txt");
	fout.open("output" + a + ".txt");

	int T;
	fin >> T;
	for (int i = 0; i < T; i++) {
		solve2();
	}
	fout.close();
	fin.close();
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