#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6+2;

vector<int> spf;

void sieve() {
    spf.resize(MAXN);
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        spf[i] = i;
    }
    for (int i = 4; i < MAXN; i += 2) {
        spf[i] = 2;
    }
    for (int i = 3; i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}
void pfactor(int x, vector<int> &pfac) {
    while (x != 1) {
        pfac.push_back(spf[x]); x = x / spf[x];
    }
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    map<int, int> mp;

    for (auto x : v) {
        vector<int> z;
        pfactor(x, z);

        for (auto y : z) {
            mp[y]++;
        }
    }

    vector<int> a;

    for (auto [x, f] : mp) {
        a.push_back(f);
    }

    n = a.size();
    int sm = 0;
    for (auto a : a) {
        sm += a;
    }

    int r = sm / k + 2, l = 0;

    auto check = [&](int md) {
        int sm = 0;
        for (auto x : a) {
            sm += min(x, md);
        }
        return sm >= md * k;
    };

    while (r - l > 1) {
        int md = (r + l) >> 1ll;
        if (check(md)) {
            l = md;
        } else {
            r = md - 1;
        }
    }
    cout << (check(r) ? r : l) << "\n";
}

signed main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #else
// #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    sieve();

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    // cerr << "Time elapsed: " << ((long double)clock() / CLOCKS_PER_SEC) << " s.\n";
}
