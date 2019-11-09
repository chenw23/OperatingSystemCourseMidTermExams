---
title: "Fall 2017 Mid Term Solution"
subtitle: "Solution for CS 143A course at University of California, Irvine"
author: 
  - Chen Wang^[Undergraduate in Computer Engineering, Samueli School of Engineering, University of California, Irvine. (chenw23@uci.edu)]
date: "11/8/2019"
output:

  html_document:
    keep_md: yes
  word_document: default
  odt_document: default
  rtf_document: default
---

# Basic page tables.

## Address Mapping Explanation

(10 points)  Illustrate the page table used by xv6 to map the kernel into the virtual address space  of  each  process  (draw  a  page  table  diagram  and  explain  the  page  table  entries). Specifically concentrate on one entry:  the entry responsible for the translation of the first page of the kernel.  Keep in mind that xv6 maps the kernel into the virtual address range starting above the second gigabyte of virtual memory. Note, that after xv6 is done booting,it xv6 uses normal 4KB, 32bit, 2-level page tables.  You also have to recall the physical address of the first kernel page (look at the boot lecture or the kernel map), and the virtual address where this page is mapped.  To make the example realistic, don’t forget that xv6 allocates memory for it’s page table directory and page tables from the kernel memory allocator.

***Reference Solution:***

The mapping relationship can be just found on the [Lecture 10 - Kernel Page Table](https://www.ics.uci.edu/~aburtsev/143A/lectures/lecture10-kernel-page-table/lecture10-kernel-page-table.pdf), the diagram is on the slide page 79. And for the page table diagram, this can be found at the slide page 82. As for the first page of the kernel, it is certainly at virtual address 0x80000000. We take its first 10 bits, and find out that this is at the 512th entry at the page table directory. Then we take the second 10 bits of the virtual address, which is 0, we can look into the 0th entry of the page table found through the 512th entry of the directory. Through the 0th entry of the table, we find out the physical address of the kernel.

# Shell

***This question is not covered in this midterm***

# OS isolation and protection

## Memory Layout of xv6

(5 points)  Explain the organization and memory layout of the xv6 process.  Draw a diagram.  Explain which protection bits are set by the kernel and explain why kernel does it.

***Reference Solution:***

It can be found from [Lecture 04 - Linking and Loading](https://www.ics.uci.edu/~aburtsev/143A/lectures/lecture04-linking-and-loading/lecture04-linking-and-loading.pdf). It is in the page 6 of the slides.

The third bit from the right end is the kernel bit. It prevents the user from modifying kernel data and prevents potential faults.

## Memory isolation between processes

In  xv6  individual  processes  are  isolated,  specifically  they  cannot  access  each others memory.  Explain how this is implemented.

***Reference Solution:***

Each process has its own page table. When reading from a virtual address, MMU will find physical address by reading this process's page table. The pages of other processes are not mapped to this process's page table, therefore, the physical address of other processes will never be the translate result of this process.

# OS organization

## Kernel Base Understanding

(10 points) `KERNBASE` limits the amount of memory a single process can use, which might be  irritating  on  a  machine  with  a  full  4  GB  of  RAM.  Would  raising `KERNBASE` allow  a process to use more memory (explain your answer)?

***Reference Solution:***

Yes. Currently a process can access 2GB of virtual memory because the upper 4 GB are reserved by kernel. If this restriction is lifted, the user process can access more memory. Nevertheless, we should acknowledge that the corresponding page table flags should be changed accordingly as well.