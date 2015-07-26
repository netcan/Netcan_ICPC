////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-01 19:39:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2071
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
        int T;
        double a,b;
        int n;
        scanf("%d",&T);
        for ( int i=0;i<T;i++)
        {
                scanf("%d",&n);
                b=0.0;
                for(int j=0;j<n;j++)
                {
                        scanf("%lf",&a);
                        if(a>b)
                                b=a;
                }
                printf("%.2f\n",b);
        }
}

