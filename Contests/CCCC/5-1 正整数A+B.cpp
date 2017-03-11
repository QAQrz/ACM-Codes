#include <bits/stdc++.h>
using namespace std;
char s[111111];
int i,flag,flag2,a,b;
int main(){
	gets(s);
	for(i=0;s[i]!=' ';i++)
		if(!isdigit(s[i]))
			flag=1;
		else
			a=a*10+s[i]-'0';
	for(i++;s[i];i++)
		if(!isdigit(s[i]))
			flag2=1;
		else
			b=b*10+s[i]-'0';
	if(a<1||a>1000)
		flag=1;
	if(b<1||b>1000)
		flag2=1;
	if(!flag)
		cout<<a;
	else
		cout<<"?";
	cout<<" + ";
	if(!flag2)
		cout<<b;
	else
		cout<<"?";
	cout<<" = ";
	if(!flag&&!flag2)
		cout<<a+b;
	else
		cout<<"?";
	cout<<endl;
	return 0;
}