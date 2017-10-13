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

int week[2111][15][33];
int nth[2111][15][33];
pair<int, int> p1[2111], p2[2111];
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool IsLeap(int y) {
	if((y%4==0 && y%100!=0) || y%400==0) return true;
	else return false;
}

void Init() {
	week[2007][1][1] = 0;
	int cnt = -1;
	for(int i=2007; i<=2100; ++i) {
		for(int j=1; j<=12; ++j) {
			int num = days[j];
			if(j==2 && IsLeap(i)) num++;
			int weekcnt[7] = {0};
			for(int k=1; k<=num; ++k) {
				cnt++;
				week[i][j][k] = cnt%7;
				weekcnt[cnt%7]++;
				nth[i][j][k] = weekcnt[cnt%7];
				if(j==3 && (cnt%7)==6 && nth[i][j][k]==2)
					p1[i] = make_pair(j, k);
				if(j==11 && (cnt%7)==6 && nth[i][j][k]==1)
					p2[i] = make_pair(j, k);
			}
		}
	}
}

int Hash(int mo, int d, int h, int mi, int s) {
	int tmpd = mo*32 + d;
	int tmps = h*3600 + mi*60  + s;
	return tmpd*3600*24 + tmps;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	Init();
	// printf("%d  %d\n", nth[2016][3][13], week[2016][3][13]);
	int t, y, mo, d, h, mi, s;
	scanf("%d", &t);
	for(int cs=1; cs<=t; ++cs) {
		scanf("%d-%d-%d %d:%d:%d", &y, &mo, &d, &h, &mi, &s);
		int p1m = p1[y].first;
		int p1d = p1[y].second;
		int p2m = p2[y].first;
		int p2d = p2[y].second;
		// printf("%d %d | %d %d\n", p1m, p1d, p2m, p2d);
		int time1 = Hash(p1m, p1d, 2, 0, 0);
		int time2 = Hash(p1m, p1d, 3, 0, 0);
		int time3 = Hash(p2m, p2d, 1, 0, 0);
		int time4 = Hash(p2m, p2d, 2, 0, 0);
		int tm = Hash(mo, d, h, mi, s);
		// printf("%d  %d %d %d %d\n", tm, time1, time2, time3, time4);
		printf("Case #%d: ", cs);
		if(tm < time1) printf("PST\n");
		else if(tm>=time1 && tm<time2) printf("Neither\n");
		else if(tm>=time2 && tm<time3) printf("PDT\n");
		else if(tm>=time3 && tm<time4) printf("Both\n");
		else printf("PST\n");
	}
	
	return 0;
}