#include <iostream>
#include <string>
#include <math.h>

using  namespace  std;

double PMToverPV(int n, double r)
{
    return r + r / (pow(1 + r, n) - 1);
}

int main () {
    int n, exo;
    double PV, PMT, r;

    cout << "Dear user, what do you want to calculate?" << endl;
    cout << "Press 1 to obtain the instalment fee" << endl;
    cout << "Press 2 to obtain the amount of the loan" << endl;
    cout << "Press 3 to obtain the number of years of the loan" << endl;
    cout << "Press 4 to obtain the interest rate of the loan" << endl;
    cin >> exo;

    switch (exo) {
        case 1: {
            cout << "Provide the amount of the loan" << endl;
            cin >> PV;
            cout << "Provide the number of years" << endl;
            cin >> n;
            cout << "Provide the interest rate" << endl;
            cin >> r;

            PMT = PV * PMToverPV(n, r);

            cout << "The instalment fee is " << PMT << endl;
        }
            break;

        case 2: {
            cout << "Provide the instalment fees" << endl;
            cin >> PMT;
            cout << "Provide the number of years" << endl;
            cin >> n;
            cout << "Provide the interest rate" << endl;
            cin >> r;

            PV = PMT / PMToverPV(n, r);

            cout << "The amount of the loean is " << PV << endl;
        }
            break;

        case 3: {
            cout << "Provide the amount of the loan" << endl;
            cin >> PV;
            cout << "Provide the instalment fees" << endl;
            cin >> PMT;
            cout << "Provide the interest rate" << endl;
            cin >> r;

            n = round(log(1 + (1 / (PMT / (PV * r) - 1))) / log(1 + r));

            cout << "The number of years is " << n << endl;
        }
            break;

        case 4: {
            int method;
            cout << "Which method do you want to use to obtain r?" << endl;
            cout << "Press 1 for Weronika's method" << endl;
            cout << "Press 2 for binary method" << endl;
            cout << "Press 3 for secant method" << endl;
            cin >> method;

            switch (method) {
                case 1: {
                    cout << "Provide the amount of the loan" << endl;
                    cin >> PV;
                    cout << "Provide the instalment fees" << endl;
                    cin >> PMT;
                    cout << "Provide the number of years" << endl;
                    cin >> n;

                    r = 0;
                    do { r = r + 0.0001; }
                    while (PMToverPV(n, r) <= PMT / PV);

                    r = round(r * 1000) / 1000;

                    cout << "The interest rate is " << r * 100 << " %" << endl;
                }
                    break;

                case 2: {
                    cout << "Provide the amount of the loan" << endl;
                    cin >> PV;
                    cout << "Provide the instalment fees" << endl;
                    cin >> PMT;
                    cout << "Provide the number of years" << endl;
                    cin >> n;

                    double a = 0, b = 1;
                    int i = 1;

                    do {
                        if ((PMT / PV) <= PMToverPV(n, (a + b) / 2)) {
                            b = (a + b) / 2;
                            i++;
                        } else {
                            a = (a + b) / 2;
                            i++;
                        }

                    } while (b - a > 0.00001);

                    r = (a + b) / 2;
                    r = round(r * 1000) / 1000;

                    cout << "The interest rate is " << r * 100 << " %" << endl;
                }
                    break;

                case 3: {
                    cout << "Provide the amount of the loan" << endl;
                    cin >> PV;
                    cout << "Provide the instalment fees" << endl;
                    cin >> PMT;
                    cout << "Provide the number of years" << endl;
                    cin >> n;

                    double r0 = 0.0001, r1 = 0.9999, r2;

                    for (int i = 0; i < 1000; i++) {
                        r2 = r1 - ((PMToverPV(n, r1) - (PMT / PV)) * (r1 - r0) / (PMToverPV(n, r1) - PMToverPV(n, r0)));
                        r0 = r1;
                        r1 = r2;
                    }

                    r2 = round(r2 * 1000) / 1000;

                    cout << "The interest rate is " << r2 * 100 << " %" << endl;
                }
                    break;

                default: {
                    cout << "Please enter the number of the method between 1 and 3" << endl;
                }
            }

        }
            break;

        default: {
            cout << "Please enter the number of the exercise between 1 and 4" << endl;
        }


    }
    system (" pause ");
}