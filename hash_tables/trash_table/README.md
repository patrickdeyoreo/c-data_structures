# Trash Table

## Binary Search **Tr**_ee_ _+_ _H_**ash** **Table** = **Trash Table**

---

### Concept

The motivation for this data structure was derived from the sorted dictionary used
by the language `PHP`, which simultaneously stores values in a hash table and a doubly linked list. The idea is that by connecting the items in a hash table such that they form a binary search tree, we can reap benefits of both structures.

### Benefits

By combining the `O(k)` time-complexity of retrieval achieved by a hash table, where
`k` represents the cost of resolving a collision, with the `O(log(n))` time-complexity
of insertion achieved by a balanced BST, where `n` is the number of nodes, we get a
sorted hash table with the following operational time-complexity:

* `O(k)` search & retrieval,
* `O(log(n))` insertion & removal

### Implementation

The hash table included here uses chaining to resolve collisions. The chains themselves are singly-linked lists,
although using self-balancing BSTs instead would yield allow for retrieval in `O(log(k))` and may therefore be
preferrable if space is not a limiting factor. The keys are hashed using the `djb2` algorithm, chosen for its
simplicity, as this is merely a proof-of-concept. The BST written here is a red-black tree. An AVL tree would
be a fine choice as well.

### Compilation

To compile the included sample program using `gcc`, run:

`gcc -Wall -Werror -Wextra -pedantic *.c -o`
_`output-filename`_

### Testing

Run `test.sh` to compile the sample program and execute it with a variety of input.

### Things To Do

* Implement removal
* Implement level-order traversal using a queue
* Re-write chaining with BSTs instead of linked lists

---

### Related Projects

- [Binary Trees](https://github.com/patrickdeyoreo/holbertonschool-low_level_programming/tree/master/0x1D-binary_trees)
- [Hash Tables](https://github.com/patrickdeyoreo/holbertonschool-low_level_programming/tree/master/0x1A-hash_tables)


### Authors

- [Patrick DeYoreo](https://github.com/patrickdeyoreo/)
\[[pdeyoreo@gmail.com](mailto:pdeyoreo@gmail.com)\]
