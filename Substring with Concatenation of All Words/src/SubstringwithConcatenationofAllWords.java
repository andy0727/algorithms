import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;


public class SubstringwithConcatenationofAllWords {
	public List<Integer> findSubstring(String S, String[] L) {
        List<Integer> res= new ArrayList<Integer>();
		int n=S.length();
		int l=L.length,p;
		if(n<=0||l<=0||(p=L[0].length())<=0||n<l*p)
			return res;
		
		HashMap<String,Integer> h = new HashMap<String, Integer>();
		for(String s:L)
			h.put(s, (h.containsKey(s)?h.get(s)+1:1));
		
		int left,count;
		String s;
		for(int i=0;i<p;i++){
			left=i;count=0;
			HashMap<String,Integer> th = new HashMap<String, Integer>();
			for(int j=i;j<=n-p;j+=p){
				s=S.substring(j,j+p);
		
				if(h.containsKey(s)){
					
					th.put(s, th.containsKey(s)?th.get(s)+1:1);
					if(th.get(s)<=h.get(s))
						count++;
					else{
						while(th.get(s)>h.get(s)){
							String tmp=S.substring(left,left+p);
							th.put(tmp,th.get(tmp)-1);
							if(th.get(tmp)<h.get(tmp))
								count--;
							left+=p;
						}
					}
					System.out.println(s+" "+count);
					if(count==l){
						res.add(left);
						count--;
						th.put(S.substring(left,left+p),th.get(S.substring(left,left+p))-1);
						left+=p;
					}
				}
				else{
					count=0;
					left=j+p;
					th.clear();
				}
			}
		}
		return res;
    }
	public static void main(String s[]){
		SubstringwithConcatenationofAllWords so=new SubstringwithConcatenationofAllWords();
		String S="barfoothefoobarman";
		String [] L={"foo","bar"};
		System.out.println(so.findSubstring(S, L));
	}
}
