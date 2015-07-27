/*************************************************************************
    > File Name: g.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2015/2/1 8:02:17
 ************************************************************************/
 
#include<stdio.h>
#include<string.h>
 
bool testdata(int *test)
{
    for(int i=1; i<=9; ++i)
        if(!test[i]) return false;
    return true;
}
 
int main()
{
    int n;
    int sudu[10][10];
    int test[10];
    const char *result[2] = {"Wrong", "Right"};
    int stat = 1;
 
    scanf("%d",&n);
    while(n--) {
        stat = 1;
        memset(test, 0, 10);
        for(int j = 1; j <= 9; ++j)
            for(int i = 1; i <= 9; ++i)
                scanf("%d",&sudu[j][i]);
// 宫 
    if(stat) {
        int x = 1,y = 1;
        while(y <= 7) {
            int X = x+2;
            int Y = y+2;
            for(int j = y; j<= Y; ++j) {
                for(int i = x; i <= X; ++i)
                    test[sudu[j][i]] = 1;
            }
            if(!testdata(test)) {
                stat = 0;
                break;
            }
            x += 3;
            if(x > 7) {
                x = 1;
                y += 3;
            }
            memset(test, 0, 10);
        }
    }
// 行
    if(stat) {
        memset(test, 0, 10);
        for(int j = 1; j <=9; ++j) {
            for(int i = 1; i <= 9; ++i)
                    test[sudu[j][i]] = 1;
            if(!testdata(test)) {
                stat = 0;
                break;
            }
            memset(test, 0, 10);
        }
    }
// 列
    if(stat) {
        memset(test, 0, 10);
        for(int i = 1; i <= 9; ++i) {
            for(int j = 1; j <=9; ++j) 
                test[sudu[j][i]] = 1;
            if(!testdata(test)) {
                stat = 0;
                break;
            }
            memset(test, 0, 10);
        }
    }
 
    puts(result[stat]);
    }
    return 0;
}
