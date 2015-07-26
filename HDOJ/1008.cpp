////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-10 18:16:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1008
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1008.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Sun 10 May 2015 05:58:39 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <sstream>
#include <deque>
#include <functional>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <stack>
#include <set>
#include <numeric>
#include <utility>
#include <cstring>
using namespace std;

int main()
{
	int N;
	vector<int> elevator;
	while(cin>>N && N) {
		int layer;
		elevator.push_back(0);
		for(int i=0; i<N; ++i) {
			cin >> layer;
			elevator.push_back(layer);
		}
		int sum = 0;
		for(int i=1; i<=N; ++i) {
			if(elevator[i] > elevator[i-1])
				sum += (elevator[i] - elevator[i-1])*6+5;
			else
				sum += (elevator[i-1] - elevator[i])*4+5;
//			cout << sum << endl;


		}
		cout << sum << endl;
		elevator.clear();

	}

	return 0;
}