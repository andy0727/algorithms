import java.util.ArrayList;
import java.util.List;


public class TextJustification {
    public List<String> fullJustify(String[] words, int L) {
    	List<String> res=new ArrayList<String>();
    	int n=words.length;
    	if(L<0||n<=0)
    		return res;
    	ArrayList<String> line=new ArrayList<String>();
    	String word;
    	int lc=-1;
    	for(int i=0;i<n;i++){
    		word=words[i];
    		if(lc+1+word.length()<=L){
    			line.add(word);
    			lc+=1+word.length();
    		}
    		else{	
    			int space=(L-lc);
    			
    			String l="";
    			for (int k=0;k<line.size();k++){
    				l+=line.get(k);
    				int each=(line.size()-k-1>0)?(space+line.size()-k-2)/(line.size()-k-1):space;
    				System.out.println(each);
    				for(int j=0;j<=each;j++,l+=" ");
    				space-=each;
    			}
    			if(!l.isEmpty())
    				res.add(l.substring(0,l.length()-1));
    			
    			while(word.length()>L){
    				res.add(word.substring(0,16));
    				word=word.substring(16);
    			}
    			line.clear();
    			line.add(word);
    			lc=word.length();
    		
    		}
    	}
    	
    	
		String l="";
		for (int k=0;k<line.size();k++){
			l+=line.get(k)+" ";
		}
		int space=(L-lc);
		for(int j=0;j<space;j++,l+=" ");
		System.out.println(l.length());
		res.add(l.substring(0,l.length()-1));
        return res;
    }
    
    public static void main(String s[]){
    	TextJustification so=new TextJustification();
    	String [] words={"so","fine","That","all","the","world","will","be","in","love"};
    	System.out.println(so.fullJustify(words, 25));
    }
}
