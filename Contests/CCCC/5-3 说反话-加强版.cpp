#include <bits/stdc++.h>
using namespace std;
string s[555555];
int t;
int main(){
	while(cin>>s[t++]);
	--t;
	while(~--t)
		cout<<s[t]<<(t>0?" ":"\n");
	return 0;
}