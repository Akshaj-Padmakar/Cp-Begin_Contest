#include<bits/stdc++.h>
using namespace std;
#define int long long


int rand(int  a, int b) {
    // x = [a,b]
    return a + rand() % (b - a + 1);
}

ifstream fin;
ofstream fout;

bool ispower2(int x) {return x && (!(x & (x - 1)));}

void solve2() {
    int n; fin >> n;
    if (n == 1) {
        fout << "Vik\n";
        return;
    } else {
        fout << (ispower2(n) ? "Vik\n" : "Prat\n");
    }
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



