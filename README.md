
# Linux Device Driver Examples

This repository contains multiple examples for Linux device drivers, starting 
from a simple Hello World to more advanced applications.

The code available here is recommended for those who want to start some project
in the Linux environment but don't know where to start.


## Usage/Examples
On the examples folder, edit the first line of the Makefile, replacing the '.o'
file name with the example you want to compile:
```
obj-m += 007_example.o
```
Open the terminal, access the examples folder and run make.
```console
juvenal@pi:~/device-driver/examples $ make
```
This should compile the example. After it is done, run the following to insert
the module.
```console
juvenal@pi:~/device-driver/examples $ sudo insmod 007_example.ko
```
Check dmesg for output messages to see if the module was inserted.\
To remove the module:
```console
juvenal@pi:~/device-driver/examples $ sudo rmmod 007_example
```
