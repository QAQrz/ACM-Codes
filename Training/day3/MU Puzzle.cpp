#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl;
typedef long long LL;
int n,a,flag;
char s[1123456];
int main(){
	scanf("%d",&n);
	while(n--){
		flag=a=0;
		scanf("%s",s);
		for(int i=0;s[i];i++){
			if((!i&&s[i]!='M')||(i&&s[i]=='M')){
				flag=1;
				break;
			}
			else if(s[i]=='I')
				a++;
			else if(s[i]=='U')
				a+=3;
		}
		printf("%s\n",(!flag&&(a==1||(!(a%2)&&(a%3))))?"Yes":"No");
	}
	return 0;
}