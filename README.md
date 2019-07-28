# libftASM 🛠

Intel x86_64 assembly implementation of some C standard library functions. (For macOS and 64-bit linux systems.) A project for École 42.

## Building the library

```bash
git clone https://github.com/Failte21/libftasm <directory>
cd <directory>
make
```

## Usage

In source files in the root of the cloned repository:
```C
# include "inc/libfts.h"
```

## Test

```bash
libtasm$ sh test.sh [-v|--verbose]
```

## Cleanup

```bash
libtasm$ make fclean
```
