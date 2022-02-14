#include<bits/stdc++.h>
using namespace std;
#define int long long


int rand(int  a, int b) {
    // x = [a,b]
    return a + rand() % (b - a + 1);
}

ifstream fin;
ofstream fout;

const int MAXN = 1e6 + 5;

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

void solve2() {
    int n, k;
    fin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        fin >> v[i];
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
    fout << (check(r) ? r : l) << "\n";
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

    sieve();
    int t = 1;

    cin >> t;

    for (int i = 0; i < t; i++) {
        solve(i);
    }

}



