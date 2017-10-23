/*
4. Median of Two Sorted Arrays 
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/ 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int find_kth(vector<int>::const_iterator A, int m, vector<int>::const_iterator B, int n, int k) {
		//确保m<=n 
		if (m > n) {
			return find_kth(B, n, A, m, k);
		}
		// A为空，直接找B中第k个 
		if (m == 0){
			return *(B + k - 1);
		}
		// 若k==1，比较A[0],B[0],取最小 
		if (k == 1){
			return min(*A, *B);
		}
		//divide k into two parts 
		int ia = min(k / 2, m), ib = k - ia;
		// A[ia-1] < B[ib-1] A的前ia个舍去，再在剩余A和原来B中找第K-ia小的 
		if (*(A + ia - 1) < *(B + ib - 1)) {
			return find_kth(A + ia, m - ia, B, n, k - ia);
		} else if (*(A + ia - 1) > *(B + ib - 1))  {
		// A[ia-1] > B[ib-1] B的前ib个舍去，再在剩余B和原来A中找第K-ib小的 
			return find_kth(A, m, B + ib, n - ib, k - ib);
		} else {// 若二者相等直接返回 
			return A[ia - 1];
		}
	} 
	
	
	double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
		int m = A.size();
		int n = B.size();
		int total = m + n;
		if (total & 0x1) {
			// 奇数
			return find_kth(A.begin(), m, B.begin(), n, total/2 + 1);
		} else {
			return (find_kth(A.begin(), m, B.begin(), n, total/2)+
			find_kth(A.begin(), m, B.begin(), n, total/2 + 1))/2.0;
		}	
	} 
};
