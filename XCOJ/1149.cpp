/*************************************************************************
    > File Name: 1149.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2015/4/13 22:30:56
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main()
{
	char n[10] = {
		2,0,1,2,0,9,1,7,9,8
	};
	static char num[100];
	
	while(scanf("%s",num) == 1) {
		int sum = 0;
		for(int i=strlen(num)-1; i>=0; --i) 
			sum+=n[num[i]-'0'];
		printf("%d\n", sum);
	}
	return 0;
}

