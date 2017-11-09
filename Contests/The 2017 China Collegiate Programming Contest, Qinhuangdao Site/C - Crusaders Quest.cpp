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
int t;
char s[12];
int ans;
char cm[3] = {'g', 'a', 'o'};
void DFS(int ch, vector<char> s, set<int> st) {
	if(st.size() >= 3) return;
	int num = 0, l = 0, r = 0;
	for(int i=0; i<s.size(); ++i) {
		if(s[i] == cm[ch]) {
			num++;
			if(num == 1) l = r = i;
			else if(num > 1) r = i;
		}
	}
	if(num < 3) return;
	vector<char> tmp;
	for(int i=0; i<l; ++i) {
		tmp.push_back(s[i]);
	}
	for(int i=r+1; i<s.size(); ++i) {
		tmp.push_back(s[i]);
	}
	st.insert(ch);
	ans = max(ans, (int)(st.size()));
	for(int i=0; i<3; ++i) {
		if(!st.count(i)) DFS(i, tmp, st);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>s;
		ans = 0;
		vector<char> v;
		for(int i=0; i<9; ++i) {
			v.push_back(s[i]);
		}
		set<int> st;
		for(int i=0; i<3; ++i) {
			DFS(i, v, st);
		}
		printf("%d\n", ans);
	}
	return 0;
}