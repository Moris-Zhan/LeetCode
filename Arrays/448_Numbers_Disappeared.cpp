/*
448. Find All Numbers Disappeared in an Array
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[5,6]
*/

#include <iostream>
#include <vector>
#include <set>
#include <string> 

using namespace std;

void vectorToString(vector<int>& v) {
    // 檢查vector轉換字串輸出
    string s = "";
    for(int a = 0; a < v.size(); a ++) s += to_string(v[a]) + " ";
    cout << s << endl;        
    }

class Solution {
public: 
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 重要條件就是1 ≤ a[i] ≤ n (n = size of array)
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            // vectorToString(nums);            
            nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1]); // 將a[i]位置上的數值變為負數
            // cout << abs(nums[i]) << " , " << abs(nums[i])-1 << " , " << nums[abs(nums[i])-1] << endl;  
        }
        // vectorToString(nums);
        for(int i=0;i<nums.size();i++)
            if(nums[i]>0)
                ans.push_back(i+1); //未符合重要條件的正數極為答案
        return ans;
    }
};

int main()
{
    int a[8] = {4,3,2,7,8,2,3,1};
    int arrSize = sizeof(a)/sizeof(a[0]);
	vector<int> testCase(a, a + arrSize);

	Solution solution ;
    vector<int> v = solution.findDisappearedNumbers(testCase);
    vectorToString(v);
}
