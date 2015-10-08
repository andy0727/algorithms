import java.util.HashMap;

public class StringSets {
	public static boolean allstringSetsIdentical(String[][] sets)
	{
		//hashmap used to record all unique elements
		HashMap<String,Integer> myhash = new HashMap<String,Integer>();
		int size = sets.length;
		// handle the edge cases
		if(sets.length<=1)
			return true;
		
		//Use the first string set to set up hashmap
		for(int i =0; i<sets[0].length;i++) {
			myhash.put(sets[0][i],new Integer(1));
		}
		
		//used to check whether current set covers 
		//all the elements in map
		int unique_count= myhash.size();
		//use the built hashmap to check the rest sets.
		for(int j=1; j<size;j++)
		{
			int count= 0;
			for(int k=0; k< sets[j].length;k++)
			{	
				Integer val =myhash.get(sets[j][k]);
				//fails if the set contains something not in hashmap
				if(val==null)
					return false;
				//only increment the value when everything is right.
				else if (j == val){
						count+=1;
						myhash.put(sets[j][k],val+1);
				}		
			}
			//fails if current set detects that previous set did not
			//cover all the elements in the hashmap
			if(count!=unique_count)
				return false;
		}
		
		//only true after visiting all the elments in each set.
		return true;
	}
	
	public static void main(String[] args){
		String [][] sets = {{"a","b"},{"a","b","a"},{"a","b"}};
		if(allstringSetsIdentical(sets))
			System.out.println("they are equal");
		else
			System.out.println("they are not equal");
		
	}
}
