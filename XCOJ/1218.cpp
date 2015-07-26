/*************************************************************************
	> File Name: string_offeset.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Sun 07 Jun 2015 05:23:42 PM CST
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


void reverse(char *s, int start, int end) {
	for (int i = start; i <= (start+end)/2; ++i) {
		char t = s[i];
		s[i] = s[end+start-i];
		s[end+start-i] = t;
	}
	return;
}

int main()
{
#ifdef Oj
	  // freopen("string_offset.in", "r", stdin);
	  // freopen("string_offset.out", "w", stdout);
#endif
	int m, n;
	char s[1000];
	while(cin >> n >> m) {
		m%=n;
		getchar();
		for (int i = 0; i < n; ++i)
			s[i] = getchar();

		// for (int i = 0; i < n; ++i)
			// printf("%c", s[i]);
		// puts("");

		reverse(s, 0, max(m-1,0));
		reverse(s, m, n-1);
		reverse(s, 0, n-1);
		for (int i = 0; i < n; ++i)
			printf("%c", s[i]);
		puts("");

	}

	return 0;
}
