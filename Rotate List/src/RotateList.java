
public class RotateList {
	private class ListNode{
		int val;
		ListNode next;
		public ListNode(int x){ val=x; next=null;}
	}
	public ListNode rotateRight(ListNode head, int n) {
        if(head==null||n<1)
        	return head;
        ListNode cur= head;
        int count=0;
        for(;cur.next!=null;count++,cur=cur.next);
        cur.next=head;
        for( int step =count-n%count; step>0;step--)
        	head=head.next;
        cur=head.next;
        head.next=null;
        return cur;
        
    }
}
