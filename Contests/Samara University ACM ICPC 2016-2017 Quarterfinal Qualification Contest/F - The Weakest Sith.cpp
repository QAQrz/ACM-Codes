#include <bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}p[222222];
int n,i,per=1,flag;
int cmp(node a,node b){
	int l=0,r=0;
	if(a.a<b.a)
		r++;
	else
		l++;
	if(a.b<b.b)
		r++;
	else
		l++;
	if(a.c<b.c)
		r++;
	else
		l++;
	return l>r;
}
int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>p[i].a>>p[i].b>>p[i].c;
		if(i>1&&cmp(p[per],p[i]))
			per=i;
	}
	for(i=1;i<=n;i++)
		if(per!=i&&cmp(p[per],p[i])){
			flag=1;
			break;
		}
	cout<<(flag^1)<<endl;
	if(!flag)
		cout<<per<<endl;
	return 0;
}