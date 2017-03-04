#include <bits/stdc++.h>
using namespace std;
char s[128],s1[128];
int flag,i,num,num2,l;
int main(){
	cin>>s>>s1;
	for(i=0;s[i];i++)
		if(s[i]=='|')
			flag=1;
		else if(!flag)
			num++;
		else
			num2++;
	l=strlen(s1)-abs(num-num2);
	if(l<0||l%2)
		flag=0;
	else
		l/=2;
	if(num<num2)
		l=strlen(s1)-l;
	if(flag){
		for(i=0;i<l;i++)
			cout<<s1[i];
		cout<<s;
		for(;s1[i];i++)
			cout<<s1[i];
	}
	else
		cout<<"Impossible";
	cout<<endl;
	return 0;
}