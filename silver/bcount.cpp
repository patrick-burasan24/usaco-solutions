/**
 * [ 熟能生巧 - Practice makes perfect! ]
 * With love by patrick_burasan
 */

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define dbg(...) "马到成功"
#endif /// LOCAL

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

const string problem_name = "bcount";

array<vector<int>, 3> cows;
int N, Q, x, a, b;

void solve() {
    cin >> N >> Q;
    cows[0].resize(N + 1, 0);
    cows[1].resize(N + 1, 0);
    cows[2].resize(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> x;
        cows[x - 1][i]++;
        cows[0][i] += cows[0][i - 1];
        cows[1][i] += cows[1][i - 1];
        cows[2][i] += cows[2][i - 1];
    }

    while (Q--) {
        cin >> a >> b;
        cout << cows[0][b] - cows[0][a - 1] << ' ';
        cout << cows[1][b] - cows[1][a - 1] << ' ';
        cout << cows[2][b] - cows[2][a - 1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((problem_name + ".in").c_str(), "r", stdin);
    freopen((problem_name + ".out").c_str(), "w", stdout);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
/**
         ,      \    /       ,        
        / \    )\__/(      / \       
       /   \  (_\  /_)    /   \      
  ____/_____\__\@  @/___/_____\____ 
 |             |\../|              |
 |              \VV/               |
 |       -------必过-------        |
 |_________________________________|
  |    /\ /      \       \ /\    | 
  |  /   V        ))       V   \  | 
  |/     `        //        '     \| 
  `               V                '
 */