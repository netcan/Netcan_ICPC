////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-09 22:49:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2074
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2074.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Sat 09 May 2015 09:58:39 PM CST
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
//	freopen("2074.data", "r", stdin);
	int N;
	char a,b;
	bool endline = false;
	static char img[80][80];
	while(cin >> N >> a >> b) {
		if((N-3)%4 == 0) {
			char t = b;
			b = a;
			a = t;
		}
//		cout << a << " " << b << endl;
		int i, j;
		int cnt = (N+1)/2;
		int direct = 1;
		bool ab = 0;
		i = j = 1;
		int layer = 0;
		memset(img, 0, sizeof(img));

		// for(int i=1; i<80; ++i) {
			// for(int j=1; j<80; ++j)
				// printf("%d ", img[i][j]);
			// cout << endl;
		// }

		while(!(i==cnt&&j==cnt)) {
//			printf("(%d, %d)\n", i, j);
			while(direct == 1 && j<=N-layer)
				if(ab) img[i][j++] = b;
				else img[i][j++] = a;
			if(j>N-layer) {
				j = N-layer;
				direct = 2;
			}

			while(direct == 2 && i<=N-layer)
				if(ab) img[i++][j] = b;
				else img[i++][j] = a;
			if(i>N-layer) {
				i = N-layer;
				direct = 3;
			}
			while(direct == 3 && j>=1+layer)
				if(ab) img[i][j--] = b;
				else img[i][j--] = a;
			if(j<1+layer) {
				j = 1+layer;
				direct = 4;
			}
			while(direct == 4 && i>=1+layer)
				if(ab) img[i--][j] = b;
				else img[i--][j] = a;
			if(i<1+layer) {
				i = 1+layer;
				direct = 1;
			}
			i+=1;
			j+=1;

			ab = !ab;
			++layer;
		}

		if(ab) img[cnt][cnt] = b;
		else img[cnt][cnt] = a;
		if(N!=1)
			img[1][1] = img[1][N] = img[N][1] = img[N][N] = ' ';

		if(endline)
			cout << endl;
		endline = true;

		 for(int i=1; i<=N; ++i)  {
			 for(int j=1; j<=N; ++j)
				 cout << img[i][j];
			cout << endl;
		 }

	}


	return 0;
}