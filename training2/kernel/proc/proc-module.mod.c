#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
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
	{ 0x355f7b1c, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xb9bc331, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0xb7de2906, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0xc194a96f, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0x970cf670, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0xd4e197f2, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0x91831d70, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0x8dc2e19a, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "91069C741CC647C4E1EAD8B");