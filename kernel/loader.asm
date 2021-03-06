bits 32

global loader
extern kmain ; entry point to C

; Multiboot header
MODULEALIGN equ   1<<0
MEMINFO     equ   1<<1
FLAGS       equ   MODULEALIGN | MEMINFO
MAGIC       equ   0x1BADB002
CHECKSUM    equ   -(MAGIC + FLAGS)

MultibootHeader:
      dd MAGIC
      dd FLAGS
      dd CHECKSUM
      
STACKSIZE   equ 0x4000        ; 16 KB

loader:
      cmp eax, 0x2BADB002     ; verify booted with grub
      jne .bad
      
      mov esp, STACKSIZE + stack
      mov ax, 0x10
      mov ds, ax
      mov es, ax
      mov fs, ax
      mov gs, ax
      
      push ebx
      call kmain
      
.bad:
      cli
      hlt
      
align 4
stack:
      TIMES STACKSIZE db 0
      
