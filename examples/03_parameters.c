/** @file 03_parameters.c
 *  @brief Pass parameters to the module when loading.
 *
 *  Define a test integer that could represent any information you want
 *  to pass to the kernel module.
 *  After compiling, call insmod this way:
 *  $ sudo insmod 03_parameters.ko test_num=10
 *
 *  @author Filipe do Ó Cavalcanti
 */

#define pr_fmt(fmt) "%s %s: " fmt, KBUILD_MODNAME, __func__
#include <linux/module.h>

static int test_num = 1;
module_param(test_num, int, S_IRUSR | S_IWUSR);

static int __init devd_init(void) {
  pr_info("Example driver loaded\n");
  pr_info("Test num is: %d\n", test_num);
  return 0;
}

static void __exit devd_exit(void) {
  pr_info("Example driver removed\n");
}

MODULE_PARM_DESC(test_num, " Test number to be passed as module parameter");
module_init(devd_init);
module_exit(devd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Filipe do Ó Cavalcanti");
MODULE_DESCRIPTION("Passing module parameters.");
