// Joseph Camarena
// jc0588321@swccd.edu


#include <stdio.h>	//printf
#include <stdlib.h>	//exit

int main(int argc, char* argv[]){

	unsigned int valRead = 0;
  	unsigned int machine_code, opcode, func, rs, rd, rt, shamt, imm, address;
	//FILE* inFile = fopen("hexInstructions.txt","r");
	FILE* outFile = fopen ("hexOutput.csv","w");
  	FILE* inFile = fopen(argv[1], "r");
	
	if ( (inFile == NULL) || (outFile == NULL) ) {
		printf("File not found \n");
		exit(1);
	}

	fprintf( outFile,"Machine code, opcode,  func,  Inst, Format,  rs,  rt,  rd, shamt,  Imm, address\n");
  
  	while ( fscanf(inFile,"%x",&valRead) != EOF ){

		machine_code = valRead;
		opcode = valRead >> 26;

		fprintf( outFile,"  0x%08X,  0x%02x,",machine_code,opcode);
		
		if (opcode == 0) {

		  //print hex function
		  func = valRead << 26;
		  func = func >> 26;
		  fprintf(outFile,"  0x%02x,",func);

		  //print appropriate mnemonic
		  if      (func ==  0){ fprintf(outFile,"    sll,"); }
		  else if (func ==  2){ fprintf(outFile,"    srl,"); }
		  else if (func ==  8){ fprintf(outFile,"     jr,"); }
		  else if (func == 32){ fprintf (outFile,"   add,"); }
		  else if (func == 33){ fprintf (outFile,"  addu,"); }
		  else if (func == 34){ fprintf (outFile,"   sub,"); }
		  else if (func == 35){ fprintf (outFile,"  subu,"); }
		  else if (func == 36){ fprintf (outFile,"   and,"); }
		  else if (func == 37){ fprintf (outFile,"    or,"); }
		  else if (func == 39){ fprintf (outFile,"   nor,"); }
		  else if (func == 42){ fprintf (outFile,"   slt,"); }
		  else if (func == 43){ fprintf (outFile,"  sltu,"); }
		  else                { fprintf (outFile,"    -1,"); }

		  //print format
		  fprintf(outFile,"    R,");

		  //print rs
		  rs = valRead << 6;
		  rs = rs >> 27;
		  fprintf(outFile,"   %x,",rs);
		  //print rt
		  rt = valRead << 11;
		  rt = rt >> 27;
		  fprintf(outFile,"   %x,",rt);
		  //print rd
		  rd = valRead << 16;
		  rd = rd >> 27;
		  fprintf(outFile,"   %d,",rd);
		  //print shamt
		  shamt = valRead << 21;
		  shamt = shamt >> 27;
		  fprintf(outFile,"   %d,",shamt);
		  //print Imm
		  fprintf(outFile,"   -,");
		  //print address
		  fprintf(outFile,"    -,");

		}//end if opcode==0

		  else {
		  //print null hex function
			fprintf(outFile,"     -,");

			//print appropriate mnemonic
			if      (opcode ==  2) { fprintf(outFile,"     j,"); }
			else if (opcode ==  3) { fprintf(outFile,"   jal,"); }
			else if (opcode ==  4) { fprintf(outFile,"   beq,"); }
			else if (opcode ==  5) { fprintf(outFile,"   bne,"); }
			else if (opcode ==  8) { fprintf(outFile,"  addi,"); }
			else if (opcode ==  9) { fprintf(outFile," addiu,"); }
			else if (opcode == 10) { fprintf(outFile,"  slti,"); }
			else if (opcode == 11) { fprintf(outFile," sltiu,"); }
			else if (opcode == 12) { fprintf(outFile,"  andi,"); }
			else if (opcode == 13) { fprintf(outFile,"   ori,"); }
			else if (opcode == 15) { fprintf(outFile,"   lui,"); }
			else if (opcode == 35) { fprintf(outFile,"    lw,"); }
			else if (opcode == 36) { fprintf(outFile,"   lbu,"); }
			else if (opcode == 37) { fprintf(outFile,"   lhu,"); }
			else if (opcode == 40) { fprintf(outFile,"    sb,"); }
			else if (opcode == 41) { fprintf(outFile,"    sh,"); }
			else if (opcode == 43) { fprintf(outFile,"    sw,"); }
			else if (opcode == 48) { fprintf(outFile,"    ll,"); }
			else if (opcode == 56) { fprintf(outFile,"    sc,"); }
			else                   { fprintf(outFile,"    -1,"); }

			//print J format
			if ( (opcode==2) || (opcode==3) ) {

				fprintf(outFile,"    J,");
				fprintf(outFile,"    -,");
				fprintf(outFile,"    -,");
				fprintf(outFile,"    -,");
				fprintf(outFile,"    -,");
				fprintf(outFile,"    -,");
				address = valRead << 6;
				address = address >> 6;
				fprintf(outFile,"%x,",address);

			}
			//print I format
			else { 

				fprintf(outFile,"    I,");
				rs = valRead << 6;
				rs = rs >> 27;
				fprintf(outFile,"   %d,",rs);
				rt = valRead << 11;
				rt = rd >> 27;
				fprintf(outFile,"   %d,",rt);
				fprintf(outFile,"   -,");
				fprintf(outFile,"   -,");
				imm = valRead << 16;
				imm = imm >> 16;
				fprintf(outFile,"  %04x,",imm);
				fprintf(outFile,"    -,");
			}

		}//end else

		fprintf(outFile,"\n");

	  }//end while

	printf("Program success. New file has been created.\n");

	fclose (inFile);
	fclose (outFile);
	return 0;
}//end main
