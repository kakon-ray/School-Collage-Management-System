#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int rollno;
    char name[80];
    int total_marks;
    int marks_first_exam;
    int marks_second_exam;
    int marks_final_exam;
};

void accept(struct student list[], int student_number); 
void display(struct student list[], int student_number);
void sorting_student_list(struct student list[], int student_number);

int main()
{
    struct student data[20];
    int n;

    char reg_username[50];
    char reg_password[50];
    char username[50];
    char password[50];
    int log_sing,num;
    char receve_username,receve_password;

    printf("\nIf You Want To Register Press 1 and You Want To Login Press 2\n");
    printf("Press Here: ");
    scanf("%d",&log_sing);

    FILE *login_sing,*login;

    if(log_sing == 1)
    {


        login = fopen("login.txt","w");

        if(login == NULL)
        {
            printf("Error!");
            exit(1);
        }
        printf("Please Enter The User Name or Email: ");
        scanf("%s",&reg_username);
        fprintf(login,"%s\n",reg_username);
        printf("Please Enter The Password: ");
        scanf("%s",&reg_password);
        fprintf(login,"%s\n",reg_password);

        printf("\n\n////////////////////////////////////////////////////////////////////////\n");
        printf("\tRegistation Compleat Please Login\n");
        printf("////////////////////////////////////////////////////////////////////////\n\n");


           login = fopen("login.txt","r");

        if ((login_sing = fopen("login.txt","r")) == NULL)
        {
            printf("Error! opening file");

            exit(1);
        }

        printf("Enter your username: ");
        scanf("%s",username);

        printf("Enter your password: ");
        scanf("%s",password);

        fscanf(login_sing,"%s",&reg_username);
        fscanf(login_sing,"%s",&reg_password);

        if(strcmp(username,reg_username)==0)
        {
            if(strcmp(password,reg_password)==0)
            {

                // লগইন ইনফরমেশন যদি সঠিক হয় তাহলে স্কুল ম্যানেজমেন্ট সিস্টেম টি কাজ করবে

                //Start School Management System
                printf("\n///////////  Login Success ////////// \n\n\n");

                printf("Please Enter Number of Student: ");
                scanf("%d", &n);

                accept(data, n);

                sorting_student_list(data, n);
                printf("\n\t=======================================================\n");
                printf("\t\t\tStudent Maritlist: ");
                printf("\n\t=======================================================\n\n\n");

                display(data, n);

                //ENd School Management System

            }
            else
            {
                printf("\nwrong password");
            }
        }
        else
        {
            printf("\nUser doesn't exist");
        }

    }

    else
    {

        login = fopen("login.txt","r");

        if ((login_sing = fopen("login.txt","r")) == NULL)
        {
            printf("Error! opening file");

            exit(1);
        }

        printf("Enter your username: ");
        scanf("%s",username);

        printf("Enter your password: ");
        scanf("%s",password);

        fscanf(login_sing,"%s",&reg_username);
        fscanf(login_sing,"%s",&reg_password);

        if(strcmp(username,reg_username)==0)
        {
            if(strcmp(password,reg_password)==0)
            {

                // লগইন ইনফরমেশন যদি সঠিক হয় তাহলে স্কুল ম্যানেজমেন্ট সিস্টেম টি কাজ করবে

                //Start School Management System
                printf("\n///////////  Login Success ////////// \n\n\n");

                printf("Please Enter Number of Student: ");
                scanf("%d", &n);

                accept(data, n);

                sorting_student_list(data, n);
                printf("\n\t=======================================================\n");
                printf("\t\t\tStudent Maritlist: ");
                printf("\n\t=======================================================\n\n\n");

                display(data, n);

                //ENd School Management System

            }
            else
            {
                printf("\nwrong password");
            }
        }
        else
        {
            printf("\nUser doesn't exist");
        }

    }
    fclose(login);
    return 0;
}

void accept(struct student list[80], int student_number)
{
    int i;
    for (i = 0; i < student_number; i++)
    {
        printf("\n\nStudent Number #%d", i + 1);

        printf("\nEnter name : ");
        scanf(" %[^\n]",list[i].name);
        scanf("%[^\n]%*c", list[i].name);

        printf("First Exam Mark: ");
        scanf("%d", &list[i].marks_first_exam);

        printf("Second Exam Mark : ");
        scanf("%d", &list[i].marks_second_exam);

        printf("Final Exam Mark: ");
        scanf("%d", &list[i].marks_final_exam);

        list[i].total_marks = (list[i].marks_first_exam + list[i].marks_second_exam + list[i].marks_final_exam) / 3 ;
        printf("\nTotal Marks %s: %d",list[i].name,list[i].total_marks);
    }

}

void display(struct student list[80], int student_number)
{
    int i;


    FILE *fptr;
    fptr = fopen("stuent_maritlist.txt","w");

    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    printf("\t\tRoll\t\tName\t\tMarks\n\n");
    fprintf(fptr,"\t\tRoll\t\tName\t\tMarks\n\n");

    for (i = 0; i < student_number; i++)
    {
        printf("\t\t%d\t\t\%s\t\t%d\n",i+1,list[i].name, list[i].total_marks);
        fprintf(fptr,"\t\t%d\t\t\%s\t\t%d\n",i+1,list[i].name, list[i].total_marks);
    }

    fclose(fptr);
}

void sorting_student_list(struct student list[80], int student_number)
{
    int i, j;
    struct student temp;

    for (i = 0; i < student_number - 1; i++)
    {
        for (j = 0; j < (student_number - 1-i); j++)
        {
            if (list[j].total_marks < list[j + 1].total_marks)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}