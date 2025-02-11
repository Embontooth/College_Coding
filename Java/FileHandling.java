import java.util.*;
import java.io.*;
public class Main{
    public static void main(String[] args) throws IOException{
        Scanner o = new Scanner(System.in);
        int n = o.nextInt();
        int[] arr = new int [n];
        for(int i=0;i<n;i++){
            arr[i] = o.nextInt();
        }
        File f = new File("student.txt");
        f.createNewFile();
        BufferedWriter writer = new BufferedWriter(new FileWriter(f));
        for(int i:arr){
            writer.write(i+" ");
        }
        writer.close();
        int totalscore=0;
        for(int i:arr){
            totalscore+=i;
        }
        double avg = (double)totalscore/n;
        File f2 = new File("performance.txt");
        f2.createNewFile();
        writer = new BufferedWriter(new FileWriter(f2));
        writer.write("Total Score: "+totalscore+"\n");
        writer.write(String.format("Average: %.1f",avg));
        writer.close();
        BufferedReader reader = new BufferedReader(new FileReader(f2));
        String line;
        while((line=reader.readLine())!=null){
            System.out.println(line);
        }
    }
}