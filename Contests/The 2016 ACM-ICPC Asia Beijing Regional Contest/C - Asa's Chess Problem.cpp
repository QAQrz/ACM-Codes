#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 51;
const int MAXM = 15000;
const int N = 110;
const int INF = 0x3f3f3f3f;
struct edge {
	int u, v, f, c;
	int next;
} e[MAXM<<1];
int n, g[MAXN][MAXN], R[MAXN], C[MAXN], l, r, X1, Y1, X2, Y2;
int ridx[MAXN], cidx[MAXN];
int S, T, SS, TT;
int head[N], cnt;
int d[N], dis[N], pre[N];

void Init() {
	memset(head, 0, sizeof(head));
	cnt = 1;
	memset(d, 0, sizeof(d));
}
inline void Add(int u, int v, int f, int c) {
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].f = f;
	e[cnt].c = c;
	e[cnt].next = head[u];
	head[u] = cnt;
}
inline void AddEdge(int u, int v, int lf, int hf, int c) {
	d[u] -= lf;
	d[v] += lf;
	Add(u, v, hf-lf, c);
	Add(v, u, 0, -c);
}
bool SPFA(int s, int t) {
	bool flag = false;
	memset(dis, 0x3f, sizeof(dis));
	memset(pre, 0, sizeof(pre));
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(u == t) flag = true; 
		for(int i=head[u]; i; i=e[i].next) {
			if(e[i].f>0 && dis[u]+e[i].c < dis[e[i].v]) {
				dis[e[i].v] = dis[u] + e[i].c;
				pre[e[i].v] = i;
				q.push(e[i].v);
			}
		}
	}
	return flag;
}
pair<int, int> MCMF(int s, int t) {
	int max_flow = 0, min_cost = 0;
	while(SPFA(s, t)) {
		int flow = INF;
		int g = pre[t];
		while(g) {
			flow = min(flow , e[g].f);
			g = pre[e[g].u];
		}
		g = pre[t];
		while(g) {
			e[g].f -= flow;
			e[g^1].f += flow;
			min_cost += e[g].c * flow;
			g = pre[e[g].u];
		}
		max_flow += flow;
	}
	return make_pair(max_flow, min_cost);
}
int main(int argc, char const *argv[]) {
	while(~ scanf("%d", &n)) {
		Init();
		memset(R, 0, sizeof(R));
		memset(C, 0, sizeof(C));
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=n; ++j) {
				scanf("%d", &g[i][j]);
				if(g[i][j]) {
					R[i]++;
					C[j]++;
				}
			}
		}
		for(int i=1; i<=n; ++i) {
			ridx[i] = i;
		}
		for(int i=1; i<=n; ++i) {
			cidx[i] = n + i;
		}
		S = n*2 + 1;
		T = S + 1;
		for(int i=1; i<=n; ++i) {
			scanf("%d %d", &l, &r);
			AddEdge(S, ridx[i], R[i], R[i], 0);
			AddEdge(ridx[i], T, l, r, 0);
		}
		for(int i=1; i<=n; ++i) {
			scanf("%d %d", &l, &r);
			AddEdge(S, cidx[i], C[i], C[i], 0);
			AddEdge(cidx[i], T, l, r, 0);
		}
		for(int i=0; i<n*n/2; ++i) {
			scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
			if(g[X1][Y1] != g[X2][Y2]) {
				if(g[X1][Y1] == 0) {
					swap(X1, X2);
					swap(Y1, Y2);
				}
				if(X1 == X2) AddEdge(cidx[Y1], cidx[Y2], 0, 1, 1);
				else AddEdge(ridx[X1], ridx[X2], 0, 1, 1);
			}
		}
		AddEdge(T, S, 0, INF, 0);
		SS = T + 1; TT = SS + 1;
		for(int i=1; i<=T; ++i) {
			if(d[i] < 0) {
				Add(i, TT, -d[i], 0);
				Add(TT, i, 0, 0);
			}
			if(d[i] > 0) {
				Add(SS, i, d[i], 0);
				Add(i, SS, 0, 0);
			}
		}
		int ans = MCMF(SS, TT).second;
		for(int i=head[SS]; i; i=e[i].next) {
			if(e[i].f)
				ans = -1;
		}
		printf("%d\n", ans);
	}
	return 0;
}