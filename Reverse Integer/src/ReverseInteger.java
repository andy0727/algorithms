
public class ReverseInteger {
	public int reverse(int x) {
        long res=0;
        while(x!=0){
            res=10*res+x%10;
            x/=10;
            System.out.println(res);
        }
        
        return (int)res;    
    }
	public static void main(String[] s){
		ReverseInteger so=new ReverseInteger();
		System.out.println(so.reverse(-321));
	}
}

