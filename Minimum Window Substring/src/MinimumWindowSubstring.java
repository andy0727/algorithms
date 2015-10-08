import java.util.HashMap;


public class MinimumWindowSubstring {
	public String minWindow(String S, String T) {
        String res="";
        int min=S.length();
        if(min<T.length())
        	return res;
        char[] s=S.toCharArray();
        char[] t=T.toCharArray();
 
        HashMap<Character,Integer> m=new HashMap<Character,Integer>();
        for(char c:t)
        	m.put(c, m.containsKey(c)?m.get(c)+1:1);
        
        int slow,fast;
        int count=0;
        HashMap<Character,Integer> tm=new HashMap<Character,Integer>();
        for(slow=0,fast=0;fast<s.length;fast++){
        	
        	if(m.containsKey(s[fast])){
        		tm.put(s[fast], tm.containsKey(s[fast])?tm.get(s[fast])+1:1);
        		if(tm.get(s[fast])<=m.get(s[fast]))
        			count++;
        	}	
        	
        	if(count>=t.length){
        		System.out.println(S.substring(slow,fast+1)+" "+count);
        			while(!tm.containsKey(s[slow])||tm.get(s[slow])>m.get(s[slow])){
        				if(tm.containsKey(s[slow]))
        					tm.put(s[slow],tm.get(s[slow++])-1);
        				
        			}
        			System.out.println(S.substring(slow,fast+1)+" "+count);
        			if(fast-slow+1<min){
        				min=fast-slow+1;
        				res=S.substring(slow,fast+1);
        			}
        		}
        }
        return res; 
    }
	public static void main(String s[]){
		MinimumWindowSubstring so=new MinimumWindowSubstring();
		System.out.println(so.minWindow("ab", "b"));
		
	}
}
