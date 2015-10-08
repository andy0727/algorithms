
public class ValidPalindrome {
	public static boolean isPalindrome(String s) {
        int l=0, r=s.length()-1;
        char[] c= s.toCharArray();
        while(l<r){
        	while(l<s.length() && !Character.isAlphabetic(c[l]) && !Character.isDigit(c[l]))
        		l++;
        	while(r>0 && !Character.isAlphabetic(c[r]) && !Character.isDigit(c[r]))
        		r--;
        	if(l>=s.length()||r<=0)
        		break;
        	if(Character.toLowerCase( c[l++])!=Character.toLowerCase( c[r--]))
        		return false;
        }	
        return true;
    }
	public static void main(String args[]){
		String s="a.";
		if(isPalindrome(s))
			System.out.println("true");
		else 
			System.out.println("false");
	}
}
