import java.util.ArrayList;
import java.util.List;


public class SpiralMatrix {
	 public List<Integer> spiralOrder(int[][] matrix) {
		 List<Integer> res= new ArrayList<Integer>();
		 int n=matrix.length;
		 if(n<=0)
			 return res;
	
		 int lstart=0, lend=matrix[0].length-1,rstart=0,rend=n-1;
		 int i=0,j=0;
		 while(lstart<lend || rstart<rend){
			 for(j=lstart;j<=lend;j++)
				 res.add(matrix[rstart][j]);
			 rstart++;
			 for(i=rstart;i<=rend;i++)
				 res.add(matrix[i][lend]);
			 lend--;
			 for(j=lend;j>=lstart && rstart<=rend;j--)
				 res.add(matrix[rend][j]);
			 rend--;
			 for(i=rend;i>=rstart && lstart<=lend;i--)
				 res.add(matrix[i][lstart]);
			 lstart++;
		 }
		 return res;
	 }
	 public static void main(String args[]){
		 SpiralMatrix so= new SpiralMatrix();
		 int[][] m={{4,3},{1,2},{5,6}};
		 for(int i:so.spiralOrder(m))
			 System.out.println(i);
		 System.out.println("a");
	 }
}
