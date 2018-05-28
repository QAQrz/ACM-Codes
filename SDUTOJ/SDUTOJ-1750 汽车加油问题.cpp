#include <bits/stdc++.h>

using namespace std;
int n, k, t, ans, x;

int main() {
    cin >> n >> k;
    t = n;
    for (int i = 0; i <= k; i++) {
        cin >> x;
        if (x > n)
            ans = -1;
        if (!~ans)
            continue;
        if (x > t)
            t = n, ans++;
        t -= x;
    }
    if (~ans)
        cout << ans << endl;
    else
        cout << "No Solution!" << endl;
    return 0;
}