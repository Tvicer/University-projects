package lab11;



public class Main {
    public static void main(String[] args) {
        double x0 = 0.0, xK = 2.0, h1 = 0.5, h2 = 0.25;
//        double x0 = 0, xK = Math.PI/2, h1 = Math.PI/8, h2 = Math.PI/16;

        double s1 = countRect(x0, xK, h1);
        double s2 = countRect(x0, xK, h2);
        System.out.println("Rectangle");
        System.out.println("h = " + h1 + ", rectangle square:" + s1);
        System.out.println("h = " + h2 + ", rectangle square:" + s2);
        System.out.println("Make more accurately:" + makeMoreAccurately(s1, s2, h1, h2, 1));

        System.out.println();

        s1 = countTrapezoid(x0, xK, h1);
        s2 = countTrapezoid(x0, xK, h2);
        System.out.println("Trapezoid");
        System.out.println("h = " + h1 + ", rectangle square:" + s1);
        System.out.println("h = " + h2 + ", rectangle square:" + s2);
        System.out.println("Make more accurately:" + makeMoreAccurately(s1, s2, h1, h2, 2));

        System.out.println();

        s1 = countSimpson(x0, xK, h1);
        s2 = countSimpson(x0, xK, h2);
        System.out.println("Simpson");
        System.out.println("h = " + h1 + ", rectangle square:" + s1);
        System.out.println("h = " + h2 + ", rectangle square:" + s2);
        System.out.println("Make more accurately:" + makeMoreAccurately(s1, s2, h1, h2, 4)); // до пятого
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

    private static double countRect(double x0, double xK, double h) {
        double xCurr = x0, s = 0;
        while (xCurr < xK) {
            //System.out.println("x :" + xCurr);
            s += h * countF(xCurr);
            xCurr += h;
        }
        return s;
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

    private static double makeMoreAccurately(double I1, double I2, double h1, double h2, double p) {
        return I1 + (I1 - I2)/(Math.pow(h2/h1, p) - 1);
    }

    private static double countF(double x) {
        return Math.sqrt(x)/(4 + 3*x);
//        return Math.sin(x);
    }
}
