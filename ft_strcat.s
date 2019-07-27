extern _ft_memcpy
extern _ft_strlen

section .text
    global _ft_strcat

_ft_strcat:

init:
	push rbp
	mov rbp, rsp
	push rdi				; save pointer before moving it

mv_to_end:
    cmp byte[rdi], 0		; loop until \0
    je strlen
    inc rdi
    jmp mv_to_end

strlen:
	push rdi
	mov rdi, rsi
	call _ft_strlen
	inc rax					; inc to include \0 in the copy
	mov rdx, rax
	pop rdi

append:
	call _ft_memcpy

end:
	pop rax					; return original pointer
	leave
	ret