#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

static int __init init_choo(void) {
	int i,count;
	printk("[Choo]: Hello Choo~ This is init\n");
	for(i=0;i<3;i++)
	{
		for(count=0;count<3;count++)
		{
			printk("*");
		}
		printk("\n");
	}
	return 0;
}

static void __exit exit_choo(void)
{
	printk("this is exit of choo_kernel\n");
	printk("[COMP3120] Good bye, kernel\n");
} 

module_init(init_choo);
module_exit(exit_choo);
MODULE_LICENSE("GPL");

