#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=3123;
struct node{
	int num[26],t;
}p[maxn*2];
struct col{
	int num,sign;
}ans[maxn*2];
int n,vis[maxn*2],t;
char s[maxn][maxn];
inline bool del(){
	for(int i=0;i<n*2;i++)
		if(!vis[i]&&p[i].t==1)
			for(int j=0;j<26;j++)
				if(p[i].num[j]){
					for(int k=i<n?n:0;k<(i<n?n*2:n);k++)
						if(!vis[k]&&s[i<n?i:k][(i<n?k:i)-n]!='?'){
							p[k].num[j]--;
							if(!p[k].num[j])
								p[k].t--;
						}
					vis[i]=1,ans[t++]=col{i,j};
					return 1;
				}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		for(int j=0;j<n;j++)
			if(s[i][j]!='?'){
				if(!p[i].num[s[i][j]-'a'])
					p[i].t++;
				if(!p[j+n].num[s[i][j]-'a'])
					p[j+n].t++;
				p[i].num[s[i][j]-'a']++,p[j+n].num[s[i][j]-'a']++;
			}
	}
	while(del());
	for(int i=0;i<n*2;i++)
		if(!vis[i])
			printf("%c %d a\n",i<n?'h':'v',i<n?i+1:i-n+1);
	for(int i=t-1;~i;i--)
		printf("%c %d %c\n",ans[i].num<n?'h':'v',ans[i].num<n?ans[i].num+1:ans[i].num-n+1,ans[i].sign+'a');
	return 0;
}