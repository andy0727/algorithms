import java.math.BigInteger;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Date;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;



public class Test {
	class TreeNode{
		int val;
		TreeNode left, right;
		public TreeNode(int x){val=x;}
	}
	public static void dfs(TreeNode root){
		if(root==null) return;
		dfs(root.left);
		System.out.println(root.val);
		dfs(root.right);
	}
	
	public static void dfs2(TreeNode root){
		if(root==null) return;
		Stack<TreeNode> st = new Stack();

		while(true){
			if(root ==null && st.isEmpty()) break;
			if(root ==null) root= st.pop();
			else{
				while(root.left!=null){
					st.push(root);
					root=root.left;
				}
			}
			System.out.println(root.val);
			root = root.right;
		}
		
	}
	
	public static void bfs(TreeNode root){
		if(root ==null) return;
		int stop = 3;
		int curlevel = 0 , next =0;
		Queue<TreeNode> q= new ArrayDeque();
		q.add(root);
		curlevel++;
		while(!q.isEmpty()){
			TreeNode temp = q.poll();
			curlevel--;
			if(temp.left!=null){q.add(temp.left); next++;}
			if(temp.right!=null){q.add(temp.left); next++;}
			if(curlevel ==0){
				if (curlevel==stop) return; 
				curlevel=next; 
				next = 0;
			}
		}
	}
	static class Employee {
		private final String[] titles;
		
		Employee(String[] titles){
			this.titles = Arrays.copyOf(titles, titles.length);
		}
		String[] getTitles(){
			String[] res = Arrays.copyOf(titles, titles.length);
			return res;
		}
	}
	
    static int isPrime(long n) {
        double sqrt = Math.sqrt(n);
        int res = 2;
        while(res<=sqrt){
            if(n % res ==0) 
                return res;
            else 
                res++;
        }
        return 1;
    }
	
	
    public static void main(String[] args) {
       System.out.println(isPrime(11));
    }
}
