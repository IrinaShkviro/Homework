#include <QCoreApplication>
#include "stdio.h"
#include "calculator.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    printf("%s\n", "Set size of array");
    int size;
    scanf("%d", &size);
    float* array = new float[size];
    float cur = 0;
    printf("%s\n", "Put elements of array");
    for (int i = 0; i < size; i++) {
        scanf("%f", &cur);
        array[i] = cur;
    }
    Calculator* myCalc = new Calculator();
    printf("\n%s%d", "amount of zero elements in this array = ", myCalc->calculateZeroElements(array, size));

    return a.exec();
}
