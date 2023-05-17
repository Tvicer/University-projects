package lab7;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Map;

public class Newton {
    private static int size;
    private static double[] x , y;
    private static Map<Integer, Double> indexSumAndItsValue = new HashMap<>();

    public static void main(String[] args) throws IOException {
        initXAndY();

        LinkedList<Integer> indexes = new LinkedList<>();
        int indexSum = 0;
        for (int i = 0; i < size; i++) {
            indexes.add(i);
            indexSum += i;

            if (indexes.size() == 1) {
                System.out.print((y[i]));
                continue;
            }

            System.out.print(" + ");

            double fValue = countFValue(indexSum, indexes);
            indexSumAndItsValue.put(indexSum, fValue);

            System.out.print("(" + fValue + ")");

            for (int j = 0; j < i; j++) {
                System.out.print("(x - " + x[j] + ")");
            }
        }
        System.out.println();
    }

    private static void initXAndY() throws IOException {
        Scanner scanner = new Scanner(Files.newBufferedReader(Path.of("src/lab7/Newton.txt")));
        size = scanner.nextInt();

        x = new double[size];
        for (int i = 0; i < size; ++i) {
            x[i] = scanner.nextDouble();
        }

        y = new double[size];
        for (int i = 0; i < size; ++i) {
            y[i] = scanner.nextDouble();
        }
    }

    private static double f(int indexSum, LinkedList<Integer> indexes) {
        if (indexes.size() == 1) {
            return y[indexSum];
        }

        if (!indexes.contains(indexSum)) {
            indexSumAndItsValue.put(indexSum, countFValue(indexSum, indexes));
        }
        return indexSumAndItsValue.get(indexSum);
    }

    private static double countFValue(int indexSum, LinkedList<Integer> indexes) {
        int firstIndex = indexes.removeFirst();
        double fLeft = f(indexSum-firstIndex, indexes);
        indexes.addFirst(firstIndex);

        int lastIndex = indexes.removeLast();
        double fRight = f(indexSum-lastIndex, indexes);
        indexes.addLast(lastIndex);

        return (fLeft-fRight)/(x[lastIndex] - x[firstIndex]);
    }
}
