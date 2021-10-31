#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define rep(i,x,y) for(int i=x;i<=y;i++)
int a,n,T;
int main(){
	cin>>T;
	while(T--){
		scanf("%d",&n);
		if(n%2==0){
			printf("YES
");rep(i,1,n)scanf("%d",&a);
			continue;
		}
		int flag=1,mx=0;;
		rep(i,1,n){
			scanf("%d",&a);
			if(a<=mx&&flag){
				printf("YES
");
				flag=0;
			}
			mx=a;
		}
		if(flag){
			printf("NO
");
		}
	}
} 
