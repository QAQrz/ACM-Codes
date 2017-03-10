#include <bits/stdc++.h>
using namespace std;
char s[128];
int i,ans,n,m;
int main(){
	cin>>n>>m;
	while(n--){
		cin>>s;
		for(ans=i=0;s[i];i++){
			if(s[i]=='S')
				ans++;
			else
				ans--;
			if(ans<0||ans>m)
				break;
		}
		cout<<((s[i]||ans)?"NO":"YES")<<endl;
	}
	return 0;
}