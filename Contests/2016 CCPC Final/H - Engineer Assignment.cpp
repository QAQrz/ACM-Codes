#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int t, n, m, num, val;
int dp[11][1<<10];
vector<int> a[11], c[11], d[11];
inline bool Check(int idx, map<int, bool> &mp) {
	for(int i=0; i<c[idx].size(); ++i) {
		if(!mp[c[idx][i]]) return false;
	}
	return true;
}
void DFS(int idx, int begin, int st, map<int, bool> mp, map<int, bool> &mp_dest, int cur) {
	if(cur == 3) return;
	for(int i=begin; i<=m; ++i) {
		int dst = st | (1<<(i-1));
		bool ok = false;
		for(int j=0; j<d[i].size(); ++j) {
			if(mp_dest[d[i][j]]) {
				ok = true;
				mp[d[i][j]] = true;
			}
		}
		if(!ok) continue;
		if(Check(idx, mp))
			a[idx].push_back(dst);
		if(i+1 <= m) DFS(idx, i+1, dst, mp, mp_dest, cur+1);
		for(int j=0; j<d[i].size(); ++j) {
			if(mp_dest[d[i][j]]) mp[d[i][j]] = false;
		}
	}
}
void Init() {
	map<int, bool> mp_empty;
	for(int i=1; i<=n; ++i) {
		a[i].clear();
		map<int, bool> mp_dest;
		for(int j=0; j<c[i].size(); ++j) {
			mp_dest[c[i][j]] = true;
		}
		DFS(i, 1, 0, mp_empty, mp_dest, 0);
	}
}
int main(int argc, char const *argv[]) {
	scanf("%d", &t);
	for(int cs=1; cs<=t; ++cs) {
		scanf("%d %d", &n, &m);
		for(int i=1; i<=n; ++i) {
			c[i].clear();
			scanf("%d", &num);
			for(int j=0; j<num; ++j) {
				scanf("%d", &val);
				c[i].push_back(val);
			}
		}
		for(int i=1; i<=m; ++i) {
			d[i].clear();
			scanf("%d", &num);
			for(int j=0; j<num; ++j) {
				scanf("%d", &val);
				d[i].push_back(val);
			}
		}
		Init();
		memset(dp, 0, sizeof dp);
		for(int i=1; i<=n; ++i) {
			for(int j=0; j<(1<<m); ++j) {
				for(int k=0; k<a[i].size(); ++k) {
					if((j|a[i][k]) == j)
						dp[i][j] = max(dp[i][j], dp[i-1][j-a[i][k]]+1);
				}
				dp[i][j] = max(dp[i][j], dp[i-1][j]);
			}
		}
		printf("Case #%d: %d\n", cs, dp[n][(1<<m)-1]);
	}
	return 0;
}