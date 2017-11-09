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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=212345;
int t,n,l,ans,flag;
char s[maxn];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %s",&n,s);
		l=strlen(s),ans=flag=0;
		for(int i=0;i+2<l;i++){
			if(s[i]=='C'&&s[i+1]=='P'&&s[i+2]=='C'&&(!i||s[i-1]=='P'))
				flag=1;
			else if(s[i]=='C'&&s[i+1]=='C'&&s[i+2]=='P'){
				if(i+3>=l||s[i+3]=='P')
					flag=1;
				else if(i+3<l&&s[i+3]=='C')
					ans++;
			}
			else if(s[i]=='C'&&s[i+1]=='C'&&s[i+2]=='C'&&(i+3>=l||s[i+3]=='C'))
				flag=1;
		}
		printf("%d\n",ans+flag);
	}
	return 0;
}