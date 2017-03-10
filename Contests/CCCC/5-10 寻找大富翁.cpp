#include <bits/stdc++.h>
using namespace std;
priority_queue<long long>q;
int n,m,i;
long long a;
int main() {
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%lld",&a);
        q.push(a);
    }
    m=min(n,m);
    while(m--){
        printf("%d%c",q.top(),m?' ':'\n');
        q.pop();
    }
    return 0;
}