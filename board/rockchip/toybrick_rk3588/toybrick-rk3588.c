// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2024 Rockchip Electronics Co,. Ltd.
 */

#include <fdtdec.h>
#include <fdt_support.h>

#ifdef CONFIG_OF_BOARD_SETUP
static int rk3588_add_reserved_memory_fdt_nodes(void *new_blob)
{
	struct fdt_memory gap1 = {
		.start = 0x3fc000000,
		.end = 0x3fc4fffff,
	};
	struct fdt_memory gap2 = {
		.start = 0x3fff00000,
		.end = 0x3ffffffff,
	};
	unsigned long flags = FDTDEC_RESERVED_MEMORY_NO_MAP;
	int ret;

	/*
	 * Inject the reserved-memory nodes into the DTS
	 */
	ret = fdtdec_add_reserved_memory(new_blob, "gap1", &gap1,  NULL, 0,
					 NULL, flags);
	if (ret)
		return ret;

	return fdtdec_add_reserved_memory(new_blob, "gap2", &gap2,  NULL, 0,
					  NULL, flags);
}

int ft_board_setup(void *blob, struct bd_info *bd)
{
	return rk3588_add_reserved_memory_fdt_nodes(blob);
}
#endif
