extern _ft_isupper

section .text
	global _ft_tolower

_ft_tolower:

init:
	push rbp
	mov rbp, rsp

ft_tolower:
	call _ft_isupper
	cmp al, 0
	je end
	add rdi, 32

end:
	mov rax, rdi
	leave
	ret
	