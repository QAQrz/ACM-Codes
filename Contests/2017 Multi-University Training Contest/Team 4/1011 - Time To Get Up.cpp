#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define debug(x) cout<<(x)<<endl;
int t;
char s[7][22];
char mp[10][7][5] = {
".XX.",
"X..X",
"X..X",
"....",
"X..X",
"X..X",
".XX.",


"....",
"...X",
"...X",
"....",
"...X",
"...X",
"....",

".XX.",
"...X",
"...X",
".XX.",
"X...",
"X...",
".XX.",

".XX.",
"...X",
"...X",
".XX.",
"...X",
"...X",
".XX.",

"....",
"X..X",
"X..X",
".XX.",
"...X",
"...X",
"....",

".XX.",
"X...",
"X...",
".XX.",
"...X",
"...X",
".XX.",

".XX.",
"X...",
"X...",
".XX.",
"X..X",
"X..X",
".XX.",

".XX.",
"...X",
"...X",
"....",
"...X",
"...X",
"....",

".XX.",
"X..X",
"X..X",
".XX.",
"X..X",
"X..X",
".XX.",

".XX.",
"X..X",
"X..X",
".XX.",
"...X",
"...X",
".XX.",
};


int Find(int d) {
	for(int l=0; l<=9; ++l) {
		bool ok = true;
		for(int i=0; i<7 && ok; ++i) {
			for(int j=0; j<4 && ok; ++j) {
				if(s[i][d+j] != mp[l][i][j]) {
					// printf("%d %d %c    %d %d %c\n", i, d+j, s[i][d+j], i, j, mp[l][i][j]);
					ok = false;
				}
			}
		}
		if(ok) return l;
	}
	return 0;
}

int main(){
	scanf("%d", &t);
	while(t--) {
		for(int i=0; i<7; ++i) {
			scanf("%s", s[i]);
		}
		printf("%d%d:%d%d\n", Find(0), Find(5), Find(12), Find(17));
	}
	
	return 0;
}