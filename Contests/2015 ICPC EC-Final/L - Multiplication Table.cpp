#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL t, n, m, val, a, b;
char s[1010];
struct node{
	LL x, y, val;
};
vector<node>vec;
bool check(){
	val = 0;
	for(int i = 0; s[i]; ++i){
		if(!(s[i]>='0'&&s[i]<='9'))return false;
		val = val*10+s[i]-'0';
	}
	return true;
}
bool check2(LL a, LL b, int sz){
	for(int i = 0; i<sz; ++i){
		if((vec[i].x-vec[0].x+a)*(vec[i].y-vec[0].y+b)!=vec[i].val)return false;
	}
	return true;
}
int main(){
	scanf("%lld", &t);
	for(LL cas = 1; cas<=t; ++cas){
		scanf("%lld%lld", &n, &m);
		vec.clear();
		int flag = 1;
		for(int i =0; i<n; ++i){
			for(int j = 0; j<m; ++j){
				scanf("%s", s);
				if(flag&&check()){
					vec.push_back((node){i,j,val});
					if((i+1)*(j+1)>val)flag = 0;
				}
			}
		}
		int sz = vec.size();
		if(sz&&flag){
			flag = 0;
			val = vec[0].val;
			LL sqr = sqrt(val);
			for(LL i = 1; i<=sqr; ++i){
				if(val%i==0){
					if(check2(i, val/i, sz)|| check2(val/i, i, sz)){
						flag = 1;
						break;
					}
				}
			}
		}
		if(flag)printf("Case #%lld: Yes\n", cas);
		else printf("Case #%lld: No\n", cas);
	}
	return 0;
}