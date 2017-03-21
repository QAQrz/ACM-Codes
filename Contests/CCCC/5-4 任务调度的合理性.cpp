#include <bits/stdc++.h>
using namespace std;
vector<int>v[128];
queue<int>q;
int n,m,i,j,deg[128],x,l,num;
int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>deg[i];
		for(j=0;j<deg[i];j++){
			cin>>x;
			v[x].push_back(i);
		}
		if(!deg[i])
			q.push(i);
	}
	while(q.size()){
		x=q.front();
		q.pop();
		l=v[x].size(),num++;
		for(i=0;i<l;i++){
			deg[v[x][i]]--;
			if(!deg[v[x][i]])
				q.push(v[x][i]);
		}
	}
	printf("%d\n",num<n?0:1);
	return 0;
}