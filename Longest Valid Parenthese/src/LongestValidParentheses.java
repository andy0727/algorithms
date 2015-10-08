import java.util.Stack;


public class LongestValidParentheses {
	public int longestValidParentheses(String s) {
		int max=0;
        Stack<Integer> st=new Stack<Integer>();
        int index=s.length()-1,count=0;
        
        for(int i=0;i<s.length();i++){
        	if(s.charAt(i)=='('){
        		st.push(count);
        		count=0;
        	}	
        	else if(!st.isEmpty()){
        		count+=st.pop()+1; 
        		if(count>max) max=count;
        	}
        	else{
        		count=0;
        		st.clear();
        	}
        }
        return max;
        
    }
    public int longestValidParentheses2(String s) {
        int max=0;
        char[] c= s.toCharArray();
        int n= c.length;
        int open=0;
        int[] v= new int[n];
        for(int i=0;i<n;i++){
            if(c[i]=='(') open++;
            else if(open>0){
                open--;
                v[i]=v[i-1]+2+((i-v[i-1]-2>0)?v[i-v[i-1]-2]:0);
            }
            if(v[i]>max)
                max=v[i];
        }
        return max;
    }
	public static void main(String s[]){
		LongestValidParentheses so= new LongestValidParentheses();
		System.out.println(so.longestValidParentheses("(()()"));
	}
}
