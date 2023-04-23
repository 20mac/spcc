#include <stdio.h>
#include <conio.h>
#include "convert.h"

int main()
{
    int ch;
    float celsius, fahrenheit, metre, feet, litre, cubic;
    float Cel, Far, Met, Ft, Lt, Cu;
    do
    {
        printf("\nMenu 1.Cel to Far 2.Far to Cel 3.Met to Feet 4.Feet to Met 5.Lt to CubFt 6.CubFt to Lt 7.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            print();
            scanf("%f", &celsius);
            Far = convertCelFahrenheit(celsuis);
            printf("\n The Conversion of Celsius to Fahrenheit is: %f", Far);
            break;

        case 2:
            print();
            scanf("%f", &fahrenheit);
            Cel = convertFarCelsuis(fahrenheit);
            printf("\n The Conversion of Fahrenheit to Celsius is: %f", Cel);
            break;

        case 3:
            print();
            scanf("%f", &metre);
            Met = convertMetreFeet(metre);
            printf("\n The Conversion of Metre to Feet is: %f", Met);
            break;

        case 4:
            print();
            scanf("%f", &feet);
            Ft = convertFeetMetre(feet);
            printf("\n The Conversion of Feet to Metre is: %f", Ft);
            break;

        case 5:
            print();
            scanf("%f", &litre);
            Lt = convertLitreCubic(litre);
            printf("\n The Conversion of Litre to Cubic Feet is: %f ", Lt);
            break;

        case 6:
            print();
            scanf("%f", &cubic);
            Cu = convertCubicLitre(cubic);
            printf("\n The Conversion of Cubic Feet to Litre is: %f ", Cu);
            break;
            
        case 7:
            printf("Bye");
            break;
        default:
            printf("Wrong Input\n");
            break;
        }
    } while (ch != 7);
    getch();
    return 0;
}
