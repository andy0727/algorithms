import java.util.Arrays;


public class RegularExpressionMatching {
	public boolean isMatch2(String s, String p) {
       boolean res;
       System.out.println("s: "+s+" p: "+p);
       if(s.isEmpty() && p.isEmpty())
    	   return true;
       else if(p.isEmpty())
    	   return false;
       
       int n1=s.length();
       int n2=p.length();
       
       if(n2>=2 && p.charAt(1) =='*'){
    	   if((p.charAt(0)== '.' || (n1!= 0 && p.charAt(0) == s.charAt(0)))
    			   &&n1 > 0 && isMatch2(s.substring(1), p ))
    		   return true;
    	   
    	   return isMatch2(s,p.substring(2));
       }else{
    	   return n1!=0 && (p.charAt(0)== '.' || p.charAt(0) == s.charAt(0) ) && 
    			   isMatch2(s.substring(1), p.substring(1));
       }
    }
	
	public boolean isMatch(String s, String p) {
        int sl=s.length(),pl=p.length();
        boolean[] dp=new boolean[sl+1];
        dp[0]=true;
        for(int i=0;i<pl;i++){
        	char c= p.charAt(i);
        	if(i+1<pl && p.charAt(i+1)=='*') continue;
        	else if(c=='*'){
        		c=p.charAt(i-1);
        		for(int j=1;j<=sl;j++)
        			dp[j]=dp[j]||(dp[j-1]&&(c==s.charAt(j-1)||c=='.'));
        	}
        	else {
        		for(int j=sl;j>0;j--)
        			dp[j]=dp[j-1]&&(c==s.charAt(j-1)||c=='.');
        		dp[0]=false;
        	}
        }
        return dp[sl];
    }
	public static void main(String s[]){
		RegularExpressionMatching so= new RegularExpressionMatching();
		String st="aab";
		String p=".*c";
		if(so.isMatch2(st, p))
			System.out.println("true");
		else
			System.out.println("false");
	}
}
