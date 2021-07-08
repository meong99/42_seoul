section .text
		global _ft_strcpy

_ft_strcpy:
		mov rax, 0
		jmp loop

loop:
		mov cl, [rsi + rax]
		mov [rdi + rax], cl
		cmp cl, 0
		je end
		inc rax
		jmp loop

end:
		mov rax, rdi
		ret
