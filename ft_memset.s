section .text
	global _ft_memset

_ft_memset:

init:
	push rbp
	mov rbp, rsp

ft_memset:
	push rdi				; save pointer
	mov rax, rsi			; store byte
	mov rcx, rdx			; store counter
	rep stosb				; load bytes to pointer
	pop rax					; get original pointer back

end:
	leave
	ret