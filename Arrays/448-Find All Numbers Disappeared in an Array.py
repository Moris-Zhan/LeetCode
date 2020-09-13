'''
448. Find All Numbers Disappeared in an Array

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
'''

class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """        
        if len(nums) == 0: return []        
        Disappeared  = []
        nums.sort()
        nums = [0] + nums 
        nums = nums + [len(nums)]
        for i in range(0,len(nums)-1):
            j = i+1
            if nums[j] - nums[i] <=1: continue
            a, b = nums[i]+1, nums[j]
            interval = [item for item in range(a,b)]
            Disappeared = Disappeared + interval
        return Disappeared
        
