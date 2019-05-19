typedef struct complex
{
    float real, img;
} complex;

typedef struct list
{
    complex coeff, coord;
    struct list *prev, *next;
} list;

void complex_summ(complex* cnumber1, complex* cnumber2);

void complex_diff(complex* cnumber1, complex* cnumber2);

void complex_multip(complex* cnumber1, complex* cnumber2);

list* create_list(int number_of_elements, int flag, int mode);

list* multiplication_by_a_constant(int number_of_elements, int flag, int mode);

list *summ_coeff(int number_of_elements, int flag, int mode);

list *diff_coeff(int number_of_elements, int flag, int mode);

list *function_of_line_form(list *Head, int number_of_elements, int flag, int mode);

void print_list(list *Head, int number_of_elements, int flag);

void print_function(list *Head, int number_of_elements, int flag);

void comparison(list *Head, int number_of_elements, int flag);

void program_exit();

void user(int mode);

void test(int mode);

void main();
