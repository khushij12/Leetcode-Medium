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
        
        
        ListNode t = l1;
        ListNode t2 = l2;
        
        if(t==null && t2!=null) return t2;
        if(t2==null && t!=null) return t;
        if(t2==null && t==null) return t;
        int s=0;
        while(t!=null || s!=0){
            if(t!=null){
                s=t.val+s;
                t=t.next;
            }
            

                t2.val=t2.val+s;
          
            
            if(t2.val>9){
                t2.val=t2.val-10;
                s=1;
            }else s=0;
            
            if(t2.next==null && (s!=0 || t!=null)){
                t2.next=new ListNode(s,null);
                s=0;
            }
            
            
            
            t2=t2.next;
        }
       
        
        return l2;
    }
}