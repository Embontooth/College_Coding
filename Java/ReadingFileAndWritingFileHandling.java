import java.util.*;
import java.io.*;
public class Main{
    public static void main(String[] args) throws IOException{
        Scanner o = new Scanner(System.in);
        String[] ch = o.nextLine().split("");
        char change = o.next().charAt(0);
        File f1 = new File("file1.txt");
        f1.createNewFile();
        BufferedWriter f1writer = new BufferedWriter(new FileWriter(f1));
        for(int i=0;i<ch.length;i++){
            f1writer.write(ch[i]);
        }
        f1writer.close();
        
        File f2 = new File("file2.txt");
        f1.createNewFile();
        BufferedReader f1reader = new BufferedReader(new FileReader(f1));
        BufferedWriter f2writer = new BufferedWriter(new FileWriter(f2));
        
        int character;
        while((character=f1reader.read())!=-1){
            char f = (char)(character);
            if(f=='a'||f=='e'||f=='i'||f=='o'||f=='u'||f=='A'||f=='E'||f=='I'||f=='O'||f=='U'){
                f2writer.write(change);
            }
            else{
                f2writer.write(f);
            }
        }
        f2writer.close();
        f1reader.close();
        
        BufferedReader f2reader = new BufferedReader(new FileReader(f2));
        String line1;
        while((line1=f2reader.readLine())!=null){
            System.out.println(line1);
        }
        f2reader.close();
    }
}