%define MACH_SYSCALL(nb)	0x2000000 | nb
%define READ 3
%define WRITE 4

extern _ft_puts

section .text
	global _ft_cat

_ft_cat:

init:
	push rbp
	mov rbp, rsp
	mov rdx, 8						; BUF_SIZE

ft_cat:
	mov rax, MACH_SYSCALL(READ)
	syscall
	mov rdi, 1						; STDOUT
	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	syscall

end:
	leave
	ret