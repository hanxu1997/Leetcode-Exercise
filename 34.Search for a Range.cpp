/*
34. Search for a Range
Given an array of integers sorted in ascending order,
find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 
*/ 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        auto upper = upper_bound(lower, nums.end(), target);
        if (lower == nums.end() || *lower != target) {
        	// 未找到target
			return vector<int>{-1,-1}; 
		} else {
			return vector<int>{distance(nums.begin(), lower),distance(nums.begin(),prev(upper))};
		}
    }
    
    template<typename ForwardIterator, typename T>
    ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, T value) {
    	while (first != last) {
		/*  其中auto和register对应自动存储期。
			具有自动存储期的变量在进入声明该变量的程序块时被建立，
			它在该程序块活动时存在，退出该程序块时撤销。
			在函数内部定义的变量成为局部变量。
		*/
		/*distance取到两迭代器间距离
		  next(it,n) 指向从it开始(本身不计）的第n个元素的迭代器*/
    		auto mid = next(first, distance(first,last)/2);
    		if (value > *mid) {
    			first = ++mid;
			} else {
				last = mid;
			}
		}
		return first;
	}
	
	template<typename ForwardIterator, typename T>
	ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, T value) {
		while (first != last) {
			auto mid = next(first, distance(first,last)/2);
			if (value >= *mid) {
				first = ++mid; // 找到一次后仍向后半部分找，最后first停在上界+1 
			} else {
				last = mid;
			} 
		}
		return first;
	}
	
};
