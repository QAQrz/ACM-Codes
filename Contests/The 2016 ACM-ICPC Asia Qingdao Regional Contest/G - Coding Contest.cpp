#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
const int INF = 2e9;
const int MAXN = 202;
const int MAXM = 44000;
const double eps=1e-6;
struct Edge{
	int to, next, cap, flow;
	double cost;
} edge[MAXM];
int head[MAXN], tol;
int pre[MAXN];
double dis[MAXN];
bool vis[MAXN];
int N;
void Init() {
	tol = 0;
	memset(head,-1,sizeof(head));
}
void AddEdge(int u, int v, int cap, double cost) {
	edge[tol].to = v;
	edge[tol].cap = cap;
	edge[tol].cost = cost;
	edge[tol].flow = 0;
	edge[tol].next = head[u];
	head[u] = tol++;
	edge[tol].to = u;
	edge[tol].cap = 0;
	edge[tol].cost = -cost;
	edge[tol].flow = 0;
	edge[tol].next = head[v];
	head[v] = tol++;
}
bool spfa(int s, int t) {
	queue<int>q;
	for(int i = 0; i < N; i++) {
		dis[i] = INF;
		vis[i] = false;
		pre[i] = -1;
	}
	dis[s] = 0;
	vis[s] = true;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = head[u]; i != -1; i = edge[i].next) {
			int v = edge[i].to;
			if(edge[i].cap>edge[i].flow &&
				  dis[v]-dis[u]-edge[i].cost>eps){
				dis[v] = dis[u] + edge[i].cost;
				pre[v] = i;
				if(!vis[v]){
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	if(pre[t] == -1) return false;
	else return true;
}
int minCostMaxflow(int s, int t, double &cost){
	int flow = 0;
	cost = 0;
	while(spfa(s,t)) {
		int Min = INF;
		for(int i = pre[t]; i != -1; i = pre[edge[i^1].to]) {
			if(Min > edge[i].cap - edge[i].flow)
					Min = edge[i].cap - edge[i].flow;
		}
		for(int i = pre[t]; i != -1; i = pre[edge[i^1].to]) {
			edge[i].flow += Min;
			edge[i^1].flow -= Min;
			cost += edge[i].cost * Min;
		}
		flow += Min;
	}
	return flow;
}
int main(int argc, char const *argv[]) {
	int T, n, m, a, b, c, s, t;
	double p;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &m);
		Init();
		s = 0;
		t = n+1;
		N = n+2;
		for(int i=1; i<=n; ++i) {
			scanf("%d %d", &a, &b);
			if(a > b) {
				a -= b;
				b = 0;
				AddEdge(s, i, a, 0);
			}
			else if(a == b) {
				a = b = 0;
			}
			else {
				b -= a;
				a = 0;
				AddEdge(i, t, b, 0);
			}
		}
		for(int i=0; i<m; ++i) {
			scanf("%d %d %d %lf", &a, &b, &c, &p);
			if(c<1)
				continue;
			if(c>1){
				AddEdge(a, b, c-1, -log2(1-p));
			}
			AddEdge(a, b, 1, 0);
		}
		double ans = 0;
		minCostMaxflow(s, t, ans);
		ans = pow(2, -ans);
		printf("%.2f\n", 1-ans);
	}
	return 0;
}