# Simple Shell

This is a simple shell program written in C. It allows you to execute shell commands, set and unset environment variables, and exit the shell. The shell provides a basic command-line interface for interacting with your system.

## Requirements
- Ubuntu 20.04 LTS
- GCC with options: -Wall -Werror -Wextra -pedantic -std=gnu89
- C Standard Library

## How to Use

1. **Compilation**:

    To compile the shell, use the following command:
    ```shell
    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
    ```

2. **Running the Shell**:

    To run the shell, execute the compiled binary:
    ```shell
    ./hsh
    ```

3. **Shell Commands**:

    The shell supports the following commands:
    - Shell commands (e.g., `ls`, `pwd`)
    - Set environment variables (e.g., `setenv VARIABLE VALUE`)
    - Unset environment variables (e.g., `unsetenv VARIABLE`)
    - Exit the shell (e.g., `exit` or `exit STATUS`)

## Authors

- [Ayoub882](https://github.com/Ayoub882)
- [Mourad Tiferras](https://github.com/M0R4D-Tiferras-self-learning-account)

## License

:)|(:
