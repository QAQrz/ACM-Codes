#include <bits/stdc++.h>
using namespace std;
int t, n, m, a, b;
int main(){
	scanf("%d", &t);
	while(t--) {
		set<int> mk[55], ba[55];
		set<int>::iterator it1, it2;
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; ++i) {
			scanf("%d %d", &a, &b);
			mk[a].insert(b);
		}
		for(int i=0; i<m; ++i) {
			scanf("%d %d", &a, &b);
			ba[a].insert(b);
		}
		set<pair<int, int> > ans;
		set<pair<int, int> >::iterator it;
		for(int i=1; i<=50; ++i) {
			for(it1=mk[i].begin(); it1!=mk[i].end(); ++it1) {
				int bana = *it1;
				for(it2=ba[bana].begin(); it2!=ba[bana].end(); ++it2) {
					ans.insert(make_pair(i, *it2));
				}
			}
		}
		for(it=ans.begin(); it!=ans.end(); ++it) {
			printf("%d %d\n", it->first, it->second);
		}
		printf("\n");
	}
	return 0;
}