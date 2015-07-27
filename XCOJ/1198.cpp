/*************************************************************************
    > File Name: 1005_a.c
    > Author: Netcan
    > Mail: 1469709759@qq.com
    > Created Time: Sun 26 Apr 2015 18:17:15 CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int  n,m;
    while(scanf("%d%d", &n, &m) == 2) {
        int count,x;
        count = 0;
        for(int i=0; i<n; ++i) {
            scanf("%d", &x);
            if(m > x)
                ++count;
        }
        printf("%d\n", count);

    }
    return 0;
}
