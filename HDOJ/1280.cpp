////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-24 15:22:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1280
////Problem Title: 
////Run result: Accept
////Run time:703MS
////Run memory:18048KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1280.cpp
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/24 14:35:00
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}
int main() {
	int N,M;
	static int num[3005];
	static int out[4500000];
	while(scanf("%d%d",&N,&M)==2) {
		int count=0;
		for(int i=0;i<N;i++) 
			cin >> num[i];
		
		for(int i=0;i<N;i++)
			for(int j=i+1;j<N;j++)
					out[count++]=num[i]+num[j];
		sort(out,out+N*(N-1)/2,cmp);
		for(int i=0;i<M;i++)
			if(i == 0)	cout << out[i];
			else		cout << ' ' << out[i];
		cout << endl;
		
	}
	return 0;
}
