////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-09 23:29:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2064
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1404KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main(){
	int i,n;
	__int64 a[100];
	while(scanf("%d",&n)==1){
		a[1]=2;
		for(i=2;i<=n;i++){
			a[i]=3*a[i-1]+2;
		}
		printf("%I64d\n",a[n]);
	}
}