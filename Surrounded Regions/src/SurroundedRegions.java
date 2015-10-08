import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.Stack;


public class SurroundedRegions {
	public void dfs(char[][]board, int i, int j){
		int n=board.length;
		int m=board[0].length;
		Stack<int[]> q=new Stack<int[]>();
		q.push(new int[]{i,j});
		int x,y;
		while(!q.isEmpty()){
			int[] t=q.pop();
			x=t[0]; y=t[1];
			board[x][y]='U';
			if(x>0 && board[x-1][y]=='O')
				q.push(new int[]{x-1,y});
			if(x<n-1 && board[x+1][y]=='O')
				q.push(new int[]{x+1,y});
			if(y>0 && board[x][y-1]=='O')
				q.push(new int[]{x,y-1});
			if(y<m-1 && board[x][y+1]=='O')
				q.push(new int[]{x,y+1});
		}
	}
	public void dfs2(char[][]board, int i, int j){
		int n=board.length;
		int m=board[0].length;
		Queue<int[]> q=new ArrayDeque<int[]>();
		q.add(new int[]{i,j});
		int x,y;
		while(!q.isEmpty()){
			int[] t=q.poll();
			x=t[0]; y=t[1];
			board[x][y]='U';
			if(x>0 && board[x-1][y]=='O')
				q.add(new int[]{x-1,y});
			if(x<n-1 && board[x+1][y]=='O')
				q.add(new int[]{x+1,y});
			if(y>0 && board[x][y-1]=='O')
				q.add(new int[]{x,y-1});
			if(y<m-1 && board[x][y+1]=='O')
				q.add(new int[]{x,y+1});
		}
		
	}
	public void solve(char[][] board) {
		int n=board.length;
		if(n<=0)
		    return;
		int m=board[0].length;
		for(int i=0;i<n;i++){
			if(board[i][0]=='O')
				dfs(board,i,0);
			
			if(board[i][board[i].length-1]=='O')
				dfs(board,i,board[i].length-1);
		}
		for(int j=0;j<m;j++)
			if(board[0][j]=='O')
				dfs(board,0,j);
		for(int j=0;j<board[n-1].length;j++)
			if(board[n-1][j]=='O')
				dfs(board,n-1,j);
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(board[i][j]=='O')
					board[i][j]='X';
				else if(board[i][j]=='U')
					board[i][j]='O';
			}
		}
    }
	public static void main(String s[]){
		SurroundedRegions so=new SurroundedRegions();
		char[][] b={{'X', 'X','X','X'},
					{'X','O','O','X'},
					{'X','X','O','X'},
					{'X','O','X','X'}};
		so.solve(b);
		System.out.println(Arrays.deepToString(b));
	}
	
}
