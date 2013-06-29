loadI 40 => rBSS
L5: nop
L1: loadAI rBSS, 0 => r0
loadAI rFP, 0 => r1
cmp_GT r0, r1 -> r2
cbr r2 -> L2, L3
L2: loadI 1 => r3
storeAI r3 => bss, 0
jumpI -> L1
L3: nop
