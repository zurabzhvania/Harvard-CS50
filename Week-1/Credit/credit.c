#include <stdbool.h>
#include <stdio.h>
bool isValidLuhn(long long card);
int countDigits(long long card);
int getFirstTwoDigits(long long card);
const char *getCardType(long long card);
int main(void)
{
    long long card;
    printf("Enter Card Number: ");
    scanf("%lld", &card);
    if (!isValidLuhn(card))
    {
        printf("INVALID\n");
        return 0;
    }
    printf("%s\n", getCardType(card));
    return 0;
}
bool isValidLuhn(long long card)
{
    int sum = 0;
    bool doubleDigit = false;
    while (card > 0)
    {
        int digit = card % 10;
        if (doubleDigit)
        {
            int doubled = digit * 2;
            if (doubled > 9)
            {
                sum += (doubled / 10) + (doubled % 10);
            }
            else
            {
                sum += doubled;
            }
        }
        else
        {
            sum += digit;
        }
        doubleDigit = !doubleDigit;
        card /= 10;
    }
    return sum % 10 == 0;
}
int countDigits(long long card)
{
    int digits = 0;
    while (card > 0)
    {
        card /= 10;
        digits++;
    }
    return digits;
}
int getFirstTwoDigits(long long card)
{
    while (card >= 100)
    {
        card /= 10;
    }
    return (int)card;
}
const char *getCardType(long long card)
{
    int digits = countDigits(card);
    int firstTwo = getFirstTwoDigits(card);
    int firstOne = firstTwo / 10;
    if ((firstTwo == 34 || firstTwo == 37) && digits == 15)
    {
        return "AMEX";
    }
    if (firstTwo >= 51 && firstTwo <= 55 && digits == 16)
    {
        return "MASTERCARD";
    }
    if (firstOne == 4 && (digits == 13 || digits == 16))
    {
        return "VISA";
    }
    return "INVALID";
}
