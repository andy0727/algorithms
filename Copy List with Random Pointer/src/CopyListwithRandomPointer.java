import java.util.LinkedHashMap;
public class CopyListwithRandomPointer {
public RandomListNode copyRandomList(RandomListNode head) {
		if(head==null)
			return null;
        LinkedHashMap<RandomListNode,RandomListNode> visited;
        visited = new LinkedHashMap<RandomListNode, RandomListNode>();
       
        RandomListNode res =new RandomListNode(head.label);
		visited.put(head, res);
		
        RandomListNode tmp;
        while(head!=null){
        	tmp= visited.get(head);
        	
        	if(head.random==null)
        		tmp.random=null;
        	else if(!visited.containsKey(head.random))
        	{
        		tmp.random =new RandomListNode(head.random.label);
        		visited.put(head.random, tmp.random);
        	}
        	else
        		tmp.random=visited.get(head.random);
        	
        	if(head.next==null)
        		tmp.next=null;
        	
        	else if(!visited.containsKey(head.next))
        	{
        		tmp.next =new RandomListNode(head.next.label);
        		visited.put(head.next, tmp.next);
        	}
        	else
        		tmp.next=visited.get(head.next);
        	
        	head=head.next;
        }
        return res;
    }
}
