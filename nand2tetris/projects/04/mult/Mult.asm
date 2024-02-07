@2
M=0

@i
M=0

@1
D=M
@n
M=D
@sum
M=0


(LOOP)
	//if(i==n) goto PLACE
@i
D=M
@n
D=D-M
@PLACE
D;JEQ

//sum+=A
@0
D=M
@sum
M=M+D

//i++
@i
M=M+1

@LOOP
0;JMP

(PLACE)	//place result into RAM[2]
@PLACE
	//RAM[2]=sum
@sum
D=M
@2
M=D
@END

(END)
@END
0;JMP
