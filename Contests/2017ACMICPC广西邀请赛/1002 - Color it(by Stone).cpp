#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#include <queue>
#include <vector>
typedef long long LL;
using namespace std;
const LL MAX = 1e6+10;
int x, a, b, c;
struct node{
	int x, y;
};
vector<node>vec[51];
int main(){
	while(~scanf("%d", &x)){
		if(x==3)break;
		else if(x==0){
			for(int i = 0; i<=50; ++i){
				vec[i].clear();
			}
		}else if(x==1){
			scanf("%d%d%d", &a, &b, &c);
			vec[c].push_back((node){a,b});
		}else {
			scanf("%d%d%d", &a, &b, &c);
			int ans = 0;
			for(int i = 0; i<=50; ++i){
				int sz = vec[i].size();
				for(int j = 0; j<sz; ++j){
					if(vec[i][j].x<=a&&vec[i][j].y>=b&&vec[i][j].y<=c){
						ans++;
						break;
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}