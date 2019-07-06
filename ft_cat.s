%define MACH_SYSCALL(nb)	0x2000000 | nb
%define READ 3

extern _ft_puts

section .text
	global _ft_cat

_ft_cat:

init:
	push rbp
	mov rbp, rsp

ft_cat:
	mov rdx, 8
	mov rax, MACH_SYSCALL(READ)
	syscall
	cmp rax, 0
	jl end
	mov rdi, rsi
	call _ft_puts

end:
	leave
	ret