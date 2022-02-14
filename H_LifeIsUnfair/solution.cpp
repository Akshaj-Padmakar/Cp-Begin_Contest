#include <bits/stdc++.h>
using namespace std;

// #define long long long long

const long long INF = 1e9;

void solve() {
    long long n;
    cin >> n;

    vector<long long> a(n), b(n);

    for (auto &x : a) {
        cin >> x;
    }

    for (auto &x : b) {
        cin >> x;
    }

    vector<vector<long long>> dp(n, vector<long long>(1ll << n, INF));
    /*
    let, y(msk) = number of switched on bits in msk
    msk represents a set, each bit which is switched on indicates that the column has been used in the prefix of length y, i-th is the last column in this prefix
    */

    for (long long i = 0; i < n; i++) {
        dp[i][1ll << i] = i;// just placing the ith column at the 1st place = i swaps needed
    }


    for (long long msk = 0; msk < 1ll << n; msk++) {
        for (long long j = 0; j < n; j++) {
            if (msk & (1ll << j)) {
                long long on = __builtin_popcount(msk) - 1;
                long long cur = (abs(on - j)) % 2 == 0 ? a[j] : b[j];//Only the final and long longial postion of the column is needed to determine whether the 1st element of the column or the 2nd element of the column is on the top.

                long long cnt = 0;
                for (long long k = 0; k < n; k++) {
                    if (!(msk & (1ll << k))) {
                        // we place the kth column next to the ith column in the final array
                        long long nxt = (abs((on + 1) - k)) % 2 == 0 ? a[k] : b[k];// again only the long longial and final position matters

                        if (nxt > cur) {
                            dp[k][msk | 1ll << k] = min(dp[k][msk | 1ll << k], dp[j][msk] + cnt);// all the columns that has not been used yet , there relative ordering wont change !{relative ordering changes only when there is some b/w the two columns}
                        }
                        cnt++;
                    }
                }
            }
        }
    }

    long long ans = INF;

    for (long long i = 0; i < n; i++) {
        ans = min(ans, dp[i][(1ll << n) - 1]);//1ll<<n-1 = all the bits on => all the columns has been used and the ith column is the last column
    }

    cout << (ans == INF ? -1 : ans) << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

}

