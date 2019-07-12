section .text
	global _ft_memcpy

_ft_memcpy:

init:
	push rbp
	mov rbp, rsp

ft_memcpy:
	push rdi						; save original pointer
	mov rcx, rdx					; store counter
	rep movsb						; copy rsi -> rdi
	pop rax							; get original pointer back

end:
	leave
	ret