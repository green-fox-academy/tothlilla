#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} notebook_t;

int main()
{
    struct computer lilla_computer;
    lilla_computer.cpu_speed_GHz = 6.50;
    lilla_computer.ram_size_GB = 500;
    lilla_computer.bits = 64;

    notebook_t laci_notebook;
    laci_notebook.cpu_speed_GHz = 5.50;
    laci_notebook.ram_size_GB = 450;
    laci_notebook.bits = 64;

    printf("Lilla's computer data: cpu speed %.2f GHz, ram size %d GB and it is %d bits.\n",
        lilla_computer.cpu_speed_GHz, lilla_computer.ram_size_GB, lilla_computer.bits);
    printf("Laci's notebook data: cpu speed %.2f GHz, ram size %d GB and it is %d bits.",
        laci_notebook.cpu_speed_GHz, laci_notebook.ram_size_GB, laci_notebook.bits);

    return 0;
}