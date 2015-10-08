import java.util.Arrays;
import java.util.Stack;


public class largestRectangleArea {
	public static int min(int[] h, int x, int y){
		if(x==-1) return y;
		if(y==-1) return x;
		return h[x]<h[y]?x:y;
	}
	public static int max(int x, int y, int z){
		return Math.max(Math.max(x,y),z);
	}
	public  static int construct(int[] a, int [] st, int ss, int se, int cur ){
		if(ss==se){
			st[cur]=ss;
		}
		else{
			int mid = (ss+se)/2;
			st[cur]=min(a,construct(a,st,ss,mid,2*cur+1),
					         construct(a,st,mid+1,se,2*cur+2));
		}
		return st[cur];
	}
	public static int[] construct(int[] a){
		int n=a.length;
		int x= (int) Math.ceil(Math.log(n)/Math.log(2));
		x= (int) (2*Math.pow(2, x)-1);
		int[] res= new int[x];
		construct(a,res,0,n-1,0);
		return res;
	}
	
	public static int QMR(int[] a,int[] st, int ss, int se, int qs , int qe, int cur){
		if(ss>=qs && se<=qe)
			return st[cur];
		else if (qs>se || qe<ss)
			return -1;
		else
		{
			int mid = (ss+se)/2;
			return min(a,QMR(a, st,ss,mid,qs,qe,2*cur+1), QMR(a,st,mid+1,se,qs,qe,2*cur+2));
		}
	}
	
	public static int QMR(int[] a, int[] st,int qs, int qe,int n){
		return QMR(a,st,0,n, qs, qe, 0);
	}
	
	
	public static int largestRectangleArea(int[] h ,int[]st, int s, int e){
		if(s>e) return -1;
		if(s==e) return h[s];
		
		int min= QMR(h,st,s,e,h.length-1);
		System.out.println(min+" "+s+" "+e);
		return max(largestRectangleArea(h,st,s,min-1), 
				   largestRectangleArea(h,st,min+1,e),
				   (e-s+1)*h[min]);
		
	}
	public static int largestRectangleArea(int[] height) {
		if(height==null || height.length<=0)
			return 0;
		int[] h= construct(height);
		//System.out.println(Arrays.toString(h));
		return largestRectangleArea(height,h,0,height.length-1);
		
    }
	
	public static int largestRectangleArea2(int[] height){
		Stack<Integer> st= new Stack<Integer>();
		int n = height.length;
		int max=0,tp,area=0;
		for(int i=0;i<n;i++){
			tp=(i==n-1)?0:height[i];
			if(st.empty()||height[st.peek()]<=tp)
				st.push(i);
			else{
				tp=st.pop();
				area=height[tp]*(st.empty()?i:i-st.peek()-1);
				i--;
				if(max<area)
					max=area;
			}
		}
		return max;
	}
	public static void main(String args[])
	{
	    int hist[] =  {6,2,5,4,5,1,6};
	    System.out.println( largestRectangleArea2(hist));
	}
}
