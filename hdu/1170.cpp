////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-09 14:48:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1170
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1170.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/9 14:23:07
 ************************************************************************/

#include<stdio.h>
int main() {
	int T;
	char c;
	int a,b;
	double d;
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		scanf("%c %d %d",&c,&a,&b);
		getchar();
		switch(c)
		{
			case '+':
				printf("%d\n",a+b);
				break;
			case '-':
				printf("%d\n",a-b);
				break;
			case '*':
				printf("%d\n",a*b);
				break;
			case '/':
				d=double(a)/double(b);
				if(d-(int)d==0.0)
					printf("%.0f\n",d);
				else
					printf("%.2f\n",d);
				break;
		}
	}
	return 0;
}

