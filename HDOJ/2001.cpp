////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-10-31 16:33:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2001
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2001.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/10/31 16:13:43
 ************************************************************************/

#include<stdio.h>
#include<math.h>
struct p
{
	float x,y;
};
int main() {
	p p1,p2;
	float d;
	while(scanf("%f%f%f%f",&p1.x,&p1.y,&p2.x,&p2.y)!=EOF)
	{
		d=sqrt(((float)p1.x-(float)p2.x)*((float)p1.x-(float)p2.x)+((float)p1.y-(float)p2.y)*((float)p1.y-(float)p2.y));
		printf("%.2f\n",d);
	}
	return 0;
}
