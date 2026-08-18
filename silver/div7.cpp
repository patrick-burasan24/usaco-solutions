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

const string problem_name = "div7";

void solve() {
    int N, id;
    map<int, int> M;

    cin >> N;
    int sum = 0;
    int ans = 0;
    M[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> id;
        sum = (sum + id) % 7;
        if (M.find(sum) == M.end()) {
            M[sum] = i;
        }
        else {
            ans = max(ans, i - M[sum]);
        }
    }

    cout << ans << '\n';
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