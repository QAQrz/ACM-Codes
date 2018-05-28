#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
struct node {
    LL a, b;
} p[11234];
LL n;
priority_queue<LL, vector<LL>, greater<LL> > q;

inline bool cmp(node a, node b) {
    return a.a < b.a;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].a >> p[i].b;
    sort(p, p + n, cmp);
    for (int i = 0; i < n; i++) {
        if (q.size() && q.top() <= p[i].a)
            q.pop();
        q.push(p[i].b);
    }
    cout << q.size() << endl;
    return 0;
}