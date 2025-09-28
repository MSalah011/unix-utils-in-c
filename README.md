# Unix Utilities in C  

Re-implementing classic Unix commands in **C** for learning purposes.  
This repository contains simplified versions of the following commands:  

- **pwd** → Print working directory  
- **echo** → Print a string to standard output  
- **cp** → Copy a file to a new location  
- **mv** → Move (or rename) a file
- **cat** → Display the contents of a file

---

## ⚙️ Compilation  

You can compile each utility individually using `gcc`:  

```bash
gcc -o pwd pwd.c
gcc -o echo echo.c
gcc -o cp cp.c
gcc -o mv mv.c
gcc -o cat cat.c
```
This will create executables named pwd, echo, cp, mv, and cat.

---

## 🖥️ Usage Examples  

### 1. pwd  
Prints the current working directory.  

```bash
$ ./pwd
/home/user/projects/unix-utils
```
### 2. echo  
Prints the given string(s) to standard output.

```bash
$ ./echo Hello World
Hello World
```
### 3. cp  
Copies a file from source to destination.

```bash
$ ./cp file.txt /tmp/file_copy.txt
```
### 4. mv  
Moves (or renames) a file to a new destination.

```bash
$ ./mv /tmp/file.txt /tmp/new_name.txt
$ ./mv /tmp/file.txt /home/user/new_name.txt
$ ./mv /tmp/file.txt /home/user/file.txt
```
### 5. cat  
Displays the contents of a file to standard output.

```bash
$ ./cat file.txt
This is the content of file.txt
Displayed line by line...
```
---
## 📝 Notes  

- These are **simplified** versions of the Unix commands.  
- Only explicit operations are supported (no flags/options like `-r`, `-n`, etc.).  
- Error handling is included (check return values of system calls).  
- Object files and executables are **not included** in the repository(compile them on your own machine 🙂).  

---

## 🎯 Purpose  

This project is a practical exercise to understand:  
- File handling in C  
- System calls like `getcwd`, `open`, `read`, `write`, `close`, `remove`  
- Re-implementing Unix-like behavior in a minimal way  

---
## 📜 License  
This project is for educational purposes.
