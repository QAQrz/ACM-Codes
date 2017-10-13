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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=112345;
LL n,num,x,flag;
char s[maxn],str[maxn];
inline LL check(){
	LL ans=0,num=0;
	for(int i=strlen(s)-1;~i;i--)
		if(s[i]=='1'){
			ans++;
			if(ans>1)
				return -1;
		}
		else if(s[i]=='0')
			num++;
		else
			return -1;
	return num;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		if(strlen(s)<2&&s[0]=='0'){
			db(0);
			return 0;
		}
		x=check();
		if(~x)
			num+=x;
		else{
			flag=1;
			strcpy(str,s);
		}
	}
	if(flag)
		printf("%s",str);
	else
		pc('1');
	for(int i=0;i<num;i++)
		pc('0');
	printf("\n");
	return 0;
}