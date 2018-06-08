#include <bits/stdc++.h>

using namespace std;
struct node {
    int s, x, f, pre;
} a, b;
int n, m;
map<int, node> mmp;

int main() {
    cin >> n >> m;
    a = {0, n, 0, -1};
    mmp[n] = a;
    queue<node> q;
    q.push(a);
    while (!q.empty()) {
        a = q.front();
        q.pop();
        if (a.x == m) {
            cout << a.s << endl;
            while (~a.pre) {
                cout << (a.f ? 'f' : 'g');
                a = mmp[a.pre];
            }
            cout << endl;
            break;
        }
        b = a;
        b.s++, b.x = a.x * 3, b.f = 1, b.pre = a.x;
        if (!mmp.count(b.x)) {
            mmp[b.x] = b;
            q.push(b);
        }
        b = a;
        b.s++, b.x = a.x / 2, b.f = 0, b.pre = a.x;
        if (!mmp.count(b.x)) {
            mmp[b.x] = b;
            q.push(b);
        }
    }
    return 0;
}