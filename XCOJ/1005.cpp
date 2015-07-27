/*************************************************************************
	> File Name: 1005_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Wed 06 May 2015 08:28:23 CST
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
	static char s1[1002];
	static char s2[1002];
	static int maxlen[1002][1002];
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%s", s1);
		int count = 0;
		memset(maxlen, 0, sizeof(maxlen));
		int len = strlen(s1);
		for(int i=0; i<len; ++i)
			s2[i] = s1[len-i-1];
//		printf("%s\n", s2);

		for(int i=0; i<len; ++i) {
			for(int j=0; j<len; ++j) {
				if(i==0 || j==0)
					maxlen[i][j] = 0;
				else {
					if(s1[i] == s2[j])
						maxlen[i][j] = maxlen[i-1][j-1] + 1;
					else
						maxlen[i][j] = max(maxlen[i][j-1], maxlen[i-1][j]);
				}
			}
		}
		printf("%d\n", len - (maxlen[len-1][len-1] + 1));


	}

	return 0;
}
