import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;

/**
 * Facilitates dispensing stamps for a postage stamp machine.
 */
public class StampDispenser
{
	
	// properties
	private Integer[] denominations;
	
	//used in sorting in descending order
	private class DescendingComparator implements Comparator<Integer>{
		@Override
		public int compare(Integer o1, Integer o2){ return o2 - o1;}
	}
	

    /**
     * Constructs a new StampDispenser that will be able to dispense the given 
     * types of stamps.
     *
     * @param stampDenominations The values of the types of stamps that the 
     *     machine should have.  Should be sorted in descending order and 
     *     contain at least a 1.
     */
    public StampDispenser(int[] stampDenominations)
    {
    	int n = stampDenominations.length;
    	
    	//allocate, initializes properties and check for input
    	denominations = new Integer[n];
    	for(int i= 0; i< n; i++){
    		assert stampDenominations[i] >= 1: "para stampDenominations less than 1";
    		denominations[i] = stampDenominations[i];
    	}
    	
    	//make sure the properties obey the rules 
    	Arrays.sort(denominations, new DescendingComparator());
    }
 
    
    /**
     * A recursive function to help calcMinNumStampsToFillRequest(int request)
     * 
     * @param request (recursive) The total value of the stamps to be dispensed
     * @param dp (recursive) remember the result to save repeated work
     * @return min the minimum number of stamps to satisfy request
     */
    private int calcMinNumStampsToFillRequest(int request, HashMap<Integer, Integer> dp){
    	int min =request;
    	if(dp.containsKey(request)) return dp.get(request);
    	
    	for(int i = 0 ; i < denominations.length; i++){
    		if (request >= denominations[i]){
    			min = Math.min(min, 1 + calcMinNumStampsToFillRequest(request - denominations[i], dp));
    		}
    	}
    	dp.put(request, min);
    	return min;
    }
    
    
    /**
     * Returns the minimum number of stamps that the machine can dispense to
     * fill the given request.
     *
     * @param request The total value of the stamps to be dispensed.
     */
    public int calcMinNumStampsToFillRequest(int request)
    {  
    	//initialize the dp used in helper
    	HashMap<Integer, Integer> dp = new HashMap<Integer,Integer>();
    	int val = calcMinNumStampsToFillRequest(request, dp);
    	System.out.println(dp);
    	return val;
    }
    
    
    public static void main(String[] args)
    {
        int[] denominations = { 90, 30, 24, 10, 7, 6, 3};
        StampDispenser stampDispenser = new StampDispenser(denominations);
        assert stampDispenser.calcMinNumStampsToFillRequest(19) == 3;
    }
}
