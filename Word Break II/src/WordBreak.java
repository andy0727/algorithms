import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;


public class WordBreak {
	public boolean check(String s, Set<String> dict){
		for(int i=0;i<s.length();i++){
			if (dict.contains(s.substring(i)))
				return true;
		}
		return s.isEmpty();
	}
    public List<String> wordBreak(String s, Set<String> dict) {
    	List<String> res= new ArrayList<String>();
    	int n=s.length();
    	if(n<=0)
    		return res;
    	int[] dp=new int[n+1];
    	ArrayList<ArrayList<String>> ans=new ArrayList<ArrayList<String>>();
    	for(int i=0;i<=n;i++)
    		ans.add(new ArrayList<String>());
    	dp[0]=1;
    	for(int i=0;i<=n;i++){
    		if(dp[i]==1){
    			for(int j=i+1;j<=n;j++){
    				if(dict.contains(s.substring(i,j))&&check(s.substring(j),dict)){
    					dp[j]=1;
    					if(ans.get(i).isEmpty())
    						ans.get(j).add(s.substring(i,j));
    					else{
    						for(String tmp:ans.get(i))
    							ans.get(j).add(tmp+" "+s.substring(i,j));
    					}
    				}
    			}
    		}
    	}
    	return ans.get(n);
    }
    public static void main(String s[]){
    	WordBreak so=new WordBreak();
    	Set<String> dict = new HashSet<String>();
    	String t="";
    	for(int i=0;i<10;i++){
    		t+="a";
    		dict.add(t);
    	}
    	String p="a";
    	System.out.println(p.substring(1));
    	System.out.println(dict);
    	for(String st:so.wordBreak("a", dict))
    		System.out.println(st);
    }
}
