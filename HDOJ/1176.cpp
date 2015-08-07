/*************************************************************************
	> File Name: 最大子序列和O(N).cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Sat 06 Jun 2015 01:20:10 PM CST
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
#endif
	int n;
	cin >> n;
	int data[10006];
		for (int i = 0; i < n; ++i)
			cin >> data[i];
		int maxsum = -1;
		int sum = 0;
		int s, e;
		int istart=0;
		s = e = 0;
		for (int i = 0; i < n; ++i) {
			sum += data[i];
			if(sum > maxsum) {
				e = i;
				maxsum = sum;
				s = istart;
			}
			if(sum <0) {
				sum = 0;
				istart = i+1;
			}
		}

		if(maxsum == -1)
			printf("0 %d %d\n",0, n-1);
		else
		printf("%d %d %d\n", maxsum, s,e);

	return 0;
}
