'''
784. Letter Case Permutation
Medium

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order. 

Example 1:

Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: S = "3z4"
Output: ["3z4","3Z4"]
Example 3:

Input: S = "12345"
Output: ["12345"]
Example 4:

Input: S = "0"
Output: ["0"]
'''

class Solution(object):
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        # S = "abc"，那么先让 res = [""]，然后res中的每个字符串分别加上第一个字符a和A，得到           
        # ["a", "A"]，然后res中的每个字符串分别加上第二个字符b和B
            
        res = []
        for c in S:
            if c.isalpha():
                if len(res) == 0 :
                    res = res + [c.lower()] + [c.upper()]
                else:                
                    res = [item + c.upper() for item in res] + \
                    [item + c.lower() for item in res]                
            else:
                if len(res) == 0 : res = res + [c]
                else: res = [item + c for item in res]
        return res 
