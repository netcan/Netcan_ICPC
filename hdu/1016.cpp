////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-08 11:30:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1016
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1016.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Fri 08 May 2015 10:54:46 CST
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

static bool is_prime[400];
static int ring[25];
bool visited[25];
int n;
void DFS(int i) {
	if(i > n && is_prime[ring[n] + ring[1]]) {
		for(int i=1; i<=n; ++i)
			if(i!=n)	cout << ring[i] << " ";
			else  cout << ring[i];
		cout << endl;
		return;
	}
	else
		for(int j=2; j<=n; ++j) {
			if(!visited[j] && is_prime[j + ring[i-1]]) {
				// for(int i=1; i<=n; ++i)
				// cout << ring[i] << " ";
				// cout << endl;
				// cout << j << endl;
				visited[j] = true;
				ring[i] = j;
				DFS(i+1);
				visited[j] = false;
			}
		}

}

int main()
{
	memset(is_prime, 1, sizeof(is_prime));
	is_prime[1] = false;
	for(int i=2; i<400; ++i)
		for(int j=2; j*i<400; ++j)
			is_prime[i*j] = false;

	// for(int i=1; i<400; ++i)
		// if(is_prime[i])
			// cout << i << " ";
	// cout << endl;


	int count = 0;
	while(cin >> n) {
		memset(visited, 0, sizeof(visited));
		ring[1] = visited[1] = 1;
		cout << "Case " << ++count << ":" << endl;
		DFS(2);
		cout << endl;
	}

	return 0;
}