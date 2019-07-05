// Testing program for linked list code

#include "ll.h"
#include <stdio.h>


int main(int argc, char *argv[])
{
        ll_t list_A;
        ll_t list_B;

	printf("Creating lists...\n");
	list_A = ll_new();
        list_B = ll_new();

        for (int i = 1; i < argc; ++i) {
		printf("\nAppending to list A...\n");
                ll_append(&list_A, strtol(argv[i], NULL, 10));
		printf("list A: ");
                ll_print(list_A);
        }

	printf("\nCopying list A to list B...\n");
        ll_copy(&list_B, list_A);
	printf("list B: ");
        ll_print(list_B);

	printf("\nReversing list B...\n");
        ll_reverse(&list_B);
	printf("list B: ");
        ll_print(list_B);

	printf("\nAppending list B to list A...\n");
        ll_extend(&list_A, list_B);
	printf("list A: ");
        ll_print(list_A);

	printf("\nInserting '42' into list A at index '-1'...\n");
        ll_insert(&list_A, -1, 42);
	printf("list A: ");
        ll_print(list_A);

        printf("\nCounting number of %d's in list A...\n", 2);
	printf("%d found\n", ll_count(list_A, 2));

        printf("\nRemoving first %d from list A...\n", 2);
        ll_remove(&list_A, 2);
	printf("list A: ");
        ll_print(list_A);

        printf("\nPopping first item from list A...\n");
	printf("'%d' popped\n", ll_pop(&list_A, 0));
	printf("list A: ");
        ll_print(list_A);

        printf("\nClearing lists...\n");
        ll_clear(&list_A);
        ll_clear(&list_B);

	printf("list A: ");
        ll_print(list_A);
	printf("list B: ");
        ll_print(list_B);

        printf("\nDone.\n");

        return 0;
}
