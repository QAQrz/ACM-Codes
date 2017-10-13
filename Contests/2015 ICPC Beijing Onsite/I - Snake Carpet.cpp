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

struct point {
	int x, y;
};

int a[1000][1000], b[1000][1000];
int n, h, w, cur;
vector<point> ans[505];
int dirt[4][2] = {
	{-1, 0}, {1, 0}, {0, -1}, {0, 1},
};
bool vis[1000][1000];

void MoveR2() {
	for(int i=1; i<=h; ++i) {
		for(int j=w; j>=1; --j) {
			b[i][j+2] = b[i][j];
		}
	}
	for(int i=1; i<cur; ++i) {
		// printf("here\n");
		for(int j=0; j<ans[i].size(); ++j) {
			ans[i][j].y += 2;
		}
	}
}

void Calc(int n) {
	for(int i=1; i<=n; ++i) {
		ans[i].clear();
	}
	// memset(vis, false, sizeof vis);
	memcpy(b, a, sizeof a);
	h = 2;
	w = 3;
	ans[1].push_back((point){2, 3});
	ans[2].push_back((point){1, 1});
	ans[2].push_back((point){2, 1});
	ans[3].push_back((point){1, 3});
	ans[3].push_back((point){1, 2});
	ans[3].push_back((point){2, 2});
	// 0: even -> to left, number 1 at bottom right now
	// 1: even -> to right, number 1 at bottom left now
	int flag = 1;
	for(cur=4; cur<=n; ++cur) {
		if(cur%2 == 0) {
			if(flag) {
				MoveR2();
				for(int i=1; i<=h; ++i) {
					b[i][1] = cur;
					ans[cur].push_back((point){i, 1});
				}
				for(int i=h; i>=1; --i) {
					b[i][2] = cur;
					ans[cur].push_back((point){i, 2});
				}
			}
			else {
				for(int i=1; i<=h; ++i) {
					b[i][w+1] = cur;
					ans[cur].push_back((point){i, w+1});
				}
				for(int i=h; i>=1; --i) {
					b[i][w+2] = cur;
					ans[cur].push_back((point){i, w+2});
				}
			}
			w += 2;
		}
		else {
			if(flag) {
				ans[cur].push_back((point){h, w});
				b[h][w] = cur;
				for(int j=w; j>=2; --j) {
					b[h+1][j] = cur;
					ans[cur].push_back((point){h+1, j});
				}
				b[h+1][1] = 1;
				ans[1][0].x = h+1;
				ans[1][0].y = 1;
			}
			else {
				ans[cur].push_back((point){h, 1});
				b[h][1] = cur;
				for(int j=1; j<=w-1; ++j) {
					b[h+1][j] = cur;
					ans[cur].push_back((point){h+1, j});
				}
				b[h+1][w] = 1;
				ans[1][0].x = h+1;
				ans[1][0].y = w;
			}
			h++;
			flag ^= 1;
		}
		// for(int i=1; i<=h; ++i) {
		// 	for(int j=1; j<=w; ++j) {
		// 		printf("%d ", b[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
	}
	// for(int i=1; i<=h; ++i) {
	// 	for(int j=1; j<=w; ++j) {
	// 		ans[b[i][j]].push_back((point){i, j});
	// 	}
	// }
}

// bool Judge(int x, int y) {
// 	if(x>=1 && x<=h && y>=1 && y<=w) return true;
// 	else return false;
// }

// void DFS(int x, int y, int cur) {
// 	vis[x][y] = true;
// 	ans[cur].push_back((point){x, y});
// 	for(int i=0; i<4; ++i) {
// 		int nx = x + dirt[i][0];
// 		int ny = y + dirt[i][1];
// 		if(Judge(nx, ny) && b[nx][ny]==cur && !vis[nx][ny]) {
// 			DFS(nx, ny, cur);
// 		}
// 	}
// }

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	a[1][1] = a[2][1] = 2;
	a[1][2] = a[1][3] = a[2][2] = 3;
	a[2][3] = 1;
	
	// s[1] = (point){2, 3};
	// s[1] = (point){1, 1};
	// s[1] = (point){1, 3};
	while(~ scanf("%d", &n)) {
		if(n == 1) {
			printf("1 1\n");
			printf("1 1\n");
		}
		else if(n == 2) {
			printf("1 3\n");
			printf("1 1\n");
			printf("1 2 1 3\n");
		}
		else if(n == 3) {
			printf("2 3\n");
			printf("2 3\n");
			printf("1 1 2 1\n");
			printf("1 3 1 2 2 2\n");
		}
		else {
			Calc(n);
			// for(int i=1; i<=n; ++i) {
			// 	DFS(s[i].x, s[i].x, i);
			// }
			printf("%d %d\n", h, w);
			for(int i=1; i<=n; ++i) {
				for(int j=0; j<ans[i].size(); ++j) {
					if(j) printf(" ");
					printf("%d %d", ans[i][j].x, ans[i][j].y);
				}
				printf("\n");
			}
		}
	}
	
	return 0;
}