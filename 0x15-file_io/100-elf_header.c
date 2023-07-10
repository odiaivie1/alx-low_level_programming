#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unstd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic (unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - Checks if file is ELF file
 * @e_ident: A ponter to array with ELf number
 * Description: If the file is not a ELF file, exit code 98
 */
void check_elf(unsigned char *e_ident)
{
	int line;

	for (line = 0; line < 4; line++)
	{
		if (e_ident[line] != 127 &&
				e_ident[line] != 'E' &&
				e_ident[line] != 'L' &&
				e_ident[line] != 'F')
		{
			dprintf(STDERR_FILENO, " Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - A function that prints ELF header number
 * @e_ident: A pointer that contains the ELF number
 * Decription: The magic numbers are separated by spaces
 */
void print_magic(unsigned char *e_ident)
{
	int line;

	print(" Magic: ");

	for (line = 0; line < EI_NIDENT; line++)
	{
		printf("%02x", e_ident[line]);

		if (line == EI_NIDENT -1)
			printf("\n");
	else 
		printf(" ");
	}

}
/** print_class - Prints ELF class
 * @e_ident: A pointer to array with ELF class
 */
void print_class(unsigned char *e_ident)
{
	printf(" Class:
