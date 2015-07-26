/*************************************************************************
	> File Name: 1064.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Thu 07 May 2015 16:39:28 CST
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
	int N, M, K;
	static bool board[105][105];
	while(scanf("%d%d%d", &N, &M, &K)==3) {
		memset(board, 0, sizeof(board));
		int r, c;
		for(int i=1; i<=K; ++i) {
			scanf("%d%d", &r, &c);
			board[r][c]=true;
		}
		bool YES = false;
		for(int i=1; i<=N; ++i) {
			if(YES)
				break;
			for(int j=1; j<=M; ++j) {
				if(board[i][j]) {
					for(int k=i-1; k<=i+1; ++k) {
						if(YES) break;
						for(int l=j-1; l<=j+1; ++l)
							if(board[k][l] && !(k==i&&l==j))
								YES = true;
					}
				}
			}
		}
		if(YES)
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}
