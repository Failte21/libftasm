section .text
	global _ft_islower

_ft_islower:

init:
	push rbp
	mov rbp, rsp

ft_islower:
	cmp dil, 'a'
	jl ret_false
	cmp dil, 'z'
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