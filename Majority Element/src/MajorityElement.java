import java.util.LinkedHashMap;
public class MajorityElement {
	public static int majorityElement(int[] num) {
        int len = num.length;
        LinkedHashMap<Integer,Integer> map=new LinkedHashMap<Integer,Integer>();
        for(int n:num){
        	if(map.containsKey(n)){
        		int val = map.get(n);
        		if(val>=(len+1)/2)
        			return n;
        		map.put(n,val+1);
        	}
        	else
        		map.put(n, 1);
        }
        return -1;
    }
}
