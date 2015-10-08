
public class ExcelSheetColumnTitle {
	public String convertToTitle(int n) {
		String res="";
		int div=26;
		while(n>0){
			int t=(n-1)%div;
			res=(char)(t+'A')+res;
			n=(n-1)/div;
		}
		return res;
    }
	public static void main(String s[]){
		ExcelSheetColumnTitle so=new ExcelSheetColumnTitle();
		System.out.println(so.convertToTitle(26));
	}
}
