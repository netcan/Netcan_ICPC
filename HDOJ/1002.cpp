////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-07 15:38:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000],b[1000],c[1001];
	int i,j=1,p=0,n,n1,n2;
	scanf("%d",&n);
    while(n)
	{
		scanf("%s %s",a,b);
		printf("Case %d:\n",j);
		printf("%s + %s = ",a,b);
		n1=strlen(a)-1;
		n2=strlen(b)-1;
		for(i=0;n1>=0||n2>=0;i++,n1--,n2--)
		{
			if(n1>=0&&n2>=0){c[i]=a[n1]+b[n2]-'0'+p;}
			if(n1>=0&&n2<0){c[i]=a[n1]+p;}
			if(n1<0&&n2>=0){c[i]=b[n2]+p;}
			p=0;
			if(c[i]>'9'){c[i]=c[i]-10;p=1;}
		}
		if(p==1){printf("%d",p);}
		while(i--)
		{printf("%c",c[i]);}
		j++;
		if(n!=1){printf("\n\n");}
		else {printf("\n");}
		n--;
	}
}