import java.util.Arrays;


public class MaximumGap {
public static int maximumGap(int[] num) {
        if(num.length <=2)
        	return 0;
        int res=0;
        int min=Integer.MAX_VALUE,max = Integer.MIN_VALUE;
        for(int i:num){
        	min = Math.min(min,i);
        	max= Math.max(max,i);
        }
        int gap=(int) Math.ceil((double)(max-min)/(num.length-1));
        int bsize=(int) Math.ceil((double)(max-min)/gap);
        int[] bucket_min= new int[bsize];
        int[] bucket_max= new int[bsize];
        Arrays.fill(bucket_min,Integer.MAX_VALUE);
        Arrays.fill(bucket_max,Integer.MIN_VALUE);
        
        for(int i:num){
        	if(i==min||i==max)
        		continue;
        	int index = (i-min)/gap;
        	bucket_min[index]= Math.min(i,bucket_min[index]);
        	bucket_max[index]= Math.max(i,bucket_max[index]);
        	
        }
        int pre = min;
        res= gap;
        //System.out.println(Arrays.toString(bucket_min));
        //System.out.println(Arrays.toString(bucket_max));
        for(int i=0;i<bsize;i++){
        	if(bucket_min[i]>bucket_max[i])
        		continue;
        	res=Math.max(res, bucket_min[i]-pre);
        	pre=bucket_max[i];
        }
        res=Math.max(res, max-pre);
        return res;
    }

	public static void main(String[] args){
			int[] a={4,11,12,14,15};
			System.out.println(maximumGap(a));
		
	}
}
