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

            # Let the last node of the new list point to the last node of the original list
            while curr1.next != curr2:
                curr1 = curr1.next
            curr2.next = curr1
            
            # let the last node of the original list point to None to avoid a loop
            curr1.next = None

            # reset the pointer for the next round
            curr2 = curr1
            curr1 = head

        return tail




        