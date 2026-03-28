<h1 align="center">get_next_line</h1>

<p align="center">
  Lire un descripteur de fichier ligne par ligne en C, avec une gestion explicite du buffer et de la mémoire.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/School-42-black?style=for-the-badge" alt="42 badge" />
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge" alt="Language badge" />
  <img src="https://img.shields.io/badge/Status-Mandatory%20OK%20%2F%20Bonus%20to%20fix-yellow?style=for-the-badge" alt="Status badge" />
</p>

<p align="center">
  <strong>file descriptor, static buffer, line-by-line reading, dynamic allocation, 42 project</strong>
</p>

---

## 📌 Overview

If you want to study how a C function can read a file one line at a time, this repository gives you a compact implementation of `get_next_line`.

The mandatory part reads from a file descriptor, stores unread data in a static buffer, returns one line per call, and handles the last line even when it does not end with `\n`.

This project focuses on:
- reading from a file descriptor with `read`
- keeping state between function calls with a static variable
- building strings dynamically as data arrives
- separating the extracted line from the remaining unread content

---

## ✨ Features

- ✅ Read one line at a time from a file descriptor
- ✅ Keep unread data between calls in a static buffer
- ✅ Change the read chunk size with `BUFFER_SIZE`
- ✅ Return lines including the trailing `\n` when present
- ✅ Mandatory sources compile with `-Wall -Wextra -Werror`
- ⚠️ Bonus source files are present, but the current bonus compilation still needs a fix before use

---

## 🧠 Concepts Covered

If you read or test this project, you will work with the following concepts:

- static storage duration
- file descriptors
- dynamic memory allocation
- string concatenation without `libft`
- newline detection and line extraction
- end-of-file handling

---

## 🛠️ Build

Clone the repository:

```bash
git clone git@github.com:Middle-555/get_next_line.git
cd get_next_line
```

This repository does not currently include a `Makefile` or a ready-to-run tester. To compile the mandatory part, add your own `main.c` test file and build it manually:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl_test
```

To try other buffer sizes:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c -o gnl_test
cc -Wall -Wextra -Werror -D BUFFER_SIZE=999 main.c get_next_line.c get_next_line_utils.c -o gnl_test
```

If you want to test the bonus version, note that the current `get_next_line_bonus.c` does not compile as-is and needs a correction first.

---

## 🚀 Usage

Run your tester with:

```bash
./gnl_test
```

### Minimal example

If you want a quick local tester, you can use a `main.c` like this:

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("fichier.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

### Examples

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl_test && ./gnl_test
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c -o gnl_test && ./gnl_test
cc -Wall -Wextra -Werror -D BUFFER_SIZE=999 main.c get_next_line.c get_next_line_utils.c -o gnl_test && ./gnl_test
```

The repository already includes `fichier.txt`, which can be used as a simple input file for local tests.

---

## 📂 Project Structure

```text
.
├── fichier.txt
├── get_next_line.c
├── get_next_line.h
├── get_next_line_bonus.c
├── get_next_line_bonus.h
├── get_next_line_utils.c
├── get_next_line_utils_bonus.c
├── template.md
└── README.md
```

### Structure Details

- `get_next_line.c` : mandatory implementation of the line-reading logic
- `get_next_line_utils.c` : helper functions for strings, zeroing, and allocation
- `get_next_line.h` : declarations and `BUFFER_SIZE` configuration
- `get_next_line_bonus.c` : bonus attempt for multiple file descriptors
- `get_next_line_utils_bonus.c` : helper functions used by the bonus part
- `fichier.txt` : small sample file used for local tests

---

## ⚙️ Project Constraints

This repository is centered on the classic 42 `get_next_line` exercise:
- written in C
- reads from a file descriptor with `read`
- uses dynamic allocation with `malloc` and cleanup with `free`
- keeps unread content between calls with static storage
- reimplements the small helper utilities needed by the function

---

## 🧪 Testing

The current repository was checked with the following approach:
- mandatory compilation with `-Wall -Wextra -Werror`
- execution on the provided `fichier.txt`
- execution with `BUFFER_SIZE=1`
- execution with `BUFFER_SIZE=999`
- bonus compilation check, which currently fails

### Manual test examples

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl_test && ./gnl_test
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c -o gnl_test && ./gnl_test
cc -Wall -Wextra -Werror -D BUFFER_SIZE=999 main.c get_next_line.c get_next_line_utils.c -o gnl_test && ./gnl_test
```

### Memory checks

```bash
valgrind --leak-check=full --show-leak-kinds=all ./gnl_test
```

---

## 📖 What You Can Learn Here

If you study this repository, you can reinforce the following skills:
- structuring a function around a persistent internal state
- cutting a growing buffer into a returned line and a saved remainder
- handling partial reads and end-of-file cases
- testing the same logic with different `BUFFER_SIZE` values

---

## 🚧 Possible Improvements

Although the mandatory part compiles and runs, several improvements are still possible:
- add a `Makefile` for standard 42 build targets
- add a dedicated test folder with several input files
- document expected behavior for invalid file descriptors and edge cases

---

## 👤 Author

Kevin Pourcel
42 student

<p>
  <a href="https://github.com/Middle-555">GitHub</a>
</p>
