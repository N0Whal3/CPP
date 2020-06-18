#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
bool doubleEquals(double left, double right, double epsilon) {
    return (fabs(left - right) < epsilon);
}
bool doubleLess(double left, double right, double epsilon,
    bool orequal = false) {
    if (fabs(left - right) < epsilon) {
        // В рамках epsilon, так что считаются равными
        return (orequal);
    }
    return (left < right);

}
bool doubleGreater(double left, double right, double epsilon,
    bool orequal = false) {
    if (fabs(left - right) < epsilon) {
        // В рамках epsilon, так что считаются равными
        return (orequal);
    }
    return (left > right);
}
int main()
{
    float a, b, x0, x1, dx, x, xi, max, min;
    cin >> a >> b >> x0 >> x1 >> dx;
    x = x0;
    max = x0;
    min = x0;
    while (doubleLess(x, x1, .0001, true)) {
        if (doubleLess(x, a, .0001, true)) xi = x * x + sin(x);
        else if (doubleGreater(x, a, .0001) && doubleLess(x, b, .0001)) xi = cos(x * x);
        else if (doubleLess(x, b, .0001, true)) xi = log(2) / log(x);
        if (max < xi)max = xi;
        if (min > xi)min = xi;
        cout << xi << "    " << x << "\n";
        x += dx;
    }
    cout << "Max=" << max << "    Min=" << min;
    system("pause");
}