<div align="center">

# 🖥️ CS-411 System Programming Labs

<img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c&logoColor=white"/>
<img src="https://img.shields.io/badge/OS-Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black"/>
<img src="https://img.shields.io/badge/Shell-Bash-4EAA25?style=for-the-badge&logo=gnu-bash&logoColor=white"/>
<img src="https://img.shields.io/badge/Status-Complete-success?style=for-the-badge"/>

<br/>

**A comprehensive collection of Linux system programming labs and assignments**  
covering POSIX APIs, process management, I/O, threading, and more.

<br/>

> 🎓 **UET Peshawar – Jalozai Campus** &nbsp;|&nbsp; Muhammad Ahmad Khan &nbsp;|&nbsp; CS-411 System Programming

</div>

---

## 📁 Repository Structure

```
system-programming-labs/
│
├── 🔬 lab1/          → Linux Command Overview
├── 🔬 lab2/          → Program Layout & Error Handling
├── 🔬 lab3/          → Programs, Processes & Threads
├── 🔬 lab4/          → Processes in Linux
├── 🔬 lab5/          → Processes (exec family)
├── 🔬 lab 6/         → Background Processes & Task Division
├── 🔬 lab 7/         → Linux I/O + memtrack-tool
├── 🔬 lab 8/         → Advanced I/O in Linux
├── 🔬 lab 9/         → File Copying & Monitoring (select)
├── 🔬 lab 10/        → Files and Directories
├── 🔬 lab 11/        → Traversing Directories
├── 🔬 lab 12/        → Inter-Process Communication (IPC)
├── 🔬 lab 13/        → Signals
│
├── 📝 assig1/        → File Handling & Signal Handling
└── 📝 assig2/        → Parallel Computing (Threads & Processes)
```

---

## 🧪 Labs

<table>
<thead>
<tr>
<th>Lab</th>
<th>Topic</th>
<th>Key Concepts</th>
</tr>
</thead>
<tbody>

<tr>
<td><b>Lab 1</b></td>
<td>Linux Command Overview</td>
<td>
  <code>ls</code> <code>chmod</code> <code>ln</code> hard/soft links · user management · shell scripting basics
</td>
</tr>

<tr>
<td><b>Lab 2</b></td>
<td>Program Layout & Error Handling</td>
<td>
  Memory segments (text · data · BSS · heap · stack) · <code>errno</code> · <code>perror()</code> · static variables
</td>
</tr>

<tr>
<td><b>Lab 3</b></td>
<td>Programs, Processes & Threads</td>
<td>
  <code>pthread_create()</code> · <code>pthread_join()</code> · shared memory · thread lifecycle
</td>
</tr>

<tr>
<td><b>Lab 4</b></td>
<td>Processes in Linux</td>
<td>
  <code>fork()</code> · <code>wait()</code> · <code>waitpid()</code> · process chains · fan topology
</td>
</tr>

<tr>
<td><b>Lab 5</b></td>
<td>Processes — <code>exec</code> Family</td>
<td>
  <code>execl()</code> · <code>execv()</code> · <code>execvp()</code> · multi-program pipelines
</td>
</tr>

<tr>
<td><b>Lab 6</b></td>
<td>Background Processes & Task Division</td>
<td>
  Daemon processes · background execution · data partitioning across processes
</td>
</tr>

<tr>
<td><b>Lab 7</b></td>
<td>Linux I/O </td>
<td>
  <code>open()</code> · <code>read()</code> · <code>write()</code> · <code>lseek()</code> · custom memory leak detector via <code>LD_PRELOAD</code>
</td>
</tr>

<tr>
<td><b>Lab 8</b></td>
<td>Advanced I/O</td>
<td>
  Buffered vs unbuffered · <code>readv()</code>/<code>writev()</code> · <code>dup()</code>/<code>dup2()</code> · custom <code>cat</code> utility
</td>
</tr>

<tr>
<td><b>Lab 9</b></td>
<td>Multiple File Copying & Monitoring</td>
<td>
  <code>select()</code>-based I/O multiplexing · concurrent file monitoring · non-blocking I/O
</td>
</tr>

<tr>
<td><b>Lab 10</b></td>
<td>Files and Directories</td>
<td>
  <code>stat()</code> · <code>opendir()</code> · <code>readdir()</code> · file metadata · directory listing
</td>
</tr>

<tr>
<td><b>Lab 11</b></td>
<td>Traversing Directories</td>
<td>
  Recursive DFS traversal · <code>nftw()</code> · <code>find</code>-style filtering
</td>
</tr>

<tr>
<td><b>Lab 12</b></td>
<td>Inter-Process Communication (IPC)</td>
<td>
  pipe() · mkfifo() · parent–child communication · process fan · FIFO (named pipes) · read()/write() · IPC · process synchronization
</td>
</tr>

<tr>
<td><b>Lab 13</b></td>
<td>Signals</td>
<td>
  Signal handling · SIGCHLD · signal()/sigaction() · signal masks · sigprocmask() · pause() · sigsuspend() · sigwait() · process synchronization
</td>
</tr>

</tbody>
</table>


---

## 📝 Assignments

### Assignment 1 — File Handling & Signal Handling

| Question | Topic | Highlights |
|---|---|---|
| **Q1** | File Handling in Linux | `open()` · `read()` · `write()` · error handling with `errno` / `perror()` |
| **Q2** | Signal Handling in Linux | `SIGINT` · `signal()` · `sigaction()` · process control via signals |

---

### Assignment 2 — Parallel Computing

**Q1 — Parallel Array Processing with `pthreads`**

Computes sum, average, and max of an array — sequential baseline vs. multithreaded parallel version.

```
Sequential  →  Single thread, linear scan
Parallel    →  Data partitioned across N threads using pthreads
```

**Q2 — Parallel File Copying with `fork` / `exec`**

Sequential file copy vs. multi-process approach using POSIX process management APIs.

```
Sequential  →  Single process reads source → writes to destination
Parallel    →  fork() spawns child processes, each handling a file segment
               wait() synchronizes, exec() loads copy workers
```

---

## ⚙️ Build & Run

All programs are written for **Linux**. Compiled binaries (no extension) are included alongside `.c` sources.

**Basic compilation:**
```bash
gcc -o output_name source_file.c
```

**With POSIX threads:**
```bash
gcc -o output_name source_file.c -lpthread
```


> ⚠️ **Windows users:** The included binaries are Linux ELF executables — they won't run on Windows natively. Use **WSL** or a Linux VM to run them.

---

## 🛠️ Tech Stack

<div align="center">

| Layer | Technologies |
|---|---|
| **Language** | C (C99/C11), Bash Shell |
| **OS** | Linux (Ubuntu 22.04) |
| **POSIX APIs** | `unistd.h` · `fcntl.h` · `sys/stat.h` · `pthread.h` · `signal.h` · `dirent.h` |
| **Tools** | GCC · Valgrind · Make |

</div>

---

<div align="center">

📚 *Academic repository — CS-411 System Programming, UET Peshawar Jalozai Campus*

</div>
