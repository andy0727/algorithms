import java.util.ArrayList;
import java.util.List;


public class Solution {
    class Heap{
        ListNode[] h;
        int n;
        Heap(List<ListNode> lists){
            n=0;
            for(ListNode t:lists)
                while(t!=null){n++;t=t.next;}
            h=new ListNode[n];
            n=0;
            for(ListNode t:lists)
                 while(t!=null){h[n++]=t;t=t.next;}
            for(int i=0;i<n/2;i++)
                sink(i);
        }
        void sink(int i){
            int l=2*i+1,r=l+1,c=i;
            if(l<n && h[l].val<h[i].val) c=l;
            if(r<n && h[r].val<h[c].val) c=r;
            if(c!=i){
                ListNode t= h[i];
                h[i]=h[c];
                h[c]=t;
                sink(c);
            }
        }
        public ListNode out(){
            if(n<=0) return null;
            ListNode res=h[0];
            h[0]=h[n-1];
            n--;
            sink(0);
            return res;
        }
        
    }
    public ListNode mergeKLists(List<ListNode> lists) {
        Heap h=new Heap(lists);
        ListNode res=h.out(),cur=res;
        while(cur!=null){
            cur.next=h.out();
            cur=cur.next;
        }
        return res;
    }
	
	public static void main(String args[]){
		Solution so=new Solution();
		int a[]={1,2,3,4,5}; 
		ListNode head= new ListNode(8);
		ListNode cur=head;
		for(int i=0; i<5;i+=2){
			cur.next= new ListNode(i);
			cur=cur.next;
		}
		ListNode head2= new ListNode(7);
		cur=head2;
		for(int i=1; i<6;i+=2){
			cur.next= new ListNode(i);
			cur=cur.next;
		}
		
		List<ListNode> test= new ArrayList<ListNode>();
		test.add(head);
		test.add(head2);
		
		head= so.mergeKLists(test);
		cur = head;
    	String s="";
    	while(cur!=null){
    		s+=cur.val+" ";
    		cur=cur.next;
    	}
    	System.out.println(s);
	}
}
