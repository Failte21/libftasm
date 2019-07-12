section .text
    global _ft_strlen

_ft_strlen:

init:
	push rbp
	mov rbp, rsp

lp:
	mov al, 0
	mov rcx, 0
	not rcx
	repnz scasb
	not rcx,
	dec rcx
	mov rax, rcx
end:
	leave
    ret