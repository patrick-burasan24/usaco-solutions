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

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> a(2 * N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        a[i] %= M;
    }
    sort(a.begin(), a.begin() + N + 1);

    for (int i = N + 1; i <= 2 * N; i++) {
        a[i] = a[i - N] + M;    
    }
    
    vector<i64> pref(2 * N + 1, 0LL);
    for (int i = 1; i <= 2 * N; i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    i64 ans = numeric_limits<i64>::max();
    int med = N / 2;
    for (int i = 1; i <= N; i++) {
        i64 lhs = pref[med + i - 1] - pref[i - 1];
        i64 rhs = pref[N + i - 1] - pref[N - med + i - 1];
        ans = min(ans, rhs - lhs);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

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