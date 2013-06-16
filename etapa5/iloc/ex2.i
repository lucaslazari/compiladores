//
// Simple example program
//
// Assign STATIC_AREA_ADDRESS to register "r0" - begining
loadI 1024 => r0

loadI 12 => r1
storeAI r1 => r0, 0

loadI 23 => r2
storeAI r2 => r0, 4

add r1, r2 => r5
storeAI r5 => r0, 8

output 1024
output 1028
output 1032
