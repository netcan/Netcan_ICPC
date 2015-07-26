/*************************************************************************
	> File Name: 1005_c.c
	  > Author: Netcan
	  > Mail: 1469709759@qq.com
	  > Created Time: Tue 28 Apr 2015 10:16:34 CST
 ************************************************************************/

#include<stdio.h>

double min(double a, double b) {
	return a>b?b:a;
}
 
int main()
{

	int A,B,L;
	double s,s2;
	double min = 9999;
	int mini=0,minj=0;
	scanf("%d%d%d", &A, &B, &L);
	s = (double)A/(double)B;
	if(A == B)
		puts("1 1");
	if(A > B) {
		for(int i=1; i<=L; ++i) // 分子
			for(int j=1; j<=i; ++j) { // 分母
				if(i % j == 0)
					continue;
				s2 = (double)i/(double)j;
				if(s2 - s > 0)
					if(min > s2-s) {
						min = s2-s;
						mini = i;
						minj = j;
					}
			}
		printf("%d %d\n", mini, minj);
	}
	if(A<B) {
		for(int i=1; i<=L; ++i) // 分母
			for(int j=1; j<=i; ++j) { // 分子 < 分母 j < i
				if(i%j == 0)
					continue;
			s2 = (double)j/(double)i;
				if(s2 - s > 0)
					if(min > s2-s) {
						min = s2-s;
						mini = i;
						minj = j;
					}
			}
		printf("%d %d\n", minj, mini);
	}



	return 0;
}

