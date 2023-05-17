package lab12;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(Files.newBufferedReader(Path.of("src/lab12/in.txt")));
        int x0 = scanner.nextInt(), xK = scanner.nextInt();
        double h = scanner.nextDouble(), y0 = scanner.nextDouble();
        List<Double> toFindNorms = new ArrayList<>();

        System.out.println("Euler");
        double x = x0, y = y0, xPrev, yPrev;
        toFindNorms.add(Math.abs(y - countExactly(x)));
        System.out.println("(" + x +  ", " + y + ")");
        while (x <= xK) {
            xPrev = x;
            yPrev = y;

            x += h;
            y = yPrev + h*countF(xPrev, yPrev);
            toFindNorms.add(Math.abs(y - countExactly(x)));
            System.out.println("(" + x +  ", " + y + ")");
        }
        System.out.println("Norm:" + countNorm(toFindNorms));
        System.out.println();

        toFindNorms.clear();

        System.out.println("Euler-Cauchy");
        x = x0; y = y0;
        toFindNorms.add(Math.abs(y - countExactly(x)));
        System.out.println("(" + x +  ", " + y + ")");
        while (x <= xK) {
            xPrev = x;
            yPrev = y;

            double yStreak = yPrev + h * countF(xPrev, yPrev);

            x += h;
            y = yPrev + h/2 * (countF(xPrev, yPrev) + countF(x, yStreak));
            toFindNorms.add(Math.abs(y - countExactly(x)));
            System.out.println("(" + x +  ", " + y + ")");
        }
        System.out.println("Norm:" + countNorm(toFindNorms));
        System.out.println();

        toFindNorms.clear();

        System.out.println("Runge-Kutty");
        x = x0;
        y = y0;
        toFindNorms.add(Math.abs(y - countExactly(x)));
        System.out.println("(" + x +  ", " + y + ")");
        while (x <= xK) {
            yPrev = y;

            double k1 = countF(x, y);
            double k2 = countF(x + h/2, y + h/2 * k1);
            double k3 = countF(x + h/2, y + h/2 * k2);
            double k4 = countF(x + h, y + h * k3);

            x += h;
            y = yPrev + h/6 * (k1 + 2*k2 + 2*k3 + k4);
            toFindNorms.add(Math.abs(y - countExactly(x)));
            System.out.println("(" + x +  ", " + y + ")");
        }
        System.out.println("Norm:" + countNorm(toFindNorms));
        System.out.println();

    }

    private static double countF(double x, double y) {
        //return (-y*x + x*(Math.pow(x, 2) +1 ))/(Math.pow(x, 2) + 1);
        return (Math.pow(Math.E, x - y) + Math.pow(Math.E, x));
    }

    private static double countExactly(double x) {
        return Math.log(-1 + Math.pow(Math.E, Math.pow(Math.E, x)));
    }

    private static double countNorm(List<Double> list) {
        return list.stream().max(Comparator.naturalOrder()).get();
    }
}
