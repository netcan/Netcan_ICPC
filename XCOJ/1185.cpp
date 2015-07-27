/*************************************************************************
    > File Name: a.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2015/1/31 17:02:50
 ************************************************************************/
 
#include<stdio.h>
#include<math.h>
 
float a,b,c,d;
inline float f(float x) {
    return a*x*x*x+b*x*x+c*x+d;
}
inline float df(float x) {
    return 3.0*a*x*x+2.0*b*x+c;
}
 
int main()
{
    int flag = 0;
    while(scanf("%f%f%f%f",&a,&b,&c,&d) == 4) {
        if(flag)
            puts("");
        else flag = 1;
        float x = -10000;
        while(fabs(f(x/100)) > 10e-3)
            ++x;
        printf("%.2f ",x/100);
        x+=100;
        while(fabs(f(x/100)) > 10e-3)
            ++x;
        printf("%.2f ",x/100);
        x+=100;
        while(fabs(f(x/100)) > 10e-3)
            ++x;
        printf("%.2f",x/100);
    }
    return 0;
}
