
#include <stdio.h>
//טבלת סמלים
typedef struct {

	char labelName[31];
	int decimalAdress;
	int isExtern;
	int isEntry;
	int isInstruction;
	S_label *next;

}S_label;


//מבנה הוראה בשפת מכונה
typedef struct {
	unsigned char instructionCode : 4;
	unsigned char operandSourceAddress : 3;
	unsigned char sourceRegister : 3;
	unsigned char operandDestinationAddress : 3;
	unsigned char destinationRegister : 3;

}S_instruction;


typedef struct {

	char label[31];
	int adress;
	unsigned int code : 16;
	S_data *next;
}S_data;



char instructionsArr[][4] = { "mov", "cmp", "add", "sub", "mul", "div", "lea", "inc", "dec", "brz", "jmp", "red", "prn", "jsr", "rts", "hlt" };
