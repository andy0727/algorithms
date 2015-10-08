import java.util.LinkedHashMap;


public class LRUCache {
	class ListNode{
		int val;
		int key;
		ListNode pre;
		ListNode next;
		ListNode(int x,int key){val=x;this.key=key;pre=null;next=null;}
	}
	
    LinkedHashMap<Integer,ListNode> m;
    int size;
    ListNode head,tail;
    public LRUCache(int capacity) {
        m=new LinkedHashMap<Integer,ListNode>();
        size=capacity;
        head=null;
        tail=null;
    }
    
    public int get(int key) {
        if(m.containsKey(key)){
        	ListNode node= m.get(key);
        	update(node);
        	return node.val;
        }
        else
        	return -1;
    }
    
    public void set(int key, int value) {
    	if(m.containsKey(key)){
    		ListNode node=m.get(key);
    		node.val=value;
    		update(node);
    	}
    	else{
    		ListNode node=new ListNode(value,key);
    		node.next=head;
    		if(head!=null)
    			head.pre=node;
    		head=node;
    		m.put(key,node);
    		
    		if(tail==null)
    			tail=head;
    		
       		if(m.size()>size){
       			m.remove(tail.key);
       			if(tail==head)
       				head=null;
    			tail=tail.pre;
    			if(tail!=null)
    				tail.next=null;
    		}
    	}
    }
    public void update(ListNode node){
    	if(node.pre==null)
    		return;
    	node.pre.next=node.next;
    	if(node.next!=null)
    		node.next.pre=node.pre;
    	
    	else
    		tail=node.pre;
    	
    	node.pre=null;
    	node.next=head;
    	
    	head.pre=node;
    	head=node;
    	
    }
}
