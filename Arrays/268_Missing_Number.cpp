/*
268. Missing Number
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
Example 1:
Input: [3,0,1]
Output: 2
Example 2:
Input: [9,6,4,2,3,5,7,0,1]
Output: 8
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i=0;i < nums.size();i++) {
            sum += nums[i];
        }
        // For numbers 0, 1, 2, ..., n the sum should be n*(n+1)/2,
        // return what is left out
        // 數列和公式 : 上下底乘高除2
        return n*(n+1)/2 - sum;
        
    }
};

int main()
{
    int a[3] = { 3,0,1 };
	vector<int> testCase(a, a + 3);

	Solution solution ;
	cout << solution.missingNumber(testCase);
}
