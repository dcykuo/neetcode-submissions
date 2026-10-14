# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return None
        
        curr = head
        while curr.next != None:
            curr = curr.next
        tail = curr

        curr1 = head
        curr2 = tail

        while curr2 != head:
            while curr1.next != curr2:
                curr1 = curr1.next
            curr2.next = curr1
            curr2 = curr1
            
            curr1.next = None

            curr1 = head
            
        return tail




        