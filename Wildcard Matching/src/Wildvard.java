import java.util.Arrays;

public class Wildvard {
	 public boolean isMatch(String s, String p) {
		 if(s.isEmpty()){
			 int pp=0;
			 while(pp<p.length() && p.charAt(pp)=='*')pp++;
			 return p.isEmpty()||pp==p.length();
		 }
		 if(p.isEmpty())
			 return false;
		 int m=s.length()-1;
		 int n=p.length()-1;
		 int[][]dp=new int[n+1][m+1];
		 char c= p.charAt(n);
		 dp[n][m]=(c=='?'||c=='*'||c==s.charAt(m))?1:0;
		 
		 for(int j=m-1;j>=0;j--)
			 dp[n][j]=c=='*'?1:0;
		 
		 for(int i=n-1;i>=0;i--){
			 c=p.charAt(i);
			 dp[i][m]= dp[i+1][m]& (p.charAt(i)=='*'||
					 			(p.charAt(i+1)=='*'&&(c=='?'||c==s.charAt(m)))?1:0);
		 }
		 
		 for(int i=n-1;i>=0;i--){
			 for(int j=m-1;j>=0;j--){
				 c=p.charAt(i);
				 dp[i][j]=dp[i+1][j+1];
				 if(p.charAt(i+1)=='*')
					 dp[i][j]=dp[i][j]|dp[i+1][j];
				 if(c=='*')
					 dp[i][j]=dp[i][j]|dp[i+1][j]|dp[i][j+1];
				 dp[i][j]=dp[i][j]&((c=='?'||c=='*'||c==s.charAt(j))?1:0);
				 
			 }
		}
		for(int i=0;i<=n;i++)
			System.out.println(Arrays.toString(dp[i]));
		return dp[0][0]==1; 
	 }
	 public boolean isMatch2(String s, String p){
	        int ss=0,pp=0,mark=-1,sl=s.length(),pl=p.length();
	        while(ss<sl){
	            if(pp==pl||(s.charAt(ss)!='?' &&s.charAt(ss)!=p.charAt(pp)&&p.charAt(pp)!='*')){
	                if(mark==-1)
	                    return false;
	                ss=ss-(pp-mark)+1;
	                pp=mark;
	            }
	            else if(p.charAt(pp)=='*'){mark=++pp;}
	            else{
	                ss++;
	                pp++;
	            }
	        }
	        for(;pp<pl&&p.charAt(pp)=='*';pp++);
	        System.out.println(pp);
	        return pp==pl;
	    }
	 public static void main(String s[]){
		 Wildvard so=new Wildvard();
		 System.out.println(so.isMatch2("aa", "*"));
	 }
}
