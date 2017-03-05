#include <bits/stdc++.h>
using namespace std;
char s[55];
int num,l,i,flag,flag2;
double ans;
int main(){
	cin>>s;
	l=strlen(s);
	if(s[0]=='-')
		flag=1,i++;
	for(;i<l;i++)
		if(s[i]=='2')
			num++;
	if(!((s[l-1]-'0')%2))
		flag2=1;
	if(flag)
		l--,ans=100.0*num/l*1.5;
	else
		ans=100.0*num/l;
	if(flag2)
		ans*=2;
	printf("%.2lf%%\n",ans);
	return 0;
}