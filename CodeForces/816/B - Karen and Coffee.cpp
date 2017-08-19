#include <bits/stdc++.h>
using namespace std;
int n,k,q,l,r,i,j,num[212345],ans[212345];
inline int query(int x){
	int a=0;
	while(x)
		a+=ans[x],x-=x&-x;
	return a;
}
int main(){
	cin>>n>>k>>q;
	while(n--){
		cin>>l>>r;
		num[l]++,num[r+1]--;
	}
	for(i=1;i<=200000;i++){
		num[i]+=num[i-1];
		if(num[i]>=k)
			for(j=i;j<=200000;j+=j&-j)
				ans[j]++;
	}
	while(q--){
		cin>>l>>r;
		cout<<(query(r)-query(l-1))<<endl;
	}
	return 0;
}