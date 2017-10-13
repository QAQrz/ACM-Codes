#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker,"/stack:1024000000,1024000000")
#define db(x) cout<<(x)<<endl
#define pc(x) putchar(x)
#define ps(x) puts(x)
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456;

int n, cnt;
int dirt[4][2] = {
	{-1, 0}, {1, 0}, {0, -1}, {0, 1},
};
char g[100][100];
int vis[60][60];

bool Judge(int x, int y) {
	if(x>=0 && x<n && y>=0 && y<n && g[x][y]=='#') return true;
	else return false;
}

void DFS(int x, int y) {
	vis[x][y] = cnt;
	for(int i=0; i<4; ++i) {
		int nx = x + dirt[i][0];
		int ny = y + dirt[i][1];
		if(Judge(nx, ny) && !vis[nx][ny]) {
			DFS(nx, ny);
		}
	}
}

bool Check4(int x, int y) {
	// printf("in %d %d\n", x, y);
	for(int i=0; i<4; ++i) {
		int nx = x + dirt[i][0];
		int ny = y + dirt[i][1];
		// printf("next %d %d\n", nx, ny);
		if(!Judge(nx, ny) || vis[nx][ny]!=cnt)
			return false;
	}
	// printf("true\n");
	return true;
}

void PrintG() {
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			printf("%d ", vis[i][j]);
		}
		printf("\n");
	}
}

bool Check() {
	// PrintG();
	int x = -1, y = -1;
	for(int i=0; i<n && x==-1; ++i) {
		for(int j=0; j<n && x==-1; ++j) {
			if(vis[i][j]==cnt && Check4(i, j)) {
				x = i;
				y = j;
			}
		}
	}
	// printf("find %d %d\n", x, y);
	if(x==-1 && y==-1) return false;
	vis[x][y] = -1;
	int num[4] = {0};
	for(int j=x-1; j>=0; --j) {
		if(vis[j][y] == cnt) {
			vis[j][y] = -1;
			num[0]++;
		}
		else break;
	}
	for(int j=x+1; j<n; ++j) {
		if(vis[j][y] == cnt) {
			vis[j][y] = -1;
			num[1]++;
		}
		else break;
	}
	for(int j=y-1; j>=0; --j) {
		if(vis[x][j] == cnt) {
			vis[x][j] = -1;
			num[2]++;
		}
		else break;
	}
	for(int j=y+1; j<n; ++j) {
		if(vis[x][j] == cnt) {
			vis[x][j] = -1;
			num[3]++;
		}
		else break;
	}
	// printf("num %d %d %d %d\n", num[0], num[1], num[2], num[3]);
	sort(num, num+4);
	if(num[0] != num[3]) return false;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(vis[i][j] == cnt) return false;
		}
	}

	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(scanf("%d", &n), n) {
		memset(vis, 0, sizeof vis);
		cnt = 0;
		for(int i=0; i<n; ++i) {
			scanf("%s", g[i]);
		}
		int ans = 0;
		for(int i=0; i<n; ++i) {
			for(int j=0; j<n; ++j) {
				if(g[i][j]=='#' && !vis[i][j]) {
					cnt++;
					// printf("#%d\n", cnt);
					DFS(i, j);
					if(Check()) ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}