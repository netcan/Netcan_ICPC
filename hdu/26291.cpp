////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-17 23:52:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2629
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2629.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/9 15:28:25
 ************************************************************************/

#include<stdio.h>
int main() {
    static char id[19];
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int rgn,y,m,d;
        scanf("%s",id+1);
        printf("He/She is from ");
        rgn=(id[1]-'0')*10+(id[2]-'0');
        switch(rgn)
        {
            case 33:
                printf("Zhejiang,");
                break;
            case 11:
                printf("Beijing,");
                break;
            case 71:
                printf("Taiwan,");
                break;
            case 81:
                printf("Hong Kong,");
                break;
            case 82:
                printf("Macao,");
                break;
            case 54:
                printf("Tibet,");
                break;
            case 21:
                printf("Liaoning,");
                break;
            case 31:
                printf("Shanghai,");
                break;
        }
        printf("and his/her birthday is on ");
        y=(id[7]-'0')*1000+(id[8]-'0')*100+(id[9]-'0')*10+(id[10]-'0');
        m=(id[11]-'0')*10+(id[12]-'0');
        d=(id[13]-'0')*10+(id[14]-'0');
        printf("%02d,%02d,%04d based on the table.\n",m,d,y);


    }
    return 0;
}