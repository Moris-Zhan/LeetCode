/*
217. Contains Duplicate
Easy
Share
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
Example 1:
Input: [1,2,3,1]
Output: true
Example 2:
Input: [1,2,3,4]
Output: false
Example 3:
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() != set<int>(nums.begin(), nums.end()).size();  
    }
};

int main()
{
	// int a[5] = { 4,1,2,1,2 };
    int a[5] = { 1,2,3,4 };
	vector<int> testCase(a, a + 5);

	Solution solution ;
	cout << solution.containsDuplicate(testCase);
}
