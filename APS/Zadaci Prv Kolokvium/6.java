import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;


public class card_trick {
	public static int count(int N){
		Queue<Integer> dek = new LinkedList<Integer>();
		Stack<Integer> meshanje = new Stack<>();

		for (int i = 1; i <= 51; i++) {
			dek.add(i);
		}

		int baram = N;
		int meshanja = 0;

		do{
			for (int i = 7; i >= 1; i--) {
				meshanje.add(dek.poll());
			}
			while (!meshanje.isEmpty()){
				dek.add(meshanje.pop());
				dek.add(dek.poll());
			}
			meshanja++;
		}while(dek.peek() != baram);
		return meshanja;

	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in) );
		System.out.println(count(Integer.parseInt(br.readLine())));
	}

}