# Trash Table

### Concept

A trash table is a sorted dictionary implemented by connecting the items in a hash table with a binary search tree,
hence the name (i.e. TRee + HASH Table -> Trash Table). By combining these data structures, we reap benefits of both.

### Benefits

By combining the efficiency of retrieval achieved by a hash table (where `k` represents the cost of travesing a chain) with
the efficiency of insertion achieved by a balanced BST, we get a sorted hash table with the following operational efficiency:
- `O(k)` search & retrieval
- `O(log(n))` insertion & removal

### Implementation

The hash table included here uses chaining to resolve collisions. The chains themselves are singly-linked lists, however
using self-balancing BSTs would yield `O(log(k))` retrieval and may therefore be preferrable if space is not a limiting
factor. The keys are hashed using the `djb2` algorithm, chosen for its simplicity, as this is merely a proof-of-concept.
Lastly, the BST is implemented as a red-black tree. Ann AVL tree would also be a fine choice.

### Compilation

To compile the files in this directory using `gcc`, run:

```gcc -Wall -Werror -Wextra -pedantic *.c -o ```_`name-of-executable`_

### To-Do

- Implement removal
- Implement level-order traversal using a queue
- Re-write chaining with BSTs instead of linked lists

### Authors

- __[Patrick DeYoreo](https://github.com/patrickdeyoreo/)__ <pdeyoreo@gmail.com>

### Related Projects

- [Binary Trees](https://github.com/patrickdeyoreo/holbertonschool-low_level_programming/tree/master/0x1D-binary_trees)
- [Hash Tables](https://github.com/patrickdeyoreo/holbertonschool-low_level_programming/tree/master/0x1A-hash_tables)
