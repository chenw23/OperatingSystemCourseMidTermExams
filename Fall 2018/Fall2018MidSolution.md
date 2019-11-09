---
title: "Fall 2018 Mid Term Solution"
author: 
  - Chen Wang^[Undergraduate in Computer Engineering, Samueli School of Engineering, University of California, Irvine. (chenw23@uci.edu)]
date: "11/8/2019"
output:

  html_document:
    keep_md: yes
  word_document: default
---



# OS Interfaces

***This question is not covered in this midterm***

# Basic page tables

## (5 points)  Draw page table structure

Alice wants to construct a page table that maps virtual addresses 0x0, 0x1000and 0x2000 into physical addresses 0x1000, 0x2000, and 0x3000.  Assume that the Page Directory Page is at physical address 0x0, and the Page Table Page is at physical address0x00001000 (which is PPN 0x00001).

Draw a picture of the page table Alice will construct (or alternatively simply write it down in the format similar to the one below):  

Page Directory Page:

`PDE 0: PPN=0x1, PTE_P, PTE_U, PTE_W`

...  all other PDEs are zero

The Page Table Page:

`PTE 0: PPN=0x1, PTE_P, PTE_U, PTE_W`

`PTE 1: PPN=0x2, PTE_P, PTE_U, PTE_W`

`PTE 2: PPN=0x3, PTE_P, PTE_U, PTE_W`

...  all other PTEs are zero

***Reference Solution:***

Page Directory Page:

`PDE 0: PPN=0x1, PTE_P, PTE_U, PTE_W`

...  all other PDEs are zero

The Page Table Page:

`PTE 0: PPN=0x1, PTE_P, PTE_U, PTE_W`

`PTE 1: PPN=0x2, PTE_P, PTE_U, PTE_W`

`PTE 2: PPN=0x3, PTE_P, PTE_U, PTE_W`

...  all other PTEs are zero

# Stack and calling conventions

Alice developed a program that has a function `foo()` that is called from two other functions `bar()` and `baz()`:
`int foo(int a) {`