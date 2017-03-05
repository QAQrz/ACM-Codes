#include <bits/stdc++.h>
using namespace std;
int n,m,a[1024],i,j,b[22222],u,v;
char s[128];
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		j=i;
		while(j>1&&a[j/2]>a[j]){
			swap(a[j/2],a[j]);
			j/=2;
		}
	}
	for(i=1;i<=n;i++)
		b[a[i]+10000]=i;
	getchar();
	while(m--){
		cin.getline(s,128);
		if(strstr(s,"root")){
			sscanf(s,"%d",&u);
			cout<<(b[u+10000]>1?"F":"T")<<endl;
		}
		else if(strstr(s,"siblings")){
			sscanf(s,"%d %*s %d",&u,&v);
			cout<<(b[u+10000]/2!=b[v+10000]/2?"F":"T")<<endl;
		}
		else if(strstr(s,"parent")){
			sscanf(s,"%d %*s %*s %*s %*s %d",&u,&v);
			cout<<(b[u+10000]!=b[v+10000]/2?"F":"T")<<endl;
		}
		else{
			sscanf(s,"%d %*s %*s %*s %*s %d",&u,&v);
			cout<<(b[u+10000]/2!=b[v+10000]?"F":"T")<<endl;
		}
	}
	return 0;
}