package lab7;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;

public class Lagrange {
    private static int size;
    private static double[] x , y;
    private static double xToFind;

    public static void main(String[] args) throws IOException {
        initFromFile();

        List<List<Double>> numerators = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            numerators.add(new ArrayList<>());
        }
        List<Double> denominators = new ArrayList<>();

        for (int i = 0; i < size; i++)
        {
            double div = 1;
            List<Double> currentNumerator = numerators.get(i);
            for (int j = 0; j < size; j++)
            {
                if (i == j) continue;
                currentNumerator.add(x[j]);
                div *= x[i]-x[j];
            }
            denominators.add(div);
        }

        System.out.println("Polynomial:");
        for (int i = 0; i < size; i++) {
            System.out.print("\n("+y[i]+")");

            System.out.print("(");
            numerators.get(i)
                    .forEach((xValue) -> {
                        System.out.print("(x - " + xValue + ")");
                    });
            System.out.print(")/");

            System.out.print("(" + denominators.get(i) + ")");

            if (i != size -1) System.out.print(" + ");
        }
        System.out.println();
    }

    private static void initFromFile() throws IOException {
        Scanner scanner = new Scanner(Files.newBufferedReader(Path.of("src/lab7/Lagrange.txt")));
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
}
