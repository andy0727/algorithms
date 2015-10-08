import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;


public class RepeatedDNASequence {
	public List<String> findRepeatedDnaSequences(String s) {
		List<String> res=new ArrayList<String>();
        HashMap<Integer,Integer> m=new HashMap<Integer,Integer>();
        int t=0;
        for(int i=0;i<s.length();i++){
        	t=t<<3 & 0x3FFFFFFF| (s.charAt(i) &7);
        	if(!m.containsKey(t))
        		m.put(t,1);
        	else if(m.get(t)==1){
        		res.add(s.substring(i-9,i+1));
        		m.put(t, 2);
        	}
        }
        return res;
    }
	public static void main(String s[]){
		RepeatedDNASequence so=new RepeatedDNASequence();
		System.out.println(so.findRepeatedDnaSequences("AAAAAAAAAAAAA"));
	}
}
