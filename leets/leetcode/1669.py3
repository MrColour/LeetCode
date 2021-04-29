# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        la = list1
        
        for i in range(a - 1):
            la = la.next
            
        lb = la
        for i in range(b - a + 2):
            lb = lb.next
            
        la.next = list2
        
        it = list2
        while (it.next is not None):
            it = it.next
        
        it.next = lb
        return (list1)