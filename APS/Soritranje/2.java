import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SortExample {
    
    static void sortArray(int arr[], int size) {   
        int leftIndex = 0;
        int rightIndex = 0;
        boolean sorted = false;
        for (int round = 0; round < (arr.length + 1) / 2; ++round) {
        
            sorted = true;    
            
            for (int i = arr.length - 1; i > leftIndex; --i) {
                if (arr[i] < arr[i - 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i - 1];
                    arr[i - 1] = temp;
                    sorted = false;
                }
            }
            ++leftIndex;
            printArray(arr);
            
            for (int i = rightIndex; i < arr.length - 1; ++i) {
                if (arr[i] > arr[i + 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    sorted = false;
                }
            }
            ++rightIndex;
            printArray(arr);
            
            if (sorted)
                break;
        }
    }
    
    static void printArray(int [] arr) {
        for (int i = 0; i < arr.length; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
    
    public static void main(String[] args) throws IOException {
        int i;
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in)); 
        String input = reader.readLine();
        int size = Integer.parseInt(input);
        
        input = reader.readLine();
        String[] tempArray = input.split(" ");
        int[] arr = new int[size];
        for(i = 0; i < size; i++)
            arr[i] = Integer.parseInt(tempArray[i]);
        
        sortArray(arr, size);
    }
}
