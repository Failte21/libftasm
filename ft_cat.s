%define MACH_SYSCALL(nb)	0x2000000 | nb
%define READ 3
%define WRITE 4
%define BUF_SIZE 1024
%define STDOUT 1

extern _ft_puts

section .data
	buffer times BUF_SIZE db 0

section .text
	global _ft_cat

_ft_cat:

init:
	push rbp
	mov rbp, rsp
	mov rdx, BUF_SIZE

ft_cat:

read:
	sub rsp, 8						; save buf_size
	push rdx
	lea rsi, [rel buffer]			; init buffer
	mov rax, MACH_SYSCALL(READ)
	syscall
	pop rdx
	add rsp, 8

write:
	sub rsp, 32
	push rdi						; save fd
	push rax						; save read output
	push rdx						; save buf_size
	mov rdi, STDOUT
	mov rdx, rax					; write as many bytes as we were able to read
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	pop rdi
	pop rax
	pop rdx
	add rsp, 32

lp:
	; cmp rax, 0
	; jg ft_cat

end:
	leave
	ret