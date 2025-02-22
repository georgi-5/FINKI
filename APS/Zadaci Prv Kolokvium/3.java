import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Bus {

    public static void main(String[] args) throws Exception {
        int i,j,k;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        br.close();

        // Vasiot kod tuka
        int deca=0;
        if(M>N){
            deca=(M-N)*100;
        }
        else if(M==1 || M==0){
            deca=0;
        }
        else{
            deca=(N-M)*100;
        }
        
        int min=N*100+deca;
        if(N>M){min=N*100;}
        int max=N*100+((M-1)*100);
        if(deca==0){max=N*100;}

        System.out.println(min);
        System.out.println(max);

    }

}
