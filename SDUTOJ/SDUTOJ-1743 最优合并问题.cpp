#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
LL n, x, ans, ansx, t;
priority_queue<LL, vector<LL> > q;
priority_queue<LL, vector<LL>, greater<LL> > qx;

int main() {
    cin >> n;
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
        ans += t - 1;
        q.push(t);
    }
    while (qx.size() > 1) {
        t = qx.top();
        qx.pop();
        t += qx.top();
        qx.pop();
        ansx += t - 1;
        qx.push(t);
    }
    cout << ans << " " << ansx << endl;
    return 0;
}