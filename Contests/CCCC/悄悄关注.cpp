#include <bits/stdc++.h>
using namespace std;
map<string,int>maps;
int n,m,i,a[11111],t;
double sum;
string str,s[11111],ans[11111];
int main(){
	cin>>n;
	while(n--){
		cin>>str;
		maps[str]=1;
	}
	cin>>m;
	for(i=0;i<m;i++){
		cin>>s[i]>>a[i];
		sum+=a[i];
	}
	sum/=m;
	for(i=0;i<m;i++)
		if(a[i]>sum&&!maps[s[i]])
			ans[t++]=s[i];
	sort(ans,ans+t);
	for(i=0;i<t;i++)
		cout<<ans[i]<<endl;
	if(!t)
		cout<<"Bing Mei You"<<endl;
	return 0;
}