#include <bits/stdc++.h>
using namespace std;
long long b,q,l,m,ans,a,i;
map<long long,long long>maps;
int main(){
	cin>>b>>q>>l>>m;
	for(i=0;i<m;i++){
		cin>>a;
		maps[a]=1;
	}
	if(!q){
		if(!maps[b]&&abs(b)<=l)
			ans++;
		if(!maps[0LL]&&abs(b)<=l)
			ans=-1;
	}
	else if(q==1||!b){
		if(!maps[b]&&abs(b)<=l)
			ans=-1;
	}
	else if(!~q){
		if((!maps[b]||!maps[-b])&&abs(b)<=l)
			ans=-1;
	}
	else{
		while(abs(b)<=l){
			if(!maps[b])
				ans++;
			b*=q;
		}
	}
	if(ans<0)
		cout<<"inf"<<endl;
	else
		cout<<ans<<endl;
	return 0;
}