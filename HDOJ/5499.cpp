/*************************************************************************
	> File Name: 1001.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-10 六 18:55:00 CST
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

int T, n, m;
int max_1, max_2;
bool has_female;

struct person {
	string name;
	bool sex; // 0为男, 1为女
	int round1, round2;
	double score;
	bool operator<(const person &b) const {
		return score > b.score;
	}
} p[102];

void solve() {
	string female;
	double max_female = 0;
	double r1 = 300.0/max_1;
	double r2 = 300.0/max_2;
	for(int i=0; i<n; ++i) {
		p[i].score = (p[i].round1 * r1)*0.3 + (p[i].round2 * r2) * 0.7;
		if(p[i].sex == 1 && max_female <= p[i].score) {
			max_female = p[i].score;
			female = p[i].name;
		}
	}
	bool is_voted = false;
	// cout << has_female<< endl;
	sort(p, p+n);
	printf("The member list of Shandong team is as follows:\n");
	if(!has_female)
		for(int i=0; i<m; ++i)
			printf("%s\n", p[i].name.c_str());
	else {
		for(int i=0; i<m-1; ++i) {
			printf("%s\n", p[i].name.c_str());
			if(p[i].name == female) is_voted = true;
		}
		if(is_voted) printf("%s\n", p[m-1].name.c_str());
		else printf("%s\n", female.c_str());
	}


}

int main()
{
#ifdef Oj
	freopen("1001.in", "r", stdin);
#endif
	string sex;
	cin.sync_with_stdio(false);
	cin >> T;
	while(T--) {
		max_1 = max_2 = 0;
		has_female = false;
		cin >> n >> m;
		for(int i=0; i<n; ++i) {
			cin >> p[i].name >> sex >> p[i].round1 >> p[i].round2;
			if(sex == "male") p[i].sex = 0;
			else {
				p[i].sex = 1;
				has_female = true;
			}
			if(max_1 < p[i].round1) max_1 = p[i].round1;
			if(max_2 < p[i].round2) max_2 = p[i].round2;
		}
		solve();
	}
	return 0;
}
