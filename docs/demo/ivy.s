	.name "Ivy"
	.comment "3 painters: 2 forward, 1 backward"

# Forks into 3 processes. Each one paints a window of memory with
# changing words, then starts over; windows are relative to the paint
# instruction (sti r6, r2, %0). Generated for the README demo.

begin:	sti r1, %:lv, %1
	ld %1632862684, r6
	ld %232245513, r7
	ld %1, r10
	ld %80, r12
	ld %4, r3
	ld %87, r13
	fork %:reset
	ld %-172, r12
	ld %-8, r3
	ld %41, r13
	fork %:reset
	ld %48, r12
	ld %8, r3
	ld %41, r13
reset:	add r12, r14, r2
	add r13, r14, r9
lv:	live %0
	sti r6, r2, %0
	add r2, r3, r2
	add r6, r7, r6
	sub r9, r10, r9
	zjmp %:reset
	ld %0, r8
	zjmp %:lv
