#include<bits/stdc++.h>
using namespace std;

#define int long long


int rand(int  a, int b) {
	// x = [a,b]
	return a + rand() % (b - a + 1);
}

ifstream fin;
ofstream fout;

const int INF = 1e9;

void solve2() {
	int n;
	fin >> n;

	vector<int> a(n), b(n);

	for (auto &x : a) {
		fin >> x;
	}

	for (auto &x : b) {
		fin >> x;
	}

	vector<vector<int>> dp(n, vector<int>(1ll << n, INF));
	//dp[i][msk] -> stores the number of moves needed -> states are , the last card is i and msk={1010110} this set has been used till now

	for (int i = 0; i < n; i++) {
		dp[i][1ll << i] = i;
	}


	for (int msk = 0; msk < 1ll << n; msk++) {
		for (int j = 0; j < n; j++) {
			if (msk & (1ll << j)) {
				// so we the jth card last
				int on = __builtin_popcount(msk) - 1;// 0-index
				int cur = (abs(on - j)) % 2 == 0 ? a[j] : b[j];

				int cnt = 0;
				for (int k = 0; k < n; k++) {
					if (!(msk & (1ll << k))) {
						int nxt = (abs((on + 1) - k)) % 2 == 0 ? a[k] : b[k];

						if (nxt >= cur) {
							dp[k][msk | 1ll << k] = min(dp[k][msk | 1ll << k], dp[j][msk] + cnt);
							//current array -> 000000111111
							//1 = used 0 = unused
						}
						cnt++;
					}
				}
			}
		}
	}

	int ans = INF;

	for (int i = 0; i < n; i++) {
		ans = min(ans, dp[i][(1ll << n) - 1]);
	}

	fout << (ans == INF ? -1 : ans) << "\n";
}


void solve(int x) {
	string a = to_string(x);
	if (a.size() < 2) {
		a = '0' + a;
	}

	fin.open("input" + a + ".txt");
	fout.open("output" + a + ".txt");

	int T = 1;
	// fin >> T;
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



