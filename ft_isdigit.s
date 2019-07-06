section .text
	global _ft_isdigit

_ft_isdigit:

init:
	push rbp
	mov rbp, rsp

ft_isdigit:
	cmp rdi, 0x31
	jl ret_false
	cmp rdi, 0x39
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