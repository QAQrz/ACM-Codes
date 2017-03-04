#include <bits/stdc++.h>
using namespace std;
char s1[100086],s2[100086];
int l,i,num;
int main(){
	cin>>s1>>s2;
	l=strlen(s1);
	for(i=0;i<l;i++)
		if(s1[i]!=s2[i])
			num++;
	if(num%2)
		cout<<"impossible";
	else{
		num/=2;
		for(i=0;i<l;i++)
			if(s1[i]!=s2[i]&&num-->0)
				cout<<((s1[i]-'0')^1);
			else
				cout<<s1[i];
	}
	cout<<endl;
	return 0;
}