extern _ft_memset

section .text
    global _ft_bzero

_ft_bzero:

init:
	push rbp
	mov rbp, rsp

ft_bzero:
	mov rdx, rsi
	mov rsi, 0
	call _ft_memset

end:
	leave
	ret