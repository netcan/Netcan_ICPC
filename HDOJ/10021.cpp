////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-07 16:18:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1002.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/7 14:46:49
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main() {
	int T,t;
	scanf("%d",&T);
	static char a[1000],b[1000],c[1000];
	int la,lb,p,i;
	t=0;
	while(T--)
	{
		scanf("%s %s",a,b);
		printf("Case %d:\n",++t);
		printf("%s + %s = ",a,b);
		la=strlen(a)-1;
		lb=strlen(b)-1;
		p=0;
		for(i=0;la>=0 || lb>=0;la--,lb--,i++)
		{
			if(la>=0&&lb>=0)
				c[i]=a[la]+b[lb]-'0'+p;
			if(la>=0&&lb<0)
				c[i]=a[la]+p;
			if (la<0 && lb>=0)
				c[i]=b[lb]+p;
			p=0;
			if(c[i]>'9')
			{
				c[i]-=10;
				p=1;
			}
		}
		if(p==1)
			printf("1");
		while(i--)
			printf("%c",c[i]);
		if(T!=0)
			printf("\n\n");
		else
			printf("\n");
	}
	return 0;

}
