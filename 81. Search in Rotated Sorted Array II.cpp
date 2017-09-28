/*
81. Search in Rotated Sorted Array II 

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Write a function to determine if a given target is in the array.
The array may contain duplicates.
*/
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
	bool search(const vector<int>& nums, int target) {
		int first = 0;
		int last = nums.size();
		while (first != last) {
			int mid = (first + last) / 2;
			if (nums[mid] == target) {
				return true;
			}
			if (nums[first] < nums[mid]) { // 前半部分递增 
				if (nums[first] <= target && target < nums[mid]) { // target在递增部分（可直接确定范围） 
					last = mid;
				} else {
					first = mid + 1;
				}
			} else if (nums[first] > nums[mid]) { // 后半部分递增 
				if (nums[mid] < target && target <= nums[last-1]) {
					first = mid + 1;
				} else {
					last = mid;
				}
			} else { // 有重复，由于只要判断存在与否，可直接舍去first 
				first++;
			}
		}
		return false;
	}
};
