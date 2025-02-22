import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;


public class ExpressionEvaluator {

	public static int evaluateExpression(String expression){
		//Dodadete go vasiot kod tuka
		String number="";
		Stack<Integer> stack=new Stack<Integer>();
		int isMultiplication=0;
		for (int i=0;i<expression.length();i++){
			if (expression.charAt(i)=='+'||expression.charAt(i)=='*'){
				stack.push(Integer.parseInt(number));
				if (isMultiplication!=0)
					stack.push(stack.pop()*stack.pop());
				number="";
				if (expression.charAt(i)=='+')
					isMultiplication=0;
				else
					isMultiplication=1;
			}
			else {
				number+=expression.charAt(i);
				if (i==expression.length()-1){
					stack.push(Integer.parseInt(number));
					if (isMultiplication!=0)
						stack.push(stack.pop()*stack.pop());
				}
			}
		}
		int sum=0;
		while(!stack.isEmpty())
			sum+=stack.pop();
		return sum;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader input=new BufferedReader(new InputStreamReader(System.in));
		System.out.println(evaluateExpression(input.readLine()));
	}

}
