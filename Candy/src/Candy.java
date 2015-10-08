
public class Candy {
	public int candy(int[] ratings) {
		if(ratings.length<=0)
			return 0;
		int res=1;
		int last=1,i=1;
		while(i<ratings.length){
			if(ratings[i]==ratings[i-1]){
				res+=last;
				i++;
			}
			else if(ratings[i]>ratings[i-1]){
				last++;
				res+=last;
				i++;
			}
			else{
				int j=i;
				while(j<ratings.length&&ratings[j]<ratings[j-1]) j++;
				int len=i-j+1;
				if(last<len)
					res+=(len-last);
				res+=len*(len-1)/2;
				last=1;
				i=j;
			}
		}
		return res;
	}
	public static void main(String s[]){
		Candy so=new Candy();
		System.out.println(so.candy(new int[]{3,2,1}));
	}
}
