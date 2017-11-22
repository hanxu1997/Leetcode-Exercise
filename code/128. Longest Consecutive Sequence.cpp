/* 2.1.6 Longest Consecutive Sequence
Given an unsorted array of integers, 
find the length of the longest consecutive elements sequence.
For example, Given [100, 4, 200, 1, 3, 2], The longest consecutive elements sequence is [1,2, 3, 4].
Return its length: 4.
Your algorithm should run in O(n) complexity.
*/ 

/*
1. 用一个哈希表unordered_map<int, bool>used 
*/ 

#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
 
class Solution {
public:
	int longestConsecutive(const vector<int> &nums) {
		unordered_map<int, bool> used;
		for (auto i : nums) {
			used[i] = false;
		}
		int longest = 0;
		for (auto i : nums) {
			if (used[i]) {
				continue;
			}
			int length = 1;
			for (int j = i+1; used.find(j) != used.end(); j++) {
				used[j] = true;
				length++;
			}
			for (int j = i-1; used.find(j) != used.end(); j--) {
				used[j] = true;
				length++;
			} 
			longest = max(longest, length);
		} 
		return longest;
		
	}
};

/*2. unordered_map<int, int> 记录数值和所在连续长度*/
class Solution {
public:
	int longestConsecutive(const vector<int> &nums) {
		unordered_map<int, int>map;
		int length = 1;
		for (auto i:nums) {
			if (map.find(i) != map.end()) {
				continue;
			}
            map[i] = 1;
            if (map.find(i-1) != map.end()) {
				length = max(length, merge(map, i-1, i));
			}
			if (map.find(i+1) != map.end()) {
				length = max(length, merge(map, i, i+1));
			}
			
		}
		return nums.size() == 0 ? 0 : length;
	}
private:
	int merge(unordered_map<int, int>& map, int left, int right) { 
		int upper = right + map[right] - 1;
		int lower = left - map[left] + 1;
		int length = upper - lower + 1;
		map[upper] = length;
		map[lower] = length;
		return length;
	}
};
