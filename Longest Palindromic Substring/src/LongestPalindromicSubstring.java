
public class LongestPalindromicSubstring {
	private int start=0;
	private int len=0;
	private int n=0;
	public void helper(String s, int p,int even){
		int p2= p+even;
		
		while(p>=0 && p2<n && (s.charAt(p)==s.charAt(p2))){
			if(p2-p>len){
				start=p;
				len=p2-p;
			}
			p--; p2++;
		}
		
	}
	public String longestPalindrome(String s) {
		n = s.length();
		for(int i=0;i<n-1;i++){
			helper(s,i,0);
			helper(s,i,1);
		}
		return s.substring(start,start+len+1);
    }
}
