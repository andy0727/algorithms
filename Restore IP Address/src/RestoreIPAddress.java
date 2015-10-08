import java.util.ArrayList;
import java.util.List;


public class RestoreIPAddress {
	public void helper(List<String> res, String p, String s, int cur){
		//System.out.println(p);
		if(cur==4){
			if(s.isEmpty()&&!p.isEmpty())
				res.add(p.substring(1));
			return;
		}
		String p1;
		for(int i=0;i<3&& s.length()>i;i++){
			p1= s.substring(0,i+1);
			if((p1.charAt(0)!='0'||i==0)&&Integer.parseInt(p1)<=255)
				helper(res,p+"."+p1,s.substring(i+1),cur+1);
		}
	} 
	public List<String> restoreIpAddresses(String s) {
		List<String> res= new ArrayList<String>();
		helper(res,"",s,0);
		return res;
	}
	
	public static void main(String s[]){
		String st="010010";
		RestoreIPAddress so=new RestoreIPAddress();
		for(String i: so.restoreIpAddresses(st))
			System.out.println(i);
	}
}
