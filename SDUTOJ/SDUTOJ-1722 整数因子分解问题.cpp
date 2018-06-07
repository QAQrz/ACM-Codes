#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
map<LL,LL>mmp;
LL dfs(LL x) {
    if(x<4)
        return 1;
    if(mmp.count(x))
        return mmp[x];
    LL ans=1;
    for(LL i=2; i*i<=x; i++)
        if(!(x%i)) {
            ans+=dfs(i);
            if(i!=x/i)
                ans+=dfs(x/i);
        }
    return mmp[x]=ans;
}
int main() {
    cin>>n;
    cout<<dfs(n)<<endl;
    return 0;
}