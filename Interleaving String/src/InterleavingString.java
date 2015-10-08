import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;


public class InterleavingString {
	public boolean isInterleave(String s1, String s2, String s3) {
		System.out.println("s1: "+s1+" s2: "+s2+" s3: "+s3);
        if(s1.isEmpty()&&s2.isEmpty()&&s3.isEmpty())
        	return true;
        String tmp="",news3=(s3.length()>1)?s3.substring(1):"";
        if(!s1.isEmpty()&&!s3.isEmpty()&&s1.charAt(0)==s3.charAt(0)){
        	if(s1.length()>1)
        		tmp=s1.substring(1);
        	if(isInterleave(tmp,s2,news3)) return true;
        }
        
        if(!s2.isEmpty()&&!s3.isEmpty()&&s2.charAt(0)==s3.charAt(0)){
        	if(s2.length()>1)
        		tmp=s2.substring(1);
        	if(isInterleave(s1,tmp,news3)) return true;
        }
        return false;     	
    }
	
	public boolean isInterleave2(String s1, String s2, String s3) {
		int n=s1.length();
		int m=s2.length();
		int p=s3.length();
		if(n<1||m<0)
			return (s1.equals(s3))||(s2.equals(s3));
		
		int[][] dp=new int[n+1][m+1];
		Stack<int[]> moves=new Stack<int[]>();
		dp[0][0]=1;
		char[] c=s3.toCharArray();
		moves.add(new int[]{0,0});
		int r1,r2;
		int[] tmp;
		
			while(!moves.isEmpty()){
				tmp=moves.pop();
				r1=tmp[0];
				r2=tmp[1];
				System.out.println("r1: "+r1+" r2: "+r2);
				if(r1<n && s1.charAt(r1)==s3.charAt(r1+r2)){
					dp[r1+1][r2]=1;
					moves.push(new int[]{r1+1,r2});
				}
				if(r2<m && s2.charAt(r2)==s3.charAt(r1+r2)){
					dp[r1][r2+1]=1;
					moves.push(new int[]{r1,r2+1});
					
				}
			}
		
		for(int i=0;i<n;i++)
			System.out.println(Arrays.toString(dp[i]));
		return dp[n][m]==1;
	}
	public boolean isInterleave3(String s1, String s2, String s3) {
		int n=s1.length();
		int m=s2.length();
		int p=s3.length();
		if(m+n!=p)
			return false;
		boolean[][] dp=new boolean[n+1][m+1];
		dp[0][0]=true;
		for(int i=1;i<=m;i++)
			dp[0][i]=dp[0][i-1] && (s2.charAt(i-1)==s3.charAt(i-1)); 
		for(int i=1;i<=n;i++)
			dp[i][0]=dp[i-1][0]&& (s1.charAt(i-1)==s3.charAt(i-1));
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				dp[i][j]= (dp[i-1][j] && (s1.charAt(i-1)==s3.charAt(i+j-1)))||
						  (dp[i][j-1] && (s2.charAt(j-1)==s3.charAt(i+j-1)));
		}
		return dp[n][m];
	}
	public static void main(String s[]){
		InterleavingString so=new InterleavingString();
		System.out.println(so.isInterleave3("aabcc", "dbbca", "aadbbcbcac"));
	}
}
