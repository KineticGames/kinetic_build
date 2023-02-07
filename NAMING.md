# Naming Convention

## Capitalization

|                    | naming               | example                                   |
|--------------------|----------------------|-------------------------------------------|
| typedef            | PascalCase           | `typedef void TypeName;`                  |
| struct             | snake_case_t         | `struct struct_name_t {};`                |
| function           | snake_case           | `void function_name(int parameter_name);` |
| function parameter | snake_case           | `void function_name(int parameter_name);` |
| global variable    | g_snake_case         | `extern int g_global_name;`               |
| local variable     | snake_case           | `int g_global_name = 0;`                  |
| define             | SCREAMING_SNAKE_CASE | `#define DEFINE_NAME`                     |

## Common Words

| word     | usage                                                 |
|----------|-------------------------------------------------------|
| array    | array of data                                         |
| type     | usually used for enums                                |
| node     | links to other nodes e.g. in a linked list            |
| handle   | pointer to opaque data structure                      |
| func / f | function pointer or function used as function pointer |

## Function names

A function in the public API should have the following format: `<module>_<object>_<action>`

The action should be descriptive, the caller should be able to know what the function does from the name alone.

Use complete words, except in cases where the abbreviation is more canonical.

#### Right:

```c
size_t character_size;
size_t length;
short tab_index; // More canonical.
```

#### Wrong:

```c
size_t char_size;
size_t len;
short tabulation_index; // Goofy.
```
