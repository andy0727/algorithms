
public class SqrtX {
	public static int sqrt(int x) {
		int res = 0;
		if(x==0||x==1)
			return x;
		int l=1,r=x,m,m2;
		while(l<r){
			m=(l+r)/2;
			m2=x/m;
			if(m2==m)
				return m;
			else if (m2>m){
				res=m;
				l=m+1;
			}
			else
				r=m;
			//System.out.println(l);
		}
		return res;
    }
	public static int sqrt2(int x){
		if(x==0)
			return 0;
		else if (x<4)
			return 1;
		int res= 2*sqrt(x/4);
		if(res+1 <= x/(res+1))
			return res+1;
		else
			return res;
	}
	
	public static int sqrt3(int x){
		long y= x>>1;
		for(long dx; (dx= y*y-x)>0;y-=(dx-1)/(y<<1)+1)System.out.println(y);
		return (x==1)? 1:(int) y;
		
	}
	
	public static void main(String args[]){
		int val = 6;
		System.out.println(sqrt3(val));
	}
}
