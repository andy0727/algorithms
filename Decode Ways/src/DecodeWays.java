
public class DecodeWays {
	public int numDecodings(String s) {
		if(s.length()<=0|| s.charAt(0)>'9'||s.charAt(0)<'1')
			return 0;	
		int []dp=new int[s.length()];
		dp[0]=1;

		for(int i=1;i<s.length();i++){
			char c= s.charAt(i);
			if(c>'9'||c<'0')
				return 0;
			if(s.charAt(i-1)=='1'||(s.charAt(i-1)=='2'&&c<'7'))
				dp[i]=(i-2>=0)?dp[i-2]:1;
			if(c!='0')	
				dp[i]+=dp[i-1];
		}
		return dp[s.length()-1];
    }
	
}
