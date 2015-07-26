/*************************************************************************
    > File Name: 1005_b.c
    > Author: Netcan
    > Mail: 1469709759@qq.com
    > Created Time: Sun 26 Apr 2015 18:16:13 CST
 ************************************************************************/

#include <stdio.h>

static unsigned int count[2003005];
int main() {
	int id;
	while(scanf("%d",&id)==1) {
			count[id-12216000]++;
			printf("%d\n", count[id-12216000]);
		}
	return 0;
}
