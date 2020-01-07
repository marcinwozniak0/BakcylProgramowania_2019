#pragma once

struct A
{
    int field = 4;
};

int getSumOfObjectsMeber_1(A tab[])
{
    int sum = 0;
    for (int i = 0; i < 7; i++)
    {
        sum = sum + tab[i].field;
    }

    return sum;
}

int getSumOfObjectsMeber_2(A tab[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum = sum + tab[i].field;
    }

    return sum;
}

void changeObjectsMemberValue(A tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
        tab[i].field = 10;
    }
}