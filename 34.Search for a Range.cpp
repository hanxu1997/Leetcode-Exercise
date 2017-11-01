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
        	// δ�ҵ�target
			return vector<int>{-1,-1}; 
		} else {
			return vector<int>{distance(nums.begin(), lower),distance(nums.begin(),prev(upper))};
		}
    }
    
    template<typename ForwardIterator, typename T>
    ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, T value) {
    	while (first != last) {
		/*  ����auto��register��Ӧ�Զ��洢�ڡ�
			�����Զ��洢�ڵı����ڽ��������ñ����ĳ����ʱ��������
			���ڸó����ʱ���ڣ��˳��ó����ʱ������
			�ں����ڲ�����ı�����Ϊ�ֲ�������
		*/
		/*distanceȡ���������������
		  next(it,n) ָ���it��ʼ(�����ƣ��ĵ�n��Ԫ�صĵ�����*/
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
				first = ++mid; // �ҵ�һ�κ������벿���ң����firstͣ���Ͻ�+1 
			} else {
				last = mid;
			} 
		}
		return first;
	}
	
};
