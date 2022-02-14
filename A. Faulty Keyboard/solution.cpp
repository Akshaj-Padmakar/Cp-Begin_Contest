#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        int z = (s[i] - 'A');
        cout << (char)('A' + (25 - z));
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}
