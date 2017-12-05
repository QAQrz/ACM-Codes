#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
struct node {
	char sign[25],opera[25];
} p[128];
int value[128];
int run(int j,node a) {
	if (!strcmp(a.sign,"STOP"))
		return 0;
	if(!strcmp(a.sign,"IF")) {
		if (value[(int)a.opera[0]]>value[(int)a.opera[2]])
			return j+1;
		return j+2;
	}
	if (!strcmp(a.sign,"GOTO")) {
		int k,ans=0;
		for (k=0; a.opera[k]; k++)
			ans=ans*10+a.opera[k]-'0';
		return ans;
	}
	if (!strcmp(a.sign,"LET")) {
		if (isalpha(a.opera[2]))
			value[(int)a.opera[0]]=value[(int)a.opera[2]]+value[(int)a.opera[4]];
		else {
			value[(int)a.opera[0]]=0;
			for (int k=2; a.opera[k]; k++)
				value[(int)a.opera[0]]=value[(int)a.opera[0]]*10+a.opera[k]-'0';
		}
	} else
		printf("%c=%d\n",a.opera[0],value[(int)a.opera[0]]);
	return j+1;
}
int main() {
	int i,j=1;
	memset(value,0,sizeof(value));
	while(~scanf("%d",&i)) {
		scanf("%s",p[i].sign);
		if (strcmp(p[i].sign,"STOP"))
			scanf("%s",p[i].opera);
	}
	while(j)
		j=run(j,p[j]);
	return 0;
}