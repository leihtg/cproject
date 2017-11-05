#include <stdio.h>
EXEC SQL BEGIN DECLARE SECTION;
VARCHAR username[20];
VARCHAR password[20];
EXEC SQL END DECLARE SECTION;
EXEC SQL INCLUDE  sqlca;
void sqlerror();

main(){
	EXEC SQL BEGIN DECLARE SECTION;
	 int emp_number;
	 VARCHAR emp_name[15];
	 float salary;
	 float commission;
	 EXEC SQL END DECLARE SECTION;
	 
	 int total_number;
	 strcpy(username.arr,"SCOTT");
	 username.len=strlen(username.arr);
	 strcpy(password.arr,"tiger");
	 password.len=strlen(password.arr);
	 EXEC SQL WHENEVER SQLEROR DO sqlerror();
	 EXEC SQL CONNECT:username IDENTIFIED BY :password;
	 printf("\n Connected to Oracle as user:%s\n",username.arr);
	 
	 total_number=0;
	 while(1){
		 emp.number=0;
		 printf("\nEnter employee number(0 to quit):");
		 scanf("5d",$emp_number);
		 if(emp_number==0)break;
		 
		 EXEC SQL WHENEVER NOT FOUND GOTO notfound;
		 EXEC SQL SELECT ENAME,SAL,COMM INTO :emp_name,:salary,:commission
		 FROM 	EMP
		 WHERE EMPNO=:emp_number;
		 
		 printf("\n\nEmployee\tSalary\tCommission\n");
		 printf("--------------\t--------------\t--------------\n");
		 emp_name.arr[emp_name.len]='\0';
		 printf("%-8s\t%6.2f\t%6.2f\n",emp_name.arr,salary,commission);
		 total_number=total_number+1;
		 continue;
		 notfound:
			 printf("\nNot a valid employee number--try again.\n");
	 }
	 printf("\n\nTotal number queried was :%d\n",total_number);
	 printf("\nHave a good day.\n");
	 
	 EXEC SQL COMMIT WORK RELEASE;
	 exit(0);
}
void sqlerror(){
	EXEC SQL WHENEVER SQLERROR CONTINUE;
	printf("\nOracle error detected :\n");
	EXEC SQL ROLLBACK RELEASE;
	exit(1);
}