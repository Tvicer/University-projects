package lab11;

// 0.531219 - answer

public class Simpson {
    public static void main(String[] args) {
        double x0 = 0.0, xK = 2.0, h1 = 0.5, h2 = 0.25;
        double s1 = countSimpson(x0, xK, h1);
        double s2 = countSimpson(x0, xK, h2);

        System.out.println("Integral = " + s1 + " with step = " + h1);
        System.out.println("Integral = " + s2 + " with step = " + h2);
        System.out.println("Make more accurately:" + makeMoreAccurately(s1, s2, h1, h2, 4));
    }

    private static double countSimpson(double x0, double xK, double h) {
        double x, y0, yK, yUneven = 0, yEven = 0;

        // uneven
        x = x0 + h;
        while (x < xK) {
            yUneven += countF(x);
            x += 2*h;
        }

        // even
        x = x0 + 2*h;
        while (x < xK) {
            yEven += countF(x);
            x += 2*h;
        }

        y0 = countF(x0);
        yK = countF(xK);

        double s1 = (h/3 * ((y0 + yK + 4*yUneven) + 2*yEven));
        return s1;
    }

    private static double countF(double x) {
        return Math.sqrt(x)/(4 + 3*x);
    }

    private static double makeMoreAccurately(double I1, double I2, double h1, double h2, double p) {
        return I1 + (I1 - I2)/(Math.pow(h2/h1, p) - 1);
    }
}
