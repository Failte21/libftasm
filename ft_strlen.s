section .text
    global _ft_strlen

_ft_strlen:

init:
	push rbp
	mov rbp, rsp
    mov eax, 0

lp:
    cmp byte[rdi], 0
    je end
    inc rdi
    inc eax
    jmp lp

end:
	leave
    ret