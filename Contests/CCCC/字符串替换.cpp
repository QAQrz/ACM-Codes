#include <bits/stdc++.h>
using namespace std;
char s[128];
int i;
int main(){
	gets(s);
	for(i=0;s[i];i++){
		if(isupper(s[i]))
			s[i]=-s[i]+155;
		cout<<s[i];
	}
	cout<<endl;
	return 0;
}