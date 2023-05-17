import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

public class Main {
    public static void startExchange(Integer[] arr, int num) {
        Integer[] amount = new Integer[arr.length];
        Arrays.fill(amount, 0);

        Arrays.sort(arr, Collections.reverseOrder());

        if (!exchange(arr, num, num, amount))
            System.out.println("Размен невозможен!");
    }

    public static boolean exchange(Integer[] arr, int num, int source, Integer[] amount) {
        if (num == 0) {
            System.out.println("Размен:");
            StringBuilder answer = new StringBuilder();
            answer.append(String.valueOf(source) + " -> ");
            for (int i = 0; i < amount.length; i++) {
                answer.append(String.valueOf(arr[i]) + '[' + String.valueOf(amount[i]) + "] ");
            }
            System.out.println(answer);
            return true;
        } else {
            for (int i = 0; i < arr.length; i++) {
                if (num - arr[i] >= 0) {
                    amount[i]++;
                    if (exchange(arr, num - arr[i], source, amount))
                        return true;
                    amount[i]--;
                }

            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.println("Введите сумму для размена:");
        int num = in.nextInt();

        System.out.println("Количество номиналов монет для размена:");
        int arr_size = in.nextInt();
        Integer[] arr = new Integer[arr_size];

        System.out.println("Количество номиналы монет для размена:");

        for (int i = 0; i < arr_size; i++) {
            arr[i] = in.nextInt();
        }

        startExchange(arr, num);

    }
}