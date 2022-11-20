#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    unsigned int address;
    unsigned int page_number;
    unsigned int offset;

    if(argc<2) {
        printf("Enter the address: ");
        return -1;
    }

    address = atoi(argv[1]);
    page_number = address / 4096;
    offset = address % 4096;

    printf("The address = %u\n Page number = %u \noffset = %u\n", address, page_number, offset);

    return 0;
}