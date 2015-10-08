import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class ThreeSum {
public List<List<Integer> > threeSum(int[] num) {
        Arrays.sort(num);
        List<List<Integer> > res= new ArrayList<List<Integer> >();
        int last=num[0]-1;
        for(int i=0;i<num.length;i++){
        	if(last==num[i])
        		continue;
        	last=num[i];
        	int tar=-num[i];
        	int l=i+1,r=num.length-1;
        	
        	while(l<r){
        		if(num[l]+num[r]==tar)
        		{
        			ArrayList<Integer> tmp=new ArrayList<Integer>();
        			tmp.add(num[i]);tmp.add(num[l]);tmp.add(num[r]);
        			res.add(tmp);
        			for(;l<num.length-1 && num[l+1]==num[l];l++);
        			for(;r>0 && num[r-1]==num[r];r--);
        			l++;r--;
        		}	
        		else if(num[l]+num[r]>tar)
        			r--;
        		else
        			l++;
        	}
        }
        return res;
    }
	public static void main(String s[]){
		ThreeSum so=new ThreeSum();
		System.out.println(so.threeSum(new int[]{-9,14,-7,-8,9,1,-10,-8,13,12,6,9,3,-3,-15,-15,1,8,-7,-4,-6,8,2,-10,8,11,-15,3,0,-11,-1,-1,10,0,6,5,-14,3,12,-15,-7,-5,9,11,-1,1,3,-15,-5,11,-12,-4,-4,-2,-6,-10,-6,-6,0,2,-9,14,-14,-14,-9,-1,-2,-7,-12,-13,-15,-4,-3,1,14,3,-12,3,3,-10,-9,-1,-7,3,12,-6,0,13,4,-15,0,2,6,1,3,13,8,-13,13,11,11,13,14,-6}));
	}
}
