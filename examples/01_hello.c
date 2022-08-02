/** @file 01_hello.c
 *  @brief A very basic kernel module. Start here if new to device drivers.
 *
 *  When inserted, this module will show "Example driver loaded" on dmesg.
 *  Similarly, when removed it will show "Example driver removed."
 *
 *  To insert a kernel module: $ sudo insmod <module>.ko
 *  To remove a kernel module: $ sudo rmmod <module>
 *
 *  @author Filipe do Ó Cavalcanti
 */

#include <linux/module.h>

static int __init devd_init(void) {
  pr_info("Example driver loaded\n");
  return 0;
}

static void __exit devd_exit(void) {
  pr_info("Example driver removed\n");
}

module_init(devd_init);
module_exit(devd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Filipe do Ó Cavalcanti");
MODULE_DESCRIPTION("Device driver loading and removing.");
