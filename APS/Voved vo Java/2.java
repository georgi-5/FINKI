import java.util.Scanner;

public class ReverseWord {

    public static void printReversed(String word) {
        StringBuilder sb = new StringBuilder(word);
        String reversedString=sb.reverse().toString();
        System.out.println(reversedString);
    }

    public static void main(String[] args) {
        int n;
        String word[];
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        word = new String[n];
        for (int i = 0; i < n; i++) {
            word[i] = sc.next();
        }
        for (int i = 0; i < n; i++) {
            printReversed(word[i]);
        }
    }
}
