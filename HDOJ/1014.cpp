////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-11 22:05:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1014
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1580KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1014.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Mon 11 May 2015 09:38:04 PM CST
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
	int STEP, MOD;
	while(cin >> STEP >> MOD) {
		int seek = 0;
		bool yes = false;
		for(int i=1; i<=MOD; ++i) {
			seek = (seek+STEP) % MOD;
			if(seek == 0) {
//				cout << i << endl;
				if(i == MOD)
					yes = true;
				else
					yes = false;
				break;
			}
		}
		if(yes)
			printf("%10d%10d    Good Choice\n\n", STEP, MOD);
		else
			printf("%10d%10d    Bad Choice\n\n", STEP, MOD);
		// for(int i=0; i<100; ++i) {
			// cout << seek[i] << " ";
		// }
		// cout << endl;

	}

	return 0;
}