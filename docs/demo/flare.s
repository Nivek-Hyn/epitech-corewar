	.name "Flare"
	.comment "2 painters: 1 forward, 1 backward"

# Forks into 2 processes. Each one paints a window of memory with
# changing words, then starts over; windows are relative to the paint
# instruction (sti r6, r2, %0). Generated for the README demo.

begin:	sti r1, %:lv, %1
	ld %265083651, r6
	ld %330480353, r7
	ld %1, r10
	ld %-136, r12
	ld %-12, r3
	ld %30, r13
	fork %:reset
	ld %204, r12
	ld %12, r3
	ld %24, r13
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
