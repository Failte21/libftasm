extern _ft_isalpha
extern _ft_isdigit

section .text
	global _ft_isalnum

_ft_isalnum:

init:
	push rbp
	mov rbp, rsp

ft_isalnum:
	call _ft_isdigit
	cmp rax, 1
	je end
	call _ft_isalpha

end:
	leave
	ret