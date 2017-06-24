#include <cstdio>
using namespace std;
int a[1123456],l,r,ans,n,m,t,x;
char s[11];
int main(){
	int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		while(m--){
			scanf("%s",s);
			if(s[0]=='S'){
				scanf("%d %d",&l,&r);
				for(i=l,ans=0;i<=r;i++)
					ans+=a[i];
				printf("%d\n",ans);
			}
			else if(s[0]=='A'){
				scanf("%d %d %d",&x,&l,&r);
				for(i=l;i<=r;i++)
					a[i]&=x;
			}
			else if(s[0]=='O'){
				scanf("%d %d %d",&x,&l,&r);
				for(i=l;i<=r;i++)
					a[i]|=x;
			}
			else{
				scanf("%d %d %d",&x,&l,&r);
				for(i=l;i<=r;i++)
					a[i]^=x;
			}
		}
	}
	return 0;
}