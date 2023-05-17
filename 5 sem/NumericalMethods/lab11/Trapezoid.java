package lab11;

// 0.531219 - answer

public class Trapezoid {
    public static void main(String[] args) {
        double x0 = 0.0, xK = 2.0, h1 = 0.5, h2 = 0.25;

        double s1 = countTrapezoid(x0, xK, h1);
        double s2 = countTrapezoid(x0, xK, h2);

        System.out.println("Integral = " + s1 + " with step = " + h1);
        System.out.println("Integral = " + s2 + " with step = " + h2);
        System.out.println("Make more accurately:" + makeMoreAccurately(s1, s2, h1, h2, 2));
    }

    private static double countTrapezoid(double x0, double xK, double h) {
        double s = 0.0, xCurr = x0, yLeft, yRight;
        while (xCurr < xK) {
            //System.out.println("x :" + xCurr);

            yLeft = countF(xCurr);
            yRight = countF(xCurr + h);
            s += h * (yLeft+yRight)/2;

            xCurr += h;
        }
        return s;
    }

    private static double countF(double x) {
        return Math.sqrt(x)/(4 + 3*x);
    }

    private static double makeMoreAccurately(double I1, double I2, double h1, double h2, double p) {
        return I1 + (I1 - I2)/(Math.pow(h2/h1, p) - 1);
    }
}
