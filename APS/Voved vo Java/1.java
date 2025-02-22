import java.util.Scanner;
//12
//1 9 8 4 0 0 2 7 0 6 0 9
//0 0 0 0 1 9 8 4 2 7 6 9
public class PushZero
{
    static void pushZerosToBeginning(int arr[], int n)
    {
        int cnt = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] != 0) {
                arr[cnt--] = arr[i];
            }
        }
        while (cnt >= 0) {
            arr[cnt--] = 0;
        }
    }

    public static void main (String[] args)
    {
        int arr[];
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        arr= new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = sc.nextInt();
        }
        System.out.println("Transformiranata niza e:");
        for(int i=0;i<n;i++){
            pushZerosToBeginning(arr, n);
            System.out.print(arr[i]+" ");
        }
    }
}
