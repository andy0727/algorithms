
public class WordSearch {
	int m;
	int n;
	int l;
	public boolean helper(char[][] board, String word,int i,int j,int cur,int[][] v){
		if(board[i][j]!=word.charAt(cur)||v[i][j]==1)
			return false;
		if(cur==l-1)
			return true;
		v[i][j]=1;
		if((i>0 && helper(board,word,i-1,j,cur+1,v)) ||
		   (i<m-1 && helper(board,word,i+1,j,cur+1,v)) ||
		   (j>0 && helper(board,word,i,j-1,cur+1,v)) ||
		   (j<n-1 && helper(board,word,i,j+1,cur+1,v)))
			return true;
			
		v[i][j]=0;
		return false;
	}
	public boolean exist(char[][] board, String word) {
		m=board.length;
		if(m<=0)
			return false;
		n=board[0].length;
		l=word.length();
		if(l<1)
			return true;
		int[][] v=new int[m][n];
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++){
				if(board[i][j]==word.charAt(0)&&helper(board,word,i,j,0,v))
					return true;
			}
		return false;	
    }
	public static void main(String s[]){
		char[][] b={{'b','b'},
				{'a','b'},
				{'b','a'}};
		String word="a";
		WordSearch so=new WordSearch();
		System.out.println(so.exist(b, word));
	}
}
