#include <bits/stdc++.h>
using namespace std;
int n,i,j,k,ans,t,a[312345];
vector<int>v[312345];
int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j*j<=i;j++)
			if(!(i%j)){
				v[i].push_back(j);
				if(j*j!=i)
					v[i].push_back(i/j);
			}
		sort(v[i].begin(),v[i].end());
	}
	for(i=1;i<=n;i++)
		for(j=1;i*j<=n;j++){
			t=n-i*j;
			for(k=0;k<v[t].size()&&v[t][k]<i;k++)
				if(a[v[t][k]]!=i)
					a[v[t][k]]=i,ans++;
		}
	cout<<ans<<endl;
	return 0;
}