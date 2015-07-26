////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-06-06 23:30:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5258
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 602_1001.cpp
      > Author: Netcan
      > Blog: http://www.netcan.xyz
      > Mail: 1469709759@qq.com
      > Created Time: Sat 06 Jun 2015 03:44:46 PM CST
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
struct l {
    int x1, x2, y1, y2;
} l1[30],l2[30]; // 竖， 横
 
bool cmp1(const l &a, const l &b) { // 竖木棍横坐标从小到大排序
    return a.x1 < b.x1;
}
bool cmp2(const l &a, const l &b) { // 横木棍纵坐标从大到小排序
    return a.y1 > b.y1;
}
 
int main()
{
#ifdef Oj
    freopen("602_1001.in", "r", stdin);
#endif
    int T;
    cin >> T;
    int Case = 1;
    while(T--) {
        int n;
        cin >> n;
        int lc1=0, lc2=0; // 竖、横木棍个数
        int x1, x2, y1, y2;
        for (int i = 0; i < n; ++i) {
            cin >> x1 >> y1 >> x2 >> y2;
            if(x1 == x2) { // 竖木棍
                l1[lc1].x1 = l1[lc1].x2 = x1;
                l1[lc1].y1 = min(y1, y2); // 纵坐标小的放在y1，大的放在y2
                l1[lc1].y2 = max(y1, y2);
                ++lc1;
            }
            else { // 横木棍
                l2[lc2].y1 = l2[lc2].y2 = y1;
                l2[lc2].x1 = min(x1, x2); // 横坐标小的放在x1，大的放在x2
                l2[lc2].x2 = max(x1, x2);
                ++lc2;
            }
        }
        sort(l1, l1+lc1, cmp1); // 竖木棍集合横坐标从小往大排序
        sort(l2, l2+lc2, cmp2); // 横木棍纵坐标从大到小排序
        int counts = 0; // 矩形个数
 
        for(int i=0; i<lc1; ++i) {
            for(int j=i+1; j<lc1; ++j) { //  竖木棍i, j
                for(int k=0; k<lc2; ++k)  {
                    for(int m=k+1; m<lc2; ++m) { // 横木棍k, m
                        if(l2[k].y1 <= min(l1[i].y2, l1[j].y2) && 
                        l2[m].y1 >= max(l1[i].y1, l1[j].y1) && 
                        l1[i].x1 >= max(l2[k].x1, l2[m].x1) && 
                        l1[j].x2 <= min(l2[k].x2, l2[m].x2))
                            ++counts;
                    }
 
                }
            }
        }
        printf("Case #%d:\n", Case++);
        cout << counts << endl;
    }
    return 0;
}