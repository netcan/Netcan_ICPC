/*************************************************************************
	> File Name: 2010_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-27 日 19:48:05 CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int N, C, F;
int Median;
struct Cows {
	int score, aid, rank_by_score;
} cows_rank_by_score[100005], cows_rank_by_aid[100005];

bool by_score(const Cows &a, const Cows &b) {
	return a.score < b.score;
}

bool by_aid(const Cows &a, const Cows &b) {
	return a.aid < b.aid;
}

void solve() {
	Median = N >> 1;
	sort(cows_rank_by_score, cows_rank_by_score+C, by_score);
	for(int i=0; i<C; ++i) cows_rank_by_score[i].rank_by_score = i;
	memcpy(cows_rank_by_aid, cows_rank_by_score, sizeof(Cows)*C);
	sort(cows_rank_by_aid, cows_rank_by_aid+C, by_aid);
	// for (int i = 0; i < C; ++i)
		// printf("score: %d aid: %d id:%d\n", cows_rank_by_score[i].score, cows_rank_by_score[i].aid, cows_rank_by_score[i].rank_by_score);
	// printf("=====\n");
	// for (int i = 0; i < C; ++i)
		// printf("score: %d aid: %d\n", cows_rank_by_aid[i].score, cows_rank_by_aid[i].aid);
	int ans;
	int lb = 0, ub = C; // [lb, ub)
	// printf("Median: %d\n", Median);
	while(ub - lb > 1) {
		int left = 0, right = 0;
		int mid = (lb + ub) >> 1;
		int fee = cows_rank_by_score[mid].aid;
		// printf("lb:%d ub:%d\n", lb, ub);
		for(int i=0; i<C;++i) { // 按费用大小从小到大枚举
			if((left < Median) && (fee + cows_rank_by_aid[i].aid <= F) && cows_rank_by_aid[i].rank_by_score < mid) { // 左边
				++left;
				fee += cows_rank_by_aid[i].aid;
			}
			else if((right < Median) && (fee + cows_rank_by_aid[i].aid <= F) && cows_rank_by_aid[i].rank_by_score > mid) { // 右边
				++right;
				fee += cows_rank_by_aid[i].aid;
			}
		}
		// printf("left:%d right:%d\n", left, right);

		if(left < Median && right < Median) {
			ans = -1;
			break;
		}
		else if(left < Median) 	lb = mid;
		else if(right < Median) ub = mid;
		else {
			ans = cows_rank_by_score[mid].score;
			lb = mid;
		}
	}
	printf("%d\n", ans);
}


int main() {
#ifdef Oj
	freopen("2010_2.in", "r", stdin);
#endif
	scanf("%d%d%d", &N, &C, &F);
	for (int i = 0; i < C; ++i)
		scanf("%d%d", &cows_rank_by_score[i].score, &cows_rank_by_score[i].aid);
	solve();
	return 0;
}
