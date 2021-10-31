#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c>9||c<0){if(c==-)f=-f;c=getchar();}
	while(c>=0&&c<=9){x=x*10+c-0;c=getchar();}
	return x*f;
}
int T,n,a[101010],lm[101010];
main(){lm[1]=1;
	T=read();
	while(T--){int ans;
		int a=read(),b=read();
		if(a>b){
			ans=a+b;
		}
		else if(a==b){
			ans=a;
		}
		else{
			int G=b%a;
			ans=b-G/2;
		}
		if(ans%a==b%ans)printf("%lld
",ans);
	}
} 
