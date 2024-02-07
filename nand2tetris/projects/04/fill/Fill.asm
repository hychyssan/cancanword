// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen
// by writing 'black' in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen by writing
// 'white' in every pixel;
// the screen should remain fully clear as long as no key is pressed.

//// Replace this comment with your code.

 @i
 M=0

 (PRESS)
 //if unpress ,jump to@TURNTOUNPRESS
 @KBD
 D=M
 @TURNTOUNPRESS
 D;JEQ

 //if(i==8000,i=0)
 @i
 D=M
 @8000
 D=A-D
 @TURNTOPRESS
 D;JEQ


 //RAM[SCREEN+i]=-1
 @SCREEN
 D=A
 @i
 A=M+D
 M=-1

 //i++
 @i
 M=M+1

 @PRESS
 0;JMP

 (UNPRESS)
  //if press ,jump to@TURNTOPRESS
 @KBD
 D=M
 @TURNTOPRESS
 D;JNE

 //if i==8000,goto @UNPRESS
 //if(i==8000,i=0)
 @i
 D=M
 @8000
 D=A-D
 @TURNTOUNPRESS
 D;JEQ

 //RAM[SCREEN+i]=0
 @SCREEN
 D=A
 @i
 A=M+D
 M=0

 //i++
 @i
 M=M+1

 @UNPRESS
 0;JMP

 (TURNTOUNPRESS)
 @i
 M=0
 @UNPRESS
 0;JMP

 (TURNTOPRESS)
 @i
 M=0
 @PRESS
 0;JMP
 