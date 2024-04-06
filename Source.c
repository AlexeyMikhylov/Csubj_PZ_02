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
    default:
        puts("wrong number");
        break;
    }

    run();
}

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

int ex4()
{

}