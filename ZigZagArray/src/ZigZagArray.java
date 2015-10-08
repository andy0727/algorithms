import java.util.Arrays;


public class ZigZagArray {
    static void swap(int[] intArr, int l, int r){
        int temp= intArr[l];
        intArr[l] = intArr[r];
        intArr[r] = temp;
    }
    static int[] wiggleArrangeArray(int[] intArr) {
        int n = intArr.length-1;
        boolean zig=  true;
        Arrays.sort(intArr);
        
        int smallest = 0;
        for(int i =n-1;i>=0;i--){
        	if(smallest >=i) break;
            if(zig){
                swap(intArr, i, smallest++);
            }
            else{
                swap(intArr, i , 0);
            }
            zig=!zig;
        }
        return intArr;
    }
    
    public static void main(String args[]){
    	int n = 16;
    	int[] a= new int[n];
    	for(int i=0;i<n;i++) a[i]=i;
    	int[] res = wiggleArrangeArray(a);
    	System.out.println(Arrays.toString(res));
    }

}
