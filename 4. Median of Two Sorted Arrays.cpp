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

/*
更通用的形式：给定两个已排序数组找到两者中所有元素第k大的数。
假定A,B的元素个数都大于k/2，将A和B的第k/2个元素进行比较。
三种情况：
1. A[k/2-1] == B[k/2-1] 
2. A[k/2-1] > B[k/2-1] 
3. A[k/2-1] < B[k/2-1] ?
如果A[k/2-1] < B[k/2-1]
则A[0]到A[k/2-1]必在topK元素内，可以删除A数组的这k/2个元素。
 对B同理。
 当A[k/2-1] == B[k/2-1]时，找到了第k大的元素，返回之。

递归函数的终止条件：
1. 当A或B为空，直接返回B[k-1]或A[k-1]
2. 当k=1时，返回min(A[0], B[0])
3. 当A[k/2-1] == B[k/2-1]或时，返回A[k/2-1]或B[k/2-1]
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
