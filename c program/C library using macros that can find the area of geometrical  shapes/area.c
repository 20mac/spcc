#include <stdio.h>
#include "area.h"

int main() {
    int choice;
    float length, width, side, radius, base, height, area;
    
    do {
        printf("Enter the number of the shape for which you want to find the area:\n");
        printf("1. Rectangle\n");
        printf("2. Square\n");
        printf("3. Circle\n");
        printf("4. Triangle\n");
        printf("5. Exit\n");
        scanf(" %d ", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the length and width of the rectangle:\n");
                scanf("%f %f", &length, &width);
                area = AREA_RECTANGLE(length, width);
                printf("The area of the rectangle is %.2f\n", area);
                break;
            case 2:
                printf("Enter the side of the square:\n");
                scanf("%f", &side);
                area = AREA_SQUARE(side);
                printf("The area of the square is %.2f\n", area);
                break;
            case 3:
                printf("Enter the radius of the circle:\n");
                scanf("%f", &radius);
                area = AREA_CIRCLE(radius);
                printf("The area of the circle is %.2f\n", area);
                break;
            case 4:
                printf("Enter the base and height of the triangle:\n");
                scanf("%f %f", &base, &height);
                area = AREA_TRIANGLE(base, height);
                printf("The area of the triangle is %.2f\n", area);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}

