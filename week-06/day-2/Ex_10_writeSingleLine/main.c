#include <stdio.h>
#include <string.h>

// Open a file called "my-file.txt"
// Write your name in it as a single line

int main ()
{
    FILE * f_pointer;
    f_pointer = fopen("my-file.txt", "w");
    fprintf(f_pointer, "Lilla Tóth\n"); //with fprintf

    fputs("Laszlo Fesus\n", f_pointer); //with fputs

    char third_name[] = "Szabo Veikko";
    for (int i = 0; i < sizeof(third_name); i++) {
        fputc(third_name[i], f_pointer);
    }
    fclose(f_pointer);
    return 0;
}