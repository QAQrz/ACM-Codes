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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=22;
struct node{
	int x,s;
}p[maxn];
int n,m;
char s[maxn];
inline bool cmp(node a,node b){
	if(a.s==b.s)
		return a.x<b.x;
	return a.s>b.s;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>m&&(n+m)){
		ms(p,0);
		p[0].x=0,p[1].x=2,p[2].x=3,p[3].x=4,p[4].x=6;
		while(n--){
			cin>>s;
			for(int j=0;j<m;j++)
				if(s[j]=='A')
					p[0].s++;
				else if(s[j]=='C')
					p[1].s++;
				else if(s[j]=='D')
					p[2].s++;
				else if(s[j]=='E')
					p[3].s++;
				else if(s[j]=='G')
					p[4].s++;
		}
		sort(p,p+5,cmp);
		for(int i=0;i<5;i++)
			if(p[i].s){
				if(i)
					printf(" ");
				printf("%c %d",p[i].x+'A',p[i].s);
			}
		printf("\n");
	}
	return 0;
}