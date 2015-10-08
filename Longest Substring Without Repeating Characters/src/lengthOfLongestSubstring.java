import java.util.LinkedHashMap;
public class lengthOfLongestSubstring {
	public static int lengthOfLongestSubstring(String s) {
		int res=1;
		int n=s.length();
		int l=0,r=0;
		if(n==0)
			return 0;
		LinkedHashMap<Character,Integer> repeated = new LinkedHashMap<Character,Integer>();
		int pos1=0,pos2=0;
		for(int i=0;i<n;i++){
			char c = s.charAt(i);
			if(repeated.containsKey(c) && repeated.get(c)>=pos1 ){
				pos1=repeated.get(c)+1;
			}
			if(i+1-pos1>res){
				res=i+1-pos1;
				l=pos1;
				r=i;
			}
			repeated.put(c, i);
			System.out.println("i is: "+i+" pos1 is: "+pos1+" pos2 is: " + pos2+" "+s.substring(pos1,i+1));
		}
		System.out.println(s.substring(l,r));
		return res;
    }
	
	public static void main(String args[]){
		String s= "qwnfenpglqdq";
		LinkedHashMap<Character,Integer> repeated = new LinkedHashMap<Character,Integer>();
		repeated.put('a', 1);
		repeated.put('a', 2);
		System.out.println(repeated.toString());
		System.out.println(lengthOfLongestSubstring(s));
		
	}
}
