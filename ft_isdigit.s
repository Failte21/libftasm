section .text
	global _ft_isdigit

_ft_isdigit:

init:
	push rbp
	mov rbp, rsp

ft_isdigit:
	cmp dil, '0'
	jl ret_false
	cmp dil, '9'
	jg ret_false
	jmp ret_true

ret_false:
	mov al, 0
	jmp end

ret_true:
	mov al, 1

end:
	leave
	ret