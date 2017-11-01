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
��ͨ�õ���ʽ���������������������ҵ�����������Ԫ�ص�k�������
�ٶ�A,B��Ԫ�ظ���������k/2����A��B�ĵ�k/2��Ԫ�ؽ��бȽϡ�
���������
1. A[k/2-1] == B[k/2-1] 
2. A[k/2-1] > B[k/2-1] 
3. A[k/2-1] < B[k/2-1] ?
���A[k/2-1] < B[k/2-1]
��A[0]��A[k/2-1]����topKԪ���ڣ�����ɾ��A�������k/2��Ԫ�ء�
 ��Bͬ��
 ��A[k/2-1] == B[k/2-1]ʱ���ҵ��˵�k���Ԫ�أ�����֮��

�ݹ麯������ֹ������
1. ��A��BΪ�գ�ֱ�ӷ���B[k-1]��A[k-1]
2. ��k=1ʱ������min(A[0], B[0])
3. ��A[k/2-1] == B[k/2-1]��ʱ������A[k/2-1]��B[k/2-1]
*/
 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int find_kth(vector<int>::const_iterator A, int m, vector<int>::const_iterator B, int n, int k) {
		//ȷ��m<=n 
		if (m > n) {
			return find_kth(B, n, A, m, k);
		}
		// AΪ�գ�ֱ����B�е�k�� 
		if (m == 0){
			return *(B + k - 1);
		}
		// ��k==1���Ƚ�A[0],B[0],ȡ��С 
		if (k == 1){
			return min(*A, *B);
		}
		//divide k into two parts 
		int ia = min(k / 2, m), ib = k - ia;
		// A[ia-1] < B[ib-1] A��ǰia����ȥ������ʣ��A��ԭ��B���ҵ�K-iaС�� 
		if (*(A + ia - 1) < *(B + ib - 1)) {
			return find_kth(A + ia, m - ia, B, n, k - ia);
		} else if (*(A + ia - 1) > *(B + ib - 1))  {
		// A[ia-1] > B[ib-1] B��ǰib����ȥ������ʣ��B��ԭ��A���ҵ�K-ibС�� 
			return find_kth(A, m, B + ib, n - ib, k - ib);
		} else {// ���������ֱ�ӷ��� 
			return A[ia - 1];
		}
	} 
	
	
	double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
		int m = A.size();
		int n = B.size();
		int total = m + n;
		if (total & 0x1) {
			// ����
			return find_kth(A.begin(), m, B.begin(), n, total/2 + 1);
		} else {
			return (find_kth(A.begin(), m, B.begin(), n, total/2)+
			find_kth(A.begin(), m, B.begin(), n, total/2 + 1))/2.0;
		}	
	} 
};
