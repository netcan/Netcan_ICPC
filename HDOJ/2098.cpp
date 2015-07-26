////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-26 17:03:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2098
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:284KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2098.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/23 17:16:55
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main() {
	static int ss[10005];
	int i,j;
	for(i=2;i<=10000;i++) {
		for(j=2;j<i;j++)
			if(i%j==0)
				break;
		if(j==i) ss[i]=1;
	}	
	int n;
//	for(i=0;i<=10000;i++)
//		if(ss[i]) printf("%d, ",i);
	while(scanf("%d",&n)==1 && n) {
		int count=0;
		for(int k=2;k<n/2;k++)
			if(ss[k]&&ss[n-k])
				count++;
		printf("%d\n",count);
	}
	

	return 0;
}
