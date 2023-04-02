#include <iostream>

double f(double x)
{
    return (x * x * x) + (10 * x * x) + (8 * x) + (7);
}
double fxi(double& a, double& b, double& xi)
{
    return (b - a) / 2.0 * f(((b + a) / 2.0) + (((b - a) / 2.0) * xi));
}

double calkowanie_prostokaty(int& n, double& a, double& b);
double calkowanie_trapezy(int& n, double& a, double& b);
double calkowanie_simpson(int& n, double& a, double& b);
double calkowanie_gauss(int& n, double& a, double& b);


int main()
{
    int n = 10;
    double a = 0;
    double b = 4;

    std::cout << "Metoda prostokatow;   Pole: " << calkowanie_prostokaty(n, a, b) << std::endl;
    std::cout << "Metoda trapezow;      Pole: " << calkowanie_trapezy(n, a, b) << std::endl;
    std::cout << "Metoda simpsona;      Pole: " << calkowanie_simpson(n, a, b) << std::endl;
    std::cout << "Metoda k. gaussa;     Pole: " << calkowanie_gauss(n, a, b) << std::endl;
}

double calkowanie_prostokaty(int& n, double& a, double& b)
{
    double h = (b - a) / n;
    double pole = 0;

    for (int i = 0; i < n; i++)
    {
        double x = a + i * h;
        
        pole += f(x + 0.5 * h) * h;
    }
    return pole;
}

double calkowanie_trapezy(int& n, double& a, double& b)
{
    double h = (b - a) / n;
    double pole = 0.5 * (f(a) + f(b));

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        pole += f(x);
    }

    return h * pole;
}

double calkowanie_simpson(int& n, double& a, double& b)
{
    double h = (b - a) / n;
    double pole = f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        pole += (i % 2 == 0) ? 2 * f(x) : 4 * f(x);
    }

    return h / 3 * pole;
}

double calkowanie_gauss(int& n, double& a, double& b)
{
    double cal = 0.0;

    // Tablica węzłów Gaussa i odpowiadających im wag
    double xi[4] =
    {
        -0.861136311594053,
        -0.339981043584856,
        0.339981043584856,
        0.8611363115940537
    };

    double wi[4] = 
    { 
        0.347854845137454,
        0.652145154862546,
        0.652145154862546,
        0.347854845137454
    };

    for (int i = 0; i < 4; i++)
    {
        cal = cal + fxi(a, b, xi[i]) *wi[i];
    }

    return cal;
}
