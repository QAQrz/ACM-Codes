#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
LL n, a[112345], b[112345], ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (LL i = n - 1; i; i--) {
        if (a[i] > b[i])
            a[i - 1] += a[i] - b[i], ans += a[i] - b[i];
        else
            ans += i * (b[i] - a[i]);
    }
    cout << ans << endl;
    return 0;
}