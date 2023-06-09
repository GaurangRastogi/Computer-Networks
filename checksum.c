#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n_of_seg, seg_len;
    printf("Enter no of data segments & segment length: ");
    scanf("%d%d", &n_of_seg, &seg_len);
    int data[n_of_seg][seg_len];
    for (int i = 0; i < n_of_seg; i++)
    {
        for (int j = 0; j < seg_len; j++)
        {
            scanf("%d", &data[i][j]);
        }
    }
    int checksum[seg_len], k = 0;
    int carry = 0;
    for (int j = seg_len - 1; j >= 0; j--)
    {
        int sum = carry;
        for (int i = 0; i < n_of_seg; i++)
        {
            sum += data[i][j];
        }
        checksum[k] = sum % 2;
        k++;
        carry =sum>> 1;
    }

    while (carry != 0)
    {
        for (int j = seg_len; j >= 0; j--)
        {
            checksum[j] = checksum[j] + carry;
            carry = checksum[j] >> 1;
            checksum[j] %= 2;
        }
    }
    printf("\n");
    for (int i = 0; i < seg_len; i++)
    {
        printf("%d ", 1 - checksum[i]);
    }
    return 0;
}