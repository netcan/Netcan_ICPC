/*************************************************************************
	> File Name: 1214.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Wed 27 May 2015 11:47:56 AM CST
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

int tree[105];
int n, N;
bool dfs(int l, int r) {
	// printf("Lvi=%d Rvi=%d\n", tree[l], tree[r]);
	if(l > N && r>N)
		return true;
	if((tree[l] != tree[r]) || (tree[l] == 0 && tree[r]!=0) || (tree[l]!=0 && tree[r]==0))
		return false;
	return dfs(2*l, 2*r+1) && dfs(2*l+1, 2*r);
}



int main()
{
#ifdef Oj
	 freopen("1214.in", "r", stdin);
#endif
	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		N = 2*n+1;
		int a, b, c;
		memset(tree, 0, sizeof(tree));
		tree[1] = 1;
		for(int i=0; i<n; ++i) {
			cin >> a >> b >> c;
			// printf("a=%d b=%d c=%d\n", a,b,c);
			tree[2*a] = b;
			tree[2*a+1] = c;
		}
		// for(int nodes=1; nodes<=2*n; ++nodes)
			// cout << tree[nodes] << " ";
		// cout << endl;

		int vi;
		int i=0;
		for(int nodes=1; nodes<=n; ++nodes) {
			cin >> vi;
			for(; i<=N; ++i)
				if(tree[i] == nodes)  {
					tree[i] = vi;
					++i;
					break;
				}
		}
		 // for(int nodes=1; nodes<=N; ++nodes)
			 // cout << tree[nodes] << " ";
		 // cout << endl;
		if(n==1) {
			cout << "Yes" << endl;
			continue;
		}
		if(n==2) {
			cout << "No" << endl;
			continue;
		}
		if(dfs(2,3))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;


	}



	return 0;
}
