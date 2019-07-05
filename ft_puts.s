%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT	1
%define WRITE 4

section .text
    global _ft_puts

_ft_puts:

init:
	push rbp						; save base register onto the stack
	mov rsp, rbp
	mov rsi, rdi					; save pointer
	mov rdx, 0						; len of the string

strlen:
	cmp byte[rdi + rdx], 0
	je puts
	inc rdx
	jmp strlen

puts:
	mov rdi, STDOUT					; first argument
	mov rax, MACH_SYSCALL(WRITE)
	syscall

end:
	mov rbp, rsp
	pop rbp							; same as 'leave'
	ret