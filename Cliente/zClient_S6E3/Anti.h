///HappyDay Simple Protect System.
///Public ver.
#define USER_PBUFFER \
	__asm _emit 0xEB \
	__asm _emit 0x04 \
	__asm _emit 0xEB \
	__asm _emit 0x05 \
	__asm _emit 0x39 \
	__asm _emit 0x19
///-----//
#define JUNK_CODE_ONE       \
	__asm{push eax}         \
	__asm{xor eax, eax}     \
	__asm{setpo al}         \
	__asm{push edx}         \
	__asm{xor edx, eax}     \
	__asm{sal edx, 2}       \
	__asm{xchg eax, edx}    \
	__asm{pop edx}          \
	__asm{or eax, ecx}      \
	__asm{pop eax}
///-----//
class Protector {

public:
	static void AntiDebug();
};