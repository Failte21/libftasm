section .text
	global _ft_memcpy

_ft_memcpy:

init:
	push rbp
	mov rbp, rsp

ft_memcpy:
	cmp rdx, 0
	je end
	mov cl, byte[rsi + rdx - 1]
	mov byte[rdi + rdx - 1], cl
	dec rdx
	jmp ft_memcpy

end:
	mov rax, rdi
	leave
	ret