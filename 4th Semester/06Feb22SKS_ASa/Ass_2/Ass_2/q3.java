import java.util.Arrays;
import java.util.Scanner;

public class q3 {

	static int count(String text) {
		int count = 0;
		for(char x : text.toCharArray()) {
			if(x == 'a' ) {
				count++;
			}
		}
		return count;
	}

	static int count_and(String text) {
		int count = 0;
		String a[] = text.split(" ");
		for(String x : a) {
			if(x.equals("and")) {
				count++;
			}
		}
		return count;
	}

	static boolean bool_start_the(String text) {
		return text.startsWith("The");
	}

	static String[] printTokens(String text) {
		String[] tokens = new String[100];
		int index  = 0;
		int start = 0;
		for(int i = 0; i < text.length(); i++) {
			if(text.charAt(i) == ' ' || text.charAt(i) == '@' || text.charAt(i) == '.') {
				tokens[index++] = text.substring(start, i);
				start = i+1;
			}
		}
		tokens[index++] = text.substring(start, text.length());
		return tokens;
	}


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter some text : ");
		String text = sc.nextLine();

		System.out.println("Counts of a : "+count(text));
		System.out.println("Counts of and : "+count_and(text));
		System.out.println("Started with THE: "+bool_start_the(text));
		System.out.println("Array of characters : "+Arrays.toString(text.toCharArray()));
		System.out.println("Array of tokens : "+Arrays.toString(printTokens(text)));

		sc.close();

	}

}
