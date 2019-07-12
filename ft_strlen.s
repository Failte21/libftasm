section .text
    global _ft_strlen

_ft_strlen:

init:
	push rbp
	mov rbp, rsp

lp:
	mov al, 0
	mov rcx, 0xFFFFFFFF				; rcx will count down
	inc rcx							; don't count terminal char
	repnz scasb
	not rcx,						
	mov rax, rcx
end:
	leave
    ret