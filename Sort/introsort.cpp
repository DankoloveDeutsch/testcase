#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Функция для генерации случайного числа в интервале [0, 1)
double generateRandom() {
    return rand() / (RAND_MAX + 1.0);
}

// Функция для моделирования одного испытания системы
bool simulateSystemFailure(double p1) {
    double r1 = generateRandom();
    double r2 = generateRandom();
    double r3 = generateRandom();

    // Проверка отказа каждого прибора
    bool failure1 = r1 < p1;
    bool failure2 = r2 < p1;
    bool failure3 = r3 < p1;

    // Система выходит из строя, если вышел из строя П1 и оба прибора П2 и П3 одновременно
    return failure1 || (failure2 && failure3);
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    int m, n;
    double p1, p2, p3, sum = 0, sred;

    // Ввод количества экспериментов
    do {
        cout << "Введите число экспериментов >=1 и <=1000: ";
        cin >> m;
    } while (m < 1 || m > 1000);

    // Ввод количества испытаний
    do {
        cout << "Введите число испытаний >=100 и <=2000: ";
        cin >> n;
    } while (n < 100 || n > 2000);

    // Ввод вероятностей отказа для каждого прибора
    cout << "Введите вероятность отказа приборов(P1): ";
    cin >> p1;


    for (int j = 0; j < m; ++j) {
        int kol = 0;
        for (int i = 0; i < n; ++i) {
            if (simulateSystemFailure(p1)) {
                kol++;
            }
        }
        double p = static_cast<double>(kol) / n;
        //cout << fixed << setprecision(4) << "Вероятность отказа системы = " << p << endl;
        sum += p;
    }

    sred = sum / m;
    cout << fixed << setprecision(4) << "Среднее значение вероятности отказа системы = " << sred << endl;

    return 0;
}
