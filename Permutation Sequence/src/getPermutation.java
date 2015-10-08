import java.util.Arrays;


public class getPermutation {
	public static String getPermutation(int n, int k) {
		int[] res= new int[n];
		for(int i=1;i<=n;i++)
			res[i-1]=i;
		while(k>1){
			int target;
			for(target=n-1; target>0 && res[target]<res[target-1] ;target--);
			if(target==0)
				break;
			int dest;
			for(dest=target;dest<n-1 && res[dest+1]>res[target-1];dest++);
			
			int temp = res[target-1];
			res[target-1]=res[dest];
			res[dest]= temp;
			
			for(int i=target;i<(target+n)/2;i++){
				temp=res[i];
				res[i]=res[n-1+target-i];
				res[n-1+target-i]=temp;
			}
			System.out.println(Arrays.toString(res));
			k--;
		}
		StringBuilder s= new StringBuilder();
		for(int i:res)
			s.append(i);
		return s.toString();
    }
	
	public static String getPermutation2(int n, int k) {
		char[] res= new char[n];
		int f=1,i;
		for(i=1;i<=n;i++){
			f*=i;
			res[i-1]=(char) ('1'+i-1);
		}
		
		int j=0;
		for(i=0,k--;i<n;i++){
			f/=n-i;
			j = i+k/f;
			char c= res[j];
			for(;j>i;j--)
				res[j]=res[j-1];
			res[i]=c;
			k%=f;
		}
		return new String(res);
    }
	public static void main(String args[]){
		String a= getPermutation2(4,1);
		System.out.println(a);
	}
}
