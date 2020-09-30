'''
103. Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
'''

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        ans, level = [], [root]         # 初始化level裡的元素
        leftright = True
        while level:
            if leftright:
                nodeList = [level[i].val for i in range(len(level))]
            else:
                nodeList = [level[i].val for i in range(len(level)-1,-1,-1)]
            ans.append(nodeList)
            temp = []                   # temp暫存所有level以及其左右子節點
            for node in level:
                temp.extend([node.left, node.right])
            level = [leaf for leaf in temp if leaf != None] # 過濾空節點
            leftright = not leftright            
        return ans