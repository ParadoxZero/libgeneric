# libgeneric
[![Build Status](https://travis-ci.org/TravorLZH/libgeneric.svg?branch=master)](https://travis-ci.org/TravorLZH/libgeneric)

General Purpose, Generic Data Structure library for C.

## Implemented Data structures
* Linked List
* Linked List-based Stack ( untested )
* Vector-based Stack (freestanding)
* Vector (C equivalence to `std::vector`)

## Generic Functions

* [**swap\_generic**](http://www.travor.top/libgeneric/docs/utils_8c.html#a913e9f9e9ce4e4a7d0ff2c02f28c82d0)

* [**search\_generic**](http://www.travor.top/libgeneric/docs/utils_8c.html#ac8817f9cd0580d5b1933381a0e0657e5)

## Checklist left to implement ( not exhaustive )

- [ ] Queue
- [ ] Binary Trees
- [ ] Binary Search Trees
- [ ] AVL Trees
- [ ] Graphs

## Contributing
Please contribute to it and help implement most of the common structures. 

The aim is to build a reusable standard datastructure library for different c-based projects. 

### Please keep in mind

- Please mark the option **Allow edits from maintainers**, so that we can improve your pull together.
  
- Mark an existing issue as `currently working` label.

- This project is adapting [Linux Kernel Coding Style][1]

- Try to make functions like `foo_bar()` instead of `fooBar()`

- Ensure it's stable. Write a test for each function you implement.

- Keep it generic. (use `void*`)

[1]: https://www.kernel.org/doc/html/v4.10/process/coding-style.html

