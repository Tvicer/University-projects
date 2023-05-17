package lab8;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static double[] x, y;

    private static double[][] a;
    private static double[] b;
    private static double[] countedXDegrees;

    private static int degreeOfPolynomial, size;
    private static List<Double> savedDiv = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        getFromFile();
        countA(); // matrixCoeff
        countB(); // freeValues

        double[] coefficients = countByGauss(degreeOfPolynomial); // a,b, c ...

        // вывод полинома
        for (int i = 0; i < degreeOfPolynomial; ++i) {
            int degree = degreeOfPolynomial-1-i;
            if (degree != 0) System.out.print(coefficients[i] + "x^" + degree + " + ");
            else System.out.println(coefficients[i]);
        }

        // квадратическая невязка

        // считаю y
        List<Double> yInXPoints = new ArrayList<>();
        Arrays.stream(x).forEach((xValue) -> {
            double value = 0;
            for (int i = 0; i < degreeOfPolynomial; ++i) {
                int degree = degreeOfPolynomial - 1 - i;
                value += coefficients[i] * Math.pow(xValue, degree);
            }
            yInXPoints.add(value);
        });

        // вычитаю
        double discrepancy = 0;
        for (int i = 0; i < size; i++) {
            discrepancy += Math.pow(y[i] - yInXPoints.get(i), 2);
        }
        System.out.println("Quadratic discrepancy:" + discrepancy);
    }

    private static void getFromFile() throws IOException {
        Scanner scanner = new Scanner(Files.newBufferedReader(Path.of("src/lab8/in.txt")));
        size = scanner.nextInt();

        x = new double[size];
        for (int i = 0; i < size; ++i) {
            x[i] = scanner.nextDouble();
        }

        y = new double[size];
        for (int i = 0; i < size; ++i) {
            y[i] = scanner.nextDouble();
        }

        degreeOfPolynomial = scanner.nextInt();
    }

    private static void countA() {
        // считаю степени сразу, тк они повторяются
        countedXDegrees = new double[size];
        for (int i = 0; i < size; ++i) {
            double countedDegree = 0;
            for (int k = 0; k < size; ++k) {
                countedDegree += Math.pow(x[k], i);
            }
            countedXDegrees[i] = countedDegree;
        }

        // заполняю матрицу
        a = new double[degreeOfPolynomial][degreeOfPolynomial];
        for (int i = 0; i < degreeOfPolynomial; ++i)
        {
            int row = degreeOfPolynomial-1-i;
            for (int j = 0; j < degreeOfPolynomial; ++j)
            {
                int column = degreeOfPolynomial-1-j;
                int degreeOfX = i + j ;

                a[row][column] = countedXDegrees[degreeOfX];
            }
        }
    }

    private static void countB() {
        b = new double[degreeOfPolynomial];
        for (int i = 0; i < degreeOfPolynomial; ++i) {
            double countedFreeValue = 0;
            for (int k = 0; k < size; ++k) {
                countedFreeValue += y[k] * Math.pow(x[k], i);
            }
            b[degreeOfPolynomial-1-i]  = countedFreeValue;
        }
    }

    private static double[] countByGauss(int n) {
        double[][] matrix = new double[n][n+1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = a[i][j];
            }
            matrix[i][n] = b[i];
        }

        makeStepMatrix(matrix);
        return theReverseOfTheGaussMethod(matrix);
    }

    private static void makeStepMatrix(double[][] matrix) {
        int height = matrix.length, width = height+1;
        for (int j = 0; j < width-1; ++j) {
            int iUpperIndex = j;
            for (int i = iUpperIndex + 1; i < height; ++i) {
                double upperElement = matrix[iUpperIndex][j];
                double currentElement = matrix[i][j];
                savedDiv.add(upperElement);
                double toMulti = currentElement/upperElement;

                for (int k = j; k < width; ++k) {
                    matrix[i][k] -= matrix[iUpperIndex][k]*toMulti;
                }
            }
        }
    }

    private static double[] theReverseOfTheGaussMethod(double[][] matrix) {
        int height = matrix.length, width = height+1;
        double[] answer = new double[height];

        for (int i = height-1; i >= 0; --i) {
            double rightPart = matrix[i][width-1];
            for (int j = width-2; j > i; j--) {
                rightPart -= matrix[i][j] * answer[j];
            }

            // i == j
            double coefficientBeforeVariable = matrix[i][i];
            answer[i] = rightPart/coefficientBeforeVariable;
        }
        return answer;
    }
}
