import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner o = new Scanner(System.in);
    int n = o.nextInt();
    o.nextLine();
    String[] arr = o.nextLine().split(" ");
    ArrayList<String> l = new ArrayList<>();
    //For Insertion
        // for(String i:arr){
        //   l.add(i);
        // }
    //For printing
        // System.out.println(l);
    //For iteration
        //Method 1
        // for(int i=0;i<n;i++){
        //     System.out.println("Value at index "+i+" is "+l.get(i));
        // }
        //Method 2
        // int c=0;
        // for(String i:l){
        //     System.out.println("Value at index "+c+" is "+i);
        //     c++;
        // }
    //Insert at index
        // for(String i:arr){
        //     l.add(0,i);
        // }
    //Remove at index
        // l.remove(1);  //1 is the index
    //Remove at value
        // l.remove("1");
    // Check if value is present
        // String val = o.next();
        // if(l.contains(val)){
        //     System.out.println("Found the value");
        // }
        // else{
        //     System.out.println("Value not found");
        // }
    // Sorting ArrayList
        // Collections.sort(l);
        // System.out.print(l);
   
  }
}