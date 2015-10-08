class People{
	int weight;
	People(){weight=100;}
}
public class Elevator {
	int[][] floor;
	People[] pp;
	int dir;
	int curfloor;
	public Elevator(int cap,int f){
		floor=new int[2][f];
		pp=new People[cap];
		dir=0;
		curfloor=0;
	}
	public void go(int fl,int dir){
		floor[dir][fl]=1;
	}
	public void move(){
		boolean moved=false;
		while(!moved){
			if(dir==0){
				for(int i=curfloor;i<floor.length;i++)
					if(floor[dir][i]==1){
						curfloor++;
						moved=true;
						break;
					}
			}
			else{
				for(int i=curfloor;i>=0;i--)
					if(floor[dir][i]==1){
						curfloor--;
						break;
					}	
			}
		}
		
		if(floor[dir][curfloor]==1) floor[dir][curfloor]==0;
	}
}
