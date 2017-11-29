/* See COPYRIGHT for copyright information. */
#include <inc/x86.h>

//global data:ok
char msg4[]={'P',0xA,'3',0x7};

void
i386_init(void)
{
	//stack error
	//char msg4[]={'P',0xA,'3',0x7};
	/////the next line error
//    __asm __volatile("cld\n\tmovl %0,%%esi\n\tmovl $0xb8000,%%edi\n\tmovl $4,%%ecx\n\trep movsb"::"r"(msg4));
	/////because paging: 0xf0000000 kernbase vp -> pp
    __asm __volatile("cld\n\tmovl %0,%%esi\n\tmovl $0xf00b8000,%%edi\n\tmovl $4,%%ecx\n\trep movsb"::"r"(msg4));

//	unsigned short *video = (unsigned short *)0xB8000;
	//KERNBASE:0xF0000000  CGA_BUF=0xB8000 0x8:offset
	unsigned short *video = (unsigned short *)(0xF0000000+0xB8000+0x8);
	unsigned char attrib = 0xF;
	char msg5[] = "Hello, World!";
    int i = 0;
    for (i = 0; msg5[i] != '\0'; i++)
        video[i] = (attrib << 8) | msg5[i];

	// Drop into the kernel monitor.
	while (1){
	}
}

