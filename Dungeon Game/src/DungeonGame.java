import java.util.Arrays;


public class DungeonGame {
	public int calculateMinimumHP(int[][] dungeon) {
		int res=1;
		if(dungeon.length<=0||dungeon[0].length<=0)
			return res;
		int[][]dp=new int[dungeon.length][dungeon[0].length];
		int n=dungeon.length;
		int m=dungeon[0].length;
		dp[n-1][m-1]=dungeon[n-1][m-1]>0?0:-dungeon[n-1][m-1];
		
		
		for(int i=dungeon.length-2;i>=0;i--)
			dp[i][m-1]=dp[i+1][m-1]-dungeon[i][m-1]>0?dp[i+1][m-1]-dungeon[i][m-1]:0;
		for(int j=dungeon[0].length-2;j>=0;j--)
			dp[n-1][j]=dp[n-1][j+1]-dungeon[n-1][j]>0?dp[n-1][j+1]-dungeon[n-1][j]:0;
		
		
		for(int i=dungeon.length-2;i>=0;i--)
			for(int j=dungeon[0].length-2;j>=0;j--){
				dp[i][j]=(dp[i+1][j]<dp[i][j+1]?dp[i+1][j]:dp[i][j+1])-dungeon[i][j];
				if(dp[i][j]<0)
					dp[i][j]=0;
			}	
				
			
		
		for(int i=0;i<dp.length;i++){
			for(int j=0;j<dp[0].length;j++)
				System.out.print(dp[i][j]+" ");
			System.out.println();
		}
		return dp[0][0]+1;
    }
	public static void main(String s[]){
		DungeonGame so=new DungeonGame();
		int[][] d={{0,-3},{-10,0}};
		System.out.println(so.calculateMinimumHP(d));
	}
}
