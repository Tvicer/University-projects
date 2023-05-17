package lab9;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Arrays;
import java.util.Scanner;

public class MyMain {
    private enum Coefficient {
        a(0), b(1), c(2);
        int position;
        Coefficient(int position) {
            this.position = position;
        }
    }

    private static int a, b, N, numberOfX = 3, Ns, Ng;
    private static double[] x, y, h, d, divider, p, q;
    private static double[][] matrix;

    public static void main(String[] args) throws IOException {
        initFromFile();
        countH();
        initMatrix();

        double[] answer = count();

        double m2 = answer[0], m3 = answer[1];

        outResult("Xi-1", "Xi", "Hi", "Mi-1", "Mi", "X", "Yi", "Yi-1");
        int iCur = 2, iPrev = 1;

        outResult(String.valueOf(x[iPrev]), String.valueOf(x[iCur]),
                String.valueOf(h[iCur]),
                String.valueOf(m2), String.valueOf(m3),
                "x", String.valueOf(y[iCur]), String.valueOf(y[iPrev]));

        //System.out.println(countResult(x[iPrev], x[iCur], h[iCur], m2, m3, 2, y[iCur], y[iPrev]));

        System.out.println("\nProof");
        for (int i = 0; i < N; i++) {
            System.out.println("y(" + x[i] + ")  = " + countResult(x[iPrev], x[iCur], h[iCur], m2, m3, x[i], y[iCur], y[iPrev]));
        }
        System.out.println();
        System.out.println();

    }

    private static void initFromFile() throws IOException {
        Scanner scanner = new Scanner(Files.newBufferedReader(Path.of("src/lab9/mainin.txt")));
        Ns = scanner.nextInt();
        Ng = scanner.nextInt();

        a = Ns;
        b = Ns + Ng;
        N = scanner.nextInt();
        N++;

        scanner.close();
    }


    private static void countH() {
        h = new double[N];
        x = new double[N];
        y = new double[N];

        double leftPtr = a, toAdd = (b-leftPtr)/N;
        for (int i = 0; i < N; i++) {
            x[i] = leftPtr;
            y[i] = countFunction(leftPtr);

            leftPtr += toAdd;
            if (i == 0) {
                continue;
            }
            h[i] = x[i] - x[i-1];
        }

        System.out.println("\nTable");
        for (int i = 0; i < N; i++) {
            System.out.println("y(" + x[i] + ")  = " + y[i]);
        }
        System.out.println();
        System.out.println();
    }

    private static double countFunction(double x) {
        return Ng*x + Math.sin(x);
    }

    private static void initMatrix() {
        int matrixRow = 3;
        d = new double[matrixRow];
        matrix = new double[matrixRow][matrixRow];
        Arrays.stream(matrix).forEach((row) -> Arrays.fill(row, 0.0));

        for (int j = 0; j < matrixRow; j++) {
            double first = (j == 0) ? 0 : h[j+1]/6;
            double second = (h[j+1] + h[j+2])/3;
            double third = (j == matrixRow-1) ? 0 : h[j+2]/6;
            double yValue = (y[j+2] - y[j+1])/h[j+2] - (y[j+1]-y[j])/h[j+1];

            matrix[0][j] = first;
            matrix[1][j] = second;
            matrix[2][j] = third;
            d[j] = yValue;
        }
    }

    private static double[] count() {
        divider = new double[numberOfX];

        countP();
        countQ();


        double[] answer = new double[numberOfX];
        for (int i = numberOfX-1; i >= 0; --i) {
            if (i == numberOfX-1) {
                answer[numberOfX-1] = q[numberOfX-1];
                continue;
            }
            answer[i] = p[i]*answer[i+1] + q[i];
        }

//        Arrays.stream(answer).forEach((x) -> System.out.print(x + " "));
//        System.out.println();

        return answer;
    }

    private static void countP() {
        p = new double[numberOfX];
        for (int i = 0; i < numberOfX; ++i) {
            if (i == 0) {
                double c1 = matrix[Coefficient.c.position][0];
                double b1 = matrix[Coefficient.b.position][0];
                divider[0] = b1;
                p[0] = -c1/b1;
                continue;
            }

            double ci = matrix[Coefficient.c.position][i];
            double bi = matrix[Coefficient.b.position][i];
            double ai = matrix[Coefficient.a.position][i];

            divider[i] = bi + ai*p[i-1];
            p[i] = -ci/divider[i];
        }
    }

    private static void countQ() {
        q = new double[numberOfX];
        for (int i = 0; i < numberOfX; ++i) {
            if (i == 0) {
                double d1 = d[0];
                q[0] = d1/divider[i];
                continue;
            }

            double ai = matrix[Coefficient.a.position][i];
            double di = d[i];

            q[i] = (di-ai*q[i-1])/divider[i];
        }
    }

    private static void outResult(String xPrev, String xCurrent, String hCurrent, String mPrev, String mCurrent, String x, String yCur, String yPrev) {
        System.out.printf("S(%s) = %s*((%s - %s)^3)/(6*%s) + %s((%s - %s)^3)/(6*%s) + (%s - %s * (%s^2)/6)*(%s - %s)/%s + (%s - %s * (%s^2)/6)((%s - %s)/%s)",
                x, mCurrent, x, xPrev, hCurrent, mPrev, xCurrent, x, hCurrent, yCur, mCurrent, hCurrent, x, xPrev, hCurrent, yPrev, mPrev, hCurrent, xCurrent, x, hCurrent);
        System.out.println();
    }

    private static double countResult(double xPrev, double xCurrent, double hCurrent, double mPrev, double mCurrent, double x, double yCur, double yPrev) {
        return mCurrent * Math.pow((x - xPrev), 3)/(6*hCurrent)
                + mPrev * (Math.pow((xCurrent - x), 3))/(6*hCurrent)
                + (yCur - mCurrent * Math.pow(hCurrent, 2)/6) * (x - xPrev)/hCurrent
                + (yPrev - mPrev * Math.pow(hCurrent, 2)/6) * (xCurrent - x)/hCurrent;
    }
}
