#include <bits/stdc++.h>
using namespace std;
string s[1111111];
int t=1;
int main(){
	while(cin>>s[t]&&s[t++].compare("."));
	t-=2;
	if(t>13){
		if(s[2]==s[14])
			cout<<s[2]<<" is the only one for you..."<<endl;
		else
			cout<<s[2]<<" and "<<s[14]<<" are inviting you to dinner..."<<endl;
	}
	else if(t>1)
		cout<<s[2]<<" is the only one for you..."<<endl;
	else
		cout<<"Momo... No one is for you ..."<<endl;
	return 0;
}