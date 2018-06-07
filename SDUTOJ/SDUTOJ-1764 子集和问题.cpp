#include <bits/stdc++.h>

using namespace std;
int n, c, a[11234], vis[11234], flag, x[11234];

void dfs(int s, int sum) {
    if (sum > c)
        return;
    if (sum == c) {
        for (int i = 0; i < n; i++)
            if (vis[i]) {
                if (!flag) {
                    printf("%d", a[i]);
                    flag = 1;
                } else
                    printf(" %d", a[i]);
            }
        printf("\n");
        return;
    }
    for (int i = s; i < n && !flag; i++)
        if (sum + x[i] >= c) {
            vis[i] = 1;
            dfs(i + 1, sum + a[i]);
            vis[i] = 0;
        }
}

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; ~i; i--)
        x[i] = a[i] + x[i + 1];
    dfs(0, 0);
    if (!flag)
        printf("No Solution!");
    return 0;
}