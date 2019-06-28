#include <linux/init.h>
#include <linux/module.h>

static int hi(void)
{
printk(KERN_ALERT "Hello Kitty\n");
return 0;
}

static void bye(void)
{
printk(KERN_ALERT "Goodbye Kitty\n");
}

module_init(hi);
module_exit(bye);
