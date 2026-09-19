; --------------------------------------------
; Programa: comparacao.asm
; Autor: Guilherme Correia Leal
; Descrição:
; Armazena dois números em EAX e EBX.
; Se forem iguais, calcula o dobro de um deles e guarda em ECX.
; Se forem diferentes, calcula a diferença positiva e guarda em ECX.
; --------------------------------------------

.386                          ; Define instruções do processador 80386
.model flat, stdcall           ; Modelo de memória flat (usado em Windows)
option casemap:none            ; Torna nomes case-sensitive

include \masm32\include\kernel32.inc
include \masm32\include\masm32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\masm32.lib

.data
    msgIgual db "Os números são iguais. Dobro armazenado em ECX.", 0
    msgDif   db "Os números são diferentes. Diferença armazenada em ECX.", 0

.code
main:
    ; Armazena dois números inteiros nos registradores
    mov EAX, 10            ; Primeiro número
    mov EBX, 25            ; Segundo número

    ; Compara EAX com EBX
    cmp EAX, EBX
    je  numerosIguais      ; Se forem iguais, pula para numerosIguais
    jne numerosDiferentes  ; Se forem diferentes, pula para numerosDiferentes

numerosIguais:
    ; Calcula o dobro de um deles (EAX * 2)
    mov ECX, EAX           ; Copia o valor de EAX para ECX
    add ECX, EAX           ; Soma ECX + EAX (dobro)
    invoke StdOut, addr msgIgual
    jmp fim                ; Pula para o final do programa

numerosDiferentes:
    ; Calcula a diferença sempre positiva
    mov ECX, EAX           ; Copia o valor de EAX em ECX
    cmp EAX, EBX
    jg  subtraiEAXmenor    ; Se EAX > EBX, vai para subtraiEAXmenor
    sub EBX, EAX           ; Caso contrário, EBX > EAX → faz EBX - EAX
    mov ECX, EBX           ; Guarda resultado em ECX
    invoke StdOut, addr msgDif
    jmp fim

subtraiEAXmenor:
    sub EAX, EBX           ; Calcula EAX - EBX
    mov ECX, EAX           ; Guarda resultado em ECX
    invoke StdOut, addr msgDif
    jmp fim

fim:
    invoke ExitProcess, 0   ; Finaliza o programa
end main
