#include<bits/stdc++.h>
using namespace std;
// 动态规划 自己想到的
int nthUglyNumber(int n) {
    vector<long long> dp(n + 1, 0);
    if(n == 1) return 1;
    if(n == 2) return 2;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; ++i) {
        long long start = dp[i - 1] / 5;
        long long lowest = dp[i - 1];
        long long min_value = lowest * 5;
        int j = i - 1;
        while(j >= 1 && dp[j] > start) {
            if(dp[j] * 2 > lowest) {
                min_value = min(min_value, dp[j] * 2);
            }
            if(dp[j] * 3 > lowest) {
                min_value = min(min_value, dp[j] * 3);
            }
            if(dp[j] * 5 > lowest) {
                min_value = min(min_value, dp[j] * 5);
            }
            j--;
        }
        dp[i] = min_value;
    }
    return dp[n];
}
// 动态规划 三个指针优化
int nthUglyNumber2(int n) {
    vector<int> dp(n + 1, 0);
    if(n == 1) return 1;
    if(n == 2) return 2;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    int p2 = 2, p3 = 1, p5 = 1;
    for(int i = 3; i <= n; ++i) {
        dp[i] = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
        if(dp[i] == dp[p2] * 2) p2++;
        if(dp[i] == dp[p3] * 3) p3++;
        if(dp[i] == dp[p5] * 5) p5++;
    }
    return dp[n];
}
// 使用优先队列 +  动态规划
class Solution {
  public:
    int GetUglyNumber_Solution(int index) {
        vector<int> dp(index + 1);
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        dp[1] = 1;
        pq.push(2);
        pq.push(3);
        pq.push(5);
        if (index == 1) return 1;
        for (int i = 2; i <= index; ++i) {
            long long num = pq.top();
            pq.pop();
            while (!pq.empty() && pq.top() == num) {
                pq.pop();
            }
            dp[index] = num;
            pq.push(num * 2);
            pq.push(num * 3);
            pq.push(num * 5);
        }
        return dp[index];
    }
};
int main() {
    cout<<nthUglyNumber2(1407)<<endl;
    return 0;
}