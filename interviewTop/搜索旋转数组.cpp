#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left <= right) {
            int mid = (right - left) / 2 + left;
            if(nums[mid] == target)
                return mid;
            // in left span
            else if(nums[mid] > nums[right]) {
                if(nums[mid] < target) 
                    left = mid + 1;
                else if(nums[mid] > target && nums[left] <= target) 
                    right = mid - 1;
                else if(nums[mid] > target && nums[left] > target)
                    left = mid + 1;
                    
            }
            // in right span
            else if(nums[mid] <= nums[right]) {
                if(nums[mid] > target)
                    right = mid - 1;
                else if(nums[mid] < target && nums[right] >= target)
                    left = mid + 1; 
                else if(nums[mid] < target && nums[right] < target)
                    right = mid - 1;
            }
            cout<<left<<" "<<right<<endl;
        }
        return -1;
    }
};