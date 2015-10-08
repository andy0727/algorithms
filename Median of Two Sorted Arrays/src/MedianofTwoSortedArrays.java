
public class MedianofTwoSortedArrays {
	public int findkth(int A[],int la, int ra, int B[],int lb, int rb,int k){
		if(la>ra) return B[lb+k-1];
		if(lb>rb) return A[la+k-1];
		int mida=(la+ra)/2;
		int midb=(lb+rb)/2;
		if(k>(mida-la)+(midb-lb)+1){
			if(A[mida]>B[midb])
				return findkth(A,la,ra,B,midb+1,rb,k-(midb-lb)-1);
			else
				return findkth(A,mida+1,ra,B,lb,rb,k-(mida-la)-1);
		}
		else{
			if(A[mida]>B[midb])
				return findkth(A,la,mida-1,B,lb,rb,k);
			else
				return findkth(A,la,ra,B,lb,midb-1,k);
		}		
	}
	public double findMedianSortedArrays(int A[], int B[]) {
		double res=0.0;
		int k=(A.length+B.length+1)/2;
		res=findkth(A,0,A.length-1,B,0,B.length-1,k);
		if((A.length+B.length)%2==0){
			res+=findkth(A,0,A.length-1,B,0,B.length-1,k+1);
			res/=2.0;
		}  
		return res;
    }
	public static void main(String s[]){
		MedianofTwoSortedArrays so=new MedianofTwoSortedArrays();
		System.out.println(so.findMedianSortedArrays(new int[]{1,5,7 },new int[]{2,3,6}));
	}
}
