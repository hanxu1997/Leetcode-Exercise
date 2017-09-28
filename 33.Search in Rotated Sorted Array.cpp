/*33.Search in Rotated Sorted Array*/ 

#include<iostream>
#include<vector>

using namespace std;

/*
	二分查找
在旋转排序数组中查找
*/
class Solution {
public:
	int search(const vector<int>& nums, int target) {
		int first = 0;
		int last = nums.size();
		while (first != last) {
			int mid = (first + last) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			if (nums[first] <= nums[mid]) { // 前半部分递增 
				if (nums[first] <= target && target < nums[mid]) { // target在递增部分（可直接确定范围） 
					last = mid;
				} else {
					first = mid + 1;
				}
			} else { // 后半部分递增 
				if (nums[mid] < target && target <= nums[last-1]) {
					first = mid + 1;
				} else {
					last = mid;
				}
			}
		}
		return -1;
	}
};
