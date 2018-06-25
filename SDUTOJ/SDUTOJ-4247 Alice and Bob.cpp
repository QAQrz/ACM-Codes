#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
LL n, m, dp[5555], a[33], mod = 1000000007;
double x, s;

int main() {
    while (cin >> x >> m) {
        x *= 10, n = (LL) x;
        for (int i = 0; i < m; i++) {
            cin >> s;
            a[i] = (LL) (s * 10);
        }
        if (n != x) {
            cout << 0 << endl;
            continue;
        }
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (int i = 0; i < m; i++)
            for (LL j = a[i]; j <= n; j++)
                dp[j] = (dp[j] + dp[j - a[i]]) % mod;
        cout << dp[n] << endl;
    }
    return 0;
}