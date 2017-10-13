#include <bits/stdc++.h>
using namespace std;
int main() {
	char s[300];
	int flag=1,i=0,dian1=0,dian2=0;
	scanf("%s",s);
	if (s[i]=='+'||s[i]=='-')
		i++;
	if (!isdigit(s[i]))
		flag=0;
	else if (strstr(s,"e")||strstr(s,"E")) {
		for (; s[i]!='e'&&s[i]!='E'; i++)
			if (!isdigit(s[i])&&s[i]!='.')
				break;
			else if (s[i]=='.') {
				if(!isdigit(s[i+1])||!isdigit(s[i-1])){
					flag=0;
					break;
				}
				if(!dian1)
					dian1=1;
				else {
					flag=0;
					break;
				}
			}
		if (s[i]!='e'&&s[i]!='E')
			flag=0;
		else if (!isdigit(s[i-1])||!s[i+1])
			flag=0;
		else {
			if (s[i+1]=='+'||s[i+1]=='-'){
				i++;
				if(!s[i+1])
					flag=0;
			}
			for (i++; s[i]&&flag; i++)
				if (!isdigit(s[i])) {
					flag=0;
					break;
				}
		}
	} else {
		for (; s[i]; i++)
			if (!isdigit(s[i])) {
				if (s[i]=='.') {
					if(!isdigit(s[i+1])||!isdigit(s[i-1])){
						flag=0;
						break;
					}
					if (!dian2)
						dian2=1;
					else {
						flag=0;
						break;
					}
				} else {
					flag=0;
					break;
				}
			}
	}
	if (!(strstr(s,"e")||strstr(s,"E"))&&!dian2)
		flag=0;
	for(i=0;s[i];i++)
		if(!isdigit(s[i])&&s[i]!='e'&&s[i]!='E'&&s[i]!='.'&&s[i]!='+'&&s[i]!='-'){
			flag=0;
			break;
		}
	if (flag)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}