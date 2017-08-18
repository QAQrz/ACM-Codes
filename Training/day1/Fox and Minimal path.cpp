#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const LL mod=1e9+7,inf=0x3f3f3f3f,maxn=1123456;
int a[33],t,n,s[1024][1024],m=2,p;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	while(n)
		a[t++]=n%2,n>>=1;
	s[0][m]=s[m][0]=1;
	for(int i=1;i<t;i++)
		s[m][m+1]=s[m+1][m]=s[m][m+2]=s[m+2][m]=s[m+1][m+3]=s[m+3][m+1]=s[m+2][m+3]=s[m+3][m+2]=1,m+=3;
	s[m][1]=s[1][m]=1,p=m+1;
	for(int i=0;i<(t-2)*2;i++,p++)
		s[p][p+1]=s[p+1][p]=1;
	swap(p,m);
	s[p][m]=s[m][p]=1,p++,m++;
	for(int i=0;i<t-1;i++,p+=2)
		if(a[i])
			s[i*3+2][p]=s[p][i*3+2]=1;
	db(m);
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++)
			cout<<(s[i][j]?'Y':'N');
		db("");
	}
	return 0;
}