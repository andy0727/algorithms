import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;


public class MPOL {

	public int maxPoints(Point[] points) {
		int res=0;
		double k=0;
		for(int i=0;i<points.length;i++){
			HashMap<Double,Integer> m=new HashMap<Double,Integer>();
			int count=1;
			for(int j=i+1;j<points.length;j++){
				if(points[i].x==points[j].x &&points[i].y==points[j].y)
					count++;
				
				else if(points[i].x==points[j].x)
					m.put((double) Integer.MIN_VALUE,
							m.containsKey((double)Integer.MIN_VALUE)?m.get((double)Integer.MIN_VALUE)+1:1);
				
				else{
					k=((double)(points[i].y-points[j].y))/((double)(points[i].x-points[j].x));
					if(k==-0.0) k=0;
					m.put(k, m.containsKey(k)?m.get(k)+1:1);
				}
			}	
			for(Map.Entry<Double, Integer> e:m.entrySet()){
				System.out.println(e.getKey()+"   "+e.getValue());
			}
			int max=0;
			for(Map.Entry<Double, Integer> e:m.entrySet())
				max=e.getValue()>max?e.getValue():max;
			max+=count;
			res=res>max?res:max;
		}	
		return res;
    }
	public static void main(String args[]){
		MPOL so=new MPOL();
		Point p1=new Point(4,0);
		Point p2=new Point(4,-1);
		Point p3=new Point(4,5);
		Point p4=new Point(3,10);
		Point[] p={p1,p2,p3};
		System.out.println(so.maxPoints(p));
	}
}
