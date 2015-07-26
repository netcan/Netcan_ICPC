////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-11 17:03:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1071
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1436KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1071.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Mon 11 May 2015 16:07:05 CST
 ************************************************************************/


#include<stdio.h>

double w, h, x1, x2, y1, y2;
double a, k, b;
double f(double x) {
	return a*x*x*x/3 - (a*w+k/2)*x*x+(a*w*w+h-b)*x;
}
int main()
{
//	freopen("1071.data", "r", stdin);
	int T;
	scanf("%d", &T);
		while(T--) {
			scanf("%lf%lf", &w, &h);
			scanf("%lf%lf", &x1, &y1);
			scanf("%lf%lf", &x2, &y2);

			a = (y1 - h)/((x1-w)*(x1-w));
			k = (y2-y1)/(x2-x1);
			b = y1 - k*x1;
//			printf("w=%lf h=%lf x1=%lf y1=%lf x2=%lf y2=%lf\n", w, h, x1 , y1, x2, y2);
//			printf("a=%lf k=%lf b=%lf\n", a, k, b);
//			printf("f(x1)=%lf f(x2)=%lf\n", f(x1), f(x2));
			printf("%.2lf\n", f(x2) - f(x1));
		}
	return 0;
}