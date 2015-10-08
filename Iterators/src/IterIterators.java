import java.util.Iterator;


public class IterIterators<T> implements Iterator<T>{
	Iterator<T>[] it;
	int cur;
	
	public IterIterators(Iterator<T>[] it){
		this.it = it;
	}
	
	@Override
	public boolean hasNext() {
		if (cur< it.length && it[cur].hasNext()) 
			return true;
		
		while(cur< it.length && !it[cur].hasNext()){
			cur++;
		}
		return cur != it.length;
	}

	@Override
	public T next() {
		return it[cur].next();
	}
	
	public static void main(String args[]){
		Iterator<Integer> [] nums = new Iterator [4];
		// create an array of type Integer
		nums[3] = new myList<Integer>( new Integer[]{}).iterator();
	    nums[0] = new myList<Integer>( new Integer[]{1, 2, 3, 4, 5}).iterator();
	    nums[1] = new myList<Integer>( new Integer[]{}).iterator();
	    nums[2] = new myList<Integer>( new Integer[]{6, 7, 8, 9, 10}).iterator();
	    
	    // create your list and hold the values.
	    IterIterators<Integer> its = new IterIterators<Integer>(nums);

	    // Since our class SOList is an instance of Iterable, then we can use it on a foreach loop
	    while(its.hasNext()) {
	        System.out.print(its.next());
	    }
	}
}
