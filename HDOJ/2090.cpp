////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-23 16:20:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2090
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:264KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2090.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/23 16:05:54
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main() {
	double sl,dj,cj=0.0;
	int i=0;
	while(scanf("%*s%lf%lf",&sl,&dj)==2){
		cj+=sl*dj;
	}
	printf("%.1f\n",cj);
	return 0;
}
