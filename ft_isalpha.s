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
	cmp al, 1			; since we know result is either 0 or one we can only compare the lowest byte
	je end
	call _ft_isupper

end:
	leave
	ret