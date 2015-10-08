import java.util.*;
public class Solution {
    public boolean willOverflow(int x, int y,boolean sign){
        if (x>214748364 || ( x==214748364 && (y>8 || (!sign && y==8)) ) )
            return true;
        return false;
    }
    /*
    HashMap<String, String> m= new HashMap();
    
    public List<String> letterCombinations(String digits) {
        List<String> res= new ArrayList<String>();
        res.add("");
        int n=digits.length();
        if(n<=0) return res;
        String[] m={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        char[] tmp;
        for(int i=0;i<n;i++){
            tmp = m[digits.charAt(i) - '0'].toCharArray();
            List<String> t = new ArrayList();
            for(String s: res)
                for(char c : tmp)
                    t.add(s+c);
            res = t;
        }
        return res;
    }
    */


    
    public class ListNode {
    	      int val;
    	      ListNode next;
    	      ListNode(int x) { val = x; }
    	  }
    int m, n,w;
    boolean[][] visited;
    boolean exist(char[][] b, String word, int i, int j, int cur){
        if(cur==w) return true;
        visited[i][j] = true;
        char c = word.charAt(cur);
        
        if(i>0 && !visited[i-1][j] && b[i-1][j] == c && exist(b,word, i-1, j, cur+1)) return true;
        if(i<m && !visited[i+1][j] && b[i+1][j] == c && exist(b,word, i+1, j, cur+1)) return true;
        if(j>0 && !visited[i][j-1] && b[i][j-1] == c && exist(b,word, i, j-1, cur+1)) return true;
        if(j<n && !visited[i][j+1] && b[i][j+1] == c && exist(b,word, i, j+1, cur+1)) return true;
        visited[i][j] = false;
        return false;
    }
    public boolean exist(char[][] board, String word) {
        if(word.length()==0) return true;
        w=word.length();
        m=board.length;
        if(m<=0) return false;
        n=board[0].length;
        if(n<=0) return false;
        char c= word.charAt(0);
        visited=new boolean[m][n];
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(c==board[i][j] && exist(board,word,i,j,1)) 
                    return true;
        return false;        
    }
    
    
}
