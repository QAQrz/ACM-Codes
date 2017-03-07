#include <bits/stdc++.h>
using namespace std;
int n,k,num,x;
int main(){
	cin>>n>>k;
	while(1){
		cin>>x;
		num++;
		if(x<0||num>k){
			cout<<"Game Over"<<endl;
			return 0;
		}
		if(x!=n){
			if(x>n)
				cout<<"Too big"<<endl;
			else
				cout<<"Too small"<<endl;
			if(num>=k){
				cout<<"Game Over"<<endl;
				return 0;
			}
		}
		else{
			if(num<2)
				cout<<"Bingo!"<<endl;
			else if(num<4)
				cout<<"Lucky You!"<<endl;
			else
				cout<<"Good Guess!"<<endl;
			return 0;
		}
	}
	return 0;
}