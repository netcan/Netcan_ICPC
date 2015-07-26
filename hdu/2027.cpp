////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-17 08:23:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2027
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2027.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/17 8:05:42
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main() {
	static int yy[6];
	static char s[110];
	int n;
	scanf("%d",&n);
	getchar();
	while(n--) {
		gets(s);
		int len=strlen(s);
		memset(yy,0,6*sizeof(yy[0]));
		for(int i=0;i<len;i++)
			switch(s[i])	{
			case 'a':
			case 'A':
				yy[1]++;
					break;
			case 'e':
			case 'E':
				yy[2]++;
					break;
			case 'i':
			case 'I':
				yy[3]++;
					break;
			case 'o':
			case 'O':
				yy[4]++;
					break;
			case 'u':
			case 'U':
				yy[5]++;
					break;
			}
		if(n!=0)
			printf("a:%d\n"
					"e:%d\n"
					"i:%d\n"
					"o:%d\n"
					"u:%d\n\n",yy[1],yy[2],yy[3],yy[4],yy[5]);
		else
			printf("a:%d\n"
					"e:%d\n"
					"i:%d\n"
					"o:%d\n"
					"u:%d\n",yy[1],yy[2],yy[3],yy[4],yy[5]);
	}


	return 0;
}
