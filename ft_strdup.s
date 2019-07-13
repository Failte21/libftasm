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
	push rdi			; save pointer
	call _ft_strlen
	inc rax				; inc for string terminating char
	mov rdi, rax
	push rax			; size to malloc
	call _malloc
	pop rdx				; size to copy
	mov rdi, rax		; freshly allocated pointer
	pop rsi				; get original string pointer back
	call _ft_memcpy

end:
	leave
	ret