#include<bits/stdc++.h>
using namespace std;
#define int long long


int rand(int  a, int b) {
	// x = [a,b]
	return a + rand() % (b - a + 1);
}

ifstream fin;
ofstream fout;

struct dsu {
public:
	dsu(int n) : _n(n), par_or_sz(n, -1) {}

	int find(int a) {
		assert(0 <= a && a < _n);
		if (par_or_sz[a] < 0) {
			return a;
		}
		return par_or_sz[a] = find(par_or_sz[a]);
	}

	int size(int a) {
		assert(0 <= a && a < _n);
		return -par_or_sz[find(a)];
	}

	int merge(int a, int b) {
		assert(0 <= a && a < _n);
		assert(0 <= b && b < _n);
		int x = find(a), y = find(b);

		if (x == y) {
			return x;
		}
		if (-par_or_sz[x] < -par_or_sz[y]) {
			swap(x, y);
		}
		par_or_sz[x] += par_or_sz[y];
		par_or_sz[y] = x;
		return x;
	}

	bool same(int a, int b) {
		assert(0 <= a && a < _n);
		assert(0 <= b && b < _n);
		return find(a) == find(b);
	}

	vector<vector<int>> groups() {
		vector<int> leader_buf(_n), group_size(_n);
		for (int i = 0; i < _n; i++) {
			leader_buf[i] = find(i);
			group_size[leader_buf[i]]++;
		}
		vector<vector<int>> result(_n);
		for (int i = 0; i < _n; i++) {
			result[i].reserve(group_size[i]);
		}
		for (int i = 0; i < _n; i++) {
			result[leader_buf[i]].push_back(i);
		}
		result.erase(remove_if(result.begin(), result.end(), [&](const vector<int>& v) { return v.empty(); }), result.end());
		return result;
	}

private:
	int _n;
	vector<int> par_or_sz;
	// root node: -1 * component size
	// otherwise: parent
};


void solve2() {
	int n;
	fin >> n;

	vector<int> v(n + 1);

	for (int i = 0; i < n + 1; i++) {
		fin >> v[i];
	}

	auto coo_compress = [&](vector<int> &x) {
		// coordinates compresse x and over-writes on it !
		int sz = x.size(), id = 0;
		map<int, int> mp;

		for (int i = 0; i < sz; i++) {
			mp[x[i]] = 1;
		}

		for (auto x : mp) {
			mp[x.first] = id++;
		}

		for (int i = 0; i < sz; i++) {
			x[i] = mp[x[i]];
		}
	};

	coo_compress(v);

	const int INF = 1e10;

	int ans = INF;
	for (int i = 0; i < n + 1; i++) {
		vector<int> final;
		for (int j = 0; j < i; j++) {
			final.push_back(j + 1);
		}
		final.push_back(0);

		for (int j = i; j < n; j++) {
			final.push_back(j + 1);
		}
		dsu ds(n + 1);

		for (int j = 0; j <= n; j++) {
			ds.merge(v[j], final[j]);
		}

		int cur = 0;
		auto vik = ds.groups();
		for (auto cycle : vik) {
			if (cycle.size() > 1) {
				bool b = 0;
				for (auto z : cycle) {
					if (z == 0)b = 1;
				}
				cur += cycle.size() + (b ? -1 : 1);
			}
		}
		ans = min(ans, cur);
	}

	fout << ans << "\n";
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



