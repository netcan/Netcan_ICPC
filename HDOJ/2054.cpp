////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-18 16:00:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2054
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2054.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/18 14:41:31
 ************************************************************************/

#include<stdio.h>
#include<string.h>
	static char num[100000];
	static char num2[100000];
int main() {
	while(scanf("%s%s",num,num2)==2) {
		int len=strlen(num);
		int len2=strlen(num2);
		int i,j,k;
		for(j=0;j<len;j++) 
			if(num[j]=='.') {
//			printf("j=%d\n",j);
				for(k=len-1;k>=j;k--) {
				if(num[k]!='0')		break;
				if(num[k]=='0')		num[k]=0;
				}
				break;
			}
			if(j==k)	num[j]=0;
		
		for(j=0;j<len2;j++) 
			if(num2[j]=='.') {
//				printf("j=%d\n",j);
				for(k=len2-1;k>=j;k--) {
				if(num2[k]!='0')		break;
				if(num2[k]=='0')		num2[k]=0;
				}
				break;
			}
			if(j==k)	num2[j]=0;
//		printf("num=%s\n",num2);
		
		for(i=0;i<len;i++) 
			if(num[i]!=num2[i])	break;
		if(i==len)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
