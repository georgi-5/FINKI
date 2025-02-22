import java.util.Scanner;
import java.util.Arrays;

class QuarterlySales {

    private int numOfSales;
    private int[] revenues;
    private int quarterNo;

    public QuarterlySales(int numOfSales, int[] revenues, int quarterNo) {
        this.numOfSales = numOfSales;
        this.revenues = revenues;
        this.quarterNo = quarterNo;
    }

    public int totalRevenue() {
        return Arrays.stream(revenues).sum();
    }

    @Override
    public String toString() {
        return String.valueOf(totalRevenue());
    }
}

class SalesPerson {

    private String name;
    private QuarterlySales[] quarters;

    public SalesPerson(String name, QuarterlySales[] quarters) {
        this.name = name;
        this.quarters = quarters;
    }

    public int totalRevenue() {
        return Arrays.stream(quarters).mapToInt(QuarterlySales::totalRevenue).sum();
    }

    public String getName() {
        return name;
    }

    public QuarterlySales[] getQuarters() {
        return quarters;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(name);
        for (QuarterlySales q : quarters) {
            sb.append("   ").append(q);
        }
        sb.append("   ").append(totalRevenue());
        return sb.toString();
    }
}

public class Main {

    public static int sumSales(SalesPerson sp) {
        return sp.totalRevenue();
    }

    public static SalesPerson salesChampion(SalesPerson[] arr) {
        return Arrays.stream(arr).max((sp1, sp2) -> sp1.totalRevenue() - sp2.totalRevenue()).orElse(null);
    }

    public static void table(SalesPerson[] arr) {
        System.out.println("SP   1   2   3   4   Total");
        for (SalesPerson sp : arr) {
            System.out.println(sp);
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        SalesPerson[] arr = new SalesPerson[n];

        for (int i = 0; i < n; i++) {
            String name = input.next();
            QuarterlySales[] quarters = new QuarterlySales[4];

            for (int j = 0; j < 4; j++) {
                int numOfSales = input.nextInt();
                int[] revenues = new int[numOfSales];
                for (int k = 0; k < numOfSales; k++) {
                    revenues[k] = input.nextInt();
                }
                quarters[j] = new QuarterlySales(numOfSales, revenues, j + 1);
            }

            arr[i] = new SalesPerson(name, quarters);
        }
        table(arr);
        System.out.println();
        System.out.println("SALES CHAMPION: " + salesChampion(arr).getName());
    }
}
