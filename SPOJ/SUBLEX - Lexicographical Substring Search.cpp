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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=112345,maxc=33;
struct sam{
	// maxn: character total length + number of strings
	// maxc: character set size
	int nt[maxn*2][maxc],len[maxn*2],link[maxn*2],rt,last,cnt,cur,p,q,c,k[maxn*2],b[maxn*2];
	LL a[maxn*2];
	inline void init(){
		rt=last=cnt=0;
		ms(nt,-1);
		ms(len,0);
		ms(link,-1);
		ms(a,0);
		ms(b,0);
	}
	inline int toid(char c){
		// transform character(from 1)
		return c-'a'+1;
	}
	inline void extend(int x){
		cur=++cnt,len[cur]=len[last]+1;
		for(p=last;~p&&!~nt[p][x];p=link[p])
			nt[p][x]=cur;
		if(~p){
			q=nt[p][x];
			if(len[p]+1==len[q])
				link[cur]=q;
			else{
				c=++cnt,len[c]=len[p]+1,link[c]=link[q],link[q]=link[cur]=c;
				for(int i=0;i<maxc;i++)
					nt[c][i]=nt[q][i];
				for(;~p&&nt[p][x]==q;p=link[p])
					nt[p][x]=c;
			}
		}
		else
			link[cur]=rt;
		last=cur;
	}
	inline void insert(char *s){
		int l=strlen(s);
		while(*s)
			extend(toid(*s++));
		for(int i=0;i<=cnt;i++)
			b[len[i]]++;
		for(int i=1;i<=l;i++)
			b[i]+=b[i-1];
		for(int i=0;i<=cnt;i++)
			k[--b[len[i]]]=i,a[i]=1;
		for(int i=cnt;~i;i--)
			for(int j=0;j<maxc;j++)
				if(~nt[k[i]][j])
					a[k[i]]+=a[nt[k[i]][j]];
	}
	inline void cal(LL x){
		int v=0;
		while(x){
			for(int i=0;i<maxc;i++)
				if(~nt[v][i]&&x>a[nt[v][i]])
					x-=a[nt[v][i]];
				else if(~nt[v][i]){
					printf("%c",i+'a'-1);
					x--,v=nt[v][i];
					break;
				}
		}
		printf("\n");
	}
}sam;
int t;
LL x;
char s[maxn];
int main(){
	scanf("%s %d",s,&t);
	sam.init();
	sam.insert(s);
	while(t--){
		scanf("%lld",&x);
		sam.cal(x);
	}
	return 0;
}