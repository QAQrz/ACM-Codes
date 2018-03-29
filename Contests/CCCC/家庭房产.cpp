#include <bits/stc+.h>
using namespace std;
struct node{
	int id,fid,mid,knum,kid[5];
	double num,area;
	node(){
		fid=mid=-1;
	}
}p[11111];
int n,id;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&id);
		scanf("%d %d %d",&p[id].fid,&p[id].mid,&p[id].knum);
		for(i=0;i<p[id].knum;i++)
			scanf("%d",&p[id].kid[i]);
		scanf("%lf %lf",&p[id].num,&p[id].area);
		
	}
	return 0;
}