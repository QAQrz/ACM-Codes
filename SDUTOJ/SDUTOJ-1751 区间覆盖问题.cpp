#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
LL n, k, a[11234], ans, x;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    ans = 1, x = a[0] + k;
    for (int i = 1; i < n; i++)
        if (a[i] > x)
            x = a[i] + k, ans++;
    cout << ans << endl;
    return 0;
}