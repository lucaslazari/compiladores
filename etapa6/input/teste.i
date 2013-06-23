loadAI bss, 0 => r0
loadAI bss, 4 => r1
cmp_LT r0, r1 -> r2
cbr r2 -> L2, L1
L2: loadAI bss, 4 => r1
loadI 1 => r3
add r1, r3 => r4
storeAI r4 => bss, 0
jumpI -> L3
L1: loadAI bss, 0 => r0
loadI 4 => r5
add r0, r5 => r4
storeAI r4 => bss, 4
L3: nop
