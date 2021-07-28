# LeetCode規劃
#### LEETCODE PATTERNS
https://seanprashad.com/leetcode-patterns/
#### 從LeetCode學演算法
https://desolve.medium.com/%E5%BE%9Eleetcode%E5%AD%B8%E6%BC%94%E7%AE%97%E6%B3%95-0-6c121bd8b579

#### Leetcode筆記
https://hackmd.io/U5azKxBhR1e8Z7RWTzAtLQ#3%E8%B2%AA%E5%BF%83%E7%B3%BB%E5%88%97
https://medium.com/@afly.bsky/leetcode%E7%B7%B4%E7%BF%92-3f5ad218fae4

#### Leetcode 经典题目
https://github.com/CyC2018/CS-Notes/blob/master/notes/Leetcode%20%E9%A2%98%E8%A7%A3%20-%20%E7%9B%AE%E5%BD%95.md

# 程式題
#### 1) reverse string
    Input: ["h","e","l","l","o"]
    Output: ["o","l","l","e","h"]
https://leetcode.com/problems/reverse-string/
##### 使用內部swap
    class Solution(object):
        def reverseString(self, s):
            """
            :type s: List[str]
            :rtype: None Do not return anything, modify s in-place instead.
            """
            i = 0
            j = len(s)-1

            while(i<j):
                s[i], s[j] = s[j], s[i]
                i += 1
                j -= 1
            return s
![](https://i.imgur.com/cLQCpU7.png)

#### 2) merge intervals (第一類)
    ex: [1,2], [2,3], [4,5], [5,7] => [1,2,3], [4,5,7]
#### 3) merge intervals (第二類) - Medium
    ex: [1,3], [5,9], [6,7], [10,13], [11,13] => [1,3], [5,9], [10,13]
https://leetcode.com/problems/merge-intervals/
#### 4) given a list, find all the intervals of consecutive integers - Medium
    ex: [1,3,2,11,10,12,1002,1000,1003] => [1,3], [10,12], [1000],[1002,1003]
https://leetcode.com/problems/split-array-into-consecutive-subsequences/
#### 5) 給定一串數字，每個數字重複3次，只有一個沒有，找出該數字 - Medium
    ex: 1313134 => 4
https://leetcode.com/problems/single-number-ii/
#### 6) isomorphism
    ex: "abbac" <-> "effeg" => true
    ex: "abbac" <-> "effig" => false
https://leetcode.com/problems/isomorphic-strings/
##### 使用兩個dict互相key-val檢查
    class Solution(object):
        def isIsomorphic(self, s, t):
            """
            :type s: str
            :type t: str
            :rtype: bool
            """
            if len(s) != len(t) : return False
            ds, dt = {}, {}
            for i in range(len(s)):
                s_item = s[i]
                t_item = t[i]
                if s_item not in ds and t_item not in dt:
                    ds[s_item] = t_item
                    dt[t_item] = s_item
                elif ds.get(s_item,0) != t_item:
                    return False
                elif dt.get(t_item,0) != s_item:
                    return False
            return True   

#### 7) 1~n數字隨意排列，其中只少掉了一個數字，將其找出
    ex: 1342578 => 6
https://leetcode.com/problems/missing-number/
##### 擅用set集合函數
    class Solution(object):
        def missingNumber(self, nums):
            """
            :type nums: List[int]
            :rtype: int
            """
            max_val = max(nums)
            if max_val == len(nums)-1: return max_val + 1
            mis = set([i for i in range(0,max_val)]).difference(nums)
            return list(mis)[0]
#### 8) 實作atoi - Medium
![](https://i.imgur.com/RLInYU4.png)

    
    class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """    
        str = str.strip()
        if len(str) == 0: return 0
        sign = str[0]
        tmp = "0"
        result = 0
        i = 0                 # 預設處理位置從0開始
        if sign in ['+','-']: # 如果第1位為sign直接append進待處理字串
            tmp = sign
            i = 1             # 並將處理位置設定從1開始
        for i in xrange(i, len(str)):
            if str[i].isdigit():
                tmp += str[i]
            else:
                break         # atoi輸出前面可轉成數值的字串
                
        if len(tmp) > 1: result = int(tmp)  # 去除小數點後位        
        return max(-2**31, min(result,2**31-1))

        

       
https://leetcode.com/problems/string-to-integer-atoi/
#### 9) reverse linked list (in-place)
    Input: 1->2->3->4->5->NULL
    Output: 5->4->3->2->1->NULL
https://leetcode.com/problems/reverse-linked-list/
##### 先儲存反轉列表後建立反轉串列
    # Definition for singly-linked list.
    # class ListNode(object):
    #     def __init__(self, val=0, next=None):
    #         self.val = val
    #         self.next = next
    class Solution(object):
        def reverseList(self, head):
            """
            :type head: ListNode
            :rtype: ListNode
            """
            reverse_val = []        
            while head != None:         
                reverse_val = [head.val] + reverse_val
                head = head.next

            reverse_p = reverse_head = None
            for val in reverse_val:
                node = ListNode(val,None)
                if reverse_head == None:
                    reverse_head = reverse_p = node
                else:
                    reverse_p.next = node
                    reverse_p = reverse_p.next
            return reverse_head
        
#### 10) 交錯數字
    ex: [1,2,3,4,5,6,7,8] => [1,5,2,6,3,7,4,8]
https://stackoverflow.com/questions/7946798/interleave-multiple-lists-of-the-same-length-in-python
##### zip綁定兩串列為dict-key-val
    class Solution(object):
            def interleavedNumber(self, nums):
                """
                :type nums: List[int]
                :rtype: List[int]
                """
                a_list = nums[:int(0.5*len(nums))]
                b_list = nums[int(0.5*len(nums)):]
                c_list = []
                for (i,j) in zip(a_list,b_list):
                  c_list.append(i)
                  c_list.append(j)
                return c_list
#### 11) 1代表陸地，0代表水，4-connectivity，given a 2-d array with only 0s and 1s, find the max land area
    ex:
    0011
    1001  => max land area: 5
    0011
#### 12) 承上題，找出一共有多少塊陸地以及每個陸地的重心
#### 13) 實作doubly linked list (包含從頭insert、從尾端insert、找出目標value在linked list中的位置等等)
![](https://i.imgur.com/VqpmyLP.png)

#### 14) 實作candy crush (三個以上可以消掉，一次消一組) - Medium
    ex: [1,2,2,3,3,3,2,5,5] => [1,5,5]
http://shibaili.blogspot.com/2019/01/723-candy-crush.html
#### 15) merge兩個binary search tree成一個
![](https://i.imgur.com/4zhxXn4.png)
https://leetcode.com/problems/merge-two-binary-trees/
##### 使用遞迴合併相加左右節點值
    # Definition for a binary tree node.
    # class TreeNode(object):
    #     def __init__(self, val=0, left=None, right=None):
    #         self.val = val
    #         self.left = left
    #         self.right = right
    class Solution(object):
        def mergeTrees(self, t1, t2):
            """
            :type t1: TreeNode
            :type t2: TreeNode
            :rtype: TreeNode
            """
            # 輸入兩個二元樹，並合併兩個二元樹中每個相對應的結點。

            # 若兩個樹都不存在則值接返回空。
            # 若一個存在而另一不存在則直接返回存在的樹，無須合併。
            # 若兩個樹都存在則合併目前節點的值，然後呼叫同個方法，分別合併左子節點及右子節點。
            # 分別將合併好的回傳左右節點放至父節點。

            if not t1:
                return t2
            elif not t2:
                return t1
            else:
                sum = TreeNode(t1.val + t2.val)
                sum.left = self.mergeTrees(t1.left,t2.left)
                sum.right = self.mergeTrees(t1.right,t2.right)
            return sum

#### 16) 給一個已經sort過的array，build一個binary search tree且要考慮biased的問題(Convert Sorted Array to Binary Search Tree)
![](https://i.imgur.com/yHpntec.png)
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
##### 使用遞迴處理左右子樹及中位節點
    # Definition for a binary tree node.
    # class TreeNode(object):
    #     def __init__(self, val=0, left=None, right=None):
    #         self.val = val
    #         self.left = left
    #         self.right = right
    class Solution(object):
        def sortedArrayToBST(self, nums):
            """
            :type nums: List[int]
            :rtype: TreeNode
            """
            if len(nums) == 0: return None
            mid = int(0.5*len(nums))
            root = TreeNode(nums[mid])
            root.left = self.sortedArrayToBST(nums[:mid])
            root.right = self.sortedArrayToBST(nums[mid+1:])
            return root
#### 17) 給一個singly linked list，找出middle value(延伸：是否能夠用one-path的方法)
![](https://i.imgur.com/PoTkwXx.png)
https://leetcode.com/problems/middle-of-the-linked-list/
##### 先找出mid index後指定輸出mid index後的串列
    # Definition for singly-linked list.
    # class ListNode(object):
    #     def __init__(self, val=0, next=None):
    #         self.val = val
    #         self.next = next
    class Solution(object):
        def middleNode(self, head):
            """
            :type head: ListNode
            :rtype: ListNode
            """
            l = []
            p1 = head
            while(p1 != None):
                l.append(p1.val)
                p1 = p1.next

            m = int(0.5*(len(l)))        
            i = 0
            p2 = head
            while(p2 != None and i < m):
                p2 = p2.next
                i += 1
            return p2
        
#### 18) given a binary search tree，判斷其是否對稱
![](https://i.imgur.com/FH13YGE.png)
https://leetcode.com/problems/balanced-binary-tree/
##### 遞迴檢查根節點
    # Definition for a binary tree node.
    # class TreeNode(object):
    #     def __init__(self, val=0, left=None, right=None):
    #         self.val = val
    #         self.left = left
    #         self.right = right
    class Solution(object):
        def isBalanced(self, root):
            """
            :type root: TreeNode
            :rtype: bool
            """
            def height(root):
                if root == None: # 沒東西，表示平衡為0
                    return 0
                else:
                    l_height = height(root.left)
                    r_height = height(root.right)
                    # 不平衡之條件,不平衡為-1
                    if l_height == -1 or r_height == -1 or abs(l_height-r_height) > 1:
                        return -1
                    else:
                        return 1 + max(l_height,r_height)  # 計算當前root高度    
            return height(root) != -1 # 遞迴判斷root有無不平衡

#### 19) given two sorted array, merge the second one into the first one
    ex: [1,3,5,0,0] & [2,4] => [1,2,3,4,5]
https://leetcode.com/problems/merge-sorted-array/
##### 看到洞洞就把它換成list2的值
    class Solution(object):
        def merge(self, nums1, m, nums2, n):
            """
            :type nums1: List[int]
            :type m: int
            :type nums2: List[int]
            :type n: int
            :rtype: None Do not return anything, modify nums1 in-place instead.
            """
            def check(item):
                if item == 0:
                    return True
            if len(nums2) == 0 : return nums1
            p = 0
            for idx, item in enumerate(nums1):
                if check(item):
                    nums1[idx] = nums2[p]
                    p += 1
                    if p >= len(nums2): break
            nums1.sort()
            return nums1
             
#### 20) 用linked list實作queue
![](https://i.imgur.com/36Kz5QP.png)

#### 21) given row and column number, return the corresponding Pascal's triangle
    number
    ex: row 4, col 2 => 6
    因為巴斯卡三角形長這樣：
        1       (row 0)
       1 1      (row 1)
      1 2 1
     1 3 3 1
    1 4 6 4 1   (row 4)
#### 22) given an unsorted array, find the number that is closet to a given target - Medium
    ex: {1,3,6,8,11,2,5}
    target: 6 => result: 6
    target:12 => result: 11
https://leetcode.com/problems/find-k-closest-elements/
#### 23) check if two strings are anagram
    ex: "evil" v.s "viel" => true
https://leetcode.com/problems/valid-anagram/
##### 判斷是否由相同字串組成
    class Solution(object):
        def isAnagram(self, s, t):
            """
            :type s: str
            :type t: str
            :rtype: bool
            """
            if len(s)!= len(t): return False
            s = list(s)
            t = list(t)

            for item in s:
                if item in t: t.remove(item)
            if len(t)==0: return True
            else: return False
            
#### 24) Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
![](https://i.imgur.com/afe26sy.png)

    # Definition for a binary tree node.
    # class TreeNode(object):
    #     def __init__(self, val=0, left=None, right=None):
    #         self.val = val
    #         self.left = left
    #         self.right = right
    class Solution(object):
        def maxDepth(self, root):
            """
            :type root: TreeNode
            :rtype: int
            """        
            def height(root):
                if root == None: # 沒東西，表示平衡為0
                    return 0            
                else:
                    l_height = height(root.left)
                    r_height = height(root.right)
                    return 1 + max(l_height,r_height)  # 計算當前root高度
            return height(root)


https://leetcode.com/problems/maximum-depth-of-binary-tree/
# ----------------------------------------------------
https://hackmd.io/xWA3ohZ-RqyRfm_QpvfAgA?both
