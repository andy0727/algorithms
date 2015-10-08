
public class StockIII {
    public int maxProfit(int[] prices) {
    	int release1=0, release2=0;
    	int hold1=Integer.MIN_VALUE, hold2=hold1;
    	for(int i=0;i<prices.length;i++){
    		release2 = Math.max(release2, hold2+prices[i]);
    		hold2= Math.max(hold2,release1-prices[i]);
    		release1= Math.max(release1, hold1+prices[i]);
    		hold1=Math.max(hold1,-prices[i]);
    	}
    	return release2;
    }
}
