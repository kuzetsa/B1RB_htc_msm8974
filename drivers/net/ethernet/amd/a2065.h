/*
 * Amiga Linux/68k A2065 Ethernet Driver
 *
 * (C) Copyright 1995 by Geert Uytterhoeven <geert@linux-m68k.org>
 *
 * ---------------------------------------------------------------------------
 *
 * This program is based on
 *
 *	ariadne.?:	Amiga Linux/68k Ariadne Ethernet Driver
 *			(C) Copyright 1995 by Geert Uytterhoeven,
 *			Peter De Schrijver
 *
 *	lance.c:	An AMD LANCE ethernet driver for linux.
 *			Written 1993-94 by Donald Becker.
 *
 *	Am79C960:	PCnet(tm)-ISA Single-Chip Ethernet Controller
 *			Advanced Micro Devices
 *			Publication #16907, Rev. B, Amendment/0, May 1994
 *
 * ---------------------------------------------------------------------------
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file COPYING in the main directory of the Linux
 * distribution for more details.
 *
 * ---------------------------------------------------------------------------
 *
 * The A2065 is a Zorro-II board made by Commodore/Ameristar. It contains:
 *
 *	- an Am7990 Local Area Network Controller for Ethernet (LANCE) with
 *	  both 10BASE-2 (thin coax) and AUI (DB-15) connectors
 */



struct lance_regs {
	unsigned short rdp;		
	unsigned short rap;		
};



#define LE_CSR0		0x0000		
#define LE_CSR1		0x0001		
#define LE_CSR2		0x0002		
#define LE_CSR3		0x0003		



#define LE_C0_ERR	0x8000		
#define LE_C0_BABL	0x4000		
#define LE_C0_CERR	0x2000		
#define LE_C0_MISS	0x1000		
#define LE_C0_MERR	0x0800		
#define LE_C0_RINT	0x0400		
#define LE_C0_TINT	0x0200		
#define LE_C0_IDON	0x0100		
#define LE_C0_INTR	0x0080		
#define LE_C0_INEA	0x0040		
#define LE_C0_RXON	0x0020		
#define LE_C0_TXON	0x0010		
#define LE_C0_TDMD	0x0008		
#define LE_C0_STOP	0x0004		
#define LE_C0_STRT	0x0002		
#define LE_C0_INIT	0x0001		



#define LE_C3_BSWP	0x0004		
#define LE_C3_ACON	0x0002		
#define LE_C3_BCON	0x0001		



#define LE_MO_PROM	0x8000		
#define LE_MO_INTL	0x0040		
#define LE_MO_DRTY	0x0020		
#define LE_MO_FCOLL	0x0010		
#define LE_MO_DXMTFCS	0x0008		
#define LE_MO_LOOP	0x0004		
#define LE_MO_DTX	0x0002		
#define LE_MO_DRX	0x0001		


struct lance_rx_desc {
	unsigned short rmd0;        
	unsigned char  rmd1_bits;   
	unsigned char  rmd1_hadr;   
	short    length;    	    
	unsigned short mblength;    
};

struct lance_tx_desc {
	unsigned short tmd0;        
	unsigned char  tmd1_bits;   
	unsigned char  tmd1_hadr;   
	short    length;       	    
	unsigned short misc;
};



#define LE_R1_OWN	0x80		
#define LE_R1_ERR	0x40		
#define LE_R1_FRA	0x20		
#define LE_R1_OFL	0x10		
#define LE_R1_CRC	0x08		
#define LE_R1_BUF	0x04		
#define LE_R1_SOP	0x02		
#define LE_R1_EOP	0x01		
#define LE_R1_POK       0x03		



#define LE_T1_OWN	0x80		
#define LE_T1_ERR	0x40		
#define LE_T1_RES	0x20		
#define LE_T1_EMORE	0x10		
#define LE_T1_EONE	0x08		
#define LE_T1_EDEF	0x04		
#define LE_T1_SOP	0x02		
#define LE_T1_EOP	0x01		
#define LE_T1_POK	0x03		



#define LE_T3_BUF 	0x8000		
#define LE_T3_UFL 	0x4000		
#define LE_T3_LCOL 	0x1000		
#define LE_T3_CLOS 	0x0800		
#define LE_T3_RTY 	0x0400		
#define LE_T3_TDR	0x03ff		



#define A2065_LANCE		0x4000

#define A2065_RAM		0x8000
#define A2065_RAM_SIZE		0x8000
