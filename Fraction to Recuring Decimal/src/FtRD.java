import java.util.HashMap;
import java.util.LinkedHashMap;


public class FtRD {
	public String fractionToDecimal(int numerator, int denominator) {
		if(numerator==0)
			return "0";
		StringBuilder res= new StringBuilder();
        HashMap<Long,Integer> repeated=new HashMap<Long, Integer>();
        res.append((numerator>0)^(denominator>0)?"-":"");
        long n= Math.abs(numerator);
        long d= Math.abs(denominator);
        res.append(n/d);
        n%=d;
        if(n==0)
        	return res.toString();
        
        res.append(".");
        repeated.put(n,res.length());
        while(n!=0){
        	n*=10;
        	res.append(n/d);
        	n%=d;
        	if(repeated.containsKey(n)){
        		res.insert(repeated.get(n),"(");
        		res.append(")");
        		break;
        	}
        	else
        		repeated.put(n,res.length());
        }
        return res.toString();
    }
}
