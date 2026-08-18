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

const string problem_name = "hps";

enum {
    HOOF,
    PAPER,
    SCISSORS
};

array<vector<int>, 3> wins_by;
int N;
char fj;

void solve() {
    cin >> N;
    wins_by[HOOF].resize(N + 1, 0);
    wins_by[PAPER].resize(N + 1, 0);
    wins_by[SCISSORS].resize(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> fj;
        if (fj == 'H') wins_by[PAPER][i]++;
        else if (fj == 'P') wins_by[SCISSORS][i]++;
        else wins_by[HOOF][i]++;

        wins_by[HOOF][i] += wins_by[HOOF][i - 1];
        wins_by[PAPER][i] += wins_by[PAPER][i - 1];
        wins_by[SCISSORS][i] += wins_by[SCISSORS][i - 1];
    }

    int ans = -1;
    for (int i = 1; i <= N; i++)
        for (int first_choice = 0; first_choice < 3; first_choice++)
            for (int final_choice = 0; final_choice < 3; final_choice++)
                if (first_choice != final_choice)
                    ans = max(ans, wins_by[first_choice][i - 1] + wins_by[final_choice][N] - wins_by[final_choice][i - 1]);
    
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