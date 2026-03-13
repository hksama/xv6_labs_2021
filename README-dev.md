# xv6 Development README

## Repository

Local path:

```
~/Desktop/Projects/OS/xv6-labs-2021
```

This repository contains the lab version of **xv6**, used in the MIT operating systems course.

Reference course: MIT 6.S081 – Operating System Engineering.

---

# Toolchain Setup

Tools are installed locally in:

```
~/xv6-tools
```

Structure:

```
~/xv6-tools
 ├── qemu
 │   └── xpack-qemu-riscv-8.2.2-1
 └── riscv64
     └── xpack-riscv-none-elf-gcc-13.2.0-2
```

These tools have been added to PATH:

```
export PATH=$HOME/xv6-tools/riscv64/xpack-riscv-none-elf-gcc-13.2.0-2/bin:$PATH
export PATH=$HOME/xv6-tools/qemu/xpack-qemu-riscv-8.2.2-1/bin:$PATH
```

Verify installation:

```
riscv-none-elf-gcc --version
qemu-system-riscv64 --version
```

---

# Building xv6

Navigate to the repo:

```
cd ~/Desktop/Projects/OS/xv6-labs-2021
```

Clean build:

```
make clean
```

Compile and run:

```
make qemu
```

This will:

1. Compile the kernel
2. Compile user programs
3. Build filesystem image
4. Launch QEMU

---

# Running xv6

When booted, you will see:

```
xv6 kernel is booting
init: starting sh
$
```

This `$` prompt is the xv6 shell.

Example commands:

```
ls
echo hello
cat README
```

---

# Exiting xv6

Since xv6 runs inside QEMU in nographic mode:

Press:

```
Ctrl + A
then X
```

This exits the emulator.

---

# Repository Structure

Important directories:

```
kernel/     → xv6 kernel
user/       → user programs
mkfs/       → filesystem builder
```

Important kernel files:

```
kernel/main.c
kernel/proc.c
kernel/trap.c
kernel/syscall.c
kernel/vm.c
```

These files explain most of the kernel behaviour.

---

# Recommended Reading Before Labs

1. xv6 Book
   "xv6: A simple Unix-like teaching operating system"

2. Key OSTEP chapters:

   * Process abstraction
   * Process API
   * Limited Direct Execution
   * Basic scheduling
   * Address spaces

---

# Suggested Code Reading Order

Start with boot sequence:

1. kernel/entry.S
2. kernel/start.c
3. kernel/main.c

Then process system:

4. kernel/proc.c
5. kernel/swtch.S

Then interrupts and syscalls:

6. kernel/trap.c
7. kernel/syscall.c

Then memory management:

8. kernel/vm.c

Then filesystem:

9. kernel/fs.c

---

# How to Study the Code

Recommended loop:

1. Pick one subsystem (process, memory, filesystem)
2. Trace execution path
3. Follow function calls
4. Read related structures in headers
5. Write notes explaining the control flow

Focus on:

* control flow
* data structures
* kernel/user transitions

---

# Useful Build Files

After compilation:

```
kernel/kernel.asm   → disassembled kernel
kernel/kernel.sym   → kernel symbols
user/*.asm          → user program assembly
```

These help in understanding low-level execution.

---

# Learning Strategy

Use the following loop:

```
Start lab
↓
Read relevant kernel code
↓
Get confused
↓
Read theory (OSTEP or xv6 book)
↓
Return to code
```

This makes operating system concepts stick much better than theory-first learning.

---
