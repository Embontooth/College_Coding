import java.util.*;
import java.lang.*;
class main{
    public static void main(String[] args){
        Scanner o = new Scanner(System.in);
        String ch = o.nextLine();
        StringBuilder uniquechar = new StringBuilder();
        for(int i=0;i<ch.length();i++){
            char currentchar = ch.charAt(i);
            if(uniquechar.indexOf(String.valueOf(currentchar))==-1)
            {
                uniquechar.append(currentchar);
            }
        }
        System.out.println(uniquechar.toString());
    }
}