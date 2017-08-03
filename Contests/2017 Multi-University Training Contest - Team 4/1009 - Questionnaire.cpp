#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define debug(x) cout<<(x)<<endl;
int n,a,b,x,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		a=b=0;
		while(n--){
			scanf("%d",&x);
			if(x%2)
				a++;
			else
				b++;
		}
		if(a>b)
			printf("2 1\n");
		else
			printf("2 0\n");
	}
	return 0;
}