
public class MinStack {
	class ListNode{
		int x;
		int min;
		ListNode next;
		ListNode(int val,int min){x=val;this.min=min;}
	}
	ListNode head;
    public void push(int x) {
    	int min=x;
    	if(head==null||head.min<x)
    		min=head.min;
        ListNode temp=new ListNode(x,Math.min(x, min));
        temp.next=head;
        head=temp;
    }

    public void pop() {
        if(head!=null)
        	head=head.next;
    }

    public int top() {
    	return head.x;
    }

    public int getMin() {
        return head.min;
    }
}
