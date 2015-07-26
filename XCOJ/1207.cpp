/*************************************************************************
	> File Name: 1350.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Mon 25 May 2015 02:34:32 PM CST
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
	freopen("1350.data", "r", stdin);
#endif
	int T;
	cin >> T;
	map<double, bool> s;
	pair<int, int> P[1005];
	while(T--) {
		int n;
		cin >> n;
		for(int i=0; i<n; ++i)
			cin >> P[i].first >> P[i].second;
		for(int i=0; i<n; ++i)
			for(int j=i+1; j<n; ++j) {
				if(P[i].first - P[j].first == 0)
					continue;
				else{
					double k = (P[i].second - P[j].second)*1.0 / (P[i].first - P[j].first)*1.0;
					if(!s.count(k))
						s[k] = true;
				}
			}
		cout << s.size() << endl;
		s.clear();

	}

	return 0;
}
