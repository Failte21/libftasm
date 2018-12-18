section .text
    global _ft_strcat

_ft_strcat:

mv_to_end:
    cmp byte[rdi], 0
    jle append
    inc rdi
    jmp end

append:
    cmp byte[rsi], 0
    jle end
    mov byte[rdi], 'b'
    inc rsi
    inc rdi

end:
    ret