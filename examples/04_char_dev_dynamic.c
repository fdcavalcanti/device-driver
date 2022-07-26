/** @file 04_char_dev_dynamic.c
 *  @brief
 *  This example shows how to create a character device and make it appear
 *  on /dev/. It can be the entry point for many applications and allows
 *  interactions of user space and kernel space.
 *
 *  Regarding alloc_chrdev_region and register_chrdev_region:
 *  The first will automatically select a major and minor value based on a
 *  range. The second will register a specific value for major and minor.
 *
 *  @author Filipe do Ó Cavalcanti
 */

#define pr_fmt(fmt) "%s %s: " fmt, KBUILD_MODNAME, __func__
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/module.h>

#define DEV_NAME "my_dev"
static struct cdev example_cdev;
static struct class *cdev_class;
dev_t dev_number;  // holds the MAJOR and MINOR values.

/* The file operations struct is necessary for character device creation.
 * For now, it is simplified.
 */
static struct file_operations fops = {
  .owner = THIS_MODULE,
};

static int __init devd_init(void) {
  /* The first step is to allocate a region for the character device and
   * print the values allocated on completion.
   */
  if (alloc_chrdev_region(&dev_number, 0, 1, DEV_NAME) < 0) {
    pr_err("Failed to allocate char device.\n");
    return 0;
  } else {
    pr_info("Major: %d | Minor: %d\n", MAJOR(dev_number), MINOR(dev_number));
  }

  /* Now the chracter device must be initialized in the region allocated. */
  cdev_init(&example_cdev, &fops);
  cdev_add(&example_cdev, dev_number, 1);

  /* Create the class for this device.
   * This will make "example_class" appear under /sys/class/
   */
  cdev_class = class_create(THIS_MODULE, "my_class");

  /* Now the device file node can be created.
   * On device creation, "my_cdev" will appear on /dev/.
   * This allows interactions of the kernel module with the user space.
   */
  device_create(cdev_class, NULL, dev_number, NULL, DEV_NAME);
  pr_info("Example driver loaded\n");

  return 0;
}

static void __exit devd_exit(void) {
  device_destroy(cdev_class, dev_number);
  class_destroy(cdev_class);
  cdev_del(&example_cdev);
  unregister_chrdev_region(dev_number, 1);
  pr_info("Example driver removed\n");
}

module_init(devd_init);
module_exit(devd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Filipe do Ó Cavalcanti");
MODULE_DESCRIPTION("Character device cration (dynamic).");
