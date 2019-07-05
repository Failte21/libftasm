%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT	1
%define WRITE 4

extern _ft_strlen

section .text
    global _ft_puts

_ft_puts:

init:
	push rbp						; save base register onto the stack
	mov rbp, rsp
	mov rsi, rdi					; save pointer

strlen:
	call _ft_strlen
	mov edx, eax

puts:
	mov rdi, STDOUT					; first argument
	mov eax, MACH_SYSCALL(WRITE)
	syscall

end:
	leave
	ret