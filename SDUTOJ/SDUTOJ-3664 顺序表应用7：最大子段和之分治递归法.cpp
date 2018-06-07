#include <bits/stdc++.h>
using namespace std;
int n,a[55555],cnt,ans;
inline int cal(int l,int mid,int r) {
    int sum=0,ansl=0,ansr=0;
    for(int i=mid; i>=l; i--)
        sum+=a[i],ansl=max(ansl,sum);
    sum=0;
    for(int i=mid+1; i<=r; i++)
        sum+=a[i],ansr=max(ansr,sum);
    return ansl+ansr;
}
int dfs(int l,int r) {
    cnt++;
    if(l>=r)
        return max(a[l],0);
    int mid=(l+r)>>1;
    return max(dfs(l,mid),max(dfs(mid+1,r),cal(l,mid,r)));
}
int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    ans=dfs(0,n-1);
    printf("%d %d\n",ans,cnt);
    return 0;
}