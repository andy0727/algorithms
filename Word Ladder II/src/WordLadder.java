import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Queue;
import java.util.Set;


public class WordLadder {
	public int distance(String s1, String s2){
		int count=0;
		for(int i=0;i<s1.length();i++){
			if(s1.charAt(i)!=s2.charAt(i))
				count++;
			if(count>1)
				return 2;
		}
		return count;
	}
	public List<List<String> > findLadders(String start, String end, Set<String> dict) {
        List<List<String> >res=new ArrayList<List<String> >();
        List<String>temp=new ArrayList<String>();
        List<String> remove=new ArrayList<String>();
        Queue<List<String> > q = new ArrayDeque<List<String>>();
        temp.add(start);
        q.add(temp);
        dict.remove(start);
        int cur=1,next=0;
        boolean opt =false;
        while(!q.isEmpty()){
        	temp =q.poll();
        	String s=temp.get(temp.size()-1);
        	System.out.println(s);
        	cur--;
        	if(distance(s,end)==1){
        		opt =true;
        		temp.add(end);
        		res.add(temp);
        		dict.remove(s);
        	}
        	if(!opt){
        		char[] word=s.toCharArray();
        		for(int i=0;i<word.length;i++){
        			char c =word[i];
        			for(word[i]='a';word[i]<='z';word[i]++){
        				String tmp=String.valueOf(word);
        				if(dict.contains(tmp)){
        					List<String> temp2=new ArrayList<String>(temp);
        					temp2.add(tmp);
        					q.add(temp2);
        					remove.add(tmp);
        					next++;
        				}
        			}
        			word[i]=c;
        		}
        	}
        	if(cur==0){
        		if(opt) break;	
        		cur=next;
        		next=0;	
        		for(String st:remove)
        			dict.remove(st);
        		remove.clear();
        	}
        }
        
        return res;
    }
	public static void main(String s[]){
		WordLadder so=new WordLadder();
		String start="red";
		String end="tax";
		Set<String> dict=new HashSet<String>();
		dict.add("ted");
		dict.add("tex");
		dict.add("red");
		dict.add("tax");
		dict.add("tad");
		dict.add("den");
		dict.add("rex");
		dict.add("pee");
		System.out.println(so.findLadders(start, end, dict));
	}
}
