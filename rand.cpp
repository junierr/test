#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn=10000;
char s[maxn];
int main(){
	int n=rand()%10000+1;
	int m=rand()%(2*n)+1;
	printf("%d %d\n",n,m);
	while(m--){
		int t=rand()%n+1;
		int tt=rand()%n+1;
		//while(tt==t){
		//	tt=rand()%n+1;
		//}
		printf("%d %d\n",t,tt);
	}
	return 0;
}
