section .text
	global _ft_islower

_ft_islower:

init:
	push rbp
	mov rbp, rsp

ft_islower:
	cmp rdi, 0x61
	jl ret_false
	cmp rdi, 0x7a
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