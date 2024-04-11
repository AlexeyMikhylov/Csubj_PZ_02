#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{
    printf("Exersizes [1..5]\nexamples [10..50]\n");
    run();
}

int run()
{
    int number;
    printf("\nEnter the number: ");
    if (scanf("%d", &number) != NULL)
    
    switch (number)
    {
    case 0:
        printf("exit");
        return 0;
    case 1:
        num1();
    case 12: //ввод структуры с файла 
        printf("\n");
        num1_txtOut();
        break;
    case 13: //ввод структуры с клавы, запись структуры в файл
        printf("\n");
        num1_txtIn();
        break;
    case 2:
        printf("\n");
        num2();
        break;
    case 3:
        printf("\n");
        num3();
        break;
    case 4:
        printf("\n");
        num4();
        break;
    case 5:
        printf("\n");
        num5();
        break;
    case 10:
        printf("\n");
        ex1();
        break;
    case 20:
        printf("\n");
        ex2();
        break;
    case 30:
        printf("\n");
        ex3();
        break;
    case 40:
        printf("\n");
        ex4();
        break;
    case 50:
        printf("\n");
        ex5();
        break;
    case 60:
        printf("\n");
        ex6();
        break;
    default:
        puts("wrong number");
        break;
    }

    run();
}

//ex 1
int ex1(void)
{
    struct
    {
        char fio[20];           // фамилия
        unsigned long long num; // телефон (long – 4 байта) // usnigned long long - 20 цифр
    } tel1, tel2;

    *tel2.fio = "0";
    tel2.num = 0;

    puts("Enter your name: ");
    scanf("%s", &tel1.fio);

    puts("Enter the tlf number: ");
    scanf("%llu", &tel1.num);

    tel2 = tel1;  /* так можно, но нельзя сравнивать структуры */

    puts("Input :");

    printf("Name: %s   Number: %llu\n", tel1.fio, tel1.num);
    printf("Name: %s   Number: %llu\n", tel2.fio, tel2.num);

    return 0;
} 

//ex 2
int ex2() 
{
    struct sprav
    {
        char fio[20];
        unsigned long long num;
    };
    struct sprav* tel1, * tel2;
    
    /* Выделение памяти для структуры */
    tel1 = (struct sprav*)malloc(sizeof(struct sprav));
    tel2 = (struct sprav*)malloc(sizeof(struct sprav));
    
    puts("Enter your name: ");
    //gets(tel1->fio);
    scanf("%s", &tel1->fio);

    puts("Enter the tlf number: ");
    scanf("%llu", &tel1->num);
    *tel2 = *tel1;
    
    puts("Input: ");
    
    printf("Name: %s   Number: %llu\n", (*tel2).fio, (*tel2).num);
    //printf("Name: %s   Number: %ld\n",tel2->fio,tel2->num);  // или так
    
    free(tel1);
    free(tel2);

    return 0;
}

//ex 3
#define SPRAVOCHNIK struct spravochnik
int ex3()
{
    int const N = 3;
    
    SPRAVOCHNIK
    {
       char fio[20];
       unsigned long long num;
    };

    SPRAVOCHNIK tel[3];    /* массив структур - 3 элементов */
    
    char fio_tek[20];
    int i;
    
    /* ввод данных в массив структур */
    for (i = 0; i < N; i++)
    {
        puts("Enter your name: ");
        scanf("%s", tel[i].fio);
        
        puts("Enter the tlf number: ");
        scanf("%llu", &tel[i].num);
        
        printf("\n");
    }
    
    puts("Choosing a phone by name ");
    scanf("%s", fio_tek);
    
    /* поиск структуры по фамилии абонента */
    for (i = 0; i < N; i++)
        if (!strcmp(fio_tek, tel[i].fio)) break;
    if (i != 5)    /* цикл закончен по break */
        printf("Subscriber info:\n   name %s, phonenumber %llu\n", fio_tek, tel[i].num);
    else        /* цикл выполнился полностью */
        puts("Subscriber not found"); // Абонент не найден
    
    return 0;
}

//ex 4
//int const N = 3;
typedef struct
{
    char fio[20];
    long num;
} TEL;

int ex4()
{
    int N;
    printf("How many users you want to input?: ");
    scanf("%d", &N);

    TEL* tel;
    char fio_tek[20];
    int i;

    /* Выделение памяти для массива - N элементов */
    tel = (TEL*)malloc(sizeof(TEL) * N);

    for (i = 0; i < N; i++)
    {
        puts("Enter your name: ");
        scanf("%s", (tel + i)->fio);

        puts("Enter the tlf number: ");
        scanf("%ld", &(tel + i)->num);

        printf("\n");
    }

    puts("hoosing a phone by last name ");
    scanf("%s", fio_tek);

    for (i = 0; i < N; i++, tel++)
        if (!strcmp(fio_tek, tel->fio)) break;
    if (i != N)
        printf("Subscriber info:\n   name: %s\n   phone: %ld\n", fio_tek, tel->num);
    else
        puts("Subscriber not found");

    return 0;
}

//ex 5
typedef struct {
    float a;   /* действительная часть */
    float b;   /* мнимая часть */
} COMPLEX;

void vvod(COMPLEX*, float, float);
void sum(COMPLEX*, COMPLEX*, COMPLEX*);
void out(COMPLEX*);

int ex5()
{
    COMPLEX x, y, z;

    vvod(&x, 2.5, 6.7);
    vvod(&y, 6.89, 8.45);

    puts("Numbers are entered: ");
    out(&x);
    out(&y);

    puts("The sum of complex numbers is equal to: ");
    sum(&x, &y, &z);
    out(&z);
}

/* Ввод значений для элементов структуры */
void vvod(COMPLEX* p, float a, float b)
{
    p->a = a;
    p->b = b;
    return;
}

/* Вывод комплексного числа */
void out(COMPLEX* p)
{
    printf("(%.2f,%.2f)\n", (*p).a, (*p).b);
    return;
}

/* Вычисление суммы двух комплексных чисел */
void sum(COMPLEX* p1, COMPLEX* p2, COMPLEX* p3)
{
    (*p3).a = (*p1).a + (*p2).a;
    (*p3).b = (*p1).b + (*p2).b;
    return;
}

//ex 6
typedef struct Model
{
    int id;
    
    struct
    {
        int id;
        char* name;
    } make;
    
    char* name;
    
    unsigned year;

} Model;

int ex6()
{
    Model m = { 10, {10, "Acura"}, "CL", 2012 };
    
    printf("Model name = %s\n", m.name);
    printf("Make name = %s\n", m.make.name);
    printf("year = %d\n", m.year);
    
    return 0;
}

//number 1
#define students 3

int num1()
{
    typedef struct
    {
        char surname[20];
        int group;
        unsigned int grade[5];
    } STUDENT;

    int k = 0;

    STUDENT p[students];

    for (int i = 0; i < students; i++)
    {
        puts("\nEnter student's surname: ");
        scanf("%s", &p[i].surname);

        puts("Enter student's group: ");
        scanf("%ld", &p[i].group);

        puts("Enter student's grade (1..5): ");
        for (int j = 0; j < 5; j++)
        {
            scanf("%ld", &p[i].grade[j]);

            if (p[i].grade[j] > 5)
                p[i].grade[j] = 5;
        }
    }

    puts("\nStudent's with average grade > 4.0:\n");
    for (int i = 0; i < students; i++)
    {
        float all_marks = 0;

        for (int j = 0; j < 5; j++)
        {
            all_marks += p[i].grade[j];
        }

        float average_grade = all_marks / 5;

        if (average_grade > 4.0)
        {
            printf("\n Surname: %s \n", p[i].surname);
            printf("      Group: %ld \n", p[i].group);
            k++;
        }
    }
    if (k == 0)
    {
        puts("There are no students with average grade > 4.0");
    }
    printf("\n");
}

int num1_txtOut()//считывает структуру из файла
{
    typedef struct
    {
        char surname[20];
        int group;
        unsigned int grade[5];
    } STUDENT;

    int k = 0;

    STUDENT p[students];

    FILE* fileOut;
    fileOut = fopen("Students_grades_Output.txt", "r");

    for (int i = 0; i < students; i++)
    {
        fscanf(fileOut, "%s %d %d %d %d %d %d", &p[i].surname, &p[i].group, &p[i].grade[0], &p[i].grade[1], &p[i].grade[2], &p[i].grade[3], &p[i].grade[4]);
    }

    fclose(fileOut);

    puts("\nStudent's with average grade > 4.0:");
    for (int i = 0; i < students; i++)
    {
        float all_marks = 0;

        for (int j = 0; j < 5; j++)
        {
            all_marks += p[i].grade[j];
        }

        float average_grade = all_marks / 5;

        if (average_grade > 4.0)
        {
            printf("\n   Surname: %s \n", p[i].surname);
            printf("     Group: %ld \n", p[i].group);
            printf(" Avg grade: %.2lf \n", average_grade);
            k++;
        }
    }
    if (k == 0)
    {
        puts("There are no students with average grade > 4.0");
    }
    printf("\n");
}

int num1_txtIn()//записывает с клавиатуры в файл
{
    typedef struct
    {
        char surname[20];
        int group;
        unsigned int grade[5];
    } STUDENT;

    int k = 0;

    STUDENT p[students];

    FILE* fileIn;
    fileIn = fopen("Students_grades_Input.txt", "w");

    for (int i = 0; i < students; i++)
    {
        fprintf(fileIn, "%d)\n", i+1);

        puts("\nEnter student's surname: ");
        scanf("%s", &p[i].surname);
        fprintf(fileIn, "Surname: %s", p[i].surname);

        puts("Enter student's group: ");
        scanf("%ld", &p[i].group);
        fprintf(fileIn, "\nGroup: %d", p[i].group);

        puts("Enter student's grade (1..5): ");

        fprintf(fileIn, "\nGrades:\n\t");
        for (int j = 0; j < 5; j++)
        {
            scanf("%ud", &p[i].grade[j]);

            if (p[i].grade[j] > 5)
                p[i].grade[j] = 5;
            fprintf(fileIn, "  %u", p[i].grade[j]);
        }

        fprintf(fileIn, "\n\n");
    }
    fclose(fileIn);

    puts("\nStudent's with average grade > 4.0:");
    for (int i = 0; i < students; i++)
    {
        float all_marks = 0;

        for (int j = 0; j < 5; j++)
        {
            all_marks += p[i].grade[j];
        }

        float average_grade = all_marks / 5;

        if (average_grade > 4.0)
        {
            printf("\n  Surname: %s \n", p[i].surname);
            printf("     Group: %ld \n", p[i].group);
            printf(" Avg grade: %.2lf \n", average_grade);
            k++;
        }
    }
    if (k == 0)
    {
        puts("There are no students with average grade > 4.0");
    }
    printf("\n");
}

//number 2
int num2()
{
    /*typedef struct
    {
        char surname[20];
        int group;
        int grade[5];
    } STUDENT;

    int k = 0;
    
    STUDENT p[students];
    
    for (int i = 0; i < students; i++)
    {
        puts("\nEnter student's surname: ");
        scanf("%s", &p[i].surname);

        puts("Enter student's group: ");
        scanf("%ld", &p[i].group);

        puts("Enter student's grade (1..5): ");
        for (int j = 0; j < 5; j++)
        {
            scanf("%ld", &p[i].grade[j]);
        }
    }

    puts("\nStudents that have only 4 and 5 grades: ");
    for (int i = 0; i < students; i++)
    {
        float marks = 0;
        for (int j = 0; j < 5; j++)
        {
            if (p[i].grade[j] == 4 || p[i].grade[j] == 5)
            {
                marks = 0;
            }
            else
            {
                marks++;
            }
        }
        if (marks == 0)
        {
            printf("\nSurname: %s \n", p[i].surname);
            printf("Group: %ld \n", p[i].group);
            k++;
        }
    }
    if (k == 0)
    {
        puts("There are no students that have only 4 and 5 grades");
    }
    printf("\n");*/

    typedef struct
    {
        char surname[10];
        int group;
        int grade[5];
    } STUDENT;
    int k = 0;
    STUDENT p[10];
    for (int i = 0; i < students; i++)
    {
        puts("\nEnter your surname: ");
        scanf("%s", &p[i].surname);
        puts("Enter your group: ");
        scanf("%ld", &p[i].group);
        puts("Enter your grade (1..5): ");
        for (int j = 0; j < 5; j++)
        {
            scanf("%ld", &p[i].grade[j]);
        }
    }
    puts("\nStudents with 4 and 5: ");
    for (int i = 0; i < students; i++)
    {
        float marks = 0;
        for (int j = 0; j < 5; j++)
        {
            if (p[i].grade[j] == 4 || p[i].grade[j] == 5)
            {
                if (p[i].grade[j] + p[i].grade[j + 1] + p[i].grade[j + 2] + p[i].grade[j + 3] + p[i].grade[j + 4] != 25 && p[i].grade[j] + p[i].grade[j + 1] + p[i].grade[j + 2] + p[i].grade[j + 3] + p[i].grade[j + 4] != 20)
                {
                    marks++;
                }
            }

        }
        if (marks == 5)
        {
            printf("\nSurname: %s \n", p[i].surname);
            printf("Group: %ld \n", p[i].group);
            k++;
        }
    }
    if (k == 0)
    {
        puts("There are no students with 4 and 5");
    }
}

//number 3
int num3()
{
    typedef struct
    {
        char surname[20];
        int group;
        int grade[5];
    } STUDENT;
    
    int k = 0;
    
    STUDENT p[10];

    for (int i = 0; i < students; i++)
    {
        puts("\nEnter student's surname: ");
        scanf("%s", &p[i].surname);

        puts("Enter student's group: ");
        scanf("%ld", &p[i].group);

        puts("Enter student's grade (1..5): ");
        for (int j = 0; j < 5; j++)
        {
            scanf("%ld", &p[i].grade[j]);
        }
    }
    
    puts("\nStudents that have at least one F grade (2): ");
    for (int i = 0; i < students; i++)
    {
        int fGrade = 0;
        for (int j = 0; j < 5; j++)
        {
            if (p[i].grade[j] == 2)
            {
                fGrade++;
            }
        }
        if (fGrade != 0)
        {
            printf("\nSurname: %s \n", p[i].surname);
            printf("Group: %ld \n", p[i].group);
            k++;
        }
    }
    if (k == 0)
    {
        puts("There are no students that have at least one F grade (2)");
    }
    printf("\n");
}

//numbers 4-5
typedef struct
{
    char destination[30];
    int number;
    char airplane[20];
} AEROFLOT;

#define FLIGHT 4

//number 4
int num4()
{
    AEROFLOT Flight[FLIGHT];
    char ur_fl_d[30];
    int k = 0;

    for (int i = 0; i < FLIGHT; i++)
    {
        puts("\nEnter flight destination: ");
        scanf("%s", &Flight[i].destination);

        puts("Enter flight number: ");
        scanf("%ld", &Flight[i].number);

        puts("Enter type of airplane: ");
        scanf("%s", &Flight[i].airplane);
    }

    puts("\nEnter destination to find available flights: ");
    scanf("%s", &ur_fl_d);

    for (int i = 0; i < FLIGHT; i++)
    {
        char* f1 = Flight[i].destination;
        char* f2 = ur_fl_d;

        if (strcmp(f1, f2) == 0)
        {
            puts("\nThe flight number: ");
            printf("%d", Flight[i].number);

            puts("\nThe type of airplane: ");
            printf("%s", Flight[i].airplane);

            k++;
        }
    }
    if (k == 0)
    {
        puts("There are no flights..");
    }
    printf("\n");
}

//number 5
int num5()
{
    AEROFLOT Flight[FLIGHT];
    char ur_type[30];
    int temp;
    int k = 0;

    for (int i = 0; i < FLIGHT; i++)
    {
        puts("\nEnter flight destination: ");
        scanf("%s", &Flight[i].destination);

        puts("Enter flight number: ");
        scanf("%ld", &Flight[i].number);

        puts("Enter type of airplane: ");
        scanf("%s", &Flight[i].airplane);
    }

    puts("\nEnter type of airplane to find available flights: ");
    scanf("%s", &ur_type);

    for (int i = 0; i < FLIGHT; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (strcmp(Flight[j].destination, Flight[i].destination) > 0)
            {
                AEROFLOT temp = Flight[j];
                Flight[j] = Flight[i];
                Flight[i] = temp;
            }
        }
    }
    for (int i = 0; i < FLIGHT; i++)
    {
        char* f1 = Flight[i].airplane;
        char* f2 = ur_type;

        if (strcmp(f1, f2) == 0)
        {
            puts("\nflight number: ");
            printf("%d", Flight[i].number);

            puts("\nflight destination: ");
            printf("%s", Flight[i].destination);

            k++;
        }
    }
    if (k == 0)
    {
        puts("There are no flights..");
    }
    printf("\n");
}