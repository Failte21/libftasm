extern _ft_islower

section .text
	global _ft_toupper

_ft_toupper:

init:
	push rbp
	mov rbp, rsp

ft_toupper:
	call _ft_islower
	cmp al, 0
	je end
	sub rdi, 32

end:
	mov rax, rdi
	leave
	ret
	