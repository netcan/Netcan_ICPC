////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-07-04 10:52:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2069
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2069_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-07-04 Sat 10:47:48 CST
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
	int n,count;
	while(cin >> n) {
		count = 0;
		for(int i=0; i*50<=n; ++i)
			for(int j=0; j*25<=n; ++j)
				for(int k=0; k*10<=n; ++k)
					for(int l=0; l*5<=n; ++l)
						if((n - i*50 - j*25 - k*10 - l*5 >=0) && i+j+k+l+n-i*50-j*25-k*10-l*5<=100)
							++count;
		cout << count << endl;


	}

	return 0;
}