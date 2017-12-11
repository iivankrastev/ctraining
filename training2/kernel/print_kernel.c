#include <linux/init.h>
#include <linux/module.h>
 
static int my_init(void)
{
	printk("HELLO WORLD!");
	return  0;
}
 
static void my_exit(void)
{
	printk("Exit module");
	return;
}
 
module_init(my_init);
module_exit(my_exit);
