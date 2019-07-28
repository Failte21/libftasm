%define MACH_SYSCALL(nb)	0x2000000 | nb
%define READ 3
%define WRITE 4
%define BUF_SIZE 256
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
	mov rdx, BUF_SIZE				; init buf_size
	lea rsi, [rel buffer]			; init buffer
	mov rax, MACH_SYSCALL(READ)
	syscall
	jc end							; jump if carry
	cmp rax, 0						; leave if nothing else to read or error
	jle end

write:
	push rdi						; save fd
	push rax
	mov rdi, STDOUT
	mov rdx, rax					; write as many bytes as we were able to read
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	pop rax
	pop rdi

lp:
	jg ft_cat

end:
	leave
	ret