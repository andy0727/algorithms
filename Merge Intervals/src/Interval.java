
public class Interval {
	int start, end;
	Interval(){start=end=0;}
	Interval(int s, int e){start=s;end=e;}
	@Override
	public String toString(){
		
		return "["+start+"  "+end+"]";
		
	}
	
}
