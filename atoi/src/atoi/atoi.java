package atoi;

public class atoi {
    public int atoi2(String str) {
    	int res=0,sign=0,i=0;
    	while(i<str.length()&&str.charAt(i)==' ')i++;
    	for(;i<str.length();i++){
    		char c = str.charAt(i);
    		if(sign==0 && (c=='+'||c=='-')){
    			sign=c=='+'?1:2;
    		}
    		else if(c>'9'||c<'0')
    			break;
    		else{
    			if(res<-214748364||res==-214748364 && (c=='9'||sign<2&&c>='8'))
    				return sign<2?Integer.MAX_VALUE:Integer.MIN_VALUE;
    			res=res*10-(c-'0');
    		}
    	}
    	return sign<2?-res:res;
    }
    public static void main(String s[]){
    	
    	atoi so=new atoi();
    	System.out.println(so.atoi2("-2147483649"));
    }
}
