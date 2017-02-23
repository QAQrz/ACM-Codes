#include <bits/stdc++.h>
using namespace std;
string str;
int n,i,ans;
map<string,int>m;
int main(){
	while(cin>>n){
		m.clear();
		ans=0;
		for(i=0;i<n;i++){
			cin>>str;
			if(m[str])
				m[str]++;
			else
				m[str]=1;
		}
		for(i=0;i<n;i++){
			cin>>str;
			if(m[str])
				m[str]--,ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}