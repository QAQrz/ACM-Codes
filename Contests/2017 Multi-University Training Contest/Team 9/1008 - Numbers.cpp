#include <bits/stdc++.h>
using namespace std;
int n,a[212345],ans[212345],t;
map<int,int>mmp;
map<int,int>::iterator it;
int main(){
	while(~scanf("%d",&n)){
		mmp.clear();
		t=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			mmp[a[i]]++;
		}
		for(it=mmp.begin();it!=mmp.end();it++)
			while(it->second>0){
				it->second--;
				for(int i=0;i<t;i++)
					mmp[ans[i]+it->first]--;
				ans[t++]=it->first;
			}
		printf("%d\n",t);
		for(int i=0;i<t;i++)
			printf("%d%c",ans[i],i<t-1?' ':'\n');
	}
	return 0;
}