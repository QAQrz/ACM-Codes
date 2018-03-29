#include <bits/stdc++.h>
using namespace std;
int n,x,i;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		for(i=sqrt(x);i>1;i--)
			if(!(x%i))
				break;
		printf("%s\n",(x>1&&i<2?"Yes":"No"));
	}
	return 0;
}