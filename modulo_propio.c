#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
 
MODULE_LICENSE("MIT");
MODULE_AUTHOR("Sistemas Operativos 2018");
MODULE_DESCRIPTION("Un ejemplo de modulo para ejercicio 6.");
MODULE_VERSION("1.0");
 
static char *mundo = "Mundo";
module_param(mundo, charp, S_IRUGO); ///< Param desc, charp = char ptr, S_IRUGO can be read/not changed
MODULE_PARM_DESC(mundo, "mundo en /var/log/kern.log");  ///< parameter description
 
static int __init holaMundo_init(void){
   printk(KERN_INFO "Hola %s Sistemas operativos!\n", mundo);
   return 0;
}
 
static void __exit holaMundo_exit(void){
   printk(KERN_INFO "Chau %s 2018!\n", mundo);
}
 

module_init(holaMundo_init);
module_exit(holaMundo_exit);