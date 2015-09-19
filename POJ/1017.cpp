/*************************************************************************
	> File Name: 1017.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-19 六 09:48:17 CST
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

int pack[7];

int  maxsize() {
	for(int i=6; i>=1; --i) if(pack[i] > 0) return i;
	return -1;
}



void solve() {
	int ans = 0;
	int maxs, remain;
	while(true) {
		maxs = maxsize();
		if(maxs == -1) break;
		// cout << maxs << endl;
		// cout << pack[3] << endl;

		switch (maxs) {
			case 6:
				ans += pack[6];
				pack[6] = 0;
				break;
			case 5:
				ans += pack[5];
				if(pack[1]/11.0 <= pack[5]*1.0)
					pack[1] = 0;
				else
					pack[1] -= pack[5]*11;
				pack[5] = 0;
				break;
			case 4:
				ans += pack[4];
				if(pack[2]/5.0 <= pack[4]*1.0) {
					pack[1] -= (pack[4]*36 - pack[2] * 4 - pack[4]*16);
					if(pack[1] < 0) pack[1] = 0;
					pack[2] = 0;
				}
				else
					pack[2] -= pack[4]*5;

				pack[4] = 0;
				break;
			case 3:
				ans += ceil(pack[3]/4.0);
				remain = pack[3] % 4;
				if(remain != 0) remain = 4 - remain;

				if(remain == 1) {
					if(pack[2] > 0) {
						--pack[2];
						pack[1] -= 5;
						if(pack[1] < 0) pack[1] = 0;
					}
					else {
						pack[1] -= 9;
						if(pack[1] < 0) pack[1] = 0;
					}
				}
				else if(remain == 2) {
					if(pack[2] >= 3) {
						pack[2] -= 3;
						pack[1] -= 6;
						if(pack[1] < 0) pack[1] = 0;
					}
					else {
						if(pack[2] == 1) {
							pack[1] -= 14;
							if(pack[1] < 0) pack[1] = 0;
						}
						else if(pack[2] == 2) {
							pack[1] -= 10;
							if(pack[1] < 0) pack[1] = 0;
						}
						else if(pack[2] == 0) {
							pack[1] -= 18;
							if(pack[1] < 0) pack[1] = 0;
						}
						pack[2] = 0;
					}
				}
				else if(remain == 3) {
					if(pack[2] >= 5) {
						pack[2] -= 5;
						pack[1] -= 7;
						if(pack[1] < 0) pack[1] = 0;
					}
					else {
						pack[1] -= (27-pack[2]*4);
						if(pack[1] < 0) pack[1] = 0;
						pack[2] = 0;
					}

				}
				pack[3] = 0;
				break;
			case 2:
				ans += ceil(pack[2]/9.0);
				remain = pack[2] % 9;
				pack[1] -= 36 - remain*4;
				if(pack[1] < 0) pack[1] = 0;
				pack[2] = 0;
				break;
			case 1:
				ans += ceil(pack[1]/36.0);
				pack[1] = 0;
				break;
		}
	}

	cout << ans << endl;
}

int main()
{
#ifdef Oj
	freopen("1017.in", "r", stdin);
#endif
	int zero = 0;
	int i = 1;
	while(cin >> pack[i++]) {
		if(pack[i-1] == 0) ++zero;
		if(zero == 6) break;
		if(i>6) {
			solve();
			i = 1;
			zero = 0;
		}
	}
	return 0;
}

