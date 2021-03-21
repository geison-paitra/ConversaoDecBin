/*
Biblioteca criada por: Geison Paitra
Data: 16/03/2021
Atualizada em: 17/03/2021
Finalidade: Converter números decimais em binários e Binários em decimais.
*/

#ifndef DecBinConverter
#define DecBinConverter
#include <stack>
#include <queue>
#include <math.h>
#include <iostream>
#include <cstdio>

using namespace std;

/* Converte a pilha com o resultado binário em um número binário do tipo inteiro*/
int restoToBinInt(stack<int> resto)

{
    // fórmula criada por mim (resultadoAnterior * 10) + numero atual da fila [enquanto fila não estiver vazia]

    int ant = 0, result; //ant = resultadoAnterior | result = resultado atual

    while (!resto.empty())
    {
        result = ((ant * 10) + resto.top());
        ant = result;
        resto.pop();
    }

    return result;
}

/*retorna true se o numero for par*/
bool isPar(int n)
{
    int x;

    x = n % 2;
    if (x == 1)
        return false;
    else
        return true;
}

/* Calcula a potência x^n*/
int potencia(int x, int n)
{
    int pow = x;

    if (n == 0)
    {
        return 1; //x^0=1
    }
    else if (n == 1)
    {
        return x; //x^1 = x
    }
    else
    {
        for (size_t i = 2; i <= n; i++)
        {

            pow *= x;
        }

        return pow;
    }
}

/* Converte um número decimal em binário*/
int decToBin(int n)
{

    stack<int> resto; /* pilha que vai armazenar na ordem inversa
     trazendo assim o resultado binario*/
    int restAtual;    /*Resultado e resto final em binario*/
    int quo;          /*Quociente*/

    restAtual = n % 2;
    resto.push(restAtual);
    quo = n / 2;

    //caso o quoeficiente seja menor que dois, não é mais necessário efetuar divisões
    while (quo >= 2)
    {
        restAtual = quo % 2;
        resto.push(restAtual);

        quo = quo / 2;
    }

    //o ultimo sempre será 1 (exceto 0, porque 0bin - 0dec)
    resto.push(1);

    return restoToBinInt(resto);
}

/*Converte um número binário para decimal*/
int binToDec(int n)
{
    queue<int> ordenado;
    bool isLast = false;
    int i = 0, result = 0, resultAtual = 0, prox;

    do
    {
        if (n <= 1)
            isLast = true;

        if (isPar(n))
            ordenado.push(0);
        else
            ordenado.push(1);

        n = n / 10;
    } while (!isLast);

    while (!ordenado.empty())
    {
        prox = ordenado.front();
        resultAtual = potencia(2, i);
        resultAtual = resultAtual * prox;
        result += resultAtual;
        ordenado.pop();
        i++;
    }

    return result;
}

#endif