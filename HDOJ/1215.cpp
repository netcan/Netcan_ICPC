////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-12-02 15:09:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1215
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:224KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1215.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/12/2 14:51:37
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main() {
	int T;
	scanf("%d",&T);
	int n=0;
	while(T--) {
		scanf("%d",&n);
		int q=sqrt(n);
		int r=1;
		for(int i=2;i<=q;i++) 
			if(n%i == 0)
				if(n/i!=i)	r+=i+n/i;
				else		r+=i;
		printf("%d\n",r);
		
	}

	return 0;
}
