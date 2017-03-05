#include <bits/stdc++.h>
using namespace std;
int n,x,x2,y,y2,i,j,m,flag,num;
char s[15][15];
int main(){
	cin>>n;
	for(i=1;i<=n*2;i++)
		for(j=1;j<=n*2;j++)
			cin>>s[i][j];
	cin>>m;
	while(m--){
		cin>>x>>y>>x2>>y2;
		if(flag<3){
			if(s[x][y]!='*'&&s[x][y]==s[x2][y2]){
				s[x][y]=s[x2][y2]='*',num++;
				if(num>=n*n*2){
					cout<<"Congratulations!"<<endl;
					flag=3;
					continue;
				}
				for(i=1;i<=n*2;i++)
					for(j=1;j<=n*2;j++)
						printf("%c%c",s[i][j],j<n*2?' ':'\n');
			}
			else{
				cout<<"Uh-oh"<<endl;
				flag++;
				if(flag>2)
					cout<<"Game Over"<<endl;
			}
		}
	}
	return 0;
}