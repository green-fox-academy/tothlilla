#include<stdio.h>

int main()
{
    // Modify this program to greet you instead of the World!
    //char name[50] = "Lilla Toth"; //csak az első 11 karakter helyére ír, amiből a 11. egy zárókarakter
    //char name[11] = "Lilla Toth"; //11-nek kell lennie a tömbnek a zárókarakter miatt
    char name[] = "Lilla Toth"; //másik megadási mód, ilyenkor automatikus a méretezés
    printf("Hello, %s!", name);

    return 0;
}