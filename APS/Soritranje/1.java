import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class OddEvenSort {

    static void oddEvenSort(int a[], int n)
    {
        // Vasiot kod tuka
        int counter=0;
        for(int i = 0; i < n; i++){
            if(a[i]%2 != 0){
                counter++;
            }
        }
        int pos=0;
        int pos2=0;
        int [] odd = new int[counter];
        int [] even = new int[n-counter];
            for(int i = 0; i < n; i++) {
                if (a[i] % 2 != 0) {
                    odd[pos] = a[i];
                    pos++;
                }
                else{
                   even[pos2] = a[i];
                   pos2++;
                }
            }
        for(int i = 0; i < n-counter; i++) {
            for(int j = i+1; j < n-counter; j++) {
                if(even[i] < even[j]) {
                    int temp=even[i];
                    even[i]=even[j];
                    even[j]=temp;
                }
            }
        }
        for(int i = 0; i < counter; i++){
            for(int j = i+1; j < counter; j++){
                if(odd[i]>odd[j]){
                    int temp = odd[i];
                    odd[i] = odd[j];
                    odd[j] = temp;
                }
            }
        }
        int counteri=0;
        for(int i = 0; i < counter; i++){
            a[i] = odd[i];
            counteri++;
        }
        for(int i = 0; i < n-counter; i++){
            a[counteri] = even[i];
            counteri++;
        }


    }

    public static void main(String[] args) throws IOException{
        int i;
        BufferedReader stdin = new BufferedReader( new InputStreamReader(System.in));
        String s = stdin.readLine();
        int n = Integer.parseInt(s);

        s = stdin.readLine();
        String [] pom = s.split(" ");
        int [] a = new int[n];
        for(i=0;i<n;i++)
            a[i]=Integer.parseInt(pom[i]);
        oddEvenSort(a,n);
        for(i=0;i<n-1;i++)
            System.out.print(a[i]+" ");
        System.out.print(a[i]);
    }
}
