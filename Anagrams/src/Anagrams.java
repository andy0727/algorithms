import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;


public class Anagrams {
	 List<String> res =new ArrayList<String> ();
	    HashMap<String,Integer> m= new HashMap<String,Integer>();
	    public List<String> anagrams(String[] strs) {
	    	String[] hash= new String[strs.length];
	        for(int i=0;i<strs.length;i++){
	            char[] chars=strs[i].toCharArray();
	            Arrays.sort(chars);
	            hash[i]= new String(chars);
	            m.put(hash[i],m.get(hash[i])==null?1:m.get(hash[i])+1);
	        }
	        for(int i=0;i<strs.length;i++){
	        	if(m.containsKey(hash[i])&& m.get(hash[i])>1)
	        		res.add(strs[i]);
	        }
	        return res;
	        
	    }
}
