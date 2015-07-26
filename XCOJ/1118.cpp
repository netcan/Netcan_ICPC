/*************************************************************************
    > File Name: 1118.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/12/21 23:32:08
 ************************************************************************/

#include<stdio.h>
int main() {
	int T;
	scanf("%d",&T);
	static int h[55];
	while(T--) {
		int N;
		int peaks = 0;
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%d",&h[i]);
		for(int i=1;i<N-1;i++)
			if(h[i] > h[i-1] && h[i] > h[i+1])
				peaks++;
		printf("%d\n",peaks);
	}

	return 0;
}

