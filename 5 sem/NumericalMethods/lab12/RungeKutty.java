package lab12;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Scanner;

public class RungeKutty {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(Files.newBufferedReader(Path.of("in.txt")));
        int x0 = scanner.nextInt(), xK = scanner.nextInt();
        double h = scanner.nextDouble();

        double x = x0, y = scanner.nextDouble(), yPrev;
        while (x < xK) {
            yPrev = y;

            double k1 = countF(x, y);
            double k2 = countF(x + h/2, y + h/2 * k1);
            double k3 = countF(x + h/2, y + h/2 * k2);
            double k4 = countF(x + h, y + h * k3);

            x += h;
            y = yPrev + h/6 * (k1 + 2*k2 + 2*k3 + k4);
        }

        System.out.println(y);
    }

    private static double countF(double x, double y) {
        return y / (2 * x);
    }
}
