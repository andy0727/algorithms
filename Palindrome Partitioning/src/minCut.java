
public class minCut {
	 public int minCut2(String s) {
		 int n=s.length();
		 int []res=new int[n+1];
		 for(int i=0;i<n+1;i++)
			 res[i]=i-1;
	
		 for(int i=0;i<s.length();i++){
			 for(int j=0;i+j<n&&i-j>=0 && s.charAt(i+j)==s.charAt(i-j);j++){
				 res[i+j+1]=(res[i+j]<1+res[i-j])?res[i+j]:1+res[i-j];
			 }
			 for(int j=0;i+j+1<n&&i-j>=0 && s.charAt(i-j)==s.charAt(i+j+1);j++){
				 res[i+j+2]=(res[i+j+2]<1+res[i-j])?res[i+j+2]:1+res[i-j];
			 }
		 }
		 return res[n];
	 }
}
