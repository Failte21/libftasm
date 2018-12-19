section .text
    global _ft_strlen

_ft_strlen:
    mov eax, 0

lp:
    cmp byte[rdi], 0
    je end
    inc rdi
    inc eax
    jmp lp

end:
    ret