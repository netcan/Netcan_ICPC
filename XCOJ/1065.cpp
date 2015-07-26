/*************************************************************************
	> File Name: 1065.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Wed 29 Apr 2015 21:09:42 CST
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

struct Img {
	char name[20];
	char hash[36];
} imglib[10005], img[105];
int like[10005];

int Like(Img &img, Img &imglib) {
	int count = 0;
	for(int i=0; i<36; ++i)
		if(img.hash[i] == imglib.hash[i])
			++count;
	return count;
}

int main()
{
	int N,Q;
	queue<int> like;
	while(scanf("%d",&N)==1) {
		for(int i=0; i<N; ++i) {
			scanf("%s%s", imglib[i].name, imglib[i].hash);
//			printf("%s %s\n", imglib[i].name, imglib[i].hash);
		}
		scanf("%d", &Q);
		for(int i=0; i<Q; ++i) {
			scanf("%s%s", img[i].name, img[i].hash);
//			printf("%s %s\n", img[i].name, img[i].hash);
		}
		for(int i=0; i<Q; ++i) {
			int maxl = 0;
			for(int j=0; j<N; ++j) {
			int l = Like(img[i], imglib[j]);
				if(maxl == l)
					like.push(j);
				else
				if(maxl < l) {
					maxl = l;
					like.push(j);
					if(!like.empty()) {
						int Pj = like.back();
						while(Pj != like.front() && !like.empty())
							like.pop();
					}
				}
			}

			int count = like.size();
			printf("%d\n%d\n", count, Like(img[i], imglib[like.front()]));
			for(int i=0; i<count; ++i) {
				printf("%s\n", imglib[like.front()].name);
				like.pop();
			}


			// while(!like.empty()) {
				// cout << like.front() << ", ";
				// cout << Like(img[i], imglib[like.front()]) << " ";
				// like.pop();
			// }
			// cout << endl;
		}

	}


	return 0;
}
