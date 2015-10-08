import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;
import java.util.TreeMap;
import java.util.List;


public class FourSum {
	public static List<List<Integer>> fourSum(int[] num, int target) {
        List<List<Integer> > res= new ArrayList<List<Integer>>();
        if(num.length<4)
            return res;
        Arrays.sort(num);
        TreeMap<Integer,Pair> m=new TreeMap<Integer,Pair>();
        Pair tmp;
        for(int i=0;i<num.length;i++)
        	for(int j=i+1;j<num.length;j++){
                int s=num[i]+num[j];
                if(m.containsKey(s)){
                    tmp = m.get(s);
                    tmp.tail.next=new Pair(num[i],i,num[j],j);
                    tmp.tail=tmp.tail.next;
                }
                else
                    m.put(s,new Pair(num[i],i,num[j],j));
            }
        
        
        //join
        Integer l=m.firstKey(), r=m.lastKey(),s;
        int lpre,rpre;
        while(l!=null && r!=null && l<=r){
            s=l+r;
            if(s<target) l=m.higherKey(l);
            else if (s>target) r=m.lowerKey(r);
            else{
                Pair lp=m.get(l);
                while(lp!=null){
                    Pair rp=m.get(r);
                    rpre=rp.a-1;
                    while(rp!=null){
                        if(lp.bi<rp.ai&&rp.a!=rpre){
                            res.add(Arrays.asList(lp.a,lp.b,rp.a,rp.b));
                        	rpre=rp.a;
                        }	
                        rp=rp.next;
                    }
                    lpre=lp.a;
                    lp=lp.next;
                    while(lp!=null&&lpre==lp.a) lp=lp.next;
                }
                l=m.higherKey(l);
                r=m.lowerKey(r);
            }
        }
        return res;
    }
	
	public static void main(String args[]){
		int[] num = {-3,-2,-1,0,0,1,2,3};
		List<List<Integer> > res= fourSum(num,0);
		for(List<Integer> i: res){
			System.out.print("[");
			for(Integer j: i)
				System.out.print(j+" ");
			System.out.println("]");	
		}
	}
}
