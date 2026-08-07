/* Q) Create a structure to store information of "n" number of employees.
Employee info include::
ID,NAME,DESIGNATION,BASE SALARY,HRA(%),DA(%).
Display the info of employees with gross salary. Use array of structure. */


#include <stdio.h>

struct employee {
    int id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra;
    float da;
};

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct employee emp[n];

    
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of employee %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &emp[i].id);

        printf("Enter Name: ");
        scanf("%s", emp[i].name);

        printf("Enter Designation: ");
        scanf("%s", emp[i].designation);

        printf("Enter Basic Salary: ");
        scanf("%f", &emp[i].basic_salary);

        printf("Enter HRA percentage: ");
        scanf("%f", &emp[i].hra);

        printf("Enter DA percentage: ");
        scanf("%f", &emp[i].da);
    }

    printf("Employee Details::\n");

    
    for (int i = 0; i < n; i++) {
        float hra_amount = (emp[i].basic_salary * emp[i].hra) / 100.0f;
        float da_amount  = (emp[i].basic_salary * emp[i].da) / 100.0f;
        float gross_salary = emp[i].basic_salary + hra_amount + da_amount;

        printf("\nEmployee %d\n", i + 1);
        printf("ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Designation: %s\n", emp[i].designation);
        printf("Basic Salary: %.2f\n", emp[i].basic_salary);
        printf("HRA: %.2f%%\n", emp[i].hra);
        printf("DA: %.2f%%\n", emp[i].da);
        printf("Gross Salary: %.2f\n", gross_salary);
    }

    return 0;
}