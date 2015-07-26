////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-19 22:03:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2033
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2033.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/19 21:54:20
 ************************************************************************/

#include<stdio.h>
int main() {
	struct time {
		int h,m,s;
	} A,B,C;
	int N;
	scanf("%d",&N);
	while(N--) {
		scanf("%d%d%d%d%d%d",&A.h,&A.m,&A.s,&B.h,&B.m,&B.s);
		C.s=A.s+B.s;
		if(C.s>=60)	C.m=A.m+B.m+1;
		else		C.m=A.m+B.m;
		if(C.m>=60)	C.h=A.h+B.h+1;
		else		C.h=A.h+B.h;
		C.s%=60;
		C.m%=60;
		printf("%d %d %d\n",C.h,C.m,C.s);
	}
	return 0;
}
