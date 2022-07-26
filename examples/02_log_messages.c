/** @file 02_log_messages.c
 *  @brief Based on the first example, this implementation shows how you can
 *         improve the kernel messages.
 *
 *  This code will print kernel messages in many types of priorities.
 *  The first define is used to  alter every subsequent call of the pr_*
 *  functions by appending the module name and the function that printed the
 *  statement.
 *
 *  All messages printed have different priority levels. More details can be
 *  found on linux/include/linux/kern_levels.h
 *
 *  @author Filipe do Ó Cavalcanti
 */

#define pr_fmt(fmt) "%s %s: " fmt, KBUILD_MODNAME, __func__
#include <linux/module.h>

static void kernel_messages(void) {
  pr_debug("This is a debug message: debug-level messages.\n");
  pr_info("This is an info message: informational.\n");
  pr_notice("This is a notice message: normal but significant condition.\n");
  pr_warning("This is an warning message: warning conditions.\n");
  pr_err("This is an error message: error conditions.\n");
  pr_crit("This is a critical message: critical conditions.\n");
  pr_alert("This is an alert message: action must be taken immediately.\n");
  pr_emerg("This is an emergency message: system is unusable.\n");
}

static int __init devd_init(void) {
  pr_info("Example driver loaded\n");
  kernel_messages();
  return 0;
}

static void __exit devd_exit(void) {
  pr_info("Example driver removed\n");
}

module_init(devd_init);
module_exit(devd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Filipe do Ó Cavalcanti");
MODULE_DESCRIPTION("Kernel messages and log levels.");
