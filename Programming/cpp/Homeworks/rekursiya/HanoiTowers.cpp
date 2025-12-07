#include <iostream>
#include <locale.h>

using namespace std;

void hanoi(int n, char a, char b, char c) {
    setlocale(LC_ALL, "RU");
    if (n == 1) {
        cout << "Переместить диск 1 со стержня " << a << " на стержень " << c << endl;
        return;
    }
    hanoi(n - 1, a, c, b);
    cout << "Переместить диск " << n << " со стержня " << a << " на стержень " << c << endl;
    hanoi(n - 1, b, a, c);
}

int main(void) {
    setlocale(LC_ALL, "RU");
    int num_disks;
    cout << "Введите количество дисков: ";
    cin >> num_disks;
    hanoi(num_disks, 'A', 'B', 'C');
    int p = (1 << num_disks) - 1;
    cout << "Всего перекладываний: " << p;
    return 0;
}