#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX = 1000+10;
int t, n, m, b, ans1, ans2, x, y;
vector<int>que[MAX];
int fmax(int x){
	if(x==0)return 0;
	return (x-1)/2+1;
}
int fmin(int x){
	if(x==0)return 0;
	return (x-1)/3+1;
}
int main(){
	scanf("%d", &t);
	for(int cs=1; cs<=t; ++cs) {
		scanf("%d%d%d", &n, &m, &b);
		for(int i =0; i<n; ++i){
			que[i].clear();
			que[i].push_back(-1);
			que[i].push_back(m);
		}
		for(int i =0; i<b; ++i){
			scanf("%d%d", &x, &y);
			que[x].push_back(y);
		}
		ans1 = ans2 =0;
		for(int i = 0;i<n; ++i){
			sort(que[i].begin(), que[i].end());
			int sz = que[i].size();
			for(int j =1; j<sz; ++j){
				ans1+=fmax(que[i][j]-que[i][j-1]-1);
				ans2+=fmin(que[i][j]-que[i][j-1]-1);
			}
		}
		printf("Case #%d: %d %d\n", cs, ans1, ans2);
	}
	return 0;
}