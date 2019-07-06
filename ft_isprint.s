section .text
	global _ft_isprint

_ft_isprint:

init:
	push rbp
	mov rbp, rsp

ft_isprint:
	cmp rdi, 0x20
	jl ret_false
	cmp rdi, 0x7E
	jg ret_false
	jmp ret_true

ret_false:
	mov rax, 0
	jmp end

ret_true:
	mov rax, 1

end:
	leave
	ret