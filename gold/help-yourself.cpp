/*
 * Problem: Help Yourself
 * Platform: https://usaco.org/index.php?page=viewproblem2&cpid=1018
 * Difficulty: Normal 
 * 
 * Trick/Note to remember: It's important to understand how a single segment
 * can start a new component; make sure there are no "bridges" that may eat
 * up the current segment; use Difference Arrays to calculate the bridges
 */

#include <bits/stdc++.h>

using namespace std;

const string PROBLEM_NAME = "help";

const int NMAX = 1e5;
const int MOD = 1e9 + 7;

int prec[NMAX + 1];

void precalculate() {
    prec[0] = 1;
    for (int i = 1; i <= NMAX; i++) {
        prec[i] = 2LL * prec[i - 1] % MOD;
    }
}

struct Segment {
    int l, r;  
} segments[NMAX + 1];

int n, diff[2 * NMAX + 2], pref[2 * NMAX + 1];

void solve() {
    precalculate();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> segments[i].l >> segments[i].r;
        diff[segments[i].l]++;
        diff[segments[i].r]--;
    }

    for (int i = 1; i <= 2 * n; i++) {
        pref[i] += pref[i - 1] + diff[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = segments[i].l;
        int c = pref[l - 1];
        ans = (ans + prec[n - 1 - c]) % MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef LOCAL
    freopen((PROBLEM_NAME + ".in").c_str(), "r", stdin);
    freopen((PROBLEM_NAME + ".out").c_str(), "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
