#include<bits/stdc++.h>
using namespace std;
#define int long long


int rand(int  a, int b) {
    // x = [a,b]
    return a + rand() % (b - a + 1);
}

ifstream fin;
ofstream fout;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

int add(int a, int b, int c = MOD) {int res = a + b; return (res >= c ? res % c : res);}
int sub(int a, int b, int c = MOD) {int res; if (abs(a - b) < c)res = a - b; else res = (a - b) % c; return (res < 0 ? res + c : res);}
int mul(int a, int b, int c = MOD) {int res = (long long)a * b; return (res >= c ? res % c : res);}

template<typename T>T binpow(T e, T n) {T x = 1, p = e; while (n) {if (n & 1)x = x * p; p = p * p; n >>= 1;} return x;}
template<typename T>T binpow2(T e, T n, T m = MOD) {T x = 1, p = e; while (n) {if (n & 1)x = mul(x, p, m); p = mul(p, p, m); n >>= 1;} return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y) {
    T xx = 0, yy = 1; y = 0; x = 1; while (b) {
        T q = a / b, t = b; b = a % b; a = t; \
        t = xx; xx = x - q * xx; x = t; t = yy; yy = y - q * yy; y = t;
    } return a;
}
template<typename T>T mod_inverse(T a, T n = MOD) {T x, y, z = 0; T d = extended_euclid(a, n, x, y); return (d > 1 ? -1 : sub(x, z, n));}

int ncr_modp(int n, int k, int c = MOD) {
    //O(k)
    if (n < k) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }

    int res = 1;

    if (k > n - k) {
        k = n - k;
    }
    for (int i = 0; i < k; ++i) {
        res = mul(res, n - i, c);
        res = mul(res, binpow2(i + 1, c - 2, c), c);
    }
    return res;
}

void solve2() {
    int n, m, k;
    fin >> n >> m >> k;

    if (n - m - m * k < 0) {
        fout << 0 << "\n";
        return;
    }
    int x = 1;
    for (int i = 1; i <= m - 1; i++) {
        x = mul(x, i);
    }
    fout << mul(x, mul(n, ncr_modp(n - m * (k + 1) + m - 1, m - 1))) << "\n";
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



