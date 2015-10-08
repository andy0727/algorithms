
public class ZigZagConvert {
    public String convert(String s, int nRows) {
        if(nRows==1)
			return s;
		StringBuilder res = new StringBuilder();
		int cur= 1,pos=0,zig;
		while(pos<s.length()){
			res.append(s.charAt(pos));
			pos+=(nRows-1)*2;
		}
		
		++cur;
		while(cur<nRows){
			pos=cur-1;
			zig=2*(nRows-cur);
			while(pos<s.length()){
				res.append(s.charAt(pos));
				pos+=zig;
				zig=zig==2*(cur-1)?2*(nRows-cur):2*(cur-1);
			}
			cur++;
		}
		
		pos=nRows-1;
		while(pos<s.length()){
			res.append(s.charAt(pos));
			pos+=(nRows-1)*2;
		}
		
		return res.toString();
    }
}
