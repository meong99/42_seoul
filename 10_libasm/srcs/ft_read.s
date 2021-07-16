global _ft_read
extern ___error
section .text

_ft_read:
		mov		rax, 3
		syscall
		jc		_err
		ret

_err:
		push	rax
		call	___error
		pop		rdx
		mov		[rax], rdx
		mov		rax, -1
		ret
