/*33.Search in Rotated Sorted Array*/ 

#include<iostream>
#include<vector>

using namespace std;

/*
	���ֲ���
����ת���������в���
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
			if (nums[first] <= nums[mid]) { // ǰ�벿�ֵ��� 
				if (nums[first] <= target && target < nums[mid]) { // target�ڵ������֣���ֱ��ȷ����Χ�� 
					last = mid;
				} else {
					first = mid + 1;
				}
			} else { // ��벿�ֵ��� 
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
