#include <iostream>
#include <cmath>

using namespace std;

double findRoot(double (*f) (double), double x0, int n)
{
    double x = x0;
    for (int i = 1; i <= n; i++)
        x = f(x);
    return x;
}

void findRoot(double (*f) (double), double x0, double eps)
{
    int count = 0;
    double x = x0;
    double x_prev;
 
    do
    {
        x_prev = x;
        if (fabs((f(x + eps) - f(x - eps)) / 2. * eps) >= 1.)
        {
            cout << "Метод расходится" << endl;
            exit(0);
        }
        x = f(x);
        count++;
        cout << count << ": " << x << endl;
    } while (abs(x - x_prev) > eps);
}

double F(double x) { return sqrt(x + 6); }

double G(double x) { return (x * x + 10) / 11; }

int main()
{
    setlocale(LC_ALL, "Russian");

    double x0 = 533., z0 = 4., y0 = 3.1415926 / 2., eps = .0001;
    cout << "x = F(x):" << endl;
    findRoot(F, x0, eps);
    cout << "\nx = G(x):" << endl;
    findRoot(G, z0, eps);
    cout << "\nx = H(x):" << endl;
    findRoot([](double x) { return sin(x); }, y0, eps);
    return 0;
}