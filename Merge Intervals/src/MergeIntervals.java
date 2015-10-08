import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;


public class MergeIntervals {

	public static List<Interval> merge(List<Interval> intervals) {
		 Collections.sort(intervals, new Comparator<Interval>() {
				public int compare(Interval l, Interval r) {
					return (l.start- r.start);
				}
			});
			List<Interval> res= new ArrayList<Interval>();
			Interval last=null;
			for(Interval i:intervals){
				if(last==null)
					last=i;
				else if (last.end>=i.start)
					last.end = (last.end>i.end)?last.end:i.end;

				if(i.start>last.end){
					res.add(last);
					last=i;
				}
			}
			if(last!=null)
			    res.add(last);
			return res;
    }
	public static void main(String args[]){
		List<Interval> res= new ArrayList<Interval>();
		res.add(new Interval(1,4));
		res.add(new Interval(1,6));
		res.add(new Interval(0,5));
		List<Interval> res2= merge(res);
		for(Interval i:res2)
			System.out.println(i);
		
	}
}
