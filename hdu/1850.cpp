////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-07-26 16:09:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1850
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1850.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-26 Sun 15:26:28 CST
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
#ifdef Oj
	// freopen(".in", "r", stdin);
#endif
	int M;
	// cout << 22^57<< endl;
	int h[101];
	while(cin >> M && M) {
		for(int i=0; i<M; ++i)
			cin >> h[i];
		int result = h[0];
		for(int i=1; i<M; ++i)
			result^=h[i];
		if(result) {
			int ans = 0;
			for(int i=0; i<M; ++i)
				if((result^h[i]) < h[i])
					++ans;
			cout << ans << endl;
		}
		else
			cout << 0 << endl;

	}

	return 0;
}