#include <bits/stdc++.h>
using namespace std;
int a[512],b[1024],n,m,ans,l,j,sum;
vector<int>v;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>b[i];
		l=v.size(),sum=0;
		for(j=0;j<l;j++){
			if(v[j]==b[i])
				break;
			sum+=a[v[j]];
		}
		if(j<l){
			v.erase(v.begin()+j);
			v.insert(v.begin(),b[i]);
		}
		else
			v.insert(v.begin(),b[i]);
		ans+=sum;
	}
	cout<<ans<<endl;
	return 0;
}