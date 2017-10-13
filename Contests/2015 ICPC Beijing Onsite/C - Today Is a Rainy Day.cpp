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

const int MAX = 46656;

int bak[6], a[6], step[MAX+1];
bool vis[MAX+1];
char s1[120], s2[120];
int cnt[6], dcnt[6][6];

int Hash(int a[]) {
	int ret = 0;
	for(int i=0; i<6; ++i) {
		ret = ret*6 + a[i];
	}

	return ret;
}

void RHash(int h, int a[]) {
	for(int i=5; i>=0; --i) {
		a[i] = h%6;
		h /= 6;
	}
}

void PrintArr(int a[]) {
	for(int i=0; i<6; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void BFS() {
	queue<int> q;
	for(int i=0; i<6; ++i) {
		a[i] = i;
	}
	int h = Hash(a);
	q.push(h);
	memset(step, 0x3f, sizeof step);
	step[h] = 0;
	while(!q.empty()) {
		int f = q.front();
		q.pop();
		RHash(f, bak);
		// printf("in f %d\n", f);
		// PrintArr(bak);
		for(int i=0; i<6; ++i) {
			for(int j=0; j<6; ++j) {
				if(j == i) continue;
				for(int k=0; k<6; ++k) {
					if(bak[k] == i)
						a[k] = j;
					else a[k] = bak[k];
				}
				// if(f == 1865) {
				// 	printf("%d %d\n", i, j);
				// 	PrintArr(a);
				// }
				h = Hash(a);
				if(!vis[h]) {
					step[h] = step[f] + 1;
					q.push(h);
					vis[h] = true;
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	BFS();
	// int a[] = {0, 2, 2, 3, 4, 5};
	// int h = Hash(a);
	// printf("%d %d\n", h, step[h]);
	// RHash(h, a);
	// for(int i=0; i<6; ++i) {
	// 	printf("%d ", a[i]);
	// }
	// printf("\n");
	while(~ scanf("%s %s", s1, s2)) {
		memset(cnt, 0, sizeof cnt);
		memset(dcnt, 0, sizeof dcnt);
		int ans = 0;
		for(int i=0; s2[i]; ++i) {
			cnt[s2[i]-'1']++;
			dcnt[s2[i]-'1'][s1[i]-'1']++;
			if(s2[i] != s1[i]) ans++;
		}

		for(int i=0; i<MAX; ++i) {
			// printf("here %d\n", i);
			RHash(i, a);
			// PrintArr(a);
			int tmp = step[i];
			for(int j=0; j<6; ++j) {
				tmp += cnt[j]-dcnt[j][a[j]];
			}
			ans = min(ans, tmp);
		}
		printf("%d\n", ans);
	}

	
	return 0;
}

/*
22345611
12345611
2234562221
1234561221
2234562211
1234561111
22345622112
12345611111
654321654321654321654321
123456123456123456123456
*/
// 12341561354123456135413216541312654123431211234561354132165431265431231234561354132165431265431221654312654312
// 12341561354123456135413216541312654123431211234561354132165431265431231234561354132165431265431221654312614312
// 11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
// 22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
