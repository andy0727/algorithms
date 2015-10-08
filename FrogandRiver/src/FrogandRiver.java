import java.util.Arrays;


public class FrogandRiver {
	//given A represents leaves drop at time (index), find the earliest time that the frog can cross
	//time: O(n) space: O(X)
	public int solve(int[] A, int D, int X){

		if(X ==0) return 0;
		if(D <= 0) return -1;
		
		int size = (X -1) / D;
		int[] min = new int[size];
		int[] max = new int[size];
		
		for(int i=0;i<size;i++){
			min[i] = Integer.MAX_VALUE;
		}
		
		int reach = 0;
		for(int i=0;i<A.length;i++){
			int index = (A[i] -1) / D;
			if(index <0 || index >= size) continue;
			min[index] = Math.min(A[i], min[index]);
			max[index] = Math.max(A[i], max[index]);
			
			if(index >= reach){
				while(reach+1 < size && max[reach] + D >= min[reach+1]){
					reach++;
				}
			}
			if(max[reach] + D >= X) return i;
		}
		System.out.println(reach);
		System.out.println(Arrays.toString(max));
		System.out.println(Arrays.toString(min));
		return -1;
	}
	
	public static void main(String args[]){
		FrogandRiver so = new FrogandRiver();
		int[] A = {};
		int D = 0;
		int X = 0;
		assert so.solve(A, D, X) == 0;
		
		X = 1;
		assert so.solve(A, D, X) == -1;
		
		D = -1;
		assert so.solve(A, D, X) == -1;
		
		A = new int[]{1,2,3,4};
		D = 1;
		X = 5;
		int val = so.solve(A, D, X);
		assert val == 3 : val;
		
		A = new int[]{4,3,2,1};
		D = 1;
		X = 5;
		val = so.solve(A, D, X);
		assert val == 3 : val;
		
		A = new int[]{2,4,3,1};
		D = 1;
		X = 5;
		val = so.solve(A, D, X);
		assert val == 3 : val;

		A = new int[]{2,0,0,0,0,0,4,0,0,0,0,3,0,0,0,1};
		D = 1;
		X = 5;
		val = so.solve(A, D, X);
		assert val == 15 : val;

		A = new int[]{9,5,1,11,7,2,3,6,8,13};
		D = 3;
		X = 14;
		val = so.solve(A, D, X);
		assert val == 5 : val;
		System.out.println("ok!");
	}
}
