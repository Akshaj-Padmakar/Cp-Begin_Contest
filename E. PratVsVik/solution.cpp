#include <bits/stdc++.h>
using namespace std;

#define int long long

bool ispower2(int x) {return x && (!(x & (x - 1)));}

void solve() {
    int n; cin >> n;
    cout << (ispower2(n) ? "Vik\n" : "Prat\n");
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    // cerr << "Time elapsed: " << ((long double)clock() / CLOCKS_PER_SEC) << " s.\n";
}

