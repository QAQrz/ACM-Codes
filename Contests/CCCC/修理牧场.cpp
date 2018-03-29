#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int n,ans,i,x;
int main(){
	cin>>n;
	while(n--){
		cin>>x;
		q.push(x);
	}
	while(q.size()>1){
		x=q.top();
		q.pop();
		x+=q.top();
		q.pop();
		ans+=x;
		q.push(x);
	}
	cout<<ans<<endl;
	return 0;
}