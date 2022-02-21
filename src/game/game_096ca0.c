#include <ultra64.h>
#include "constants.h"
#include "game/acosfasinf.h"
#include "game/game_096ca0.h"
#include "bss.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

const u32 var7f1ab870[] = {0x3c23d70a};
const u32 var7f1ab874[] = {0xbf7fff58};
const u32 var7f1ab878[] = {0x3f7fff58};
const u32 var7f1ab87c[] = {0xbf7fff58};
const u32 var7f1ab880[] = {0x3f7fff58};
const u32 var7f1ab884[] = {0x00000000};
const u32 var7f1ab888[] = {0x00000000};
const u32 var7f1ab88c[] = {0x00000000};

u32 var8006afa0 = 0x00000001;
u32 var8006afa4 = 0x00000002;

void quaternion0f096ca0(struct coord *angle, f32 quat[4])
{
	f32 cosx = cosf(angle->f[0] * 0.5f);
	f32 sinx = sinf(angle->f[0] * 0.5f);
	f32 cosy = cosf(angle->f[1] * 0.5f);
	f32 siny = sinf(angle->f[1] * 0.5f);
	f32 cosz = cosf(angle->f[2] * 0.5f);
	f32 sinz = sinf(angle->f[2] * 0.5f);

	f32 cosx_cosy = cosx * cosy;
	f32 cosx_siny = cosx * siny;
	f32 sinx_cosy = sinx * cosy;
	f32 sinx_siny = sinx * siny;

	quat[0] = cosx_cosy * cosz + sinx_siny * sinz;
	quat[1] = sinx_cosy * cosz - cosx_siny * sinz;
	quat[2] = cosx_siny * cosz + sinx_cosy * sinz;
	quat[3] = cosx_cosy * sinz - sinx_siny * cosz;
}

void quaternionSetRotationAroundX(f32 angle, f32 quat[4])
{
	quat[0] = cosf(angle * 0.5f);
	quat[1] = sinf(angle * 0.5f);
	quat[2] = 0.0f;
	quat[3] = 0.0f;
}

void quaternionSetRotationAroundY(f32 angle, f32 quat[4])
{
	quat[0] = cosf(angle * 0.5f);
	quat[1] = 0.0f;
	quat[2] = sinf(angle * 0.5f);
	quat[3] = 0.0f;
}

void quaternionSetRotationAroundZ(f32 angle, f32 quat[4])
{
	quat[0] = cosf(angle * 0.5f);
	quat[1] = 0.0f;
	quat[2] = 0.0f;
	quat[3] = sinf(angle * 0.5f);
}

GLOBAL_ASM(
glabel func0f096ed4
/*  f096ed4:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f096ed8:	f7b40008 */ 	sdc1	$f20,0x8($sp)
/*  f096edc:	c4940000 */ 	lwc1	$f20,0x0($a0)
/*  f096ee0:	c4800004 */ 	lwc1	$f0,0x4($a0)
/*  f096ee4:	c4820008 */ 	lwc1	$f2,0x8($a0)
/*  f096ee8:	4614a102 */ 	mul.s	$f4,$f20,$f20
/*  f096eec:	c48c000c */ 	lwc1	$f12,0xc($a0)
/*  f096ef0:	3c014000 */ 	lui	$at,0x4000
/*  f096ef4:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f096ef8:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f096efc:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f096f00:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f096f04:	460c6182 */ 	mul.s	$f6,$f12,$f12
/*  f096f08:	44815000 */ 	mtc1	$at,$f10
/*  f096f0c:	3c013f80 */ 	lui	$at,0x3f80
/*  f096f10:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f096f14:	46085183 */ 	div.s	$f6,$f10,$f8
/*  f096f18:	46060482 */ 	mul.s	$f18,$f0,$f6
/*  f096f1c:	e7a60044 */ 	swc1	$f6,0x44($sp)
/*  f096f20:	46061402 */ 	mul.s	$f16,$f2,$f6
/*  f096f24:	00000000 */ 	nop
/*  f096f28:	46066382 */ 	mul.s	$f14,$f12,$f6
/*  f096f2c:	00000000 */ 	nop
/*  f096f30:	4612a102 */ 	mul.s	$f4,$f20,$f18
/*  f096f34:	00000000 */ 	nop
/*  f096f38:	4610a282 */ 	mul.s	$f10,$f20,$f16
/*  f096f3c:	00000000 */ 	nop
/*  f096f40:	460ea202 */ 	mul.s	$f8,$f20,$f14
/*  f096f44:	e7a40034 */ 	swc1	$f4,0x34($sp)
/*  f096f48:	46120182 */ 	mul.s	$f6,$f0,$f18
/*  f096f4c:	e7aa0030 */ 	swc1	$f10,0x30($sp)
/*  f096f50:	46100102 */ 	mul.s	$f4,$f0,$f16
/*  f096f54:	e7a8002c */ 	swc1	$f8,0x2c($sp)
/*  f096f58:	460e0282 */ 	mul.s	$f10,$f0,$f14
/*  f096f5c:	e7a60028 */ 	swc1	$f6,0x28($sp)
/*  f096f60:	44800000 */ 	mtc1	$zero,$f0
/*  f096f64:	46101202 */ 	mul.s	$f8,$f2,$f16
/*  f096f68:	e7a40024 */ 	swc1	$f4,0x24($sp)
/*  f096f6c:	44818000 */ 	mtc1	$at,$f16
/*  f096f70:	460e1182 */ 	mul.s	$f6,$f2,$f14
/*  f096f74:	e7aa0020 */ 	swc1	$f10,0x20($sp)
/*  f096f78:	460e6102 */ 	mul.s	$f4,$f12,$f14
/*  f096f7c:	e7a8001c */ 	swc1	$f8,0x1c($sp)
/*  f096f80:	c7aa001c */ 	lwc1	$f10,0x1c($sp)
/*  f096f84:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*  f096f88:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f096f8c:	c7a80014 */ 	lwc1	$f8,0x14($sp)
/*  f096f90:	44812000 */ 	mtc1	$at,$f4
/*  f096f94:	46085180 */ 	add.s	$f6,$f10,$f8
/*  f096f98:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f096f9c:	e4aa0000 */ 	swc1	$f10,0x0($a1)
/*  f096fa0:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
/*  f096fa4:	c7a80024 */ 	lwc1	$f8,0x24($sp)
/*  f096fa8:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f096fac:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*  f096fb0:	c7a80030 */ 	lwc1	$f8,0x30($sp)
/*  f096fb4:	c7aa0020 */ 	lwc1	$f10,0x20($sp)
/*  f096fb8:	46085101 */ 	sub.s	$f4,$f10,$f8
/*  f096fbc:	e4a40008 */ 	swc1	$f4,0x8($a1)
/*  f096fc0:	c7aa002c */ 	lwc1	$f10,0x2c($sp)
/*  f096fc4:	c7a60024 */ 	lwc1	$f6,0x24($sp)
/*  f096fc8:	c7ae0018 */ 	lwc1	$f14,0x18($sp)
/*  f096fcc:	c7ac0028 */ 	lwc1	$f12,0x28($sp)
/*  f096fd0:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f096fd4:	c7a20034 */ 	lwc1	$f2,0x34($sp)
/*  f096fd8:	e4a80010 */ 	swc1	$f8,0x10($a1)
/*  f096fdc:	c7a40014 */ 	lwc1	$f4,0x14($sp)
/*  f096fe0:	46027200 */ 	add.s	$f8,$f14,$f2
/*  f096fe4:	46046180 */ 	add.s	$f6,$f12,$f4
/*  f096fe8:	e4a80018 */ 	swc1	$f8,0x18($a1)
/*  f096fec:	46027201 */ 	sub.s	$f8,$f14,$f2
/*  f096ff0:	46068281 */ 	sub.s	$f10,$f16,$f6
/*  f096ff4:	e4aa0014 */ 	swc1	$f10,0x14($a1)
/*  f096ff8:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*  f096ffc:	c7a40020 */ 	lwc1	$f4,0x20($sp)
/*  f097000:	e4a80024 */ 	swc1	$f8,0x24($a1)
/*  f097004:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f097008:	e4aa0020 */ 	swc1	$f10,0x20($a1)
/*  f09700c:	c7a4001c */ 	lwc1	$f4,0x1c($sp)
/*  f097010:	e4a00030 */ 	swc1	$f0,0x30($a1)
/*  f097014:	e4a00034 */ 	swc1	$f0,0x34($a1)
/*  f097018:	46046180 */ 	add.s	$f6,$f12,$f4
/*  f09701c:	e4a00038 */ 	swc1	$f0,0x38($a1)
/*  f097020:	e4a0000c */ 	swc1	$f0,0xc($a1)
/*  f097024:	e4a0001c */ 	swc1	$f0,0x1c($a1)
/*  f097028:	46068281 */ 	sub.s	$f10,$f16,$f6
/*  f09702c:	e4a0002c */ 	swc1	$f0,0x2c($a1)
/*  f097030:	e4b0003c */ 	swc1	$f16,0x3c($a1)
/*  f097034:	e4aa0028 */ 	swc1	$f10,0x28($a1)
/*  f097038:	d7b40008 */ 	ldc1	$f20,0x8($sp)
/*  f09703c:	03e00008 */ 	jr	$ra
/*  f097040:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0f097044
/*  f097044:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f097048:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f09704c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f097050:	c4860014 */ 	lwc1	$f6,0x14($a0)
/*  f097054:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f097058:	c48a0028 */ 	lwc1	$f10,0x28($a0)
/*  f09705c:	3c013f80 */ 	lui	$at,0x3f80
/*  f097060:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f097064:	44811000 */ 	mtc1	$at,$f2
/*  f097068:	3c017f1b */ 	lui	$at,%hi(var7f1ab870)
/*  f09706c:	c432b870 */ 	lwc1	$f18,%lo(var7f1ab870)($at)
/*  f097070:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f097074:	3c0e8007 */ 	lui	$t6,%hi(var8006afa0)
/*  f097078:	00a08025 */ 	or	$s0,$a1,$zero
/*  f09707c:	25ceafa0 */ 	addiu	$t6,$t6,%lo(var8006afa0)
/*  f097080:	46028300 */ 	add.s	$f12,$f16,$f2
/*  f097084:	460c903c */ 	c.lt.s	$f18,$f12
/*  f097088:	00000000 */ 	nop
/*  f09708c:	4502001a */ 	bc1fl	.L0f0970f8
/*  f097090:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f097094:	0c012974 */ 	jal	sqrtf
/*  f097098:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f09709c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0970a0:	44816000 */ 	mtc1	$at,$f12
/*  f0970a4:	8fa40060 */ 	lw	$a0,0x60($sp)
/*  f0970a8:	46006083 */ 	div.s	$f2,$f12,$f0
/*  f0970ac:	460c0102 */ 	mul.s	$f4,$f0,$f12
/*  f0970b0:	e6040000 */ 	swc1	$f4,0x0($s0)
/*  f0970b4:	c48a0024 */ 	lwc1	$f10,0x24($a0)
/*  f0970b8:	c4860018 */ 	lwc1	$f6,0x18($a0)
/*  f0970bc:	460a3201 */ 	sub.s	$f8,$f6,$f10
/*  f0970c0:	46024402 */ 	mul.s	$f16,$f8,$f2
/*  f0970c4:	e6100004 */ 	swc1	$f16,0x4($s0)
/*  f0970c8:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f0970cc:	c4920020 */ 	lwc1	$f18,0x20($a0)
/*  f0970d0:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f0970d4:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f0970d8:	e60a0008 */ 	swc1	$f10,0x8($s0)
/*  f0970dc:	c4900010 */ 	lwc1	$f16,0x10($a0)
/*  f0970e0:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f0970e4:	46104481 */ 	sub.s	$f18,$f8,$f16
/*  f0970e8:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f0970ec:	10000058 */ 	b	.L0f097250
/*  f0970f0:	e604000c */ 	swc1	$f4,0xc($s0)
/*  f0970f4:	8dc10000 */ 	lw	$at,0x0($t6)
.L0f0970f8:
/*  f0970f8:	27ab0040 */ 	addiu	$t3,$sp,0x40
/*  f0970fc:	00002825 */ 	or	$a1,$zero,$zero
/*  f097100:	ad610000 */ 	sw	$at,0x0($t3)
/*  f097104:	8dd80004 */ 	lw	$t8,0x4($t6)
/*  f097108:	ad780004 */ 	sw	$t8,0x4($t3)
/*  f09710c:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f097110:	ad610008 */ 	sw	$at,0x8($t3)
/*  f097114:	c48a0014 */ 	lwc1	$f10,0x14($a0)
/*  f097118:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f09711c:	460a303c */ 	c.lt.s	$f6,$f10
/*  f097120:	00000000 */ 	nop
/*  f097124:	45020003 */ 	bc1fl	.L0f097134
/*  f097128:	0005c900 */ 	sll	$t9,$a1,0x4
/*  f09712c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f097130:	0005c900 */ 	sll	$t9,$a1,0x4
.L0f097134:
/*  f097134:	00991821 */ 	addu	$v1,$a0,$t9
/*  f097138:	00051080 */ 	sll	$v0,$a1,0x2
/*  f09713c:	00626021 */ 	addu	$t4,$v1,$v0
/*  f097140:	c5800000 */ 	lwc1	$f0,0x0($t4)
/*  f097144:	c4880028 */ 	lwc1	$f8,0x28($a0)
/*  f097148:	4608003c */ 	c.lt.s	$f0,$f8
/*  f09714c:	00000000 */ 	nop
/*  f097150:	45020005 */ 	bc1fl	.L0f097168
/*  f097154:	01626821 */ 	addu	$t5,$t3,$v0
/*  f097158:	24830020 */ 	addiu	$v1,$a0,0x20
/*  f09715c:	c4600008 */ 	lwc1	$f0,0x8($v1)
/*  f097160:	24020008 */ 	addiu	$v0,$zero,0x8
/*  f097164:	01626821 */ 	addu	$t5,$t3,$v0
.L0f097168:
/*  f097168:	8da50000 */ 	lw	$a1,0x0($t5)
/*  f09716c:	00053880 */ 	sll	$a3,$a1,0x2
/*  f097170:	01677821 */ 	addu	$t7,$t3,$a3
/*  f097174:	8de60000 */ 	lw	$a2,0x0($t7)
/*  f097178:	0005c100 */ 	sll	$t8,$a1,0x4
/*  f09717c:	00985021 */ 	addu	$t2,$a0,$t8
/*  f097180:	00067100 */ 	sll	$t6,$a2,0x4
/*  f097184:	008e4821 */ 	addu	$t1,$a0,$t6
/*  f097188:	00064080 */ 	sll	$t0,$a2,0x2
/*  f09718c:	0128c821 */ 	addu	$t9,$t1,$t0
/*  f097190:	01476021 */ 	addu	$t4,$t2,$a3
/*  f097194:	c5920000 */ 	lwc1	$f18,0x0($t4)
/*  f097198:	c7300000 */ 	lwc1	$f16,0x0($t9)
/*  f09719c:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f0971a0:	afa90028 */ 	sw	$t1,0x28($sp)
/*  f0971a4:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f0971a8:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f0971ac:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f0971b0:	afa30038 */ 	sw	$v1,0x38($sp)
/*  f0971b4:	46040181 */ 	sub.s	$f6,$f0,$f4
/*  f0971b8:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f0971bc:	0c012974 */ 	jal	sqrtf
/*  f0971c0:	46023300 */ 	add.s	$f12,$f6,$f2
/*  f0971c4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0971c8:	44816000 */ 	mtc1	$at,$f12
/*  f0971cc:	8fa20034 */ 	lw	$v0,0x34($sp)
/*  f0971d0:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f0971d4:	46006083 */ 	div.s	$f2,$f12,$f0
/*  f0971d8:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f0971dc:	8fa90028 */ 	lw	$t1,0x28($sp)
/*  f0971e0:	8faa0020 */ 	lw	$t2,0x20($sp)
/*  f0971e4:	460c0282 */ 	mul.s	$f10,$f0,$f12
/*  f0971e8:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f0971ec:	02026821 */ 	addu	$t5,$s0,$v0
/*  f0971f0:	01277021 */ 	addu	$t6,$t1,$a3
/*  f0971f4:	01487821 */ 	addu	$t7,$t2,$t0
/*  f0971f8:	0142c021 */ 	addu	$t8,$t2,$v0
/*  f0971fc:	0067c821 */ 	addu	$t9,$v1,$a3
/*  f097200:	e5aa0004 */ 	swc1	$f10,0x4($t5)
/*  f097204:	c5e80000 */ 	lwc1	$f8,0x0($t7)
/*  f097208:	c5d00000 */ 	lwc1	$f16,0x0($t6)
/*  f09720c:	02076021 */ 	addu	$t4,$s0,$a3
/*  f097210:	01226821 */ 	addu	$t5,$t1,$v0
/*  f097214:	00687821 */ 	addu	$t7,$v1,$t0
/*  f097218:	02087021 */ 	addu	$t6,$s0,$t0
/*  f09721c:	46104481 */ 	sub.s	$f18,$f8,$f16
/*  f097220:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f097224:	e6040000 */ 	swc1	$f4,0x0($s0)
/*  f097228:	c72a0000 */ 	lwc1	$f10,0x0($t9)
/*  f09722c:	c7060000 */ 	lwc1	$f6,0x0($t8)
/*  f097230:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f097234:	46024402 */ 	mul.s	$f16,$f8,$f2
/*  f097238:	e5900004 */ 	swc1	$f16,0x4($t4)
/*  f09723c:	c5e40000 */ 	lwc1	$f4,0x0($t7)
/*  f097240:	c5b20000 */ 	lwc1	$f18,0x0($t5)
/*  f097244:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f097248:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f09724c:	e5ca0004 */ 	swc1	$f10,0x4($t6)
.L0f097250:
/*  f097250:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f097254:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f097258:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f09725c:	03e00008 */ 	jr	$ra
/*  f097260:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f097264
/*  f097264:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f097268:	00803825 */ 	or	$a3,$a0,$zero
/*  f09726c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f097270:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f097274:	00a02025 */ 	or	$a0,$a1,$zero
/*  f097278:	00c02825 */ 	or	$a1,$a2,$zero
/*  f09727c:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f097280:	0fc25bb5 */ 	jal	func0f096ed4
/*  f097284:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f097288:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f09728c:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f097290:	c4e40000 */ 	lwc1	$f4,0x0($a3)
/*  f097294:	e4c40030 */ 	swc1	$f4,0x30($a2)
/*  f097298:	c4e60004 */ 	lwc1	$f6,0x4($a3)
/*  f09729c:	e4c60034 */ 	swc1	$f6,0x34($a2)
/*  f0972a0:	c4e80008 */ 	lwc1	$f8,0x8($a3)
/*  f0972a4:	e4c80038 */ 	swc1	$f8,0x38($a2)
/*  f0972a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0972ac:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0972b0:	03e00008 */ 	jr	$ra
/*  f0972b4:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0972b8
/*  f0972b8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0972bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0972c0:	c4a60004 */ 	lwc1	$f6,0x4($a1)
/*  f0972c4:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*  f0972c8:	c4b00000 */ 	lwc1	$f16,0x0($a1)
/*  f0972cc:	c4820000 */ 	lwc1	$f2,0x0($a0)
/*  f0972d0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0972d4:	c4a60008 */ 	lwc1	$f6,0x8($a1)
/*  f0972d8:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f0972dc:	46101282 */ 	mul.s	$f10,$f2,$f16
/*  f0972e0:	3c017f1b */ 	lui	$at,%hi(var7f1ab874)
/*  f0972e4:	44867000 */ 	mtc1	$a2,$f14
/*  f0972e8:	46085480 */ 	add.s	$f18,$f10,$f8
/*  f0972ec:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f0972f0:	c486000c */ 	lwc1	$f6,0xc($a0)
/*  f0972f4:	c4a4000c */ 	lwc1	$f4,0xc($a1)
/*  f0972f8:	460a9200 */ 	add.s	$f8,$f18,$f10
/*  f0972fc:	46062482 */ 	mul.s	$f18,$f4,$f6
/*  f097300:	c42ab874 */ 	lwc1	$f10,%lo(var7f1ab874)($at)
/*  f097304:	3c017f1b */ 	lui	$at,%hi(var7f1ab878)
/*  f097308:	46089300 */ 	add.s	$f12,$f18,$f8
/*  f09730c:	460a603c */ 	c.lt.s	$f12,$f10
/*  f097310:	00000000 */ 	nop
/*  f097314:	45000020 */ 	bc1f	.L0f097398
/*  f097318:	00000000 */ 	nop
/*  f09731c:	3c013f80 */ 	lui	$at,0x3f80
/*  f097320:	44812000 */ 	mtc1	$at,$f4
/*  f097324:	00000000 */ 	nop
/*  f097328:	460e2001 */ 	sub.s	$f0,$f4,$f14
/*  f09732c:	46020182 */ 	mul.s	$f6,$f0,$f2
/*  f097330:	00000000 */ 	nop
/*  f097334:	460e8482 */ 	mul.s	$f18,$f16,$f14
/*  f097338:	46123201 */ 	sub.s	$f8,$f6,$f18
/*  f09733c:	e4e80000 */ 	swc1	$f8,0x0($a3)
/*  f097340:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f097344:	c4a60004 */ 	lwc1	$f6,0x4($a1)
/*  f097348:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f09734c:	00000000 */ 	nop
/*  f097350:	460e3482 */ 	mul.s	$f18,$f6,$f14
/*  f097354:	46122201 */ 	sub.s	$f8,$f4,$f18
/*  f097358:	e4e80004 */ 	swc1	$f8,0x4($a3)
/*  f09735c:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f097360:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*  f097364:	460a0182 */ 	mul.s	$f6,$f0,$f10
/*  f097368:	00000000 */ 	nop
/*  f09736c:	460e2482 */ 	mul.s	$f18,$f4,$f14
/*  f097370:	46123201 */ 	sub.s	$f8,$f6,$f18
/*  f097374:	e4e80008 */ 	swc1	$f8,0x8($a3)
/*  f097378:	c48a000c */ 	lwc1	$f10,0xc($a0)
/*  f09737c:	c4a6000c */ 	lwc1	$f6,0xc($a1)
/*  f097380:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f097384:	00000000 */ 	nop
/*  f097388:	460e3482 */ 	mul.s	$f18,$f6,$f14
/*  f09738c:	46122201 */ 	sub.s	$f8,$f4,$f18
/*  f097390:	1000005d */ 	b	.L0f097508
/*  f097394:	e4e8000c */ 	swc1	$f8,0xc($a3)
.L0f097398:
/*  f097398:	c42ab878 */ 	lwc1	$f10,%lo(var7f1ab878)($at)
/*  f09739c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0973a0:	460a603e */ 	c.le.s	$f12,$f10
/*  f0973a4:	00000000 */ 	nop
/*  f0973a8:	4502003d */ 	bc1fl	.L0f0974a0
/*  f0973ac:	44812000 */ 	mtc1	$at,$f4
/*  f0973b0:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f0973b4:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f0973b8:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f0973bc:	0fc25a74 */ 	jal	acosf
/*  f0973c0:	e7ae0038 */ 	swc1	$f14,0x38($sp)
/*  f0973c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0973c8:	c7ae0038 */ 	lwc1	$f14,0x38($sp)
/*  f0973cc:	44813000 */ 	mtc1	$at,$f6
/*  f0973d0:	46000306 */ 	mov.s	$f12,$f0
/*  f0973d4:	460e3101 */ 	sub.s	$f4,$f6,$f14
/*  f0973d8:	46002482 */ 	mul.s	$f18,$f4,$f0
/*  f0973dc:	00000000 */ 	nop
/*  f0973e0:	46007202 */ 	mul.s	$f8,$f14,$f0
/*  f0973e4:	e7b20024 */ 	swc1	$f18,0x24($sp)
/*  f0973e8:	0c0068f7 */ 	jal	sinf
/*  f0973ec:	e7a80020 */ 	swc1	$f8,0x20($sp)
/*  f0973f0:	e7a0001c */ 	swc1	$f0,0x1c($sp)
/*  f0973f4:	0c0068f7 */ 	jal	sinf
/*  f0973f8:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*  f0973fc:	c7aa001c */ 	lwc1	$f10,0x1c($sp)
/*  f097400:	c7ac0020 */ 	lwc1	$f12,0x20($sp)
/*  f097404:	460a0383 */ 	div.s	$f14,$f0,$f10
/*  f097408:	0c0068f7 */ 	jal	sinf
/*  f09740c:	e7ae0018 */ 	swc1	$f14,0x18($sp)
/*  f097410:	c7a6001c */ 	lwc1	$f6,0x1c($sp)
/*  f097414:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f097418:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f09741c:	46060083 */ 	div.s	$f2,$f0,$f6
/*  f097420:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f097424:	c7ae0018 */ 	lwc1	$f14,0x18($sp)
/*  f097428:	c4880000 */ 	lwc1	$f8,0x0($a0)
/*  f09742c:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*  f097430:	46022482 */ 	mul.s	$f18,$f4,$f2
/*  f097434:	00000000 */ 	nop
/*  f097438:	46087282 */ 	mul.s	$f10,$f14,$f8
/*  f09743c:	460a9180 */ 	add.s	$f6,$f18,$f10
/*  f097440:	e4e60000 */ 	swc1	$f6,0x0($a3)
/*  f097444:	c4a40004 */ 	lwc1	$f4,0x4($a1)
/*  f097448:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*  f09744c:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f097450:	00000000 */ 	nop
/*  f097454:	46127282 */ 	mul.s	$f10,$f14,$f18
/*  f097458:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f09745c:	e4e60004 */ 	swc1	$f6,0x4($a3)
/*  f097460:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*  f097464:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f097468:	46022482 */ 	mul.s	$f18,$f4,$f2
/*  f09746c:	00000000 */ 	nop
/*  f097470:	46087282 */ 	mul.s	$f10,$f14,$f8
/*  f097474:	460a9180 */ 	add.s	$f6,$f18,$f10
/*  f097478:	e4e60008 */ 	swc1	$f6,0x8($a3)
/*  f09747c:	c4a4000c */ 	lwc1	$f4,0xc($a1)
/*  f097480:	c492000c */ 	lwc1	$f18,0xc($a0)
/*  f097484:	46022202 */ 	mul.s	$f8,$f4,$f2
/*  f097488:	00000000 */ 	nop
/*  f09748c:	46127282 */ 	mul.s	$f10,$f14,$f18
/*  f097490:	460a4180 */ 	add.s	$f6,$f8,$f10
/*  f097494:	1000001c */ 	b	.L0f097508
/*  f097498:	e4e6000c */ 	swc1	$f6,0xc($a3)
/*  f09749c:	44812000 */ 	mtc1	$at,$f4
.L0f0974a0:
/*  f0974a0:	460e8482 */ 	mul.s	$f18,$f16,$f14
/*  f0974a4:	460e2001 */ 	sub.s	$f0,$f4,$f14
/*  f0974a8:	46020202 */ 	mul.s	$f8,$f0,$f2
/*  f0974ac:	46089280 */ 	add.s	$f10,$f18,$f8
/*  f0974b0:	e4ea0000 */ 	swc1	$f10,0x0($a3)
/*  f0974b4:	c4a60004 */ 	lwc1	$f6,0x4($a1)
/*  f0974b8:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*  f0974bc:	460e3102 */ 	mul.s	$f4,$f6,$f14
/*  f0974c0:	00000000 */ 	nop
/*  f0974c4:	46120202 */ 	mul.s	$f8,$f0,$f18
/*  f0974c8:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0974cc:	e4ea0004 */ 	swc1	$f10,0x4($a3)
/*  f0974d0:	c4a60008 */ 	lwc1	$f6,0x8($a1)
/*  f0974d4:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f0974d8:	460e3482 */ 	mul.s	$f18,$f6,$f14
/*  f0974dc:	00000000 */ 	nop
/*  f0974e0:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f0974e4:	46089280 */ 	add.s	$f10,$f18,$f8
/*  f0974e8:	e4ea0008 */ 	swc1	$f10,0x8($a3)
/*  f0974ec:	c4a6000c */ 	lwc1	$f6,0xc($a1)
/*  f0974f0:	c492000c */ 	lwc1	$f18,0xc($a0)
/*  f0974f4:	460e3102 */ 	mul.s	$f4,$f6,$f14
/*  f0974f8:	00000000 */ 	nop
/*  f0974fc:	46120202 */ 	mul.s	$f8,$f0,$f18
/*  f097500:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f097504:	e4ea000c */ 	swc1	$f10,0xc($a3)
.L0f097508:
/*  f097508:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f09750c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f097510:	03e00008 */ 	jr	$ra
/*  f097514:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f097518
/*  f097518:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f09751c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f097520:	c4800000 */ 	lwc1	$f0,0x0($a0)
/*  f097524:	44802000 */ 	mtc1	$zero,$f4
/*  f097528:	3c013f80 */ 	lui	$at,0x3f80
/*  f09752c:	44811000 */ 	mtc1	$at,$f2
/*  f097530:	4604003c */ 	c.lt.s	$f0,$f4
/*  f097534:	44857000 */ 	mtc1	$a1,$f14
/*  f097538:	3c017f1b */ 	lui	$at,%hi(var7f1ab87c)
/*  f09753c:	46000306 */ 	mov.s	$f12,$f0
/*  f097540:	45000003 */ 	bc1f	.L0f097550
/*  f097544:	46001406 */ 	mov.s	$f16,$f2
/*  f097548:	46006307 */ 	neg.s	$f12,$f12
/*  f09754c:	46001407 */ 	neg.s	$f16,$f2
.L0f097550:
/*  f097550:	c426b87c */ 	lwc1	$f6,%lo(var7f1ab87c)($at)
/*  f097554:	3c017f1b */ 	lui	$at,%hi(var7f1ab880)
/*  f097558:	4606603c */ 	c.lt.s	$f12,$f6
/*  f09755c:	00000000 */ 	nop
/*  f097560:	45000011 */ 	bc1f	.L0f0975a8
/*  f097564:	00000000 */ 	nop
/*  f097568:	460e1281 */ 	sub.s	$f10,$f2,$f14
/*  f09756c:	460e0202 */ 	mul.s	$f8,$f0,$f14
/*  f097570:	00000000 */ 	nop
/*  f097574:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f097578:	46124101 */ 	sub.s	$f4,$f8,$f18
/*  f09757c:	e4c40000 */ 	swc1	$f4,0x0($a2)
/*  f097580:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f097584:	460e3282 */ 	mul.s	$f10,$f6,$f14
/*  f097588:	e4ca0004 */ 	swc1	$f10,0x4($a2)
/*  f09758c:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f097590:	460e4482 */ 	mul.s	$f18,$f8,$f14
/*  f097594:	e4d20008 */ 	swc1	$f18,0x8($a2)
/*  f097598:	c484000c */ 	lwc1	$f4,0xc($a0)
/*  f09759c:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f0975a0:	10000043 */ 	b	.L0f0976b0
/*  f0975a4:	e4c6000c */ 	swc1	$f6,0xc($a2)
.L0f0975a8:
/*  f0975a8:	c42ab880 */ 	lwc1	$f10,%lo(var7f1ab880)($at)
/*  f0975ac:	460a603e */ 	c.le.s	$f12,$f10
/*  f0975b0:	00000000 */ 	nop
/*  f0975b4:	45020030 */ 	bc1fl	.L0f097678
/*  f0975b8:	460e1201 */ 	sub.s	$f8,$f2,$f14
/*  f0975bc:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0975c0:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0975c4:	e7ae003c */ 	swc1	$f14,0x3c($sp)
/*  f0975c8:	0fc25a74 */ 	jal	acosf
/*  f0975cc:	e7b00030 */ 	swc1	$f16,0x30($sp)
/*  f0975d0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0975d4:	44811000 */ 	mtc1	$at,$f2
/*  f0975d8:	c7ae003c */ 	lwc1	$f14,0x3c($sp)
/*  f0975dc:	46000306 */ 	mov.s	$f12,$f0
/*  f0975e0:	460e1481 */ 	sub.s	$f18,$f2,$f14
/*  f0975e4:	46007202 */ 	mul.s	$f8,$f14,$f0
/*  f0975e8:	00000000 */ 	nop
/*  f0975ec:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0975f0:	e7a80028 */ 	swc1	$f8,0x28($sp)
/*  f0975f4:	0c0068f7 */ 	jal	sinf
/*  f0975f8:	e7a40024 */ 	swc1	$f4,0x24($sp)
/*  f0975fc:	e7a00020 */ 	swc1	$f0,0x20($sp)
/*  f097600:	0c0068f7 */ 	jal	sinf
/*  f097604:	c7ac0028 */ 	lwc1	$f12,0x28($sp)
/*  f097608:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*  f09760c:	c7ac0024 */ 	lwc1	$f12,0x24($sp)
/*  f097610:	46060083 */ 	div.s	$f2,$f0,$f6
/*  f097614:	0c0068f7 */ 	jal	sinf
/*  f097618:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f09761c:	c7b20020 */ 	lwc1	$f18,0x20($sp)
/*  f097620:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f097624:	c7a2001c */ 	lwc1	$f2,0x1c($sp)
/*  f097628:	46120103 */ 	div.s	$f4,$f0,$f18
/*  f09762c:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f097630:	c7b00030 */ 	lwc1	$f16,0x30($sp)
/*  f097634:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f097638:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f09763c:	00000000 */ 	nop
/*  f097640:	46102182 */ 	mul.s	$f6,$f4,$f16
/*  f097644:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f097648:	e4ca0000 */ 	swc1	$f10,0x0($a2)
/*  f09764c:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*  f097650:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f097654:	e4c40004 */ 	swc1	$f4,0x4($a2)
/*  f097658:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f09765c:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f097660:	e4c60008 */ 	swc1	$f6,0x8($a2)
/*  f097664:	c48a000c */ 	lwc1	$f10,0xc($a0)
/*  f097668:	46025482 */ 	mul.s	$f18,$f10,$f2
/*  f09766c:	10000010 */ 	b	.L0f0976b0
/*  f097670:	e4d2000c */ 	swc1	$f18,0xc($a2)
/*  f097674:	460e1201 */ 	sub.s	$f8,$f2,$f14
.L0f097678:
/*  f097678:	460e0102 */ 	mul.s	$f4,$f0,$f14
/*  f09767c:	00000000 */ 	nop
/*  f097680:	46104182 */ 	mul.s	$f6,$f8,$f16
/*  f097684:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f097688:	e4ca0000 */ 	swc1	$f10,0x0($a2)
/*  f09768c:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*  f097690:	460e9202 */ 	mul.s	$f8,$f18,$f14
/*  f097694:	e4c80004 */ 	swc1	$f8,0x4($a2)
/*  f097698:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f09769c:	460e2182 */ 	mul.s	$f6,$f4,$f14
/*  f0976a0:	e4c60008 */ 	swc1	$f6,0x8($a2)
/*  f0976a4:	c48a000c */ 	lwc1	$f10,0xc($a0)
/*  f0976a8:	460e5482 */ 	mul.s	$f18,$f10,$f14
/*  f0976ac:	e4d2000c */ 	swc1	$f18,0xc($a2)
.L0f0976b0:
/*  f0976b0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0976b4:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0976b8:	03e00008 */ 	jr	$ra
/*  f0976bc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0976c0
/*  f0976c0:	c4ac0000 */ 	lwc1	$f12,0x0($a1)
/*  f0976c4:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f0976c8:	c4ae0004 */ 	lwc1	$f14,0x4($a1)
/*  f0976cc:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f0976d0:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f0976d4:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f0976d8:	c4b00008 */ 	lwc1	$f16,0x8($a1)
/*  f0976dc:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*  f0976e0:	c4a2000c */ 	lwc1	$f2,0xc($a1)
/*  f0976e4:	46102202 */ 	mul.s	$f8,$f4,$f16
/*  f0976e8:	460a3480 */ 	add.s	$f18,$f6,$f10
/*  f0976ec:	c48a000c */ 	lwc1	$f10,0xc($a0)
/*  f0976f0:	460a1102 */ 	mul.s	$f4,$f2,$f10
/*  f0976f4:	46089180 */ 	add.s	$f6,$f18,$f8
/*  f0976f8:	44809000 */ 	mtc1	$zero,$f18
/*  f0976fc:	46062000 */ 	add.s	$f0,$f4,$f6
/*  f097700:	4612003c */ 	c.lt.s	$f0,$f18
/*  f097704:	00000000 */ 	nop
/*  f097708:	45000009 */ 	bc1f	.L0f097730
/*  f09770c:	00000000 */ 	nop
/*  f097710:	46006207 */ 	neg.s	$f8,$f12
/*  f097714:	46007287 */ 	neg.s	$f10,$f14
/*  f097718:	46008107 */ 	neg.s	$f4,$f16
/*  f09771c:	46001187 */ 	neg.s	$f6,$f2
/*  f097720:	e4a80000 */ 	swc1	$f8,0x0($a1)
/*  f097724:	e4aa0004 */ 	swc1	$f10,0x4($a1)
/*  f097728:	e4a40008 */ 	swc1	$f4,0x8($a1)
/*  f09772c:	e4a6000c */ 	swc1	$f6,0xc($a1)
.L0f097730:
/*  f097730:	03e00008 */ 	jr	$ra
/*  f097734:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f097738
/*  f097738:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f09773c:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f097740:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f097744:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f097748:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f09774c:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f097750:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f097754:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*  f097758:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f09775c:	c486000c */ 	lwc1	$f6,0xc($a0)
/*  f097760:	46124101 */ 	sub.s	$f4,$f8,$f18
/*  f097764:	c4b2000c */ 	lwc1	$f18,0xc($a1)
/*  f097768:	46069282 */ 	mul.s	$f10,$f18,$f6
/*  f09776c:	46102201 */ 	sub.s	$f8,$f4,$f16
/*  f097770:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f097774:	e4c40000 */ 	swc1	$f4,0x0($a2)
/*  f097778:	c4b20004 */ 	lwc1	$f18,0x4($a1)
/*  f09777c:	c4900000 */ 	lwc1	$f16,0x0($a0)
/*  f097780:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f097784:	c4a80000 */ 	lwc1	$f8,0x0($a1)
/*  f097788:	46128182 */ 	mul.s	$f6,$f16,$f18
/*  f09778c:	c4920008 */ 	lwc1	$f18,0x8($a0)
/*  f097790:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f097794:	c4a8000c */ 	lwc1	$f8,0xc($a1)
/*  f097798:	46089282 */ 	mul.s	$f10,$f18,$f8
/*  f09779c:	c492000c */ 	lwc1	$f18,0xc($a0)
/*  f0977a0:	46043400 */ 	add.s	$f16,$f6,$f4
/*  f0977a4:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*  f0977a8:	46122202 */ 	mul.s	$f8,$f4,$f18
/*  f0977ac:	460a8180 */ 	add.s	$f6,$f16,$f10
/*  f0977b0:	46083401 */ 	sub.s	$f16,$f6,$f8
/*  f0977b4:	e4d00004 */ 	swc1	$f16,0x4($a2)
/*  f0977b8:	c4a40008 */ 	lwc1	$f4,0x8($a1)
/*  f0977bc:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f0977c0:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f0977c4:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f0977c8:	46045482 */ 	mul.s	$f18,$f10,$f4
/*  f0977cc:	c484000c */ 	lwc1	$f4,0xc($a0)
/*  f0977d0:	46083402 */ 	mul.s	$f16,$f6,$f8
/*  f0977d4:	c4a60004 */ 	lwc1	$f6,0x4($a1)
/*  f0977d8:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0977dc:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*  f0977e0:	46109280 */ 	add.s	$f10,$f18,$f16
/*  f0977e4:	c4b0000c */ 	lwc1	$f16,0xc($a1)
/*  f0977e8:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f0977ec:	46085480 */ 	add.s	$f18,$f10,$f8
/*  f0977f0:	46069281 */ 	sub.s	$f10,$f18,$f6
/*  f0977f4:	e4ca0008 */ 	swc1	$f10,0x8($a2)
/*  f0977f8:	c4b0000c */ 	lwc1	$f16,0xc($a1)
/*  f0977fc:	c4880000 */ 	lwc1	$f8,0x0($a0)
/*  f097800:	c486000c */ 	lwc1	$f6,0xc($a0)
/*  f097804:	c4b20000 */ 	lwc1	$f18,0x0($a1)
/*  f097808:	46104102 */ 	mul.s	$f4,$f8,$f16
/*  f09780c:	c4900004 */ 	lwc1	$f16,0x4($a0)
/*  f097810:	46069282 */ 	mul.s	$f10,$f18,$f6
/*  f097814:	c4b20008 */ 	lwc1	$f18,0x8($a1)
/*  f097818:	46128182 */ 	mul.s	$f6,$f16,$f18
/*  f09781c:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f097820:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f097824:	c4aa0004 */ 	lwc1	$f10,0x4($a1)
/*  f097828:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f09782c:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f097830:	46122201 */ 	sub.s	$f8,$f4,$f18
/*  f097834:	03e00008 */ 	jr	$ra
/*  f097838:	e4c8000c */ 	swc1	$f8,0xc($a2)
);

GLOBAL_ASM(
glabel func0f09783c
/*  f09783c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f097840:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f097844:	27a60018 */ 	addiu	$a2,$sp,0x18
/*  f097848:	0fc25dce */ 	jal	func0f097738
/*  f09784c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f097850:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f097854:	c7a40018 */ 	lwc1	$f4,0x18($sp)
/*  f097858:	e4a40000 */ 	swc1	$f4,0x0($a1)
/*  f09785c:	c7a6001c */ 	lwc1	$f6,0x1c($sp)
/*  f097860:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*  f097864:	c7a80020 */ 	lwc1	$f8,0x20($sp)
/*  f097868:	e4a80008 */ 	swc1	$f8,0x8($a1)
/*  f09786c:	c7aa0024 */ 	lwc1	$f10,0x24($sp)
/*  f097870:	e4aa000c */ 	swc1	$f10,0xc($a1)
/*  f097874:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f097878:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f09787c:	03e00008 */ 	jr	$ra
/*  f097880:	00000000 */ 	nop
);
