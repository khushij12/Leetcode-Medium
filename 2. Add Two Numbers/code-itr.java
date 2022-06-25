/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
        if(l1==null && l2==null) return null;
        if(l2==null) return l1;
        
        if(l1!=null) l2.val=l2.val+l1.val;
        
        if(l2.val>9){
            l2.val=l2.val%10;
            if(l2.next==null) l2.next=new ListNode(1,null);
            else l2.next.val++;
        }

        l2.next = addTwoNumbers(((l1!=null)?l1.next:l1),l2.next);
        return l2;
    }
}