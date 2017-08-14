#include <cstdio>
#include <cstring>
using namespace std;
char s[1111111];
int next[1111111],i,j,l,ans;
int main(){
	while(gets(s)&&strcmp(s,".")){
		l=strlen(s),j=next[i=0]=-1;
		while(i<l){
			while(~j&&s[i]!=s[j])
				j=next[j];
			next[++i]=++j;
		}
		ans=l-next[l];
		printf("%d\n",l%ans?1:l/ans);
	}
	return 0;
}