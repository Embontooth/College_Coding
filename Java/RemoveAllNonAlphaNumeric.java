import java.util.*;
import java.lang.StringBuilder;
class main{
    public static void main(String[] args){
        Scanner o = new Scanner(System.in);
        String ch = o.nextLine();
        ch = ch.replaceAll("[^a-zA-Z0-9]","");
        System.out.println(ch);
    }
}