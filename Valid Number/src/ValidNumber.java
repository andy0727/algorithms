
public class ValidNumber {
	public enum Mode {INTEGER,FLOAT,HEX,SCI}
	public boolean isNumber(String s) {
		s=s.toLowerCase();
		boolean sign=false;
		Mode mode=Mode.INTEGER;
		int j=0,n=s.length();
		while(j<s.length()&&s.charAt(j)==' ')j++;
		while(n>0&&s.charAt(n-1)==' ')n--;
		if(j>=n) return false;
		
		char c=s.charAt(j);
		if(c=='-'||c=='+') j++;
		if(j>=n) return false;
		
		for(int i=j;i<n;i++){
			c= s.charAt(i);
			switch(mode){
			case INTEGER:
				if(c>='0'&&c<='9') continue;
				else if(c=='.'&&(i>j||(i<n-1&&(s.charAt(i+1)>='0'&&s.charAt(i+1)<='9')))) mode=Mode.FLOAT;
				else if(c=='e'&&i>j&&i<n-1) mode=Mode.SCI;
				else if(c=='x' &&i>0 && s.charAt(i-1)=='0'&&i<n-1) mode=Mode.HEX;
				else return false;
				break;
			case FLOAT:
				if(c>='0'&&c<='9') continue;
				if(c=='e'&&i<n-1) mode=Mode.SCI;
				else return false;
				break;
			case SCI:
				if(c>='0'&&c<='9') continue;
				//else if (c=='e' && i>j &&s.charAt(i-1)!='e'&&i<n-1) continue;
				else if ((c=='-'||c=='+') && i>j &&s.charAt(i-1)=='e' &&i<n-1) continue;
				else return false;
			case HEX:
				if(c>='0'&&c<='9') continue;
				else if(c>='a'&&c<='f') continue;
				else return false;
			default:
				return false;
			}
		}
			
		return true;
	}	
}
