#include <bits/stdc++.h>
using namespace std;
struct node{
	long long a,s;
};
vector<node>vec[11111];
long long n,ans,flag,a,b,x;
void insert(long long x,long long a){
	long long l=vec[x].size(),i;
	for(i=0;i<l;i++)
		if(vec[x][i].a==a){
			vec[x][i].s++;
			break;
		}
	if(i>=l){
		node p={a,1};
		vec[x].push_back(p);
	}
}
int main(){
	cin>>n;
	while(n--){
		cin>>a>>b;
		insert(a%10007,a);
		insert(b%10007,b);
	}
	for(long long i=0;i<10007;i++){
		long long l=vec[i].size();
		for(long long j=0;j<l;j++)
			if(vec[i][j].s>ans)
				ans=vec[i][j].s,a=vec[i][j].a,flag=0;
			else if(vec[i][j].s==ans){
				if(vec[i][j].a<a)
					a=vec[i][j].a;
				flag++;
			}
	}
	printf("%011lld %lld",a,ans);
	if(flag)
		cout<<" "<<flag+1;
	cout<<endl;
	return 0;
}