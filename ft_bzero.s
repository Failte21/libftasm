section .text
    global _ft_bzero

_ft_bzero:

bzero_loop:
    cmp rsi, 0
    jle end
    mov byte[rdi], 0
    inc rdi
    dec rsi
    jmp bzero_loop

end:
    ret