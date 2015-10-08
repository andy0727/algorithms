import java.util.Arrays;


public class FirstMissingPositive {
	public int firstMissingPositive(int[] A) {
        for(int i=0;i<A.length;i++){
            if(A[i]>0 && A[i]<=A.length&& A[A[i]-1]!=A[i]){
                int tmp=A[i];
                A[i]= A[A[i]-1];
                A[tmp-1]=tmp;
                i--;
                System.out.println(i);
            }
        }
        for(int i=0;i<A.length;i++)
            if(A[i]!=i+1) return i+1;
        return A.length+1;    
	}
	public static void main(String s[]){
		FirstMissingPositive so=new FirstMissingPositive();
		System.out.println(so.firstMissingPositive(new int[]{2,1}));
	}
}
