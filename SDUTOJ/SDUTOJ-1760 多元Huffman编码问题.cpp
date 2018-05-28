#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
LL n, k, x, ans, ansx, t;
priority_queue<LL, vector<LL> > q;
priority_queue<LL, vector<LL>, greater<LL> > qx;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
        qx.push(x);
    }
    while (q.size() > 1) {
        t = q.top();
        q.pop();
        t += q.top();
        q.pop();
        ans += t;
        q.push(t);
    }
    while ((qx.size() - 1) % (k - 1))
        qx.push(0);
    while (qx.size() > 1) {
        t = 0;
        for (int i = 0; i < k; i++) {
            t += qx.top();
            qx.pop();
        }
        ansx += t;
        qx.push(t);
    }
    cout << ans << " " << ansx << endl;
    return 0;
}