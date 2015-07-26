////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-06-19 17:13:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1800
////Problem Title: 
////Run result: Accept
////Run time:982MS
////Run memory:1792KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1800.cpp
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2015/6/19 16:28:19
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;

void load(char *num) {
	char c;
	int i = 0;
	bool zero = true;
	while((c=getchar())!='\n') {
		if(c!='0')
			zero = false;
		if(!zero) num[i++] = c;
	}
	if(i==0)
		num[i++] = '0';
	num[i] = 0;
}

int main() {
	int N;
	map<string, int> level;
	char num[32];
	while(scanf("%d", &N) == 1) {
		int ans=0;
		getchar();
		for(int i=0; i<N; ++i)  {
			load(num);
			string Num(num);
			++level[Num];
			ans = max(level[Num], ans);
		}
		printf("%d\n", ans);
		level.clear();
	}
	return 0;
}
