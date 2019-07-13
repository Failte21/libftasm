section .text
	global _ft_isupper

_ft_isupper:

init:
	push rbp
	mov rbp, rsp

ft_isupper:
	cmp rdi, 0x41
	jl ret_false
	cmp rdi, 0x5a
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