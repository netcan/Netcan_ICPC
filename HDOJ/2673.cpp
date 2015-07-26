////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-25 16:06:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2673
////Problem Title: 
////Run result: Accept
////Run time:531MS
////Run memory:536KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2673.cpp
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/25 15:30:50
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

bool cmp(const int& a,const int& b ) {
	return a>b;
}
int main() {
	vector<int > max;
	vector<int > min;
	int N;
	while(scanf("%d",&N)==1){
		int n;
		for(int i=0;i<N;i++){
			cin >> n;
			min.push_back(n);
		}
		max=min;
		sort(min.begin(),min.begin()+N);
		sort(max.begin(),max.begin()+N,cmp);
		cout << max.at(0);
		int j=0,k=1;
		for(int i=1;i<N;i++){
			if(i%2==1){
				cout << ' ' << min.at(j); 
				j++;
			}
			else {
			cout << ' ' << max.at(k);
				k++;
			}
		}
		cout << endl;
		vector<int>().swap(max);
		vector<int>().swap(min);
		
		
	}
	return 0;
}
