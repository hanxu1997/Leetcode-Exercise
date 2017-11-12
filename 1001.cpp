#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int minDifference(vector<int> A) {
    	int length = A.size();
    	int max = 0; // 正数最大 
    	int min = 0; // 负数最小 
    	int TEMP = 65536;
    	for (int i = 0; i < length; i++) {
    		if (A[i] >= 0 && A[i] > max) {
    			max = A[i]; 
			} 
			if (A[i] < 0 && A[i] < min) {
				min = A[i];
			}
		} 
		int times[max-min];
		for (int i = min; i < max; i++) {
			times[i] = 0;
		}
		for (int i = 0; i < length; i++) {
			int x = A[i];
			++times[x];
		}
		int index = 0;
		for (int i = min; i < max; i++) {
			for (int j = 0; j < times[i]; j++) {
				A[index] = i;
				++index;
			}
		}
		for (int i = 0; i < length-1; i++) {
			if (A[i+1]-A[i] < TEMP) {
				TEMP = A[i+1]-A[i];
			}
		}
		return TEMP;
    }
};


int main() {
	
	int a[4] = {-8,10,30,10}; 
    vector<int>A(a,a+4);
    for(int i=0;i<4;i++) {
    	cout << A[i] << endl; 
	} 
    Solution b;
	cout<<b.minDifference(A)<<endl;
	return 0;
}
