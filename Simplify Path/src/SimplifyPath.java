import java.util.Stack;


public class SimplifyPath {
	public String simplifyPath(String path) {
        Stack<String> st=new Stack<String>();
        int n=path.length()-1;
        char c;
        String s="";
        if(path.charAt(n)!='/'){
        	path+="/";
        	n++;		
        }
        for(int i=0;i<=n;i++){
        	c=path.charAt(i);
        	if(c=='/'){
        		if(s.equals("..")){
        			if(!st.isEmpty())
        			st.pop();
        		}
        		else if(!s.isEmpty()&&!s.equals(".")){
        			st.push(s);
        		}
        		s="";	
        	}
        	else
        		s+=c;
        }
        s="";
        String tmp;
        while(!st.isEmpty()){
        	tmp=st.pop();
        	s="/"+tmp+s;
        }
        return (s.isEmpty())?"/":s;
    }
	public static void main(String args[]){
		SimplifyPath so = new SimplifyPath();
		System.out.println(so.simplifyPath("/a/./b/../../c"));
	}
}
