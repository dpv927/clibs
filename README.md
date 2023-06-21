## Content
Data Structures:
  - <a href="https://github.com/dpv927/clibs/tree/main/LinkedList">Linked List<a>
  - <a href="https://github.com/dpv927/clibs/tree/main/Queue">Queue<a>
  - <a href="https://github.com/dpv927/clibs/tree/main/ArrayList">ArrayList (In Progress)<a>
  
 ## Doucumentation
All the code is well-documented, both in the .c and .h files of the project and in the repository's <a href="https://dpv927.github.io/clibs-docs/">Wiki</a>. It is recommended to visit the Wiki as it provides usage examples, tips, and some implementation details.

## Testing
For each 'library' in this repository, a set of tests is available so that any user can verify their proper functionality. These tests are located in the same directory as the `.h` files, in a directory called `tests/`
  
To run those tests, you first have to compile them and the run the generated executable:
```bash
# You can do it all with Make
make clean test
