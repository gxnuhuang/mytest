#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x6fb8d7bc, "module_layout" },
	{ 0xcfad398d, "device_destroy" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0x37a0cba, "kfree" },
	{ 0x16808ecc, "cdev_del" },
	{ 0x5e0baa3a, "dev_set_drvdata" },
	{ 0xc7ef0ce2, "class_destroy" },
	{ 0xdc1e1b7d, "device_create" },
	{ 0x4c1d0cd4, "__class_create" },
	{ 0xda72f6c6, "cdev_add" },
	{ 0xb1f57786, "cdev_init" },
	{ 0x8836fca7, "kmem_cache_alloc" },
	{ 0xc5ae0182, "malloc_sizes" },
	{ 0x29537c9e, "alloc_chrdev_region" },
	{ 0x67c2fa54, "__copy_to_user" },
	{ 0xfbc74f64, "__copy_from_user" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x27e1a049, "printk" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "42970E2FF3FCB129FE44276");
