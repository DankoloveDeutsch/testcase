#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// ������� ��� ��������� ���������� ����� � ��������� [0, 1)
double generateRandom() {
    return rand() / (RAND_MAX + 1.0);
}

// ������� ��� ������������� ������ ��������� �������
bool simulateSystemFailure(double p1) {
    double r1 = generateRandom();
    double r2 = generateRandom();
    double r3 = generateRandom();

    // �������� ������ ������� �������
    bool failure1 = r1 < p1;
    bool failure2 = r2 < p1;
    bool failure3 = r3 < p1;

    // ������� ������� �� �����, ���� ����� �� ����� �1 � ��� ������� �2 � �3 ������������
    return failure1 || (failure2 && failure3);
}

int main() {
    srand(time(0)); // ������������� ���������� ��������� �����

    int m, n;
    double p1, p2, p3, sum = 0, sred;

    // ���� ���������� �������������
    do {
        cout << "������� ����� ������������� >=1 � <=1000: ";
        cin >> m;
    } while (m < 1 || m > 1000);

    // ���� ���������� ���������
    do {
        cout << "������� ����� ��������� >=100 � <=2000: ";
        cin >> n;
    } while (n < 100 || n > 2000);

    // ���� ������������ ������ ��� ������� �������
    cout << "������� ����������� ������ ��������(P1): ";
    cin >> p1;


    for (int j = 0; j < m; ++j) {
        int kol = 0;
        for (int i = 0; i < n; ++i) {
            if (simulateSystemFailure(p1)) {
                kol++;
            }
        }
        double p = static_cast<double>(kol) / n;
        //cout << fixed << setprecision(4) << "����������� ������ ������� = " << p << endl;
        sum += p;
    }

    sred = sum / m;
    cout << fixed << setprecision(4) << "������� �������� ����������� ������ ������� = " << sred << endl;

    return 0;
}
