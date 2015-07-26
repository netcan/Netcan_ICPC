////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-24 08:00:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1040
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:344KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1040.cpp
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/24 7:54:44
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main() {
	int T;
	int n;
	static int num[1010];
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		sort(num,num+n);
		for(int i=0;i<n;i++)
			if(i==0) printf("%d",num[i]);
			else	printf(" %d",num[i]);
		puts("");
		
	}
	return 0;
}

