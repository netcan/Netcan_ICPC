////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-18 17:10:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2055
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2055.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/18 16:37:57
 ************************************************************************/

#include<stdio.h>
int main() {
	int T;
	scanf("%d",&T);
	getchar();
	int x,y;
	while(T--) {
		x=y=0;
		scanf("%c%d",&x,&y);
		getchar();
//		printf("x=%c(%d) y=%d\n",(char)x,(int)x,y);
		if((char)x>='A' && (char)x<='Z')	x=x-'A'+1;
		else								x=-(x-'a'+1);
		printf("%d\n",x+y);
	}

	return 0;
}
