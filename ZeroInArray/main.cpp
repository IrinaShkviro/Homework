#include <QCoreApplication>
#include "stdio.h"

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
    int result = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == 0) {
            result++;
        }
    }
    printf("\n%s%d", "amount of zero elements in this array = ", result);

    return a.exec();
}
