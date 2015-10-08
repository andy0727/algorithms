import java.util.Arrays;
import java.util.HashMap;


public class TwoSum {
	public int[] twoSum(int[] numbers, int target) {
        int[] res=new int[2];
        HashMap<Integer,Integer> map=new  HashMap<Integer,Integer>();
        for(int i=0;i<numbers.length;i++){
        	if(map.containsKey(numbers[i])){
        		res[0]=map.get(numbers[i]);
        		res[1]=i;
        		break;
        	}
        	map.put(target-numbers[i], i);
        }
        return res;
    }
}
