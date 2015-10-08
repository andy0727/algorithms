
public class ScrambleString {
	public boolean isScramble(String s1, String s2) {
        boolean Scramble=false;
        if(s1.length() != s2.length())
        	return false;
        if(s1.equals(s2))
        	return true;
        
        int s= s1.length();
        int[] count= new int[26];
        for(int i=0; i<s;i++) count[s1.charAt(i)-'a']++;
        for(int i=0; i<s;i++) count[s2.charAt(i)-'a']--;
        for(int i: count)
        	if(i!=0) return false;
        for(int i =0; i<s; i++){
        	if(isScramble(s1.substring(0,i),s2.substring(0,i)) &&
        			isScramble(s1.substring(i,s),s2.substring(i,s)))
        		Scramble= true;
        	else if (isScramble(s1.substring(0,i),s2.substring(s-i,s)) &&
        			isScramble(s1.substring(i,s),s2.substring(0,s-i)))
        		Scramble= true;
        }
        return Scramble;
    }
	public boolean isScramble2(String s1, String s2) {
		if(s1.length()!=s2.length()) return false;
		int s= s1.length();
		int [][][] dp= new int[s][s][s+1];
		for(int i =s-1;i>=0;i--){
			for(int j=s-1;j>=0;j--){
				dp[i][j][1]=s1.charAt(i)==s1.charAt(j)?1:0;
				for(int l=2;l+i<=s && j+l<=s;l++){
					for(int n=1;n<l;n++){
						dp[i][j][l]|=dp[i][j][n]&dp[i+n][j+n][l-n];
						dp[i][j][l]|=dp[i][j+l-n][n]&dp[i+n][j][l-n];
					}			
				}
			}
		}
		return (dp[0][0][s]==1);
	}

}
