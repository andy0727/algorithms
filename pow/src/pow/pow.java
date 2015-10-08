package pow;

public class pow {
	public double pow(double x, int n) {
		if(x==0) return 0;
        
        if(n<0){
        	x=1/x;
        	n=-n;
        }
        if(n==0) return 1;
        if(n==1) return x;
        
        double res=pow(x,n/2);
        if(n%2==0) return res*res;
        else return res*res*x;
    }
}
