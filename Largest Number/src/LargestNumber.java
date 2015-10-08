import java.util.Arrays;


public class LargestNumber {

	public boolean compare(int i,int j){
		String s1=Integer.toString(i)+Integer.toString(j);
		String s2=Integer.toString(j)+Integer.toString(i);
		return s1.compareTo(s2)>0;
				
	}
	public void sort(int[] num,int s,int e){
		if(s>=e) return;
		int p=e,l=s,r=p-1;
		int temp;
		while(true){
			for(;compare(num[l],num[p]);l++);
			for(;l<r && compare(num[p],num[r]);r--);
			if(l>=r) break;
			temp=num[l];
			num[l++]=num[r];
			num[r--]=temp;
		}
		temp=num[p];
		num[p]=num[l];
		num[l]=temp;
		sort(num,s,l-1);
		sort(num,l+1,e);
		
	}
	public String largestNumber(int[] num) {
		String res="";
        if(num.length<=0)
        	return res;
        sort(num,0,num.length-1);
        System.out.println(Arrays.toString(num));
        for(int i=0;i<num.length;i++){
        	if(num[i]==0&&res.isEmpty()&&i!=num.length-1)
        		continue;
        	res+=Integer.toString(num[i]);
        }
        return res;
    }
	
	public static void main(String s[]){
		LargestNumber so=new LargestNumber();
		System.out.println(so.largestNumber(new int[]{0,0}));
	}
}
