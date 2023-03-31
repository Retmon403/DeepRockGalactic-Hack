#pragma once
/*
照明弹
FSD-Win64-Shipping.exe+1254A9D - FF C9                 - dec ecx ==============
FSD-Win64-Shipping.exe+1254A9F - 89 8F 18020000        - mov [rdi+00000218],ecx
FSD-Win64-Shipping.exe+1254AA5 - 48 85 C0              - test rax,rax
FSD-Win64-Shipping.exe+1254AA8 - 75 0E                 - jne FSD-Win64-Shipping.exe+1254AB8
FSD-Win64-Shipping.exe+1254AAA - 48 8B CF              - mov rcx,rdi
FSD-Win64-Shipping.exe+1254AAD - E8 CE6DF701           - call FSD-Win64-Shipping.exe+31CB880
FSD-Win64-Shipping.exe+1254AB2 - 8B 8F 18020000        - mov ecx,[rdi+00000218]
FSD-Win64-Shipping.exe+1254AB8 - 8B 80 A0050000        - mov eax,[rax+000005A0]
FSD-Win64-Shipping.exe+1254ABE - 48 8D 54 24 20        - lea rdx,[rsp+20]
FSD-Win64-Shipping.exe+1254AC3 - 89 4C 24 20           - mov [rsp+20],ecx
FSD-Win64-Shipping.exe+1254AC7 - 48 8D 8F 68010000     - lea rcx,[rdi+00000168]
FSD-Win64-Shipping.exe+1254ACE - 89 87 F0010000        - mov [rdi+000001F0],eax
FSD-Win64-Shipping.exe+1254AD4 - 48 89 7C 24 28        - mov [rsp+28],rdi
*/
UCHAR light_shell[] = { 0xFF,0xC9,0x89,0x8F,0x00,0x00,0x00,0x00,0x48,0x85,0xC0,0x75,0x00,0x48,0x8B,0xCF,0xE8,
0x00,0x00,0x00,0x00,0x8B,0x8F,0x00,0x00,0x00,0x00,0x8B,0x80,0x00,0x00,0x00,0x00,0x48,0x8D,0x54,0x24,0x00,
0x89,0x4C,0x24,0x00,0x48,0x8D,0x8F };

/*
手榴弹
FSD-Win64-Shipping.exe+150FA3E - FF C8                 - dec eax
FSD-Win64-Shipping.exe+150FA40 - 0F28 44 24 70         - movaps xmm0,[rsp+70]
FSD-Win64-Shipping.exe+150FA45 - 0F16 DA               - movlhps xmm3,xmm2
FSD-Win64-Shipping.exe+150FA48 - F3 0F10 15 904C8404   - movss xmm2,[FSD-Win64-Shipping.exe+5D546E0]
FSD-Win64-Shipping.exe+150FA50 - 0F29 5D D0            - movaps [rbp-30],xmm3
FSD-Win64-Shipping.exe+150FA54 - F2 0F10 1D 7C4C8404   - movsd xmm3,[FSD-Win64-Shipping.exe+5D546D8]
FSD-Win64-Shipping.exe+150FA5C - 0F16 DA               - movlhps xmm3,xmm2
FSD-Win64-Shipping.exe+150FA5F - 0F29 5D E0            - movaps [rbp-20],xmm3
FSD-Win64-Shipping.exe+150FA63 - 0F29 45 C0            - movaps [rbp-40],xmm0
FSD-Win64-Shipping.exe+150FA67 - 89 87 8C030000        - mov [rdi+0000038C],eax
FSD-Win64-Shipping.exe+150FA6D - 48 85 C9              - test rcx,rcx
*/
UCHAR grenade_shell[] = { 0xFF,0xC8,0x0F,0x28,0x44,0x24,0x00,0x0F,0x16,0xDA,0xF3,0x0F,0x10,0x00,0x00,0x00,0x00,
0x00,0x0F,0x29,0x5D,0xD0,0xF2,0x0F,0x10,0x00,0x00,0x00,0x00,0x00,0x0F,0x16,0xDA,0x0F,0x29,0x5D,0xE0,0x0F,
0x29,0x45,0xC0,0x89,0x87,0x00,0x00,0x00,0x00,0x48,0x85,0xC9,0x74 };

/*
侦察兵的所有子弹
FSD-Win64-Shipping.exe+14D7A68 - 0F8E E1030000         - jng FSD-Win64-Shipping.exe+14D7E4F
FSD-Win64-Shipping.exe+14D7A6E - 80 B9 10030000 00     - cmp byte ptr [rcx+00000310],00
FSD-Win64-Shipping.exe+14D7A75 - 0F85 D4030000         - jne FSD-Win64-Shipping.exe+14D7E4F
FSD-Win64-Shipping.exe+14D7A7B - 2B 81 30060000        - sub eax,[rcx+00000630]
FSD-Win64-Shipping.exe+14D7A81 - 33 ED                 - xor ebp,ebp
FSD-Win64-Shipping.exe+14D7A83 - 85 C0                 - test eax,eax
FSD-Win64-Shipping.exe+14D7A85 - 4C 89 A4 24 B8000000  - mov [rsp+000000B8],r12
FSD-Win64-Shipping.exe+14D7A8D - 0F4E C5               - cmovle eax,ebp
FSD-Win64-Shipping.exe+14D7A90 - 89 81 48060000        - mov [rcx+00000648],eax  ====================
FSD-Win64-Shipping.exe+14D7A96 - 48 8B 01              - mov rax,[rcx]
FSD-Win64-Shipping.exe+14D7A99 - FF 90 98080000        - call qword ptr [rax+00000898]
FSD-Win64-Shipping.exe+14D7A9F - 49 8B 06              - mov rax,[r14]
FSD-Win64-Shipping.exe+14D7AA2 - 49 8B CE              - mov rcx,r14
FSD-Win64-Shipping.exe+14D7AA5 - FF 90 70080000        - call qword ptr [rax+00000870]
FSD-Win64-Shipping.exe+14D7AAB - 45 32 E4              - xor r12b,r12b
FSD-Win64-Shipping.exe+14D7AAE - 41 C6 86 C2060000 02  - mov byte ptr [r14+000006C2],02
FSD-Win64-Shipping.exe+14D7AB6 - F3 41 0F58 86 70060000  - addss xmm0,[r14+00000670]
FSD-Win64-Shipping.exe+14D7ABF - F3 41 0F11 86 70060000  - movss [r14+00000670],xmm0
FSD-Win64-Shipping.exe+14D7AC8 - 41 38 AE A8060000     - cmp [r14+000006A8],bpl
FSD-Win64-Shipping.exe+14D7ACF - 75 23                 - jne FSD-Win64-Shipping.exe+14D7AF4
FSD-Win64-Shipping.exe+14D7AD1 - 41 8B 86 38060000     - mov eax,[r14+00000638]
FSD-Win64-Shipping.exe+14D7AD8 - 41 39 86 BC060000     - cmp [r14+000006BC],eax
FSD-Win64-Shipping.exe+14D7ADF - 7C 13                 - jl FSD-Win64-Shipping.exe+14D7AF4
FSD-Win64-Shipping.exe+14D7AE1 - 41 88 AE C1060000     - mov [r14+000006C1],bpl
FSD-Win64-Shipping.exe+14D7AE8 - 41 B4 01              - mov r12b,01
FSD-Win64-Shipping.exe+14D7AEB - 41 89 AE BC060000     - mov [r14+000006BC],ebp
*/
UCHAR zcb_bullet_shell[] = { 0x89,0x81,0x00,0x00,0x00,0x00,0x48,0x8B,0x01,0xFF,0x90,0x00,0x00,0x00,0x00,
0x49,0x8B,0x06,0x49,0x8B,0xCE,0xFF,0x90,0x00,0x00,0x00,0x00,0x45,0x32,0xE4,0x41,0xC6,0x86,
0x00,0x00,0x00,0x00,0x02,0xF3,0x41,0x0F,0x58,0x86 };


/*
抓钩枪
FSD-Win64-Shipping.exe+14A92CA - CC                    - int 3
FSD-Win64-Shipping.exe+14A92CB - CC                    - int 3
FSD-Win64-Shipping.exe+14A92CC - CC                    - int 3
FSD-Win64-Shipping.exe+14A92CD - CC                    - int 3
FSD-Win64-Shipping.exe+14A92CE - CC                    - int 3
FSD-Win64-Shipping.exe+14A92CF - CC                    - int 3
FSD-Win64-Shipping.exe+14A92D0 - 8B 81 C8000000        - mov eax,[rcx+000000C8]
FSD-Win64-Shipping.exe+14A92D6 - 89 81 D8000000        - mov [rcx+000000D8],eax  =============
FSD-Win64-Shipping.exe+14A92DC - 88 91 DC000000        - mov [rcx+000000DC],dl
FSD-Win64-Shipping.exe+14A92E2 - C3                    - ret
FSD-Win64-Shipping.exe+14A92E3 - CC                    - int 3
FSD-Win64-Shipping.exe+14A92E4 - CC                    - int 3
FSD-Win64-Shipping.exe+14A92E5 - CC                    - int 3
FSD-Win64-Shipping.exe+14A92E6 - CC                    - int 3
FSD-Win64-Shipping.exe+14A92E7 - CC                    - int 3
FSD-Win64-Shipping.exe+14A92E8 - CC                    - int 3
FSD-Win64-Shipping.exe+14A92E9 - CC                    - int 3
FSD-Win64-Shipping.exe+14A92EA - CC                    - int 3
FSD-Win64-Shipping.exe+14A92EB - CC                    - int 3
FSD-Win64-Shipping.exe+14A92EC - CC                    - int 3
FSD-Win64-Shipping.exe+14A92ED - CC                    - int 3
FSD-Win64-Shipping.exe+14A92EE - CC                    - int 3
*/
UCHAR zcb_grapple_cd_shell[] = { 0xCC,0xCC,0xCC,0xCC,0x8B,0x81,0xC8,0x00,0x00,0x00,0x89,0x81,0xD8,0x00,0x00,
0x00,0x88,0x91,0xDC,0x00,0x00,0x00,0xC3,0xCC,0xCC,0xCC,0xCC };


/*
抓钩枪 增长
FSD-Win64-Shipping.exe+151491A - 74 63                 - je FSD-Win64-Shipping.exe+151497F
FSD-Win64-Shipping.exe+151491C - 0F10 87 F8030000      - movups xmm0,[rdi+000003F8]
FSD-Win64-Shipping.exe+1514923 - 8B 45 84              - mov eax,[rbp-7C]
FSD-Win64-Shipping.exe+1514926 - 48 8D 54 24 60        - lea rdx,[rsp+60]
FSD-Win64-Shipping.exe+151492B - 80 8F 04040000 01     - or byte ptr [rdi+00000404],01
FSD-Win64-Shipping.exe+1514932 - 48 8B CF              - mov rcx,rdi
FSD-Win64-Shipping.exe+1514935 - 0F11 44 24 60         - movups [rsp+60],xmm0
FSD-Win64-Shipping.exe+151493A - F2 0F10 44 24 7C      - movsd xmm0,[rsp+7C]
FSD-Win64-Shipping.exe+1514940 - F2 0F11 87 F8030000   - movsd [rdi+000003F8],xmm0
FSD-Win64-Shipping.exe+1514948 - 89 87 00040000        - mov [rdi+00000400],eax
FSD-Win64-Shipping.exe+151494E - 48 8B 07              - mov rax,[rdi]
FSD-Win64-Shipping.exe+1514951 - FF 90 E8070000        - call qword ptr [rax+000007E8]
FSD-Win64-Shipping.exe+1514957 - 48 8B 8F A8030000     - mov rcx,[rdi+000003A8]
FSD-Win64-Shipping.exe+151495E - B2 01                 - mov dl,01
FSD-Win64-Shipping.exe+1514960 - E8 6B49F9FF           - call FSD-Win64-Shipping.exe+14A92D0
FSD-Win64-Shipping.exe+1514965 - 48 8D 97 F8030000     - lea rdx,[rdi+000003F8]
FSD-Win64-Shipping.exe+151496C - 48 8B CF              - mov rcx,rdi
*/
UCHAR zcb_grapple_distance_shell[] = { 0x74,0x00,0x0F,0x10,0x87,0x00,0x00,0x00,0x00,0x8B,0x45,0x84,0x48,0x8D,
0x54,0x24,0x00,0x80,0x8F,0x00,0x00,0x00,0x00,0x01,0x48,0x8B,0xCF,0x0F,0x11,0x44,0x24,0x00,0xF2,0x0F,0x10,
0x44,0x24,0x00,0xF2,0x0F,0x11,0x87 };


/*
子弹速度 侦察兵
FSD-Win64-Shipping.exe+14D7A96 - 48 8B 01              - mov rax,[rcx]
FSD-Win64-Shipping.exe+14D7A99 - FF 90 98080000        - call qword ptr [rax+00000898]
FSD-Win64-Shipping.exe+14D7A9F - 49 8B 06              - mov rax,[r14]
FSD-Win64-Shipping.exe+14D7AA2 - 49 8B CE              - mov rcx,r14
FSD-Win64-Shipping.exe+14D7AA5 - FF 90 70080000        - call qword ptr [rax+00000870]
FSD-Win64-Shipping.exe+14D7AAB - 45 32 E4              - xor r12b,r12b
FSD-Win64-Shipping.exe+14D7AAE - 41 C6 86 C2060000 02  - mov byte ptr [r14+000006C2],02
FSD-Win64-Shipping.exe+14D7AB6 - F3 41 0F58 86 70060000  - addss xmm0,[r14+00000670]
FSD-Win64-Shipping.exe+14D7ABF - F3 41 0F11 86 70060000  - movss [r14+00000670],xmm0 ================
FSD-Win64-Shipping.exe+14D7AC8 - 41 38 AE A8060000     - cmp [r14+000006A8],bpl
FSD-Win64-Shipping.exe+14D7ACF - 75 23                 - jne FSD-Win64-Shipping.exe+14D7AF4
FSD-Win64-Shipping.exe+14D7AD1 - 41 8B 86 38060000     - mov eax,[r14+00000638]
FSD-Win64-Shipping.exe+14D7AD8 - 41 39 86 BC060000     - cmp [r14+000006BC],eax
FSD-Win64-Shipping.exe+14D7ADF - 7C 13                 - jl FSD-Win64-Shipping.exe+14D7AF4
FSD-Win64-Shipping.exe+14D7AE1 - 41 88 AE C1060000     - mov [r14+000006C1],bpl
FSD-Win64-Shipping.exe+14D7AE8 - 41 B4 01              - mov r12b,01
FSD-Win64-Shipping.exe+14D7AEB - 41 89 AE BC060000     - mov [r14+000006BC],ebp
FSD-Win64-Shipping.exe+14D7AF2 - EB 45                 - jmp FSD-Win64-Shipping.exe+14D7B39
FSD-Win64-Shipping.exe+14D7AF4 - 41 8B 86 BC060000     - mov eax,[r14+000006BC]
FSD-Win64-Shipping.exe+14D7AFB - 41 3B 86 38060000     - cmp eax,[r14+00000638]
FSD-Win64-Shipping.exe+14D7B02 - 7D 35                 - jnl FSD-Win64-Shipping.exe+14D7B39
FSD-Win64-Shipping.exe+14D7B04 - F3 41 0F10 86 3C060000  - movss xmm0,[r14+0000063C]
FSD-Win64-Shipping.exe+14D7B0D - FF C0                 - inc eax
*/
UCHAR zcb_bullet_fast_shell[] = { 0xF3,0x41,0x0F,0x11,0x86,0x00,0x00,0x00,0x00,0x41,0x38,0xAE,0x00,0x00,0x00,
0x00,0x75,0x23,0x41,0x8B,0x86,0x00,0x00,0x00,0x00,0x41,0x39,0x86,0x00,0x00,0x00,0x00,0x7C,0x13,0x41,0x88,
0xAE,0x00,0x00,0x00,0x00,0x41,0xB4,0x01,0x41,0x89,0xAE };

/*
武器后坐力
FSD-Win64-Shipping.exe+11F2588 - CC                    - int 3
FSD-Win64-Shipping.exe+11F2589 - CC                    - int 3
FSD-Win64-Shipping.exe+11F258A - CC                    - int 3
FSD-Win64-Shipping.exe+11F258B - CC                    - int 3
FSD-Win64-Shipping.exe+11F258C - CC                    - int 3
FSD-Win64-Shipping.exe+11F258D - CC                    - int 3
FSD-Win64-Shipping.exe+11F258E - CC                    - int 3
FSD-Win64-Shipping.exe+11F258F - CC                    - int 3
FSD-Win64-Shipping.exe+11F2590 - 48 89 5C 24 08        - mov [rsp+08],rbx
FSD-Win64-Shipping.exe+11F2595 - 57                    - push rdi
FSD-Win64-Shipping.exe+11F2596 - 48 83 EC 30           - sub rsp,30
FSD-Win64-Shipping.exe+11F259A - F3 0F10 42 1C         - movss xmm0,[rdx+1C]
FSD-Win64-Shipping.exe+11F259F - 48 8B DA              - mov rbx,rdx
FSD-Win64-Shipping.exe+11F25A2 - F3 0F10 0D 46781A03   - movss xmm1,[FSD-Win64-Shipping.exe+4399DF0]
FSD-Win64-Shipping.exe+11F25AA - 48 8B F9              - mov rdi,rcx
FSD-Win64-Shipping.exe+11F25AD - 0F2F C1               - comiss xmm0,xmm1
FSD-Win64-Shipping.exe+11F25B0 - 76 74                 - jna FSD-Win64-Shipping.exe+11F2626
FSD-Win64-Shipping.exe+11F25B2 - F3 0F10 42 24         - movss xmm0,[rdx+24]
FSD-Win64-Shipping.exe+11F25B7 - 0F2F C1               - comiss xmm0,xmm1
FSD-Win64-Shipping.exe+11F25BA - 76 6A                 - jna FSD-Win64-Shipping.exe+11F2626
FSD-Win64-Shipping.exe+11F25BC - 48 8D 54 24 20        - lea rdx,[rsp+20]
FSD-Win64-Shipping.exe+11F25C1 - 48 8B CB              - mov rcx,rbx
FSD-Win64-Shipping.exe+11F25C4 - E8 D7570800           - call FSD-Win64-Shipping.exe+1277DA0
FSD-Win64-Shipping.exe+11F25C9 - F3 0F10 44 24 28      - movss xmm0,[rsp+28]
FSD-Win64-Shipping.exe+11F25CF - F3 0F58 87 BC000000   - addss xmm0,[rdi+000000BC]
FSD-Win64-Shipping.exe+11F25D7 - F3 0F10 4C 24 24      - movss xmm1,[rsp+24]
FSD-Win64-Shipping.exe+11F25DD - F3 0F58 8F C0000000   - addss xmm1,[rdi+000000C0]
FSD-Win64-Shipping.exe+11F25E5 - F3 0F11 87 BC000000   - movss [rdi+000000BC],xmm0
FSD-Win64-Shipping.exe+11F25ED - F3 0F10 44 24 20      - movss xmm0,[rsp+20]
FSD-Win64-Shipping.exe+11F25F3 - F3 0F58 87 C4000000   - addss xmm0,[rdi+000000C4]
FSD-Win64-Shipping.exe+11F25FB - F3 0F11 8F C0000000   - movss [rdi+000000C0],xmm1
FSD-Win64-Shipping.exe+11F2603 - F3 0F11 87 C4000000   - movss [rdi+000000C4],xmm0
FSD-Win64-Shipping.exe+11F260B - 8B 43 1C              - mov eax,[rbx+1C]
FSD-Win64-Shipping.exe+11F260E - 89 87 D4000000        - mov [rdi+000000D4],eax
FSD-Win64-Shipping.exe+11F2614 - 8B 43 20              - mov eax,[rbx+20]
FSD-Win64-Shipping.exe+11F2617 - 89 87 D8000000        - mov [rdi+000000D8],eax
FSD-Win64-Shipping.exe+11F261D - 8B 43 24              - mov eax,[rbx+24]
FSD-Win64-Shipping.exe+11F2620 - 89 87 DC000000        - mov [rdi+000000DC],eax
FSD-Win64-Shipping.exe+11F2626 - 48 8B 5C 24 40        - mov rbx,[rsp+40]
FSD-Win64-Shipping.exe+11F262B - 48 83 C4 30           - add rsp,30
FSD-Win64-Shipping.exe+11F262F - 5F                    - pop rdi
FSD-Win64-Shipping.exe+11F2630 - C3                    - ret
*/
UCHAR gun_recoil_shell[] = { 0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0x48,0x89,0x5C,0x24,0x00,0x57,
0x48,0x83,0xEC,0x00,0xF3,0x0F,0x10,0x42,0x00,0x48,0x8B,0xDA,0xF3,0x0F,0x10,0x00,0x00,0x00,0x00,0x00,0x48,0x8B,
0xF9,0x0F,0x2F,0xC1,0x76,0x74,0xF3,0x0F,0x00,0x00,0x00,0x0F,0x2F,0xC1,0x76,0x6A,0x48,0x8D };


/*
FSD-Win64-Shipping.exe+1533D03 - 48 8B C8              - mov rcx,rax
FSD-Win64-Shipping.exe+1533D06 - 0F28 D6               - movaps xmm2,xmm6
FSD-Win64-Shipping.exe+1533D09 - 0F28 CE               - movaps xmm1,xmm6
FSD-Win64-Shipping.exe+1533D0C - E8 EF29D601           - call FSD-Win64-Shipping.exe+3296700
FSD-Win64-Shipping.exe+1533D11 - F3 0F59 83 28020000   - mulss xmm0,[rbx+00000228]
FSD-Win64-Shipping.exe+1533D19 - 0F28 74 24 20         - movaps xmm6,[rsp+20]
FSD-Win64-Shipping.exe+1533D1E - F3 0F58 83 20020000   - addss xmm0,[rbx+00000220]
FSD-Win64-Shipping.exe+1533D26 - 48 83 C4 30           - add rsp,30
FSD-Win64-Shipping.exe+1533D2A - 5B                    - pop rbx
FSD-Win64-Shipping.exe+1533D2B - C3                    - ret
*/

UCHAR no_spread_shell[] = { 0x48,0x8B,0xC8,0x0F,0x28,0xD6,0x0F,0x28,0xCE,0xE8,0x00,0x00,0x00,0x00,
0xF3,0x0F,0x59,0x00,0x00,0x00,0x00,0x00,0x0F,0x28,0x74,0x24,0x00,0xF3,0x0F,0x58,0x00,0x00,0x00,0x00,0x00,0x48,0x83,0xC4,0x00,0x5B,0xC3 };


/*
枪手子弹
FSD-Win64-Shipping.exe+14D8169 - 89 86 48060000        - mov [rsi+00000648],eax
FSD-Win64-Shipping.exe+14D816F - 89 45 80              - mov [rbp-80],eax
FSD-Win64-Shipping.exe+14D8172 - E8 39313EFF           - call FSD-Win64-Shipping.exe+8BB2B0
FSD-Win64-Shipping.exe+14D8177 - 8B 86 48060000        - mov eax,[rsi+00000648]
FSD-Win64-Shipping.exe+14D817D - 48 8D 55 80           - lea rdx,[rbp-80]
FSD-Win64-Shipping.exe+14D8181 - 48 8B 8E 28040000     - mov rcx,[rsi+00000428]
FSD-Win64-Shipping.exe+14D8188 - 03 86 44060000        - add eax,[rsi+00000644]
FSD-Win64-Shipping.exe+14D818E - 48 81 C1 E8000000     - add rcx,000000E8
FSD-Win64-Shipping.exe+14D8195 - 89 45 80              - mov [rbp-80],eax
FSD-Win64-Shipping.exe+14D8198 - E8 13313EFF           - call FSD-Win64-Shipping.exe+8BB2B0
FSD-Win64-Shipping.exe+14D819D - 48 8B 8E 28040000     - mov rcx,[rsi+00000428]
FSD-Win64-Shipping.exe+14D81A4 - 48 8D 55 80           - lea rdx,[rbp-80]
FSD-Win64-Shipping.exe+14D81A8 - 8B 86 48060000        - mov eax,[rsi+00000648]
FSD-Win64-Shipping.exe+14D81AE - 48 81 C1 C8000000     - add rcx,000000C8
FSD-Win64-Shipping.exe+14D81B5 - 89 45 80              - mov [rbp-80],eax
FSD-Win64-Shipping.exe+14D81B8 - E8 F3303EFF           - call FSD-Win64-Shipping.exe+8BB2B0
FSD-Win64-Shipping.exe+14D81BD - 48 8B 06              - mov rax,[rsi]
FSD-Win64-Shipping.exe+14D81C0 - 48 8B CE              - mov rcx,rsi
FSD-Win64-Shipping.exe+14D81C3 - FF 90 F0080000        - call qword ptr [rax+000008F0]
*/
UCHAR gunner_bullet_shell[] = { 0x89,0x86,0x00,0x00,0x00,0x00,0x89,0x45,0x00,0xE8,0x00,0x00,0x00,0x00,0x8B,0x86,0x00,
0x00,0x00,0x00,0x48,0x8D,0x55,0x00,0x48,0x8B,0x8E,0x00,0x00,0x00,0x00,0x03,0x86,0x00,0x00,0x00,0x00,0x48,0x81,0xC1,
0xE8,0x00,0x00,0x00,0x89,0x45,0x00,0xE8 };

/*
枪手加特林开枪延迟
FSD-Win64-Shipping.exe+14CFE4F - F3 0F11 96 F8060000   - movss [rsi+000006F8],xmm2  ====
FSD-Win64-Shipping.exe+14CFE57 - F3 0F10 05 7195ED02   - movss xmm0,[FSD-Win64-Shipping.exe+43A93D0]
FSD-Win64-Shipping.exe+14CFE5F - 0F2F C2               - comiss xmm0,xmm2
FSD-Win64-Shipping.exe+14CFE62 - 76 50                 - jna FSD-Win64-Shipping.exe+14CFEB4
FSD-Win64-Shipping.exe+14CFE64 - 48 8B 8E D0060000     - mov rcx,[rsi+000006D0]
FSD-Win64-Shipping.exe+14CFE6B - 48 85 C9              - test rcx,rcx
FSD-Win64-Shipping.exe+14CFE6E - 74 44                 - je FSD-Win64-Shipping.exe+14CFEB4
FSD-Win64-Shipping.exe+14CFE70 - 48 8B 01              - mov rax,[rcx]
FSD-Win64-Shipping.exe+14CFE73 - FF 90 68050000        - call qword ptr [rax+00000568]
FSD-Win64-Shipping.exe+14CFE79 - 84 C0                 - test al,al
FSD-Win64-Shipping.exe+14CFE7B - 74 37                 - je FSD-Win64-Shipping.exe+14CFEB4
FSD-Win64-Shipping.exe+14CFE7D - 84 DB                 - test bl,bl
FSD-Win64-Shipping.exe+14CFE7F - 75 33                 - jne FSD-Win64-Shipping.exe+14CFEB4
FSD-Win64-Shipping.exe+14CFE81 - 40 38 AE FD060000     - cmp [rsi+000006FD],bpl
FSD-Win64-Shipping.exe+14CFE88 - 75 2A                 - jne FSD-Win64-Shipping.exe+14CFEB4
FSD-Win64-Shipping.exe+14CFE8A - 48 8B 8E D0060000     - mov rcx,[rsi+000006D0]
*/
UCHAR gunner_delay_shell[] = { 0xF3,0x0F,0x11,0x96,0xF8,0x06,0x00,0x00,0xF3,0x0F,0x10,0x05,0x71,0x95,0xED,0x02,
0x0F,0x2F,0xC2,0x76,0x50,0x48,0x8B,0x8E,0xD0,0x06,0x00,0x00,0x48,0x85,0xC9,0x74,0x44,0x48,0x8B,0x01,0xFF,0x90,0x68,0x05,0x00,0x00,0x84,0xC0,0x74 };

/*
枪手加特林冷却
FSD-Win64-Shipping.exe+14F4FF9 - F3 0F11 83 C4020000   - movss [rbx+000002C4],xmm0 =======
FSD-Win64-Shipping.exe+14F5001 - E8 1A3EDA01           - call FSD-Win64-Shipping.exe+3298E20
FSD-Win64-Shipping.exe+14F5006 - 0F2F F0               - comiss xmm6,xmm0
FSD-Win64-Shipping.exe+14F5009 - 77 3B                 - ja FSD-Win64-Shipping.exe+14F5046
FSD-Win64-Shipping.exe+14F500B - F3 0F5D 05 813EE602   - minss xmm0,[FSD-Win64-Shipping.exe+4358E94]
FSD-Win64-Shipping.exe+14F5013 - 0F28 F0               - movaps xmm6,xmm0
FSD-Win64-Shipping.exe+14F5016 - EB 2E                 - jmp FSD-Win64-Shipping.exe+14F5046
FSD-Win64-Shipping.exe+14F5018 - 0F57 C9               - xorps xmm1,xmm1
FSD-Win64-Shipping.exe+14F501B - 41 0F28 F1            - movaps xmm6,xmm9
FSD-Win64-Shipping.exe+14F501F - 0F2F C1               - comiss xmm0,xmm1
FSD-Win64-Shipping.exe+14F5022 - 76 2A                 - jna FSD-Win64-Shipping.exe+14F504E
FSD-Win64-Shipping.exe+14F5024 - 0F28 F0               - movaps xmm6,xmm0
FSD-Win64-Shipping.exe+14F5027 - F3 0F59 B3 E8020000   - mulss xmm6,[rbx+000002E8]
FSD-Win64-Shipping.exe+14F502F - F3 41 0F58 F1         - addss xmm6,xmm9
FSD-Win64-Shipping.exe+14F5034 - 0F2F CE               - comiss xmm1,xmm6
FSD-Win64-Shipping.exe+14F5037 - 76 05                 - jna FSD-Win64-Shipping.exe+14F503E
*/

UCHAR gunner_superheat_shell[] = { 0xF3,0x0F,0x11,0x83,0x00,0x00,0x00,0x00,0xE8,0x00,0x00,0x00,0x00,0x0F,0x2F,0xF0,0x77,0x00,0xF3,0x0F,0x5D,0x00,0x00,0x00,
0x00,0x00,0x0F,0x28,0xF0,0xEB,0x00,0x0F,0x57,0xC9,0x41,0x0F,0x28,0xF1,0x0F,0x2F,0xC1,0x76,0x00,0x0F,0x28,0xF0,0xF3 };

/*
FSD-Win64-Shipping.exe+1442F79 - 5F                    - pop rdi
FSD-Win64-Shipping.exe+1442F7A - C3                    - ret
FSD-Win64-Shipping.exe+1442F7B - CC                    - int 3
FSD-Win64-Shipping.exe+1442F7C - CC                    - int 3
FSD-Win64-Shipping.exe+1442F7D - CC                    - int 3
FSD-Win64-Shipping.exe+1442F7E - CC                    - int 3
FSD-Win64-Shipping.exe+1442F7F - CC                    - int 3
FSD-Win64-Shipping.exe+1442F80 - 48 83 EC 28           - sub rsp,28
FSD-Win64-Shipping.exe+1442F84 - 48 8B CA              - mov rcx,rdx
FSD-Win64-Shipping.exe+1442F87 - E8 14D3EBFF           - call FSD-Win64-Shipping.exe+13002A0
FSD-Win64-Shipping.exe+1442F8C - 48 85 C0              - test rax,rax
FSD-Win64-Shipping.exe+1442F8F - 74 10                 - je FSD-Win64-Shipping.exe+1442FA1
FSD-Win64-Shipping.exe+1442F91 - 66 0F6E 80 18050000   - movd xmm0,[rax+00000518]
FSD-Win64-Shipping.exe+1442F99 - 0F5B C0               - cvtdq2ps xmm0,xmm0
FSD-Win64-Shipping.exe+1442F9C - 48 83 C4 28           - add rsp,28
FSD-Win64-Shipping.exe+1442FA0 - C3                    - ret
FSD-Win64-Shipping.exe+1442FA1 - F3 0F10 05 2FB5F402   - movss xmm0,[FSD-Win64-Shipping.exe+438E4D8]
*/

UCHAR money_shell[] = { 0xCC,0xCC,0xCC,0x48,0x83,0xEC,0x28,0x48,0x8B,0xCA,0xE8,0x00,0x00,0x00,0x00,0x48,0x85,0xC0,0x74,0x00,0x66,0x0F,0x6E
,0x00,0x00,0x00,0x00,0x00,0x0F,0x5B,0xC0,0x48,0x83,0xC4,0x28,0xC3,0xF3,0x0F,0x10 };

/*
FSD-Win64-Shipping.exe+1345799 - 83 F8 FF              - cmp eax,-01
FSD-Win64-Shipping.exe+134579C - 74 29                 - je FSD-Win64-Shipping.exe+13457C7
FSD-Win64-Shipping.exe+134579E - 33 D2                 - xor edx,edx
FSD-Win64-Shipping.exe+13457A0 - 48 6B C8 1C           - imul rcx,rax,1C
FSD-Win64-Shipping.exe+13457A4 - 48 03 8F B8080000     - add rcx,[rdi+000008B8]
FSD-Win64-Shipping.exe+13457AB - 48 8D 49 10           - lea rcx,[rcx+10]
FSD-Win64-Shipping.exe+13457AF - 48 0F44 CA            - cmove rcx,rdx
FSD-Win64-Shipping.exe+13457B3 - 48 85 C9              - test rcx,rcx
FSD-Win64-Shipping.exe+13457B6 - 74 0F                 - je FSD-Win64-Shipping.exe+13457C7
FSD-Win64-Shipping.exe+13457B8 - F3 0F10 01            - movss xmm0,[rcx]
FSD-Win64-Shipping.exe+13457BC - 48 8B 5C 24 30        - mov rbx,[rsp+30]
FSD-Win64-Shipping.exe+13457C1 - 48 83 C4 20           - add rsp,20
FSD-Win64-Shipping.exe+13457C5 - 5F                    - pop rdi
FSD-Win64-Shipping.exe+13457C6 - C3                    - ret
FSD-Win64-Shipping.exe+13457C7 - 48 8B 5C 24 30        - mov rbx,[rsp+30]
FSD-Win64-Shipping.exe+13457CC - 0F57 C0               - xorps xmm0,xmm0
*/
UCHAR allore_shell[] = { 0x83,0xF8,0xFF,0x74,0x00,0x33,0xD2,0x48,0x6B,0xC8,0x1c,0x48,0x03,0x00,0x00,0x00,0x00,0x00,
0x48,0x8D,0x00,0x00,0x48,0x0F,0x00,0x00,0x48,0x85,0x00,0x74,0x00,0xF3,0x0F,0x10,0x00,0x48,0x8B,0x5C,0x24,0x00,0x48,0x83,0xC4,0x00,0x5F,0xC3 };

/*
FSD-Win64-Shipping.exe+13323F8 - 01 91 D0030000        - add [rcx+000003D0],edx
FSD-Win64-Shipping.exe+13323FE - 8B 81 D0030000        - mov eax,[rcx+000003D0]
FSD-Win64-Shipping.exe+1332404 - 48 81 C1 28010000     - add rcx,00000128
FSD-Win64-Shipping.exe+133240B - 89 54 24 44           - mov [rsp+44],edx
FSD-Win64-Shipping.exe+133240F - 48 8D 54 24 40        - lea rdx,[rsp+40]
FSD-Win64-Shipping.exe+1332414 - 89 44 24 40           - mov [rsp+40],eax
FSD-Win64-Shipping.exe+1332418 - E8 938E58FF           - call FSD-Win64-Shipping.exe+8BB2B0
FSD-Win64-Shipping.exe+133241D - 48 83 C4 28           - add rsp,28
FSD-Win64-Shipping.exe+1332421 - C3                    - ret
FSD-Win64-Shipping.exe+1332422 - CC                    - int 3
FSD-Win64-Shipping.exe+1332423 - CC                    - int 3
FSD-Win64-Shipping.exe+1332424 - CC                    - int 3
*/
UCHAR special_points_shell[] = { 0x01,0x91,0x00,0x00,0x00,0x00,0x8B,0x81,0x00,0x00,0x00,0x00,0x48,0x81,0x00,0x00,0x00,0x00,0x00,
0x89,0x54,0x00,0x00,0x48,0x8D,0x00,0x00,0x00,0x89,0x00,0x00,0x00,0xE8,0x00,0x00,0x00,0x00,0x48,0x83,0xC4,0x00,0xC3,0xCC,0xCC,0xCC,0xCC,0xCC };


/*
FSD-Win64-Shipping.exe+14CF30B - 45 38 BE C1060000     - cmp [r14+000006C1],r15b
FSD-Win64-Shipping.exe+14CF312 - 74 10                 - je FSD-Win64-Shipping.exe+14CF324
FSD-Win64-Shipping.exe+14CF314 - 49 8B 06              - mov rax,[r14]
FSD-Win64-Shipping.exe+14CF317 - B2 01                 - mov dl,01
FSD-Win64-Shipping.exe+14CF319 - 49 8B CE              - mov rcx,r14
FSD-Win64-Shipping.exe+14CF31C - FF 90 E8080000        - call qword ptr [rax+000008E8]
FSD-Win64-Shipping.exe+14CF322 - EB 37                 - jmp FSD-Win64-Shipping.exe+14CF35B
FSD-Win64-Shipping.exe+14CF324 - 45 38 BE 7C060000     - cmp [r14+0000067C],r15b
FSD-Win64-Shipping.exe+14CF32B - 74 2E                 - je FSD-Win64-Shipping.exe+14CF35B
*/

UCHAR zcb_auto_firing_shell[] = { 0x45,0x38,0xBE,0x00,0x00,0x00,0x00,0x74,0x00,0x49,0x8B,0x06,0xB2,0x01,0x49,0x8B,0xCE,0xFF,0x00,0x00,0x00,0x00,0x00,0xEB,
0x00,0x45,0x38,0xBE,0x00,0x00,0x00,0x00,0x74 };




/*
FSD-Win64-Shipping.exe+31E84E4 - 84 C0                 - test al,al
FSD-Win64-Shipping.exe+31E84E6 - 74 0E                 - je FSD-Win64-Shipping.exe+31E84F6
FSD-Win64-Shipping.exe+31E84E8 - F3 0F10 83 90010000   - movss xmm0,[rbx+00000190]
FSD-Win64-Shipping.exe+31E84F0 - 48 83 C4 20           - add rsp,20
FSD-Win64-Shipping.exe+31E84F4 - 5B                    - pop rbx
FSD-Win64-Shipping.exe+31E84F5 - C3                    - ret
FSD-Win64-Shipping.exe+31E84F6 - F3 0F10 83 8C010000   - movss xmm0,[rbx+0000018C]
FSD-Win64-Shipping.exe+31E84FE - 48 83 C4 20           - add rsp,20
FSD-Win64-Shipping.exe+31E8502 - 5B                    - pop rbx
FSD-Win64-Shipping.exe+31E8503 - C3                    - ret
FSD-Win64-Shipping.exe+31E8504 - F3 0F10 83 94010000   - movss xmm0,[rbx+00000194]
*/

UCHAR speed_hack_shell[] = { 0x84,0xC0,0x74,0x00,0xF3,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0x83,0xC4,0x00,0x00,0xC3,
0xF3,0x0F,0x10,0x00,0x00,0x00,0x00,0x00,0x48,0x83,0xC4,0x20,0x00,0xC3,0xF3,0x0F,0x10 };



/*FSD-Win64-Shipping.exe+14D2C3B - F3 0F11 8E 80040000   - movss [rsi+00000480],xmm1
FSD-Win64-Shipping.exe+14D2C43 - F3 0F10 05 1D68ED02   - movss xmm0,[FSD-Win64-Shipping.exe+43A9468]
FSD-Win64-Shipping.exe+14D2C4B - F3 0F58 C9            - addss xmm1,xmm1
FSD-Win64-Shipping.exe+14D2C4F - 48 8B 8E D0030000     - mov rcx,[rsi+000003D0]
FSD-Win64-Shipping.exe+14D2C56 - 48 8D 95 80000000     - lea rdx,[rbp+00000080]
FSD-Win64-Shipping.exe+14D2C5D - 48 81 C1 C8000000     - add rcx,000000C8
FSD-Win64-Shipping.exe+14D2C64 - F3 0F5C C1            - subss xmm0,xmm1
FSD-Win64-Shipping.exe+14D2C68 - F3 0F2D C0            - cvtss2si eax,xmm0
FSD-Win64-Shipping.exe+14D2C6C - D1 F8                 - sar eax,1
FSD-Win64-Shipping.exe+14D2C6E - F7 D8                 - neg eax
FSD-Win64-Shipping.exe+14D2C70 - 89 85 80000000        - mov [rbp+00000080],eax
*/
UCHAR Driller_bullet_shell[] = { 0xF3,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0xF3,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0xF3,0x0F,0x58,0x00,
0x48,0x8B,0x00,0x00,0x00,0x00,0x00,0x48,0x8D,0x00,0x00,0x00,0x00,0x00,0x48,0x81,0x00,0xC8,0x00,0x00,0x00,0xF3,0x0F,0x5c,0x00,0xF3,0x0F,0x2d,0x00,
0xD1,0xF8,0xF7,0xD8,0x89 };