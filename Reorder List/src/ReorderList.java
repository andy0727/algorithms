
public class ReorderList {
	public void reorderList(ListNode head) {
		if(head==null||head.next==null)
			return;
		ListNode cur=head;
		while(cur!=null){
			ListNode cur2=cur;
			while(cur2.next!=null&&cur2.next.next!=null) cur2=cur2.next;
			if(cur2.next!=null&&cur2.next.next!=null){
				ListNode tmp= cur2.next;
				cur2.next=tmp.next;
				tmp.next=cur.next;
				cur.next=tmp;
			}
			if(cur.next!=null)
				cur=cur.next.next;
			else
				cur=null;
			
		}
	}
	public void reorderList2(ListNode head) {
	if(head==null||head.next==null)
			return;
		ListNode cur=head,half=head,tmp,pre=head;
		while(cur!=null&&cur.next!=null){
		    pre=half;
			cur=cur.next.next;
			half=half.next;
		}
		pre.next=null;
		cur=half;
		half=null;
		while(cur!=null){
			tmp=cur.next;
			cur.next=half;
			half=cur;
			cur=tmp;
		}
		while(head!=null &&half!=null)
		{
			tmp=head.next;
			head.next=half;
			if(tmp==null)
			    break;
			head=half.next;
			half.next=tmp;
			half=head;
			head=tmp;
		}
	
	}
}
