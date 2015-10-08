import java.util.ArrayList;
import java.util.List;


public class Permutations {
    List<List<Integer> > res;
    void dfs(int[]num, int pos){
        if(pos==num.length-1){
            List<Integer> t = new ArrayList<Integer>();
            for(int i:num)
                t.add(i);
            res.add(t);
            return;
        }
        int tmp;
        for(int i=pos;i<num.length;i++){
        	if(i!=pos && num[pos]==num[i]) continue;
            tmp=num[pos];
            num[pos]=num[i];
            num[i]=tmp;
            dfs(num.clone(),pos+1);
            
        }
    }
    public List<List<Integer>> permute(int[] num) {
        res= new ArrayList<List<Integer>>();
        if(num.length<=0) return res;
        dfs(num,0);
        return res;
    }
    public static void main(String[] args){
    	Permutations so=new Permutations();
    	int [] a={1,2,1,2};
    	List<List<Integer> > res= so.permute(a);
    	for(List l:res)
    		System.out.println(l);
    }
    
}
