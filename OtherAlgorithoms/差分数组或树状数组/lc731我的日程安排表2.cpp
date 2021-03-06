#include<bits/stdc++.h>
using namespace std;
class MyCalendarTwo {
public:
    map<int, int> diff;
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        // 这里一定要首先进行，否则map中没有相应的元素
        diff[start]++;
        diff[end]--;
        int sum = 0;
        auto it = diff.begin();
        // 查询[start, end)区间内是否有等于三的sum
        while(it != diff.end() && it->first < end) {
            sum += it->second;
            if(sum > 2) {
                diff[start]--;
                diff[end]++;
                return false;
            } 
            it++;
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */