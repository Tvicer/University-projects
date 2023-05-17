package lab11;

// 0.531219 - answer

public class Rectangle {
    public static void main(String[] args) {
        double x0 = 0.0, xK = 2.0, h1 = 0.5, h2 = 0.25;

        double s1 = countRect(x0, xK, h1);
        double s2 = countRect(x0, xK, h2);
        System.out.println("h = " + h1 + ", rectangle square:" + s1);
        System.out.println("h = " + h2 + ", rectangle square:" + s2);

        System.out.println("Make more accurately:" + makeMoreAccurately(s1, s2, h1, h2, 1));
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

    private static double countF(double x) {
        return Math.sqrt(x)/(4 + 3*x);
    }

    private static double makeMoreAccurately(double I1, double I2, double h1, double h2, double p) {
        return I1 + (I1 - I2)/(Math.pow(h2/h1, p) - 1);
    }
}
