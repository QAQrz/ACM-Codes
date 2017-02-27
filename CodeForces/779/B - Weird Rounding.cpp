#include <bits/stdc++.h>
using namespace std;
char s[15];
int k,l,i,ans;
int main(){
	cin>>s>>k;
	l=strlen(s);
	for(i=l-1;i>=0;i--){
		if(s[i]=='0'){
			k--;
			if(!k)
				break;
		}
		else
			ans++;
	}
	if(k)
		ans=l-1;
	cout<<ans<<endl;
	return 0;
}