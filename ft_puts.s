%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT	1
%define WRITE 4

extern _ft_strlen

section .data
	newline db 0x0a
	null_output: db "(null)"

section .text
    global _ft_puts

_ft_puts:

init:
	push rbp						; save base register onto the stack
	mov rbp, rsp
	mov rsi, rdi					; save pointer

check:
	cmp rdi, 0						; check if we received a null pointer
	je null_end

strlen:
	call _ft_strlen
	mov edx, eax

puts:
	mov rdi, STDOUT					; first argument
	mov eax, MACH_SYSCALL(WRITE)
	syscall
	cmp eax, 0
	jl end
	jmp happy_ret

null_end:
	mov rdi, STDOUT					; first argument
	lea rsi, [rel null_output]
	mov rdx, 6						
	mov eax, MACH_SYSCALL(WRITE)
	syscall

happy_ret:							; write newline and return 10
	lea rsi, [rel newline]
	mov rdx, 1
	mov eax, MACH_SYSCALL(WRITE)
	syscall
	mov eax, 10						; return value on success
	jmp end

end:
	leave							; pop stack
	ret