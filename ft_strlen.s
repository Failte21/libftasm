section .text
    global _ft_strlen

_ft_strlen:

init:
	push rbp
	mov rbp, rsp

lp:
	mov al,	0			; substract dest string by 0
	mov rcx, 0
	not rcx				; init countdown to largest possible value
	repnz scasb			; check for zf flag on byte 0
	not rcx,			; inverse to get count
	dec rcx,			; remove \0 from count
	mov rax, rcx
end:
	leave
    ret