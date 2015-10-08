import java.util.concurrent.Callable;
import java.util.Arrays;
import java.lang.Math;
public class SortTest {
	public static boolean equals(int[] a1, int[] a2){
		int i=0, j=0;
		while(i!=a1.length && j!=a2.length){
			if(a1[i++]!=a2[j++])
				return false;
		}
		if(i!=j)
			return false;
		return true;
	}
	
	public static int[] restore(int[]a1){
		a1=new int[]{1,3,6,5,1,2,3,4};
		return a1;
	}
	
	public static void swap(int[]a1, int i, int j){
		int temp = a1[i];
		a1[i]= a1[j];
		a1[j]=temp;
	}
	public static void insertionSort(int[] a1){
		for(int i=1;i<a1.length;i++){	
			for(int j=i; j>0 && a1[j]<a1[j-1];j--)
				swap(a1,j-1,j);	
		}
	}
	public static void selectionSort(int[]a1){
		for(int i=0;i<a1.length;i++){
			int min=i;
			for(int j=i+1;j<a1.length;j++)
				min= a1[min]>a1[j]?j:min;
			swap(a1,i,min);	
		}
	}
	
	public static void bubbleSort(int[] a1){
		boolean swapped = false;
		for(int i=0; i < a1.length; i++){
			swapped = false;
			for(int j=a1.length-1; j>i ;j--){
				if(a1[j]<a1[j-1]){
					swap(a1,j,j-1);
					swapped = true;
				}
			}
			if(!swapped)
				break;
		}
	}
	
	public static void shellSort(int[] a1){
		int sequence =1;
		while(sequence < a1.length)
			sequence=3*sequence+1;
		while(sequence>0){
			sequence/=3;
			//determined gap, now sort partially
			for(int i=0; i<sequence;i++){
				for(int j=i; j<a1.length;j+=sequence)
					for(int k=j; k>sequence && a1[k]<a1[k-sequence];k-=sequence)
						swap(a1,k,k-sequence);
			}
			
		}
	}
	
	public static void mergeSort(int[] a1,int start, int end){
		if(start>=end)
			return;
		int half = (start+end)/2;
		
		mergeSort(a1,start,half);
		mergeSort(a1,half+1,end);
		int[] tmp = Arrays.copyOfRange(a1,start, half+1);
		int i=0, j=half+1,k=start;
		while(i<=half-start && j<=end){
			a1[k++]=tmp[i]>a1[j]?a1[j++]:tmp[i++];
		}
		while(i<=half-start)
			a1[k++]=tmp[i++];
	}
	
	private static void heaptify(int[] a1, int i, int end){
		int lc=2*i+1;
		if(lc>end)
			return;
		int rc=lc+1;
		int mc = (rc>end) ? lc:(a1[lc]>a1[rc])?lc:rc;
		if(a1[i]>=a1[mc])
			return;
		swap(a1,i,mc);
		heaptify(a1,mc,end);
	}
	
	public static void heapSort(int[] a1){
		for(int i=(a1.length-1)/2;i>=0;i--)
			heaptify(a1,i,a1.length-1);
		//System.out.println(Arrays.toString(a1));
		//sort down
		for(int i=0;i<a1.length;i++){
			swap(a1,0,a1.length-1-i);
			heaptify(a1,0,a1.length-2-i);
		}
		
	}
	
	public static void quickSort(int[] a1, int l, int r){
		if(l>=r)
			return;
		int i=l-1, j= r,v=a1[r];
		for(;;){
			while(a1[++i]<v);
			while(a1[--j]>v && j>i);
			if(i>=j)
				break;
			swap(a1,i,j);
		}
		swap(a1,i,r);
		quickSort(a1,l,i-1);
		quickSort(a1,i+1,r);
	}
	
	private static int med5(int[] a1, int l, int r){
		for(int i=l;i<=r;i++){
			int index=i;
			for(int j=i;j<=r;j++)
				index=a1[index]<a1[j]?index:j;
			if(i==(r+l)/2)
				return index;
			swap(a1,index,i);
		}
		return l;
	}
	private static int median(int[] a1, int l, int r){
		int i= (int) Math.ceil((r-l)/5.0);
		for(int j=0;j<i;j++)
		{
			int subleft= l+5*j;
			int subright = (subleft+4>r)?r:subleft+4;
			int index= med5(a1,subleft,subright);
			swap(a1,l+j,index);
		}
		
		return med5(a1,l,l+i-1);
	}
	
	public static void quickSort3(int[] a1, int l, int r){
		if(l>=r)
			return;
		int med= median(a1,l,r);
		swap(a1,med,r);
		
		int i=l-1, j=r, p=l-1,q=r,v=a1[r];
		for(;;){
			while(a1[++i]<v);
			while(a1[--j]>v && j>i);
			if(i>=j) break;
			swap(a1,i,j);
			if(a1[i]==v) swap(a1,++p,i);
			if(a1[j]==v) swap(a1,--q,j);
		}
		swap(a1,i,r);
		j=i-1;
		i++;
		for(int m=l;m<=p;m++,j--) swap(a1,m,j);
		for(int n=r-1;n>=q;n--,i++) swap(a1,n,i);
		quickSort3(a1,l,j);
		quickSort3(a1,i,r);
	}
	
	public static void main(String[] args){
		int[] a1 = {1,3,5,6,1,2,3,4};
		insertionSort(a1);
		System.out.println(Arrays.toString(a1));
		
		a1= restore(a1);
		selectionSort(a1);
		System.out.println(Arrays.toString(a1));
		
		a1= restore(a1);
		bubbleSort(a1);
		System.out.println(Arrays.toString(a1));
		
		a1= restore(a1);
		shellSort(a1);
		System.out.println(Arrays.toString(a1));
		
		a1= restore(a1);
		mergeSort(a1,0,a1.length-1);
		System.out.println(Arrays.toString(a1));
		
		a1= restore(a1);
		heapSort(a1);
		System.out.println(Arrays.toString(a1));
		
		a1= restore(a1);
		quickSort(a1,0,a1.length-1);
		System.out.println(Arrays.toString(a1));
		
		a1= restore(a1);
		quickSort3(a1,0,a1.length-1);
		System.out.println(Arrays.toString(a1));
	}
}
