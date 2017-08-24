#include <cstdio>
using namespace std;
#define minx(x,y) x<y?x:y
#define maxx(x,y) x>y?x:y
struct node{
	int v,next;
}p[212345];
int t,n,k,cnt,head[112345],vis[112345],u,dp[112345][2],ans;
inline void add(int u,int v){
	p[cnt].v=v,p[cnt].next=head[u],head[u]=cnt++;
}
#define BUFSIZE 100000
bool IOerr = 0;
inline char getc() {
	static char buf[BUFSIZE], *p = buf+BUFSIZE, *pend = buf+BUFSIZE;
	if(p == pend) {
		p = buf;
		pend = buf + fread(buf, 1, BUFSIZE, stdin);
		if(pend == p) {
			IOerr = 1;
			return -1;
		}
	}
	return *p++;
}
inline bool isws(char ch) {
	return (ch==' ' || ch=='\n' || ch=='\t' || ch=='\r');
}
inline void read(int &x) {
	char ch;
	while(isws(ch=getc()));
	if(IOerr) return;
	x = (ch-'0');
	while(ch=getc(), ch>='0'&&ch<='9') {
		x = x*10 + (ch-'0');
	}
}
void dfs(int u){
	dp[u][0] = dp[u][1] = 0,vis[u]=1;
	int flag=0,m=0x3f3f3f3f,sum=0,num=0;
	for(int i=head[u];~i;i=p[i].next)
		if(!vis[p[i].v]){
			dfs(p[i].v);
			num++,sum+=maxx(dp[p[i].v][0],dp[p[i].v][1]);
			if(dp[p[i].v][0]>=dp[p[i].v][1])
				flag=1;
			else
				m=minx(m,dp[p[i].v][1]-dp[p[i].v][0]);
		}
	if(flag)
		dp[u][1]=sum+1;
	else if(num)
		dp[u][1]=sum-m+1;
	vis[u]=0,dp[u][0]=sum;
}
int main(){
	read(t);
	while(t--){
		cnt=0;
		read(n);
		read(k);
		for(int i=1;i<=n;++i)
			head[i]=-1;
		for(int i=1;i<n;i++){
			read(u);
			add(u,i+1);
			add(i+1,u);
		}
		dfs(1);
		ans=maxx(dp[1][0],dp[1][1]);
		printf("%d\n",k<=ans*2?k/2+k%2:k-ans);
	}
	return 0;
}