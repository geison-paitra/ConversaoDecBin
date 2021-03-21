#include <iostream>
#include "decBinConverter.h"
using namespace std;

void startApp()
{
    int choice, n, result;

    cout << "Escolha uma das opcoes abaixo:" << endl;
    cout << "0 - Sair \n1 - Decimal > Binario \n2 - Binario > Decimal" << endl;
    cin >> choice;

    switch (choice)
    {
    case 0:
        cout << "\n\nAte mais...";
        break;

    case 1:
        cout << "\nEntre com um numero decimal: ";
        cin >> n;
        result = decToBin(n);
        cout << "Resultado em binario: ";
        cout << result << endl;
        system("pause");
        startApp(); //volta para o menu
        break;

    case 2:
        cout << "\nEntre com um numero binario: ";
        cin >> n;
        result = binToDec(n);
        cout << "Resultado em decimal: ";
        cout << result << endl;
        system("pause");
        startApp(); // volta pro menu
        break;

    default:
        break;
    }
}

int main()
{
    /* code */
    system("cls");
    startApp();
    return 0;
}
