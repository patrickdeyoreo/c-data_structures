// Testing program for linked list code

#include "ll.h"


int main(int argc, char *argv[])
{
        ll_t *list1 = ll_new(NULL, 0);
        ll_t *list2 = NULL;

        for (int i = 1; i < argc; ++i) {
                ll_append(list1, (int) strtol(argv[i], (char **) NULL, 10));
                ll_print(list1);
        }

        list2 = ll_copy(list1);
        ll_print(list2);

        ll_reverse(list2);
        ll_print(list2);

        ll_extend(list1, list2);
        ll_print(list1);

        ll_insert(list1, 0, 1234);
        ll_print(list1);

        printf("Counting %d's: %d found\n", 2, ll_count(list1, 2));

        printf("Removing %d...\n", 2);
        ll_remove(list1, 2);
        ll_print(list1);

        printf("Popping first item: %d\n", ll_pop(list1, 0));
        ll_print(list1);

        ll_clear(list1);
        ll_clear(list2);

        free(list1);
        free(list2);

        return 0;
}
