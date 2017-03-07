#include <bits/stdc++.h>
using namespace std;
char s[5];
int i;
int main(){
	cin>>s;
	for(i=0;i<4;i++)
		s[i]=(s[i]-'0'+9)%10+'0';
	swap(s[0],s[2]);
	swap(s[1],s[3]);
	cout<<"The encrypted number is "<<s<<endl;
	return 0;
}