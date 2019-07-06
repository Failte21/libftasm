section .text
	global _ft_memset

_ft_memset:

init:
	push rbp
	mov rbp, rsp

ft_memset:
	cmp rdx, 0
	jl end
	mov byte[rdi + rdx - 1], sil
	dec rdx
	jmp ft_memset

end:
	mov rax, rdi
	leave
	ret