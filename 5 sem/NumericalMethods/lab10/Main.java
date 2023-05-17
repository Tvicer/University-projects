package lab10;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Scanner;

public class Main {
    private static int size;
    private static double[] x, y;

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(Files.newBufferedReader(Path.of("src/lab10/in.txt")));
        size = scanner.nextInt();

        x = new double[size];
        for (int i = 0; i < size; i++) {
            x[i] = scanner.nextDouble();
        }

        y = new double[size];
        for (int i = 0; i < size; i++) {
            y[i] = scanner.nextDouble();
        }

        int xIndex = scanner.nextInt();
        double h = x[xIndex]-x[xIndex-1];
        System.out.println("first left:" + (y[xIndex] - y[xIndex-1])/h);
        System.out.println("first right:" + (y[xIndex+1] - y[xIndex])/h);
        System.out.println("first center:" + (y[xIndex+1] - y[xIndex-1])/(2*h));
        System.out.println("second center:" + (y[xIndex+1] - 2*y[xIndex] + y[xIndex-1])/(h*h));
    }
}
