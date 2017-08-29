#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456,maxc=128;
struct acam{
	// maxn:character total length
	// maxc:character set size
	int nt[maxn][maxc],flag[maxn],fail[maxn],rt,cnt;
	void init(){
		rt=cnt=0;
		ms(nt,0);
		ms(flag,0);
		ms(fail,0);
	}
	int toid(char c){
		// transform character
	}
	void insert(char *s){
		int st=rt;
		while(*s){
			if(!nt[st][toid(*s)])
				nt[st][toid(*s)]=++cnt;
			st=nt[st][toid(*s++)];
		}
		// update flag
	}
	void build(){
		queue<int>q;
		q.push(rt);
		while(q.size()){
			int st=q.front();
			q.pop();
			for(int i=0;i<maxc;i++)
				if(nt[st][i]){
					fail[nt[st][i]]=st==rt?rt:nt[fail[st]][i];
					q.push(nt[st][i]);
				}
				else
					nt[st][i]=st==rt?rt:nt[fail[st]][i];
		}
	}
	int cal(char *s){
		int st=rt,tmp;
		while(*s){
			tmp=st=nt[st][toid(*s++)];
			// calculate something
			while(tmp!=rt)
				tmp=fail[tmp];
		}
		// return something
	}
};
int main(){
	ios::sync_with_stdio(0);

	return 0;
}