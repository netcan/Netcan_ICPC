////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-17 07:13:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2020
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2020.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/17 6:50:51
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void * a,const void * b)
{
	return abs(*(int*)b)-abs(*(int*)a);
}
int main() {
	int n;
	static int num[110];
	static int num_c[110];
	while(scanf("%d",&n)==1 && n) {
		for(int i=0;i<n;i++) 
			scanf("%d",&num[i]);
		qsort(num,n,sizeof(num[0]),cmp);
		for(int i=0;i<n;i++) 
			if(0 == i)	printf("%d",num[i]);
			else	printf(" %d",num[i]);
		puts("");
	}
		
	return 0;
}

