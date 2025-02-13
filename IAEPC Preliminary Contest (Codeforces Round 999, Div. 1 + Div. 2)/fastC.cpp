#include <bits/stdc++.h>

using namespace std;

int a[static_cast<int>(2e5 + 1)];
int dp[static_cast<int>(2e5 + 1)]; // dp[i] corresponds to the number of valid ways a i length sequence of valid people end at a honest person

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 0;
    }

    dp[0] = 1;
    dp[1] = a[1] == 0 ? 1 : 0;

    /* We want to find dp[i]. We fix the fact that current person is honest. We take two cases.
        1. When previous is honest -> When a[i] = a[i-1]. As current person is honest, a[i] is no of liars. This must be equal to a[i-1]
            In this case, just add dp[i-1] to dp[i]
        2. When previous is liar -> If previous guy is liar, previous previous guy must be honest. a[i] = 1 + a[i-2]
            In this case, add dp[i-2] to dp[i
    ]*/

    // if (n == 1) {
    //     if (a[1] == 0) {
    //         cout << 2 << endl;
    //     } else {
    //         cout << 0 << endl;
    //     }
    //     return;
    // }

    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i-1]) {
            dp[i] += dp[i-1];
        }

        if (a[i] == 1 + a[i-2]) {
            dp[i] += dp[i-2];
        }

        dp[i] %= 998244353;
    }

    cout << (dp[n] + dp[n-1]) % (998244353) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}