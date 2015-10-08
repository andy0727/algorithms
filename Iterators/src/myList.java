import java.util.Iterator;


public class myList<Type> implements Iterable<Type>{
	Type[] A;
	int currentSize;
	public myList(Type[] A){ 
		this.A = A; 
		currentSize = A.length;
	}
	public Iterator<Type> iterator() {
		Iterator<Type> it = new Iterator<Type>(){
			int cur;
			@Override
			public boolean hasNext() {
				return cur < A.length && A[cur] != null;
			}
			
			@Override
			public Type next() {
				return A[cur++];
			}
			
			@Override
	        public void remove() {
	            throw new UnsupportedOperationException();
	        }
			
		};
		// TODO Auto-generated method stub
		return it;
	}
	
	public static void main(String[] args) {
	    // create an array of type Integer
	    Integer[] numbers = new Integer[]{1, 2, 3, 4, 5};

	    // create your list and hold the values.
	    myList<Integer> stackOverflowList = new myList<Integer>(numbers);

	    // Since our class SOList is an instance of Iterable, then we can use it on a foreach loop
	    for(Integer num : stackOverflowList) {
	        System.out.print(num);
	    }
	}    
}
