#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

void complex_summ(complex* cnumber1, complex* cnumber2)
{
    cnumber1->real= cnumber1->real + cnumber2->real;
    cnumber1->img = cnumber1->img + cnumber2->img;
}

void complex_diff(complex* cnumber1, complex* cnumber2)
{
    cnumber1->real= cnumber1->real - cnumber2->real;
    cnumber1->img = cnumber1->img - cnumber2->img;
}

void complex_multip(complex* cnumber1, complex* cnumber2)
{
    float creal1 = cnumber1->real;
    cnumber1->real = (cnumber1->real * cnumber2->real ) - (cnumber1->img * cnumber2->img );
    cnumber1->img = (cnumber1->img * cnumber2->real ) + (cnumber2->img * creal1 );
}

list* create_list(int number_of_elements, int flag, int mode) //создает список с коэффициентами
{
    list *Head = (list *)malloc(sizeof(list));
    list *head = Head;
    list *temp;
    printf("Введите коэффициенты линеной формы\n");
    if (flag == 1)
    {
        for (int i = 0; i < number_of_elements; i++)
        {
            complex *head_coeff = &head->coeff;
            scanf("%f", &head_coeff->real);
            if (mode == 2)
                printf("%.0f ", head_coeff->real);
            head->next =(list *)malloc(sizeof(list));
            temp = head;
            head = head->next;
            head->prev = temp;
        }
    }
    if (flag == 2)
    {
        for (int i = 0; i < number_of_elements; i++)
        {
            complex *head_coeff = &head->coeff;
            scanf("%f %f", &head_coeff->real, &head_coeff->img);
            if (mode == 2)
                printf("%.0f+i%.0f ", head_coeff->real, head_coeff->img);
            head->next =(list *)malloc(sizeof(list));
            temp = head;
            head = head->next;
            head->prev = temp;
        }
    }
    return Head;
}


list* multiplication_by_a_constant(int number_of_elements, int flag, int mode)
{
    list *Head = create_list(number_of_elements, flag, mode);
    printf("\nВведите константу\n");
    if (flag == 1)
    {
        float const_real;
        scanf("%f", &const_real);
        if (mode == 2)
            printf("%0.f", const_real);
        list *head = Head;
        for (int i = 0; i < number_of_elements; i++)
        {
            complex *head_coeff = &head->coeff;
            head_coeff->real = head_coeff->real * const_real;
            head = head->next;
        }
    }
    if (flag == 2)
    {
        complex constanta;
        scanf("%f %f", &constanta.real, &constanta.img);
        if (mode == 2)
            printf("%.0f+i%.0f", constanta.real, constanta.img);
        list *head = Head;
        for (int i = 0; i < number_of_elements; i++)
        {
            complex *head_coeff = &head->coeff;
            complex_multip(head_coeff, &constanta);
            head = head->next;
        }
    }
    return Head;
}

list *summ_coeff(int number_of_elements, int flag, int mode)
{
    printf("Создание первое линейной формы...\n");
    list *Head_1 = create_list(number_of_elements, flag, mode);
    list *head_1 = Head_1;
    printf("\nСоздание второй линейной формы...\n");
    list *Head_2 = create_list(number_of_elements, flag, mode);
    list *head_2 = Head_2;
    if (flag == 1)
    {
        for (int i = 0; i < number_of_elements; i++)
        {
            complex *head_1_coeff = &head_1->coeff;
            complex *head_2_coeff = &head_2->coeff;
            head_1_coeff->real = head_1_coeff->real + head_2_coeff->real;
            head_1 = head_1->next;
            head_2 = head_2->next;
        }
    }
    if (flag == 2)
    {
        for (int i = 0; i < number_of_elements; i++)
        {
            complex *head_1_coeff = &head_1->coeff;
            complex *head_2_coeff = &head_2->coeff;
            complex_summ(head_1_coeff, head_2_coeff);
            head_1 = head_1->next;
            head_2 = head_2->next;
        }
    }
    return Head_1;
}

list *diff_coeff(int number_of_elements, int flag, int mode)
{
    printf("Создание первое линейной формы...\n");
    list *Head_1 = create_list(number_of_elements, flag, mode);
    list *head_1 = Head_1;
    printf("\nСоздание второй линейной формы...\n");
    list *Head_2 = create_list(number_of_elements, flag, mode);
    list *head_2 = Head_2;
    if (flag == 1)
    {
        for (int i = 0; i < number_of_elements; i++)
        {
            complex *head_1_coeff = &head_1->coeff;
            complex *head_2_coeff = &head_2->coeff;
            head_1_coeff->real = head_1_coeff->real - head_2_coeff->real;
            head_1 = head_1->next;
            head_2 = head_2->next;
        }
    }
    if (flag == 2)
    {
        for (int i = 0; i < number_of_elements; i++)
        {
            complex *head_1_coeff = &head_1->coeff;
            complex *head_2_coeff = &head_2->coeff;
            complex_diff(head_1_coeff, head_2_coeff);
            head_1 = head_1->next;
            head_2 = head_2->next;
        }
    }
    return Head_1;
}


list *function_of_line_form(list *Head, int number_of_elements, int flag, int mode)
{
    list *head = Head;
    printf("\nВведите значения координат\n");
    if (flag == 1)
    {
        for (int i = 0; i < number_of_elements; i++)
        {
            complex *head_coord = &head->coord;
            scanf("%f", &head_coord->real);
            if (mode == 2)
                printf("%.0f ", head_coord->real);
            head = head->next;
        }
    }
    if (flag == 2)
    {
        for (int i = 0; i < number_of_elements; i++)
        {
            complex *head_coord = &head->coord;
            scanf("%f %f", &head_coord->real, &head_coord->img);
            if (mode == 2)
                printf("%.0f+i%.0f ", head_coord->real, head_coord->img);
            head = head->next;
        }
    }
    return Head;
}

void print_list(list *Head, int number_of_elements, int flag)
{
    list *head = Head;
    printf("\nF = ");
    if (flag == 1)
    {
        for (int i = 0; i < number_of_elements; i++)
        {
            complex *head_coeff = &head->coeff;
            printf("%.0f%c%d ", head_coeff->real, 'x', i);
            head = head->next;
        }
    }
    if (flag == 2)
    {
        for (int i = 0; i < number_of_elements; i++)
        {
            complex *head_coeff = &head->coeff;
            printf("(%.0f+i%.0f)%c%d ", head_coeff->real, head_coeff->img, 'x', i);
            head = head->next;
        }

    }
    printf("\n");
}

void print_function(list *Head, int number_of_elements, int flag)
{
    list *head = Head;
    printf("\nF = ");
    if (flag == 1)
    {
        float value_function = 0;
        for (int i = 0; i < number_of_elements; i++)
        {
            complex *head_coeff = &head->coeff;
            complex *head_coord = &head->coord;
            printf("%.0f%c%.0f ", head_coeff->real, '&', head_coord->real);
            value_function = head_coeff->real * head_coord->real + value_function;
            head = head->next;
        }
        printf("\nЗначение функции = %0.f\n", value_function);
    }
    if (flag == 2)
    {
        complex value_function;
        value_function.real = 0;
        value_function.img = 0;
        for (int i = 0; i < number_of_elements; i++)
        {
            complex *head_coeff = &head->coeff;
            complex *head_coord = &head->coord;
            printf("(%.0f+i%.0f)%c(%.0f+i%.0f) ", head_coeff->real, head_coeff->img, '&', head_coord->real, head_coord->img);
            complex_multip(head_coord, head_coeff);
            complex_summ(&value_function, head_coord);
            head = head->next;
        }
        printf("\nЗначение функции = %0.f+i%0.f\n", value_function.real, value_function.img);

    }
}

void comparison(list *Head, int number_of_elements, int flag)
{
    list *head = Head;
    int result = 0;
    float arr[number_of_elements];
    if (flag == 1)
        for (int i = 0; i < number_of_elements; i++)
            scanf("%f", &arr[i]);
    if (flag == 2)
        for (int i = 0; i < number_of_elements * 2; i++)
            scanf("%f", &arr[i]);
    if (flag == 1)
        for (int i = 0; i < number_of_elements; i++)
        {
            complex *head_coeff = &head->coeff;
            if (arr[i] != head_coeff->real)
                result = 1;
            head = head->next;
        }
    if (flag == 2)
        for (int i = 0; i < number_of_elements * 2; i = i + 2)
        {
            complex *head_coeff = &head->coeff;
            if (arr[i] != head_coeff->real || arr[i+1] != head_coeff->img)
            {
                result = 1;
            }
            head = head->next;
        }
    if (result == 0)
    {
        if (flag == 1)
        {
            float value_of_function_real;
            scanf("%f", &value_of_function_real);
            printf("Верное значение функции F = %.0f\n", value_of_function_real);
        }
        if (flag == 2)
        {
            complex value_of_function;
            scanf("%f%f", &value_of_function.real, &value_of_function.img);
            printf("Верное значение функции F = %.0f+i%.0f\n", value_of_function.real, value_of_function.img);
        }
        printf("Значения равны. Верно\n");
    }
        else
        {
            if (flag == 1)
            {
                float value_of_function_real;
                scanf("%f", &value_of_function_real);
                printf("Верное значение функции F = %.0f\n", value_of_function_real);
            }
            if (flag == 2)
            {
                complex value_of_function;
                scanf("%f%f", &value_of_function.real, &value_of_function.img);
                printf("Верное значение функции F = %.0f+i%.0f\n", value_of_function.real, value_of_function.img);
            }
            printf("Неверно\n");
        }

}

void program_exit()
{
    printf("Для выхода из программы нажмите \"пробел\", чтобы продолжить нажмите любую другую клавишу.\n" );
    char button = getch();
    if (button == 32)
    {
        exit(0);
    }
    freopen("CONIN$", "r", stdin); //перенапраляет поток ввода обратно в консоль
    main();
}

void user(int mode)
{
    printf("Выбирите тип данных\n");
    printf("1. Целые числа\n");
    printf("2. Комплексные числа\n");
    int flag;
    scanf("%d", &flag);
    if (flag != 1 && flag != 2)
        program_exit();
    printf("Выбирите необходимую операцию:\n");
    printf("1. Умножение на константу\n");
    printf("2. Сумма двух линейных форм\n");
    printf("3. Разность двух линейных форм\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Введите количество элементов\n");
        int number_of_elements;
        scanf("%d", &number_of_elements);
        list *Head = multiplication_by_a_constant(number_of_elements, flag, mode);
        print_list(Head, number_of_elements, flag);
        printf("Получить значение функции\n");
        printf("1. Да\n");
        printf("2. Нет\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            Head = function_of_line_form(Head, number_of_elements, flag, mode);
            print_function(Head, number_of_elements, flag);
            program_exit();
        }
            else
                program_exit();

    }
    else
        if (choice == 2)
        {
            printf("Введите количество элементов\n");
            int number_of_elements;
            scanf("%d", &number_of_elements);
            list *Head = summ_coeff(number_of_elements, flag, mode);
            print_list(Head, number_of_elements, flag);
            printf("Получить значение функции\n");
            printf("1. Да\n");
            printf("2. Нет\n");
            scanf("%d", &choice);
            if (choice == 1)
            {
                Head = function_of_line_form(Head, number_of_elements, flag, mode);
                print_function(Head, number_of_elements, flag);
                program_exit();
            }
                else
                    program_exit();
        }
        else
            if (choice == 3)
            {
                printf("Введите количество элементов\n");
                int number_of_elements;
                scanf("%d", &number_of_elements);
                list *Head = diff_coeff(number_of_elements, flag, mode);
                print_list(Head, number_of_elements, flag);
                printf("Получить значение функции\n");
                printf("1. Да\n");
                printf("2. Нет\n");
                scanf("%d", &choice);
                if (choice == 1)
                {
                    Head = function_of_line_form(Head, number_of_elements, flag, mode);
                    print_function(Head, number_of_elements, flag);
                    program_exit();
                }
                    else
                        program_exit();
            }
            else
                program_exit();
}

void test(int mode)
{
    printf("Выбирите необходимую операцию:\n");
    printf("1. Умножение на константу\n");
    printf("2. Сумма двух линейных форм\n");
    printf("3. Разность двух линейных форм\n");
    int choice;
    scanf("%d", &choice);
    if (choice != 1 && choice != 2 && choice != 3)
        program_exit();
    printf("Выбирите тип данных\n");
    printf("1. Целые числа\n");
    printf("2. Комплексные числа\n");
    int flag;
    scanf("%d", &flag);
    if (flag != 1 && flag != 2)
        program_exit();
    if (choice == 1)
    {
        if (flag == 1)
        {
            freopen("test/input_const_mult_real.txt", "r", stdin);
            int number_of_elements;
            scanf("%d", &number_of_elements);
            list *Head = multiplication_by_a_constant(number_of_elements, flag, mode);
            Head = function_of_line_form(Head, number_of_elements, flag, mode);
            print_function(Head, number_of_elements, flag);
            freopen("test/output_const_mult_real.txt", "r", stdin);
            comparison(Head, number_of_elements, flag);
            program_exit();
            main();
        }
        if (flag == 2)
        {
            freopen("test/input_const_mult_complex.txt", "r", stdin);
            int number_of_elements;
            scanf("%d", &number_of_elements);
            list *Head = multiplication_by_a_constant(number_of_elements, flag, mode);
            Head = function_of_line_form(Head, number_of_elements, flag, mode);
            print_function(Head, number_of_elements, flag);
            freopen("test/output_const_mult_complex.txt", "r", stdin);
            comparison(Head, number_of_elements, flag);
            program_exit();
            main();
        }
    }
    if (choice == 2)
    {
        if (flag == 1)
        {
            freopen("test/input_summ_real.txt", "r", stdin);
            int number_of_elements;
            scanf("%d", &number_of_elements);
            list *Head = summ_coeff(number_of_elements, flag, mode);
            Head = function_of_line_form(Head, number_of_elements, flag, mode);
            print_function(Head, number_of_elements, flag);
            freopen("test/output_summ_real.txt", "r", stdin);
            comparison(Head, number_of_elements, flag);
            program_exit();
            main();
        }
        if (flag == 2)
        {
            freopen("test/input_summ_complex.txt", "r", stdin);
            int number_of_elements;
            scanf("%d", &number_of_elements);
            list *Head = summ_coeff(number_of_elements, flag, mode);
            Head = function_of_line_form(Head, number_of_elements, flag, mode);
            print_function(Head, number_of_elements, flag);
            freopen("test/output_summ_complex.txt", "r", stdin);
            comparison(Head, number_of_elements, flag);
            program_exit();
            main();
        }
    }
    if (choice == 3)
    {
        if (flag == 1)
        {
            freopen("test/input_diff_real.txt", "r", stdin);
            int number_of_elements;
            scanf("%d", &number_of_elements);
            list *Head = diff_coeff(number_of_elements, flag, mode);
            Head = function_of_line_form(Head, number_of_elements, flag, mode);
            print_function(Head, number_of_elements, flag);
            freopen("test/output_diff_real.txt", "r", stdin);
            comparison(Head, number_of_elements, flag);
            program_exit();
            main();
        }
        if (flag == 2)
        {
            freopen("test/input_diff_complex.txt", "r", stdin);
            int number_of_elements;
            scanf("%d", &number_of_elements);
            list *Head = diff_coeff(number_of_elements, flag, mode);
            Head = function_of_line_form(Head, number_of_elements, flag, mode);
            print_function(Head, number_of_elements, flag);
            freopen("test/output_diff_complex.txt", "r", stdin);
            comparison(Head, number_of_elements, flag);
            program_exit();
            main();
        }
    }
}

void main()
{
    system("chcp 1251");
    system("cls"); //Включает русский язык
    printf("Выберите режим работы\n");
    printf("1. Пользователь\n");
    printf("2. Разработчик\n");
    int mode;
    scanf("%d", &mode);
    if (mode == 1)
        user(mode);
        else
            if (mode == 2)
                test(mode);
                else
                    program_exit();
}
