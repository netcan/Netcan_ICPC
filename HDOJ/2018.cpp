////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-08 21:44:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2018
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2018.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Fri 08 May 2015 21:30:04 CST
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
	int n;
	static int acow[60];
	while(cin>>n&&n!=0) {
		if(n<=4) {
			cout << n << endl;
			continue;
		}
		memset(acow, 0, sizeof(acow));
		acow[1] = acow[2] = acow[3] = acow[4] = 1;
		int cow = 4;
		for(int i=5; i<=n; ++i) {
			acow[i] = acow[i-1] + acow[i-3];
			cow += acow[i];
		}
		cout << cow << endl;
//		cout << acow[n] << endl;



	}

	return 0;
}