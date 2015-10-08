import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Queue;
import java.util.Set;


public class WordLadder {
	public int diffbyone(String a1,String a2){
		int count = 0,next=0;
		if(a1.length()!=a2.length())
			return -1;
		for(int i=0;i<a1.length();i++){
			if(a1.charAt(i)!=a2.charAt(i))
				count++;
			if(count>1)
				break;
		}
		return count;
	}
	public int ladderLength(String start, String end, Set<String> dict) {
		int res=2;
		int cur=0,next=0;
		if(dict.size()<=0)
			return res;
		Queue<String> q=new ArrayDeque <String>();
		q.add(start);
		dict.remove(start);
		cur++;
		
		while(!q.isEmpty()){
			start= q.poll();
			cur--;
			if(diffbyone(start,end)==1)
				return res;
			
			char[] wordArr = start.toCharArray();
	        for (int i = 0; i < wordArr.length; ++i) {
	            char c = wordArr[i];
	            for (wordArr[i] = 'a'; wordArr[i] <= 'z'; ++wordArr[i]) {
	                String tmp = String.valueOf(wordArr);
	                if (dict.contains(tmp)) {
	                	q.add(tmp);
	                	next++;
	                    dict.remove(tmp);
	                }
	            }
	            // Restore the char
	            wordArr[i] = c;
	        }
	        
			if(cur<=0)
			{
				cur=next;
				next=0;
				res++;
			}	
		}
		return res;
    }
	public static void main(String s[]){
		WordLadder so=new WordLadder();
		String start="hit";
		String end="cog";
		Set<String> dict=new HashSet<String>();
		dict.add("hot");
		dict.add("dot");
		dict.add("dog");
		dict.add("lot");
		dict.add("log");
		System.out.println(so.ladderLength(start, end, dict));
	}
}
