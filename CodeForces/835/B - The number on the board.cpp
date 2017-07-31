#include <bits/stdc++.h>
using namespace std;
int sum,k,l,ans;
char s[1123456];
int main(){
	cin>>k>>s;
	l=strlen(s);
	for(int i=0;i<l;i++)
		sum+=(s[i]-'0');
	if(sum<k){
		sort(s,s+l);
		int i=0;
		while(sum<k&&i<l)
			sum+=9-(s[i++]-'0'),ans++;
	}
	cout<<ans<<endl;
	return 0;
}