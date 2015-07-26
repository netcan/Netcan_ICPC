////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-18 15:31:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2040
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2040.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/18 15:25:12
 ************************************************************************/

#include<stdio.h>
int main() {
	int A,B;
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&A,&B);
		int count=0;
		for(int i=1;i<A;i++) 
			if(A%i==0)	count+=i;
		if(count == B) {
			count =0;
			for(int i=1;i<B;i++) 
				if(B%i==0)	count+=i;
			if(count == A)	puts("YES");
			else			puts("NO");
		}
		else	puts("NO");


	}
	return 0;
}
