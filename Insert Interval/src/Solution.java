import java.util.ArrayList;
import java.util.List;


public class Solution {
public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
		int n=intervals.size();
        int s = newInterval.start;
        int e = newInterval.end;
        int sind=-1, eind=-1,cur=0;
        for(Interval i:intervals){
        	if(i.start<=s)
        		sind++;
        	if(i.start<=e)
        		eind++;
        	cur++;
        }
        
        if(intervals.get(n-1).end<s)
        	sind++;
        
        List<Interval> res=new ArrayList<Interval>();
        for(int i=0;i<sind;i++)
        	res.add(intervals.get(i));
        
        int news,newr;
        if(sind==-1||sind>=n)
        	news=s;
        else
        	news=intervals.get(sind).start;
        
        if(e==-1)
        	newr=e;
        else
        	newr=(intervals.get(n-1).end>e)? intervals.get(n-1).end:e;
        res.add(new Interval(news,newr));
        for(int i=eind+1;i<intervals.size();i++)
        	res.add(intervals.get(i));
     
        return res;
    }
}
