
public class addTwoNumbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int val=0;
        ListNode res=null,cur=null;
        while(l1!=null||l2!=null){
        	if(l1!=null){
        		val+=l1.val;
        		l1=l1.next;
        	}
        	if(l2!=null){
        		val+=l2.val;
        		l2=l2.next;
        	}
        	if(res==null){
        		res=new ListNode(val%10);
        		cur=res;
        	}
        	else{
        		cur.next=new ListNode(val%10);
        		cur=cur.next;
        	}
        	val/=10;
        	
        }
        return res;
    }
}
