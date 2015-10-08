import java.util.Arrays;


public class MaximalRectangle {
public static int maximalRectangle(char[][] matrix) {
        if(matrix.length<1)
        	return 0;
        int m = matrix.length;
        int n= matrix[0].length;
        int [] left = new int[n];
        int [] right= new int[n];
        int [] h= new int[n];
        for(int i=0;i<n;i++){
        	left[i]=0;
        	right[i]=n;
        	h[i]=0;
        }	
        int res=0,cur_l,cur_r;
        for(int r=0;r<m;r++){
        	cur_l=0; cur_r=n;
        	
        	for(int c=0;c<n;c++)
        		h[c]=(matrix[r][c]=='1')?h[c]+1:0;
        	System.out.println("h: "+Arrays.toString(h));
        	for(int c=0;c<n;c++){
        		if(matrix[r][c]=='1')
        			left[c]=(left[c]>cur_l)?left[c]:cur_l;
        		else{
        			left[c]=0; cur_l=c+1;
        		}
        	}
        	System.out.println("l: "+Arrays.toString(left));	
        	for(int c=n-1;c>=0;c--){
        		if(matrix[r][c]=='1')
        			right[c]=(right[c]<cur_r)?right[c]:cur_r;
        		else{
        			right[c]=n; cur_r=c;
        		}
        	}
        	System.out.println("r: "+Arrays.toString(right));
        	for(int c=0;c<n;c++){
        		res=(res>(right[c]-left[c])*h[c])?res:(right[c]-left[c])*h[c];
        	}
        } 	
       return res;
    }
	public static void main(String args[]){
		char[][] m= {{'1','1','0','1'},{'1','1','0','1'},{'1','1','1','1'}};
		System.out.println(maximalRectangle(m));
	}
}
