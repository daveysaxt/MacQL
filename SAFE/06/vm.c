/*
 * (c) UQLX - see COPYRIGHT
 */

#include "QL68000.h"
#include "vm.h"
#include "unix.h"
#include "xcodes.h"

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "qx_proto.h"

/*
     catch VM errors that resulted from read/write to QL HW/special memory areas
*/

char *oldscr;
long pagesize;
int pageshift;

extern int main();
extern int strcasecmp();
extern uw32 rtop_hard;
extern int is_patching;
extern int rtc_emu_on;

char *scrModTable;
int sct_size;
int faultaddr;
int vm_ison=0;

uw32 vm_saved_rom_value;
uw32 vm_saved_rom_addr=131072;  /* IMPROTANT */
int vm_saved_nInst=0;

int vmfatalretry=0;
  
void vmMarkScreen(uw32 addr)
{
  uw32 i=addr;
  if (i>=qlscreen.qm_lo && i<=qlscreen.qm_hi)
    {
      i=PAGEI((w32)(i-qlscreen.qm_lo));
      if (scrModTable[i]) return;
  
      scrModTable[i]=1;

#if 1
      uqlx_protect(PAGEX(PAGEI(addr)),pagesize,QX_RAM);
#else
      i = (i>>RM_SHIFT);
      RamMap[i]=QX_RAM;
#endif
    }
}

void vm_setscreen()
{   
  int i,xsize;
  
  xsize=PAGEX(PAGEI(qlscreen.qm_len+pagesize-1));

  sct_size=PAGEI(xsize);
  
  scrModTable=(void*)malloc(sct_size+1);
  for (i=0 ; i<sct_size ; i++) scrModTable[i]=1;  /* hack, force init display */
 
  oldscr=(void*)malloc(xsize);
  memset(oldscr,255,xsize);    /* force first screen draw !*/
}


void vm_on(void)
{
  int res;
  int i,x=0;
  
#if 0
  printf("turn write protection on\n");
#endif
  

  vm_ison=1;
  
#if 1 /*def USE_VM */
  uqlx_prestore(0,96*1024);
  uqlx_prestore(0x18000,pagesize); /* currently not needed */
#else
  if(MPROTECT((Ptr)theROM,96*1024,PROT_READ)<0) /* ROM */
    perror("sorry, could not enable ROM protection");

  if(MPROTECT((Ptr)theROM+0x18000,pagesize,PROT_NONE)<0) /* HWREGS */
    perror("sorry, could not enable HW register protection");
#endif



#if 1 /*defined(USE_VM)*/
  uqlx_prestore(qlscreen.qm_lo,qlscreen.qm_len);
#else
  for(i=0; i<sct_size; i++) 
    if(!scrModTable[i])
      if(MPROTECT((char*)theROM+qlscreen.qm_lo+PAGEX(i),pagesize,PROT_READ)<0)  
	perror("sorry, could not enable screen write protection");
#endif
}

void vm_off(void)
{
  vm_ison=0;
}