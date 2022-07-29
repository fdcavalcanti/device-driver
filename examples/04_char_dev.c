/** @file
 *  @brief
 *
 *
 *  @author Filipe do Ó Cavalcanti
 */

#define pr_fmt(fmt) "%s %s: " fmt, KBUILD_MODNAME, __func__
#include <linux/fs.h>
#include <linux/module.h>

static int major_number = 100;
// http://www.makelinux.net/ldd3/chp-3-sect-4.shtml

static int __init devd_init(void) {
  // The first argument is the major number.
  // If set to 0, it will be dinamically allocated.
  major_number = register_chrdev(0, 0, 1, "char_dev_example", &char_dev_fops);
  if (major_number < 0) {
    pr_err("Failed to create a character device.\n");
    return major_number;
  }
  pr_info("Example driver loaded\n");

  return 0;
}

static void __exit devd_exit(void) {
  unregister_chrdev(major_number, "char_dev_example");
  pr_info("Example driver removed\n");
}

module_init(devd_init);
module_exit(devd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Filipe do Ó Cavalcanti");
MODULE_DESCRIPTION("Device driver loading and removing.");
