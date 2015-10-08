import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class CombinationSum2 {
    List<List<Integer>> res;
    void helper(int[] num, int t, int cur, List<Integer> path){
    	System.out.println(path);
        if(t==0) res.add(path);
        if(t<=0|| cur>=num.length) return;
        int i=cur;
        while(i<num.length&&t>=num[i]){
        	if(i==cur||num[i]!=num[i-1]){
        		path.add(num[i]);
        		helper(num,t-num[i],i+1,new ArrayList<Integer>(path));
        		path.remove(path.size()-1);
        	}
        	i++;
        }
    }
    public List<List<Integer>> combinationSum2(int[] num, int target) {
        res=new ArrayList<List<Integer>>();
        if(num.length<=0) return res;
        Arrays.sort(num);
        List<Integer> path=new ArrayList<Integer>();
        helper(num,target,0,path);
        return res;
    }
    public static void main(String s[]){
    	CombinationSum2 so=new CombinationSum2();
    	int [] a={10,1,2,7,6,1,5};
    	List<List<Integer>> res =so.combinationSum2(a, 7);
    	for(List l:res)
    		System.out.println(l.toString());
    }
}
