#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int no_of_parity(int n)
{
    int num = 1, k = 0;
    while (n + k + 1 > num)
    {
        num *= 2;
        k++;
    }
    return k;
}
int main()
{
    int n, j = 0, val_as_power_of_two = 1, x = 0;
    printf("Enter the no of bits in the data: ");
    scanf("%d", &n);
    int data[n];
    for (int i = n - 1; i >= 0; i--)
    {
        scanf("%d", &data[i]);
    }
    int parity = no_of_parity(n);
    int parity_array[parity];
    int hamming_data[n + parity];
    for (int i = 0; i < n + parity; i++)
    {
        if (i + 1 == val_as_power_of_two)
        {
            // printf("%d %d\n",i+1,val_as_power_of_two);
            hamming_data[i] = -1;
            val_as_power_of_two *= 2;
            parity_array[x] = i + 1;
            x++;
        }
        else
        {
            hamming_data[i] = data[j++];
        }
    }
    for (int i = 0; i < parity; i++)
    {
        int j = parity_array[i] - 1, count = 0;
        while (j < parity + n)
        {
            int temp = parity_array[i];
            while (temp-- && j < parity + n)
            {
                count += hamming_data[j++];
            }
            j += parity_array[i];
        }
        if ((count + 1) % 2 == 0)
            hamming_data[parity_array[i] - 1] = 0;
        else
            hamming_data[parity_array[i] - 1] = 1;
    }
    int l = 0, h = parity + n - 1; // reversing hamming code
    while (l < h)
    {
        int temp = hamming_data[l];
        hamming_data[l] = hamming_data[h];
        hamming_data[h] = temp;
        l++;
        h--;
    }
    printf("Hamming Code:   ");
    for (int i = parity + n - 1; i >= 0; i--)
    {
        printf("%d ", hamming_data[i]);
    }
    // hamming code correction , getting error
    int recieved_code[parity + n], code = 0;
    for (int i = 0; i < parity + n; i++)
    {
        scanf("%d", &recieved_code[i]);
    }
    for (int i = 0; i < parity; i++)
    {
        int j = parity_array[i] - 1, count = 0;
        while (j < parity + n)
        {
            int temp = parity_array[i];
            while (temp-- && j < parity + n)
            {
                count += recieved_code[j++];
            }
            j += parity_array[i];
        }
        code += ((count) % 2) * (pow(2, i));
    }
    printf("\n%d", parity + n - code);
    return 0;
}
