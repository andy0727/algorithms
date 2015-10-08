import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class wordBreak {
	 public static boolean wordBreak(String s, Set<String> dict) {
		if(s.isEmpty())
			return true;
		int n= s.length();
		boolean []dp=new boolean[n];
		for(int i=n-1;i>=0;i--){
			//dp[i]=false;
			for(String w:dict){
				if(i+w.length()<=n &&w.equals(s.substring(i,i+w.length())))
					if(i+w.length()>=n ||dp[i+w.length()])
						dp[i]=true;
			}
		}
		System.out.println(Arrays.toString(dp));
		return dp[0];
	 }
	 public static void main(String args[]){
		 String a = "abcd";
		 Set<String> dict = new HashSet<String>();
		 dict.add("a");
		 dict.add("abc");
		 dict.add("b");
		 dict.add("cd");
		 if(wordBreak(a,dict))
			 System.out.println("true");
	 }
}
