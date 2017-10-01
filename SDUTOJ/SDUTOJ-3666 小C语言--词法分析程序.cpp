#include <bits/stdc++.h>
using namespace std;
void check(char *s){
	if (!strcmp(s,"main")||!strcmp(s,"if")||!strcmp(s,"else")||!strcmp(s,"for")||!strcmp(s,"while")||!strcmp(s,"int"))
		printf("(keyword,%s)\n",s);
	else
		printf("(identifier,%s)\n",s);
}
void print(char s)
{
	if (s=='{'||s=='}'||s=='('||s==')'||s==','||s==';')
		printf("(boundary,%c)\n",s);
	else
		printf("(operator,%c)\n",s);
}
int main()
{
	char s[10028],a[10028],b[10028];
	int l,t,i,t2;
	while(~scanf("%s",s))
	{
		t=t2=0;
		l=(int)strlen(s);
		for (i=0; i<l; i++)
		{
			if (isalpha(s[i])||s[i]=='_')
				a[t++]=s[i];
			else if (isdigit(s[i]))
			{
				if (t)
					a[t++]=s[i];
				else
					b[t2++]=s[i];
			}
			else
			{
				if (t)
				{
					t=a[t]=0;
					check(a);
				}
				if (t2)
				{
					t2=b[t2]=0;
					printf("(integer,%s)\n",b);
				}
				if ((s[i]=='<'||s[i]=='>'||s[i]=='='||s[i]=='!')&&s[i+1]=='=')
				{
					printf("(operator,%c%c)\n",s[i],s[i+1]);
					i++;
				}
				else
					print(s[i]);
			}
		}
		if (t)
		{
			t=a[t]=0;
			check(a);
		}
		if (t2)
		{
			t2=b[t2]=0;
			printf("(integer,%s)\n",b);
		}
	}
	return 0;
}