import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class CombinationSum {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer> > res= new ArrayList<List<Integer>>();
        List<List<Integer> > c= new ArrayList<List<Integer>>();
        List<Integer>  s= new ArrayList<Integer>();
        if(candidates.length<=0) return res;
        List<Integer> tmp;
        int sum;
        for(int i=0;i<candidates.length;i++){
            int cur = candidates[i];
            if(cur<target){
                tmp=new ArrayList<Integer>();
                tmp.add(cur);c.add(tmp);s.add(cur);
            }
            for(int j=0;j<c.size();j++){     
                sum=target-s.get(j);
                if(sum>=cur){
                    ArrayList<Integer> t2=new ArrayList<Integer> (c.get(j));
                    t2.add(cur);
                    if(sum==cur)
                        res.add(t2);
                    else{c.add(t2);s.add(s.get(j)+cur);}
                }
            }
        }
        return res;
    }
    
    List<List<Integer>> res;
    void helper(int[] c, int t, int cur, List<Integer> path){
    	if(t==0) res.add(path);
    	if(t<=0||cur>=c.length) return;
    	List<Integer> path2=new ArrayList<Integer>(path);
    	path2.add(c[cur]);
    	helper(c,t-c[cur],cur,path2);
    	helper(c,t,cur+1,path);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
    	Arrays.sort(candidates);
    	List<Integer> path=new ArrayList<Integer>();
    	res=new ArrayList<List<Integer>>();
    	helper(candidates,target, 0, path);
    	return res;
    }
    public static void main(String s[]){
    	CombinationSum so=new CombinationSum();
    	int [] a={6,9,7,4,5,3,10,12};
    	List<List<Integer>> res =so.combinationSum(a, 21);
    	for(List l:res)
    		System.out.println(l.toString());
    }
}
