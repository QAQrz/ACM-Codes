#include <bits/stdc++.h>
using namespace std;
char s[1024];
int l,i,j,ans,x;
int main(){
	gets(s);
	l=strlen(s);
	for(i=0;i<l;i++){
		x=1;
		for(j=1;i-j>-1&&i+j<l;j++){
			if(s[i-j]!=s[i+j])
				break;
			x+=2;
		}
		ans=max(ans,x);
		if(i+1<l&&s[i]==s[i+1]){
			x=2;
			for(j=1;i-j>-1&&i+j+1<l;j++){
				if(s[i-j]!=s[i+j+1])
					break;
				x+=2;
			}
			ans=max(ans,x);
		}
	}
	printf("%d\n",ans);
	return 0;
}