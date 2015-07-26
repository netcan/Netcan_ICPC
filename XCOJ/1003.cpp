/*************************************************************************
    > File Name: 1003.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2015/4/13 14:19:49
 ************************************************************************/

#include<stdio.h>
#include<string.h>

static int Matrix[35][35];
void printm(int n) {
	for(int j = 1; j<=n; ++j) {
			for(int i = 1; i<=n; ++i)
				printf("%4d", Matrix[j][i]);
			puts("");
		}
}
void f(int n) {
	int step = 1;
	int x=1,y=1;
	int flag = 1;
	while(step <= n*n) {
		Matrix[y][x] = step;
//		printf("(%d,%d) flag = %d step = %d\n",x,y,flag,step);
		++step;
		if(flag == 1) { // 右移
			if(x<n) ++x;
			if(x!=n && y!=n) flag = 2;
			else if(x==n && y!=n)flag = 3;
			else if(x!=n && y==n) flag =4;
			continue;
		}
		if(flag == 2) { // 左下移
			if(x>1 && y<n) {
				--x;
				++y;
				if(x==1 && y!=n)
					flag = 3;
				if(y==n)
					flag = 1;
			}
			continue;
		}
		if(flag == 3) { // 下移
			if(y<n) ++y;
			if(x == n)
			flag = 2;
			else 
				flag = 4;
			continue;
		}
		if(flag == 4) { // 右上移
			if(y > 1 && x< n) {
				--y;
				++x;
				if(y==1 && x!=n)
					flag = 1;
				else if(y==1 && x==n)
					flag = 3;
				else if(y!=n && x==n)
					flag = 3;
			}
			continue; 
		}
	}
}

void  g(int n) {
	int x=1,y=n;
	int step = n*n;
	int flag = 1;
	for(int i=0; i<=n+1; ++i)
			memset(Matrix[i], 0, sizeof(int)*(n+2));
	while(step >= 1) {
		Matrix[y][x] = step;
//		printf("(%d,%d) flag = %d step = %d\n",x,y,flag,step);
	//	printm(n);
	//	puts("");
		--step;
		if(flag == 1) { // 上移
			if(y>1 && !Matrix[y-1][x]) --y;
			else flag = 2;
		}
		if(flag == 2) { // 右移
				if(x<n && !Matrix[y][x+1]) ++x;
				else flag = 3;
		}
		if(flag == 3) { // 下移
				if(y<n && !Matrix[y+1][x]) ++y;
				else flag = 4;
		}
		if(flag == 4) { // 左移
				if(x>1 && !Matrix[y][x-1]) --x;
				if(Matrix[y][x-1]) flag = 1;
		}
	}
}



int main()
{
	int n;
	while(scanf("%d", &n) == 1) {
		f(n);
		printm(n);
		puts("");
		g(n);
		printm(n);
	}
	return 0;
}

