import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.Map;


public class SudokuSolver {
	public static LinkedHashMap<Character,Boolean>[] h;
	public static LinkedHashMap<Character,Boolean>[] v;
	public static LinkedHashMap<Character,Boolean>[] in;
	public SudokuSolver(){
		h = new LinkedHashMap [9];
		v = new LinkedHashMap [9];
		in = new LinkedHashMap [9];
		for(int i=0;i<9;i++){
		    h[i]= new LinkedHashMap<Character,Boolean>();
		    v[i]= new LinkedHashMap<Character,Boolean>();
		    in[i]= new LinkedHashMap<Character,Boolean>();
		}
	}
	public static void printBoard(char[][] b){
		for(int i=0;i<b.length;i++){
			System.out.print("[");
			int count=0;
			String st="";
			for(int j=0;j<b[0].length;j++){
				st+=" "+b[i][j];
				count++;
				if(count%3==0){
					st+="     ";
				}
			}
			System.out.println(st+" ]\n");
		}
		System.out.println("\n\n\n");
	}
	
	public boolean solveSudoku(char[][] board,ArrayList<int[]> moves, int cur){
		if(cur>=moves.size()) return true;
		int r= moves.get(cur)[0], c=moves.get(cur)[1];
		for(char i='1';i<='9';i++){
			if(!h[r].containsKey(i)&&!v[c].containsKey(i)&&!in[c/3+r/3*3].containsKey(i))
			{
				h[r].put(i, true); v[c].put(i, true); in[c/3+r/3*3].put(i, true);
				board[r][c]=i;
				
				
				if(solveSudoku(board,moves,cur+1))
					return true;
	
				else{
					board[r][c]='.';
					h[r].remove(i, true); v[c].remove(i, true); in[c/3+r/3*3].remove(i, true);
				}
			}
		}
		return false;
	}
	
	public void solveSudoku(char[][] board){
		ArrayList<int[]> moves = new ArrayList<int[]>();
		for(int i=0;i<board.length;i++)
			for(int j=0;j< board[0].length;j++){
				char c=board[i][j];
				if(c=='.')
					moves.add(new int[]{i,j});
				else{
					v[j].put(c, true);
					h[i].put(c, true);
					in[j/3+i/3*3].put(c,true);
				}
			}
		solveSudoku(board,moves,0);
    }
	public static void main(String args[]){
		char[][]b={{'5','3','.',    '.','7','.',     '.','.','.'},
				   {'6','.','.',    '1','9','5',     '.','.','.'},
				   {'.','9','8',    '.','.','.',     '.','6','.'},
				   {'8','.','.',    '.','6','.',     '.','.','3'},
				   {'4','.','.',    '8','.','3',     '.','.','1'},
				   {'7','.','.',    '.','2','.',     '.','.','6'},
				   {'.','6','.',    '.','.','.',     '2','8','.'},
				   {'.','.','.',    '4','1','9',     '.','.','5'},
				   {'.','.','.',    '.','8','.',     '.','7','9'}
				   };
		
		SudokuSolver s= new SudokuSolver();
		s.solveSudoku(b);
		printBoard(b);
		
		
	}
}
