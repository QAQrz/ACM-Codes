#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker,"/stack:1024000000,1024000000")
#define db(x) cout<<(x)<<endl
#define pc(x) putchar(x)
#define ps(x) puts(x)
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456;
double  p[13][10010], ans[13];
int num[13], n;
double  pp[13];
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i<n; ++i){
			cin>>num[i]>>pp[i];
			p[i][0] = 1.0;
			for(int j = 1; j<=100; ++j){
				p[i][j] = p[i][j-1]*pp[i];
			}
		}
		if(n==1){
			printf("%.6f\n", 1.0);
			continue;
		}
		for(int i = 0; i<n; ++i){
			ans[i] = 0;
			for(int v = 1; v<=100; ++v){
				double sum = pow(1.0-p[i][v], num[i])-pow(1.0-p[i][v-1], num[i]);
				for(int j = 0; j<n; ++j){
					if(i==j)continue;
					sum*=pow(1.0-p[j][v-1], num[j]);
				}
				ans[i]+=sum;
			}
			if(i==n-1)printf("%.6f\n", ans[i]);
			else printf("%.6f ", ans[i]);
		}
	}
	return 0;
}