/******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 *****************************************************************************/
#ifndef _RTL871X_BYTEORDER_H_
#define _RTL871X_BYTEORDER_H_

#include <asm/byteorder.h>

#if defined(CONFIG_LITTLE_ENDIAN) && defined (CONFIG_BIG_ENDIAN)
	#error "Shall be CONFIG_LITTLE_ENDIAN or CONFIG_BIG_ENDIAN, but not both!\n"
#endif

#if defined(CONFIG_LITTLE_ENDIAN)
	#ifndef CONFIG_PLATFORM_MSTAR389
		#if __has_include(<linux/byteorder/little_endian.h>)
		#include <linux/byteorder/little_endian.h>
		#elif __has_include(<asm/byteorder.h>)
		#include <asm/byteorder.h>
		#else
		#include <linux/byteorder/generic.h>
		#endif
	#endif
#elif defined (CONFIG_BIG_ENDIAN)
	#if __has_include(<linux/byteorder/big_endian.h>)
	#include <linux/byteorder/big_endian.h>
	#elif __has_include(<asm/byteorder.h>)
	#include <asm/byteorder.h>
	#else
	#include <linux/byteorder/generic.h>
	#endif
#else
	#if defined(__BYTE_ORDER) && defined(__LITTLE_ENDIAN) && defined(__BIG_ENDIAN)
		#if __BYTE_ORDER == __LITTLE_ENDIAN
			#define CONFIG_LITTLE_ENDIAN 1
		#elif __BYTE_ORDER == __BIG_ENDIAN
			#define CONFIG_BIG_ENDIAN 1
		#else
			#error "Must be LITTLE/BIG Endian Host"
		#endif
	#elif defined(__LITTLE_ENDIAN) || defined(__BIG_ENDIAN)
		#if defined(__LITTLE_ENDIAN)
			#define CONFIG_LITTLE_ENDIAN 1
		#else
			#define CONFIG_BIG_ENDIAN 1
		#endif
	#else
		#error "Must be LITTLE/BIG Endian Host"
	#endif
#endif

#endif /* _RTL871X_BYTEORDER_H_ */
