import java.util.*;

class main
{
	public static void main(String[] args) {
		LinkedList<Integer> l = new LinkedList<>();
		boolean isPrime;
		l.add(2);
		//System.out.println(2);
		for (int i = 3; i < (args.length == 1 ? Integer.parseInt(args[0]) : Integer.MAX_VALUE); i += 2) {
			isPrime = true;
			for (int j : l) {
				if (j * j <= i) {
					if (i % j == 0) {
						isPrime = false;
						break;
					}
				} else {
					break;
				}
			}
			if (isPrime) {
				l.add(i);
				//System.out.println(i);
			}
		}
	}
}
