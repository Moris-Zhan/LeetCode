# LeetCode規劃
#### LEETCODE PATTERNS
https://hackmd.io/oMvSnRW4S4OQbghaqaik6A
#### 從LeetCode學演算法
https://medium.com/@desolution

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
#### 2) merge intervals (第一類)
    ex: [1,2], [2,3], [4,5], [5,7] => [1,2,3], [4,5,7]
#### 3) merge intervals (第二類)
    ex: [1,3], [5,9], [6,7], [10,13], [11,13] => [1,3], [5,9], [10,13]
https://leetcode.com/problems/merge-intervals/
#### 4) given a list, find all the intervals of consecutive integers
    ex: [1,3,2,11,10,12,1002,1000,1003] => [1,3], [10,12], [1000],[1002,1003]
https://leetcode.com/problems/split-array-into-consecutive-subsequences/
#### 5) 給定一串數字，每個數字重複3次，只有一個沒有，找出該數字
    ex: 1313134 => 4
https://leetcode.com/problems/single-number-ii/
#### 6) isomorphism
    ex: "abbac" <-> "effeg" => true
    ex: "abbac" <-> "effig" => false
https://leetcode.com/problems/isomorphic-strings/
#### 7) 1~n數字隨意排列，其中只少掉了一個數字，將其找出
    ex: 1342578 => 6
https://leetcode.com/problems/missing-number/
#### 8) 實作atoi
    String to Integer (atoi)
    Input: "42"
    Output: 42
https://leetcode.com/problems/string-to-integer-atoi/
#### 9) reverse linked list (in-place)
    Input: 1->2->3->4->5->NULL
    Output: 5->4->3->2->1->NULL
https://leetcode.com/problems/reverse-linked-list/
#### 10) 交錯數字
    ex: [1,2,3,4,5,6,7,8] => [1,5,2,6,3,7,4,8]
https://stackoverflow.com/questions/7946798/interleave-multiple-lists-of-the-same-length-in-python
#### 11) 1代表陸地，0代表水，4-connectivity，given a 2-d array with only 0s and
    1s, find the max land area
    ex:
    0011
    1001  => max land area: 5
    0011
#### 12) 承上題，找出一共有多少塊陸地以及每個陸地的重心
#### 13) 實作doubly linked list (包含從頭insert、從尾端insert、找出目標value在linked list中的位置等等)
![](https://i.imgur.com/VqpmyLP.png)

#### 14) 實作candy crush (三個以上可以消掉，一次消一組)
    ex: [1,2,2,3,3,3,2,5,5] => [1,5,5]
http://shibaili.blogspot.com/2019/01/723-candy-crush.html
#### 15) merge兩個binary search tree成一個
![](https://i.imgur.com/4zhxXn4.png)
https://leetcode.com/problems/merge-two-binary-trees/
#### 16) 給一個已經sort過的array，build一個binary search tree且要考慮biased的問題(Convert Sorted Array to Binary Search Tree)
![](https://i.imgur.com/yHpntec.png)
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
#### 17) 給一個singly linked list，找出middle value(延伸：是否能夠用one-path的方法)
![](https://i.imgur.com/PoTkwXx.png)
https://leetcode.com/problems/middle-of-the-linked-list/
#### 18) given a binary search tree，判斷其是否對稱
![](https://i.imgur.com/FH13YGE.png)
https://leetcode.com/problems/balanced-binary-tree/
#### 19) given two sorted array, merge the second one into the first one
    ex: [1,3,5,0,0] & [2,4] => [1,2,3,4,5]
https://leetcode.com/problems/merge-sorted-array/
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
#### 22) given an unsorted array, find the number that is closet to a given target
    ex: {1,3,6,8,11,2,5}
    target: 6 => result: 6
    target:12 => result: 11
https://leetcode.com/problems/find-k-closest-elements/
#### 23) check if two strings are anagram
    ex: "evil" v.s "viel" => true
https://leetcode.com/problems/valid-anagram/
# ----------------------------------------------------
https://hackmd.io/xWA3ohZ-RqyRfm_QpvfAgA?both
