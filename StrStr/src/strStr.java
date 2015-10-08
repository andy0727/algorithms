import java.util.Arrays;


public class strStr {
	 public static int strStr(String haystack, String needle) { 
		 int l=0, p=needle.length()-1,r=l+p;
		 while(r<haystack.length()){
			 while(p>=0 && haystack.charAt(r)==needle.charAt(p)){
				 r--; p--;
			 }
			 if(p<0) return l;
			 while(p>=0 && haystack.charAt(r)!=needle.charAt(p)){
				 p--;
			 }
			 l=r-p;
			 p=needle.length()-1;
			 r=l+p;
		 }
		 return -1;
	 }
	 public static int[] buildT(char[] needle){
		 int m = needle.length;
		 if(m<1)
			 return null;
		 
		 int [] p= new int[m];
		 if(m>=1)
			 p[0]=-1;
		 if(m>=2)
			 p[1]=0;
		 int cnd =0, i=2;
		 while(i<m){
			 System.out.println("m is: "+i+" i is: "+ cnd);
			 if(needle[cnd]==needle[i-1])
				 p[i]=++cnd;
			 else{
				 p[i]=0;
				 cnd=0;
			 }
			 i++;
		 }
		 return p;
	 }
	 public static int strStrKMP(String haystack, String needle) { 
		 if(needle.isEmpty())
	            return 0;
	        if(needle.length()>haystack.length())
	            return -1;
	        
		 int[] p = buildT(needle.toCharArray());
		 System.out.println(Arrays.toString(p));
		 int m=0,i=0;
		 char[] h= haystack.toCharArray();
		 char[] n= needle.toCharArray();
		 while(m+i<h.length){
			 if(n[i]==h[m+i]){
				 if(i==n.length-1)
					 return m;
				 i++;	
			 }	 
			 else if(p[i]>-1)
			 {	 
				m=m+i-p[i];
				i=p[i];
			 }		 
			else{
				m=m+1;
				i=0;
			}
			 
		 }
		 return -1;
	 }
	 public static void main(String args[]){
		 String h ="bbababaaaababbaabbbabbbaaabbbaaababbabaabbaaaaabbaaabbbbaaabaabbaababbbaabaaababbaaabbbbbbaabbbbbaaabbababaaaaabaabbbababbaababaabbaa";
		 String n = "bbabba";
		 System.out.println(strStrKMP(h,n));
		 System.out.println(h.substring(strStrKMP(h,n),strStrKMP(h,n)+n.length()));
	 }
}
