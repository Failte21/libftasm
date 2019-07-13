extern _ft_islower
extern _ft_isupper

section .text
	global _ft_isalpha

_ft_isalpha:

init:
	push rbp
	mov rbp, rsp

ft_isalpha:
	call _ft_islower
	cmp rax, 1
	je end
	call _ft_isupper

end:
	leave
	ret