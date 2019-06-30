// Testing program for linked list code

#include "ll.h"
#include <stdio.h>


int main(int argc, char *argv[])
{
        ll_t *list_1 = NULL;
        ll_t *list_2 = NULL;

	printf("Creating list1...\n");
        list_1 = ll_new();

        for (int i = 1; i < argc; ++i) {
		printf("Appending to list1...\n");
                ll_append(list_1, strtol(argv[i], NULL, 10));
                ll_print(list_1);
        }

	printf("Copying list1 to list2...\n");
        list_2 = ll_copy(list_1);
        ll_print(list_2);

	printf("Reversing list2...\n");
        ll_reverse(list_2);
        ll_print(list_2);

	printf("Extending list1 with list2...\n");
        ll_extend(list_1, list_2);
        ll_print(list_1);

	printf("Inserting '42' into list1 at index '-1'...\n");
        ll_insert(list_1, -1, 42);
        ll_print(list_1);

        printf("Counting number of %d's in list1...\n", 2);
	printf("%d found\n", ll_count(list_1, 2));

        printf("Removing first %d from list1...\n", 2);
        ll_remove(list_1, 2);
        ll_print(list_1);

        printf("Popping first item from list1...\n");
	printf("%d popped\n", ll_pop(list_1, 0));
        ll_print(list_1);

        printf("Clearing lists...\n");
        ll_clear(list_1);
        ll_clear(list_2);

        printf("Freeing lists...\n");
        free(list_1);
        free(list_2);

        return 0;
}
