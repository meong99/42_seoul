segment .text
		global	_ft_strdup
		extern	_ft_strlen
		extern	_ft_strcpy
		extern	_malloc

_ft_strdup:
		push	rdi
		call	_ft_strlen
		add		rax, 1
		mov		rdi, rax
		call	_malloc
		cmp		rax, 0
		je		_err
		pop		rdi
		mov		rsi, rdi
		mov		rdi, rax
		call	_ft_strcpy
		ret

_err:
		xor		rax, rax
		ret
