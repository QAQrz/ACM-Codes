#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
struct info{
	int s[100110],idx;
}so[26];
char tmp[100110];
int fs[26][100110],w[130],max_len;
vector<string>s;
bool flag[130];
bool cmp(info a,info b){
	for(int i=0;i<max_len;i++)
		if(a.s[i]!=b.s[i])
			return a.s[i]<b.s[i];
	return 0;
}
int main(){
	int cases=0,n;
	while(~scanf("%d",&n)){
		s.clear();
		max_len=0;
		memset(flag,0,sizeof flag);
		for(int i=0;i<n;i++){
			scanf("%s",tmp);
			int tmp_len=strlen(tmp);
			if(tmp_len>1)
				flag[tmp[0]-'a']=1;
			s.push_back(tmp);
			max_len=max(max_len,tmp_len);
		}
		for(int i=0;i<26;i++)
			for(int j=0;j<max_len+10;j++)
				fs[i][j]=0;
		int max_pos=max_len-1;
		for(int j=0;j<n;j++){
			int len=s[j].length();
			for(int i=0;i<len;i++){
				int ch=s[j][len-1-i]-'a';
				fs[ch][i]++;
				if(fs[ch][i]>25)
					fs[ch][i+1]+=fs[ch][i]/26,fs[ch][i]%=26,max_pos=max(max_pos,i+1);
			}
		}
		for(int i=0;i<26;i++){
			int len=0;
			for(int j=max_pos;j;j--)
				so[i].s[len++]=fs[i][j];
			so[i].s[len]=0,so[i].idx=i;
		}
		sort(so,so+26,cmp);
		int idx=0;
		for(int i=0;i<26;i++)
			if(!flag[so[i].idx]){
				idx=i;
				break;
			}
		info bilegou=so[idx];
		for(int i=idx;i;i--)
			so[i]=so[i-1];
		so[0]=bilegou;
		memset(w,0,sizeof w);
		for(int i=0;i<26;i++)
			w['a'+so[i].idx]=i;
		long long ans=0;
		for(int j=max_pos;j>=0;j--){
			ans=(ans*26)%mod;
			for(int i=0;i<26;i++)
				ans=(ans+1LL*w['a'+i]*fs[i][j])%mod;
		}
		printf("Case #%d: %lld\n",++cases,ans);
	}
	return 0;
}