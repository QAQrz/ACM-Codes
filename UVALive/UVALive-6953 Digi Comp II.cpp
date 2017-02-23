#include <bits/stdc++.h>
using namespace std;
int in[555555],n,i,dis[555555],a,b;
long long m,num[555555];
vector<int>v[555555];
char s[5];
int main(){
	while(cin>>m>>n){
		queue<int>q;
		memset(dis,0,sizeof dis);
		memset(in,0,sizeof in);
		memset(num,0,sizeof num);
		num[1]=m;
		for(i=1;i<=n;i++)
			v[i].clear();
		for(i=1;i<=n;i++){
			cin>>s>>a>>b;
			v[i].push_back(a);
			v[i].push_back(b);
			in[a]++,in[b]++;
			if(s[0]=='R')
				dis[i]=1;
		}
		for(i=1;i<=n;i++)
			if(!in[i])
				q.push(i);
		while(q.size()){
			a=q.front();
			q.pop();
			num[v[a][dis[a]^1]]+=num[a]/2,num[v[a][dis[a]]]+=num[a]-num[a]/2,in[v[a][0]]--,in[v[a][1]]--;
			if(num[a]%2)
				dis[a]^=1;
			if(v[a][0]&&!in[v[a][0]])
				q.push(v[a][0]);
			if(v[a][1]&&v[a][1]!=v[a][0]&&!in[v[a][1]])
				q.push(v[a][1]);
		}
		for(i=1;i<=n;i++)
			cout<<(dis[i]?'R':'L');
		cout<<endl;
	}
	return 0;
}