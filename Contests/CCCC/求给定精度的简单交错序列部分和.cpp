#include <bits/stdc++.h>
using namespace std;
double eps,i=1,s=1,sum;
int main(){
	scanf("%lf",&eps);
	while(1){
		sum+=1/i*s;
		if(1/i-eps<=0)
			break;
		i+=3,s*=-1;
	}
	printf("sum = %.6lf\n",sum);
	return 0;
}