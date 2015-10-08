
public class MaximumProductSubarray {
    public int maxProduct(int[] A) {
        if(A==null ||A.length<=0)
        	return 0;
        int res=A[0];
        for(int i=1,max=res,min=res;i<A.length;i++){
        	if(A[i]<0){
        		int tmp=max;
        		max=min;
        		min=tmp;
        	}
        	max=(A[i]>max*A[i])?A[i]:max*A[i];
        	min=(A[i]<min*A[i])?A[i]:min*A[i];
        	System.out.println(min+" "+max);
        	if(max>res)
        		res=max;
        }
        return res;
    }
    public static void main(String s[]){
    	MaximumProductSubarray so=new MaximumProductSubarray();
    	System.out.println(so.maxProduct(new int[]{-1,-2,-6,-9}));
    }
}
