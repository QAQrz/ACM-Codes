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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=251234,maxc=128;
struct sam{
	// maxn: character total length
	// maxc: character set size
	int nt[maxn*2][maxc],len[maxn*2],link[maxn*2],rt,last,cnt,cur,p,q,c;
	inline void init(){
		rt=last=cnt=0;
		ms(nt,-1);
		ms(len,0);
		ms(link,-1);
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
		while(*s)
			extend(toid(*s++));
	}
	inline int lcs(char *s){
		int v=0,l=0,ans=0,x;
		while(*s){
			x=toid(*s++);
			while(~v&&!~nt[v][x])
				v=link[v],l=len[v];
			if(!~v)
				v=l=0;
			else if(nt[v][x])
				v=nt[v][x],l++;
			ans=max(ans,l);
		}
		return ans;
	}
}sam;
char s[maxn],str[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s>>str;
	sam.init();
	sam.insert(s);
	db(sam.lcs(str));
	return 0;
}