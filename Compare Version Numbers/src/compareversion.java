import java.util.Arrays;


public class compareversion {
	 public int compareVersion(String version1, String version2) {
		 String[]v1=version1.split("\\.");
		 String[]v2=version2.split("\\.");
		 System.out.println(Arrays.toString(v1));
		 int i=0,d1=0,d2=0;
		 while(i<v1.length&&i<v2.length){
			 d1+=Integer.parseInt(v1[i]);
			 d2+=Integer.parseInt(v2[i]);
			 if (d1!=d2)
				 return d1>d2?1:-1;
			 i++;
		 }
		 for(int j=i;j<v1.length;j++) d1+=Integer.parseInt(v1[j]);
		 for(int j=i;j<v2.length;j++) d2+=Integer.parseInt(v2[j]);
		 if(d1==d2) return 0;
		 return d1>d2?1:-1;
		 
	 }
	 public static void main(String s[]){
		 compareversion so=new compareversion();
		 System.out.println(so.compareVersion("1.0.0", "1"));
	 }
}
