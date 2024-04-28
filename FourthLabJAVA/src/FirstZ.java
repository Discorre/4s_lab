import java.util.ArrayList;
import java.util.List;

public class FirstZ {

    static double f(double x) {
        return x * Math.log(x + 1) - 1;
    }

    static double df(double x) {
        return Math.log(x + 1) + x / (x + 1);
    }

    static double g(double x) {
        if (x < 0.0) return Math.exp(1.0 / x) - 1;
        else return 1.0 / Math.log(x + 1);
    }

    static void bisectionMethod(double a, double b, double eps, List<Tuple> bisection, Holder<Double> res) {
        int N = 0;
        while ((b - a) >= eps && N < 100) {
            double c = (a + b) / 2;
            bisection.add(new Tuple(N, a, b, b - a));
            if (f(c) == 0) {
                break;
            } else if (f(a) * f(c) < 0) {
                b = c;
            } else {
                a = c;
            }
            N++;
            res.setValue(c);
        }
    }

    static void newtonMethod(double x0, double eps, List<Tuple> newton, Holder<Double> res) {
        int N = 0;
        while (Math.abs(f(x0)) >= eps && N < 100) {
            double x1 = x0 - f(x0) / df(x0);
            double razn = Math.abs(x1 - x0);
            if (razn < 0.0001) razn = 0.0001;
            newton.add(new Tuple(N, x0, x1, razn));
            if (Math.abs(x1 - x0) <= eps) {
                break;
            }
            x0 = x1;
            N++;
            res.setValue(x0);
        }
    }

    static void simpleMethod(double x0, double eps, List<Tuple> simple, Holder<Double> res) {
        int N = 0;
        while (Math.abs(g(x0)) >= eps && N < 100) {
            double x1 = g(x0);
            if (Math.abs(x1 - x0) < eps) {
                break;
            }
            simple.add(new Tuple(N, x0, x1, Math.abs(x1 - x0)));
            x0 = x1;
            N++;
            res.setValue(x0);
        }
    }

    public static void main(String[] args) {
        double a = -1, b = 2, eps = 0.0001;
        Holder<Double> res = new Holder<>(0.0);
        List<Tuple> bisection = new ArrayList<>();
        List<Tuple> newton = new ArrayList<>();
        List<Tuple> simple = new ArrayList<>();

        // First root
        bisectionMethod(a, b, eps, bisection, res);
        System.out.println("Bisection Method (First root):");
        System.out.println("------------------------------------");
        System.out.println("N\t\ta\t\tb\t\tb - a");
        for (Tuple tuple : bisection) {
            System.out.println(tuple);
        }
        System.out.println();
        System.out.println("Root: " + res.getValue());
        System.out.println();

        double x0 = -0.5;
        newtonMethod(x0, eps, newton, res);

        System.out.println("Newton's Method (First root):");
        System.out.println("------------------------------------");
        System.out.println("N\t\tx0\t\tx1\t\tx1 - x0");
        for (Tuple tuple : newton) {
            System.out.println(tuple);
        }
        System.out.println();
        System.out.println("Root: " + res.getValue());
        System.out.println();

        simpleMethod(x0, eps, simple, res);

        System.out.println("Simple Iteration Method (First root):");
        System.out.println("------------------------------------");
        System.out.println("N\t\tx0\t\tx1\t\tx1 - x0");
        for (Tuple tuple : simple) {
            System.out.println(tuple);
        }
        System.out.println();
        System.out.println("Root: " + res.getValue());
        System.out.println();

        System.out.println("--------------------------------------------------");

        // Second root
        bisection.clear();
        newton.clear();
        simple.clear();

        a = 0;
        b = 2;
        bisectionMethod(a, b, eps, bisection, res);

        System.out.println("Bisection Method (Second root):");
        System.out.println("------------------------------------");
        System.out.println("N\t\ta\t\tb\t\tb - a");
        for (Tuple tuple : bisection) {
            System.out.println(tuple);
        }
        System.out.println();
        System.out.println("Root: " + res.getValue());
        System.out.println();

        x0 = 0.5;
        newtonMethod(x0, eps, newton, res);

        System.out.println("Newton's Method (Second root):");
        System.out.println("------------------------------------");
        System.out.println("N\t\tx0\t\tx1\t\tx1 - x0");
        for (Tuple tuple : newton) {
            System.out.println(tuple);
        }
        System.out.println();
        System.out.println("Root: " + res.getValue());
        System.out.println();

        simpleMethod(x0, eps, simple, res);

        System.out.println("Simple Iteration Method (Second root):");
        System.out.println("------------------------------------");
        System.out.println("N\t\tx0\t\tx1\t\tx1 - x0");
        for (Tuple tuple : simple) {
            System.out.println(tuple);
        }
        System.out.println();
        System.out.println("Root: " + res.getValue());

    }
}

class Tuple {
    private final double a;
    private final double b;
    private final double c;
    private final double d;

    public Tuple(double a, double b, double c, double d) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
    }

    @Override
    public String toString() {
        return String.format("%d\t\t%.4f\t\t%.4f\t\t%.4f", (int) a, b, c, d);
    }
}

class Holder<T> {
    private T value;

    public Holder(T value) {
        this.value = value;
    }

    public T getValue() {
        return value;
    }

    public void setValue(T value) {
        this.value = value;
    }
}
