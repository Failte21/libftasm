extern _ft_memcpy
extern _ft_strlen
extern _malloc

section .text
	global _ft_strdup

_ft_strdup:

init:
	push rbp
	mov rbp, rsp

ft_strdup:
	push rdi
	call _ft_strlen
	pop rdi
	mov rsi, rdi
	mov rdx, rax
	mov edi, 10
	push rsi
	push rdx
	sub rsp, 32 + 16
	call _malloc
	add rsp, 32 + 16
	pop rdx
	pop rsi
	mov rdi, rax
	call _ft_memcpy

end:
	leave
	ret