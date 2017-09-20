/* 35. Search Insert Position 

Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

/*在已排序数组中找到对应值，输出其在数组中的下标，
	若找不到该值，输出其应该插入的位置 */

/* 二分查找 */
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	if (nums.empty()) {
    		return 0;
    	}
    	int low = 0;
    	int high = nums.size() - 1;
    	while (low <= high) {
    		int mid = (low + high) / 2;
    		if (nums[mid] == target) {
    			return mid;
    		}
    		if (nums[mid] > target) {
    			high = mid - 1;
    		} else {
    			low = mid + 1;
    		}
    	}
        return low;
    }
}; 


int main() {
	vector<int> a(3);
	for (int i = 0; i < 3; i++) {
		a[i] = i;
	}
	Solution A;
	int output = A.searchInsert(a, 2);
	cout << output << endl;
	return 0;
	
} 
