section .text
	global _ft_isascii

_ft_isascii:

init:
	push rbp
	mov rbp, rsp

ft_isasc_ft_isascii:
	cmp rdi, 0
	jl ret_false
	cmp rdi, 0x7F
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