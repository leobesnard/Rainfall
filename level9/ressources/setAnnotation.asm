Dump of assembler code for function _ZN1N13setAnnotationEPc:
   0x0804870e <+0>:	push   %ebp
   0x0804870f <+1>:	mov    %esp,%ebp
   0x08048711 <+3>:	sub    $0x18,%esp
   0x08048714 <+6>:	mov    0xc(%ebp),%eax
   0x08048717 <+9>:	mov    %eax,(%esp)
   0x0804871a <+12>:	call   0x8048520 <strlen@plt>
   0x0804871f <+17>:	mov    0x8(%ebp),%edx
   0x08048722 <+20>:	add    $0x4,%edx
   0x08048725 <+23>:	mov    %eax,0x8(%esp)
   0x08048729 <+27>:	mov    0xc(%ebp),%eax
   0x0804872c <+30>:	mov    %eax,0x4(%esp)
   0x08048730 <+34>:	mov    %edx,(%esp)
   0x08048733 <+37>:	call   0x8048510 <memcpy@plt>
   0x08048738 <+42>:	leave  
   0x08048739 <+43>:	ret    
End of assembler dump.

