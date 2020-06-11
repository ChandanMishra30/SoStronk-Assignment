import java.util.*;

class TeamMatch{
	public static void quality(int n,List<String>li,List<Integer>arr,String str, double avg,List<String>fi,List<Double>avgs,int i,int j,int k) {
		if(j==n) {
			return; 
		}
		else if(k==n/2){
			fi.add(str);
			avgs.add(avg/k);

			return;
		}
		else{
	        quality(n,li,arr,str+","+li.get(j),avg+arr.get(j),fi,avgs,i,j+1,k+1) ;
			quality(n,li,arr,str,avg,fi,avgs,i,j+1,k);
        }	
    }
    
//Main 
    public static void main(String args[]){
        System.out.println("\n\t\t**************Program For Team Match: *************\n\n\n");
        System.out.println("Enter No. of player in a team: ");
        Scanner sc= new Scanner(System.in);
        int n= sc.nextInt();
        n=2*n;
        if(n%2!=0) {
    	System.out.println("-1");
    	return;
        }
        n=n+1;
        List<String> li =new ArrayList<String>();
        List<String> fi =new ArrayList<String>();
        List<Integer> arr =new ArrayList<>();
        List<Double> avgs =new ArrayList<Double>();

        //User Input of name and Score

        System.out.println("Enter Name And Score of Each Player: \n");
        for(int i=0;i<n-1;i++) {
        	String b=sc.next();
        	li.add(b);
        	int r=sc.nextInt();
        	arr.add(r);	
        }

        
        li.add("Shed");
        arr.add(23);
        System.out.println("\n");
        for(int i=0;i<n;i++) {
        String str=li.get(i);
        double avg= (arr.get(i));	
        int j=i+1;
         int k=1;
        quality(n,li,arr,str,avg,fi,avgs,i,j,k);
        }
        String li2[]=new String [fi.size()/2];
        double arr2[]=new double [fi.size()/2];
        int p=0,o=fi.size()-1,ca=0;
        while(p<o) {
        	arr2[ca]=Math.abs(avgs.get(p)-avgs.get(o));
        	li2[ca]=fi.get(p)+" ("+ avgs.get(p)+") "+" vs "+fi.get(o)+" ("+avgs.get(o)+")";
        	p++;
        	o--;
        	ca++;
        }
        double temp;
        String temp1;
        for(int i=0;i<arr2.length;i++) {
        	for(int j=i;j>0;j--) {
        		if(arr2[j]<=arr2[j-1]) {
        			temp=arr2[j];
        			arr2[j]=arr2[j-1];
        			arr2[j-1]=temp;
        			
        			temp1=li2[j];
        			li2[j]=li2[j-1];
        			li2[j-1]=temp1;
        		}
        		
        	}
        }
        for(int i=0;i<=li2.length-1;i++) {
        	System.out.println(li2[i]);
        }
    
        
    }
}
