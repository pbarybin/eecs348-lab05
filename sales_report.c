// Name: Peter Barybin
// KUID: 3057437
// LAB Session: Thursday 4 p.m.
// LAB Assignment: 05
// Description: Program that takes in 12 monthly sales figures via text file and outputs the monthly report, sales summary, six-month
// moving average report, and sales report from high to low.

#include <stdio.h>
#include <stdlib.h>

//function that prints the month followed by that months sales (formatted)
void monthly_report(float arr[]) {
    printf("\nMonthly Sales Report\n\nMonth\t\tSales\n");
    int i;
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (i=0; i < 12; i++) {
        printf("%-10s\t%.2f\n", months[i], arr[i]);
    }
}

//function that prints minimum, maximum, and average sales
void sales_summary(float arr[]) {
    float min = arr[0];
    int min_index = 0;
    float max = arr[0];
    int max_index = 0;
    float total = arr[0];
    int i;
    //iterate through monthly sales
    for (i=1; i < 12; i++) {
        //current month less than min
        if (arr[i] < min) {
            min = arr[i];
            min_index = i;
        }
        //current month greater than max
        if (arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
        //add to total so average can be taken in print statement
        total += arr[i];
    }
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("\nSales summary report:\n\nMinimum sales: %.2f (%s)\nMaximum sales: %.2f (%s)\nAverage sales: %.2f\n", min, months[min_index], max, months[max_index], total/12);
}

//function that prints out the 6 month moving averages of the sales by iterating through for loops 
void six_month_moving(float arr[]){
    printf("\nSix-Month moving average report:\n\n");
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int i;
    for (i=0; i < 7; i++) {
        int j;
        float total = 0;
        //sum for 6 months (average taken in print statement)
        for (j=i; j < i+6; j++) {
            total += arr[j];
        }
        printf("%s-%s\t%.2f\n", months[i], months[i+5], total/6);
    }
}

//function that prints out the months and sales from highest to lowest
void high_low(float arr[]) {
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("\nSales report (highest to lowest):\n\nMonth\t\tSales\n");
    //create temp array for sorting
    float dup[12];
    int i;
    for (i=0; i < 12; i++) {
        dup[i] = arr[i];
    }
    //sort duplicate array into descending order (bubble sort)
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12 - i - 1; j++) {
            // Swap if the element found is less than the next element
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    //print out sorted results
    int j;
    for (j=0; j < 12; j++) {
        printf("%-10s\t$%.2f\n", months[i], arr[i]);
    }
}

int main() {
    //open text file with sales numbers
    FILE * input_file = fopen("sample_sales_input.txt", "r");
    //return 1 if error in opening file
    if (input_file == NULL) {
        printf("File not found.\n");
        return 1;
    }
    //sales array
    float sales[12];
    
    //fill array with floats
    int i;
    for (i=0; i < 12; i++) {
        fscanf(input_file, "%f", &sales[i]);
    }

    fclose(input_file);

    monthly_report(sales);
    sales_summary(sales);
    six_month_moving(sales);
    high_low(sales);
}