#include <cstdio>
#include <algorithm>
#include <set>
#include <functional>
using namespace std;
set<pair<int, int>, greater<pair<int, int> > > s1;
set<int> s2;
set<int>::iterator it, tmpit;
int main(int argc, char const *argv[]) {
	int t,n,a,b[112345];
	scanf("%d",&t);
	while(t--){
		s1.clear();
		s2.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
			s1.insert(make_pair(a,i));
			if(i>1)
				s2.insert(i);
		}
		while(s1.size()&&s2.size()){
			for(it=s2.begin(); it!=s2.end();) {
				if(s1.begin()->second%(*it)){
					b[*it]=s1.begin()->first;
					s2.erase(it++);
				}
				else it++;
			}
			s1.erase(s1.begin());
		}
		for(int i=2;i<=n;i++)
			printf("%d%c",b[i],i<n?' ':'\n');
	}
	return 0;
}