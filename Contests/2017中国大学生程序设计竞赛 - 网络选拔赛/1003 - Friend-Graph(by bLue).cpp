#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define db(x) cout<<(x)<<endl
#define ms(x,y) memset(x,y,sizeof x)
#define mp(x,y) make_pair(x,y)
const LL mod=1e9+7,inf=0x3f3f3f3f,maxn=1123456;
const double eps=1e-8,PI=acos(-1.0);
const int N = 3001;
bool a[N][N];
int main() {
	int t, n, v;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i=1; i<n; ++i) {
			for(int j=i+1; j<=n; ++j) {
				scanf("%d", &v);
				a[j][i] = a[i][j] = (v==1?true:false);
			}
		}
		bool ok = false;
		for(int i=n; i>=1 && !ok; --i) {
			for(int j=i-1; j>=1 && !ok; --j) {
				for(int k=j-1; k>=1 && !ok; --k) {
					if((a[i][j] && a[i][k] && a[j][k])
						|| (!a[i][j] && !a[i][k] && !a[j][k]))
						ok = true;
				}
			}
		}
		if(ok) printf("Bad Team!\n");
		else printf("Great Team!\n");
	}
	return 0;
}