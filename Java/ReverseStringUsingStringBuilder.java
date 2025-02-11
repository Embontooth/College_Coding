import java.util.*;
import java.lang.StringBuilder;
class main{
    public static void main(String[] args){
        Scanner o = new Scanner(System.in);
        String ch = o.nextLine();
        String[] arr = ch.split(" ");
        for(int i=0;i<arr.length;i++)
        {
            StringBuilder r = new StringBuilder(arr[i]);
            StringBuilder rev = r.reverse();
            System.out.print(rev.toString()+" ");
        }
    }
}