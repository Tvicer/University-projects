package lab12;

import java.io.IOException;
import java.nio.file.Files;
import java.util.Scanner;
import java.nio.file.Path;

public class Euler {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(Files.newBufferedReader(Path.of("in.txt")));
        int x0 = scanner.nextInt(), xK = scanner.nextInt();
        double h = scanner.nextDouble();

        double x = x0, xPrev, y = scanner.nextDouble(), yPrev;
        while (x < xK) {
            xPrev = x;
            yPrev = y;

            x += h;
            y = yPrev + h*countF(xPrev, yPrev);
        }

        System.out.println(y);
    }

    private static double countF(double x, double y) {
        return y/(2*x);
    }
}
