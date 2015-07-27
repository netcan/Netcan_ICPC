/*************************************************************************
    > File Name: h.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2015/2/1 8:56:28
 ************************************************************************/
 
#include<stdio.h>
#include<math.h>
 
int main()
{
    int N;
    float R;
    while(scanf("%d%f",&N,&R) == 2)  {
        float x1,y1,x2,y2,l = 0.0;
        float x0,y0;
        if(N == 1) {
            scanf("%f%f",&x1,&y1);
            printf("%.2f\n",2.0*3.14*R);
            continue;
        }
        if(N == 2) {
            scanf("%f%f",&x1,&y1);
            scanf("%f%f",&x2,&y2);
            l += sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
            printf("%.2f\n", l + 2 * 3.14 * R);
            continue;
        }
 
 
 
        scanf("%f%f",&x0,&y0);
        x1 = x0;
        y1 = y0;
        N--;
        while(N--) {
            scanf("%f%f",&x2,&y2);
            l += sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
            x1 = x2;
            y1 =y2;
        }
        l += sqrt((x0-x2)*(x0-x2) + (y0-y2)*(y0-y2));
        printf("%.2f\n", l + 2 * 3.14 * R);
    }
    return 0;
}
