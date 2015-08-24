/*************************************************************************
	> File Name: 091CC.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-24 一 15:19:45 CST
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
// Bribe the Prisoners

int N, P, Q;
int A[10005];
int dp[10005][10005];

void solve() {
	cin >> N;
	int Case = 1;
	while(N--) {
		cin >> P >> Q;
		for(int i=1; i<=Q; ++i)
			cin >> A[i];
		A[0] = 0;
		A[Q+1] = P+1;
		for(int i=0; i<=Q; ++i)
			dp[i][i+1] = 0;
		for(int w=2; w<=Q+1; ++w) {
			for(int i=0; i+w<=Q+1; ++i) {
				int j = i+w, t = 0x3f3f3f3f;
				for(int k=i+1; k<j; ++k)
					t= min(t, dp[i][k] + dp[k][j]);
				dp[i][j] = t + A[j] - A[i] - 2;
			}
		}
		printf("Case #%d: %d\n", Case++, dp[0][Q+1]);
	}
}

int main()
{
#ifdef Oj
	freopen("091CC.in", "r", stdin);
#endif
	solve();
	return 0;
}
