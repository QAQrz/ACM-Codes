#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[111],b[111],dp[111][111],dpx[111][111],ans=0,ansx=0x3f3f3f3f;
inline LL sum(int x,int l) {
    if(x+l>n)
        return b[n]-b[x-1]+b[(x+l)%n];
    return b[x+l]-b[x-1];
}
int main() {
    memset(dpx,0x3f3f3f3f,sizeof dpx);
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        b[i+1]=a[i]+b[i],dpx[i][1]=0;
    }
    for(int j=2; j<=n; j++)
        for(int i=0; i<n; i++)
            for(int k=1; k<j; k++)
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[(i+k)%n][j-k]+sum(i+1,j-1)),dpx[i][j]=min(dpx[i][j],dpx[i][k]+dpx[(i+k)%n][j-k]+sum(i+1,j-1));
    for(int i=0; i<n; i++)
        ans=max(ans,dp[i][n]),ansx=min(ansx,dpx[i][n]);
    cout<<ansx<<endl<<ans<<endl;
    return 0;
}