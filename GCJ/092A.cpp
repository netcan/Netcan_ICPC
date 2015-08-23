/*************************************************************************
	> File Name: 092A.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-23 日 21:23:58 CST
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

bool Map[45][45]; // 矩阵信息
int a[45]; // 第i行最后一个1的位置a[i]
int N;

void solve() {
	int  T;
	cin >> T;
	int Case = 1;
	while(T--) {
		cin >> N;
		for(int i=1; i<=N; ++i)
			for(int j=1; j<=N; ++j)
				scanf("%1d", &Map[i][j]);

		// for(int i=1; i<=N; ++i) {
			// for(int j=1; j<=N; ++j)
				// printf("%d", Map[i][j]);
			// cout << endl;
		// }


		for(int i=1; i<=N; ++i) {
			a[i] = -1; // 不存在1
			for(int j=N; j>=1; --j)
				if(Map[i][j] == 1) {
					a[i] = j;
					break;
				}
		}

		int ans = 0;
		for(int i=1; i<=N; ++i) {
			int pos = -1; // 要移动的行
			for(int j=i; j<=N; ++j)
				if(a[j] <= i) {
					pos = j;
					break;
				}

			for(int j=pos; j>i; --j) {
				swap(a[j], a[j-1]);
				++ans;
			}
		}
		printf("Case #%d: %d\n", Case++, ans);

	}

}

int main()
{
#ifdef Oj
	freopen("092A.in", "r", stdin);
#endif
	solve();
	return 0;
}
