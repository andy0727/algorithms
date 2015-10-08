
public class DivideTwoIntegers {
	 public int divide(int dividend, int divisor) {
		 if(divisor==0)
			 return Integer.MAX_VALUE;
		 int res=0,i=0,curdiv=divisor;
		 boolean sign=false;
		 if(dividend>0){
			 sign=!sign;
			 dividend=0-dividend;
		 }
		 
		 if(divisor>0){
			 sign=!sign;
			 divisor=0-divisor;
		 }
		 
		 while(dividend<=divisor){
			 curdiv=divisor;
			 for(i=1;curdiv>=dividend-curdiv;i=i+i,curdiv=curdiv+curdiv);
			 res+=i;
			 dividend-=curdiv;
		 }
		 return (sign)?-res:res;
	 }
	 public static void main(String s[]){
		 DivideTwoIntegers so=new DivideTwoIntegers();
		 System.out.println(so.divide(Integer.MIN_VALUE,-1));
	 }
}
