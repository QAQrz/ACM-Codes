#include <bits/stdc++.h>
using namespace std;
const int maxn=55;
int l,cnt,x;
char s[maxn];
int dfsE();
int dfsG();
int dfsT();
int dfsS();
int dfsF();
int main(){
	scanf("%s",s);
	l=strlen(s)-1;
	printf("%s\n",dfsE()&&x==l&&s[x]=='#'?"accept":"error");
	return 0;
}
int dfsE(){
	printf("%d E-->TG\n",cnt++);
	return dfsT()&&dfsG();
}
int dfsG(){
	if(s[x]=='+'){
		printf("%d G-->+TG\n",cnt++);
		x++;
		return dfsT()&&dfsG();
	}
	else
		printf("%d G-->&\n",cnt++);
	return 1;
}
int dfsT(){
	printf("%d T-->FS\n",cnt++);
	return dfsF()&&dfsS();
}
int dfsS(){
	if(s[x]=='*'){
		printf("%d S-->*FS\n",cnt++);
		x++;
		return dfsF()&&dfsS();
	}
	else
		printf("%d S-->&\n",cnt++);
	return 1;
}
int dfsF(){
	if(s[x]=='('){
		printf("%d F-->(E)\n",cnt++);
		x++;
		return dfsE()&&s[x++]==')';
	}
	else if(s[x]=='i'){
		printf("%d F-->i\n",cnt++);
		x++;
		return 1;
	}
	return 0;
}