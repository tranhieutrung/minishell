# Minishell - 42 School Project
This project is a simple shell implementation inspired by bash. It was developed as part of the 42 School curriculum, and the goal is to recreate a basic shell with both mandatory and bonus features, supporting a range of built-in functions, shell operations, and complex shell structures.

# Authors
Tran Hieu Trung (https://github.com/tranhieutrung)<br>
Kha Tieu (https://github.com/tdkha)

# Description
The Minishell project implements a minimalistic shell that executes commands from the command line. It supports built-in functions and various shell operations, with the ability to parse, validate, and execute complex commands with various operators and redirections.

# Features
- Basic built-ins: cd, echo, env, exit, export, pwd, unset.
- Supports shell operations: piping (|), logical AND (&&), logical OR (||)always correctly handled, whether or not parentheses are used.
- Supports redirections (<, >, << and >>).
- Command expansion and wildcard handling ($, *, ?).
- Error handling: resolves ambiguous redirection, shell level tracking, and last command execution.
- Unlimited pipe and file descriptor support: No restrictions on the number of pipes or file descriptors.

## Parsing and Syntax
- Tokenization: The command line is split into tokens, categorized into operators, parentheses, commands, and redirection.
- Syntax Checking: After parsing, the syntax is verified, and any issues (e.g., unmatched parentheses or operators) are flagged.
- Expansion and Wildcards: Tokens are expanded and wildcards are resolved before execution.
- AST (Abstract Syntax Tree)
- Execution: Once the command is parsed and tokenized, an Abstract Syntax Tree (AST) is created. This tree is used for execution, where the left side of the tree is executed first, followed by the right side if needed.

## Execution Flow
- Commands are executed by traversing the AST. Built-in functions are handled by checking if the command is a valid built-in or needs to be executed via execve.
- For logical operators (&&, ||), the execution flow respects their priority, ensuring correct command execution based on the success or failure of the previous command.

## Edge Cases Handled
- Multiple Shell Instances: The shell tracks shell level accurately when invoking minishell inside itself (like bash).
- Ambiguous Redirection: Handled cases where redirection is used in combination with expansion and wildcards.
- Last Command in env: Properly handles the last command in the environment, ensuring it is executed correctly.
- Expansion and Wildcards in Heredoc: Handles expansion and wildcard characters inside heredoc.
- Priority for AND and OR Operators: Correctly evaluates the priority of && and || operators, with or without parentheses.
- "cd .." in Deleted Directory: Handles the cd .. command even when the parent directory has been deleted.

# Requirements
Linux OS (Ubuntu preferred)

# Usage
```bash
git clone https://github.com/tranhieutrung/minishell.git
cd minishell
make
./minishell
```

To exit the shell, type exit.

![Usage GIF](https://github.com/tranhieutrung/minishell/blob/main/minishell_usage.gif)

# Conclusion
The Minishell project replicates the essential behavior of a Unix shell, including various built-in functions and shell operations. It provides a solid understanding of how a shell works and the complexities of parsing and executing shell commands. The project also demonstrates error handling, edge case management, and how to build a custom shell environment with advanced features.

# Result:
125% completion rate, with full implementation of mandatory features and bonus tasks. 🎉

![Result](https://github.com/tranhieutrung/minishell/blob/main/minishell_result.png)