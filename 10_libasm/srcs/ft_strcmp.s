segment .text
		global _ft_strcmp

_ft_strcmp:
		mov	al, [rdi]
		mov	bl, [rsi]
		cmp al, 0
		je	end
		cmp bl, 0
		je	end
		cmp	al, bl
		jl	diff_less
		cmp al, bl
		jg	diff_greater
		inc	rdi
		inc	rsi
		jmp	_ft_strcmp

diff_less:
		mov rax, -1
		ret

diff_greater:
		mov rax, 1
		ret
end:
		cmp al, bl
		jl	diff_less
		cmp al, bl
		jg	diff_greater
		mov rax, 0
		ret
