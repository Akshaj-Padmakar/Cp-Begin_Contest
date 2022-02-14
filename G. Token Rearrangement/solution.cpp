#include <bits/stdc++.h>
using namespace std;

#define int long long

struct dsu {
    dsu(int _n) {
        n = _n;
        par.assign(n + 1, 0);
        sz.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int find(int v) {
        if (v == par[v]) {
            return v;
        }
        return par[v] = find(par[v]);
    }

    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) {
            return;
        }
        if (sz[u] > sz[v]) {
            swap(u, v);
        }
        par[u] = v;
        sz[v] += sz[u];
    }
    bool same(int u, int v) {
        return find(u) == find(v);
    }

    void groups(vector<vector<int>> &grp) {
        vector<vector<int>> temp(n);
        for (int i = 0; i < n; i++ ) {
            temp[find(i)].push_back(i);
        }

        for (int i = 0; i < n; i++) {
            if (temp[i].size() >= 1) {
                grp.push_back(temp[i]);
            }
        }
    }
private:
    int n;
    vector<int> par, sz;
};

void solve() {
    int n;
    cin >> n;

    vector<int> v(n + 1);

    for (int i = 0; i < n + 1; i++) {
        cin >> v[i];
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
        vector<vector<int>> vik; ds.groups(vik);
        
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

    cout << ans << "\n";
}

signed main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #else
// #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    // cerr << "Time elapsed: " << ((long double)clock() / CLOCKS_PER_SEC) << " s.\n";
}

