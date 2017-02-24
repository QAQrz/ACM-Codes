#include <bits/stdc++.h>
using namespace std;
char s[555555];
int l,i,a,b,c,p,flag;
int main(){
	cin>>s;
	l=strlen(s);
	if(l%2)
		flag=1;
	else{
		for(i=0;i<l;i++)
			if(s[i]=='(')
				a++;
			else if(s[i]==')')
				b++;
			else
				c++;
		if(a<b)
			p=b-a+(c-b+a)/2;
		else
			p=c-a+b-(c-a+b)/2;
		for(i=a=b=0;i<l;i++){
			if(s[i]=='?')
				if(p)
					s[i]='(',p--;
				else
					s[i]=')';
			if(s[i]=='(')
				a++;
			else
				b++;
			if(a<b){
				flag=1;
				break;
			}
		}
		if(a!=b)
			flag=1;
	}
	if(flag)
		cout<<"Impossible"<<endl;
	else
		cout<<s<<endl;
	return 0;
}