import java.lang.reflect.Array;
import java.util.Arrays;


public class Solution {
	public void add(char[] res, int pos, int tmp){
		int newc = res[pos]-'0'+tmp;
		if(newc>=10)
			add(res,pos-1,newc/10);
		
		res[pos]=(char)(newc%10+'0');
	}
	public String multiply(String num1, String num2) {
		if(num1.isEmpty()||num2.isEmpty())
			return "";
		char[] c1=num1.toCharArray();
		int n1= num1.length();
		char[] c2=num2.toCharArray();
		int n2= num2.length();
		
		char[] res=new char[n1+n2];
		for(int i=0;i<n1+n2;i++) res[i]='0';
		
		for(int i=n1-1; i>=0;i--)
			for(int j=n2-1;j>=0;j--){
				
				int tmp= (c1[i]-'0')*(c2[j]-'0');
				add(res,i+j+1,tmp);
			}
		String s="";
		boolean start= false;
		for(int i=0;i<n1+n2;i++){
			if(start)
				s+=res[i];
			else if(res[i]!='0'){
				start=true;
				s+=res[i];
			}
		}	
		
		return (start)?s:"0";
    }
	public static void main(String s[]){
		String num1="1";
		String num2="0";
		Solution so= new Solution();
		System.out.println( so.multiply(num1,num2));
	}
}
