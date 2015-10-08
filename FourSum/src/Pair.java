
public class Pair{
	int a, b,ai,bi;
	Pair next;
	Pair tail;
	Pair(int a1,int ai1,int b1,int bi1){a=a1;ai=ai1;b=b1;bi=bi1;next=null;tail=this;}
	@Override
	public String toString(){
		String s= "{ai: "+ai+" bi: "+bi+"}";
		Pair cur=next;
		while(cur!=null){
			s+="->";
			s+="{ai: "+cur.ai+" bi: "+cur.bi+"}";
			cur=cur.next;
		}
		return s;
	}
}
