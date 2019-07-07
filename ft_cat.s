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

read:
	sub rsp, 8
	push rdx
	mov rax, MACH_SYSCALL(READ)
	syscall
	pop rdx
	add rsp, 8 

write:
	sub rsp, 16
	push rax
	push rdx
	mov rdi, 1						; STDOUT
	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	pop rax
	pop rdx
	add rsp, 16

lp:
	cmp rax, 0
	jg ft_cat

end:
	leave
	ret