#include <stdio.h>
#define SIZE 4


struct student{
	char name[10];

	int age;
	char addr[15];
}stu[SIZE] ;

void save(){
	FILE *fp;
	int i;
	if(!(fp=fopen("student-list","wb"))){
		printf("不能打开student-list文件\n");
		return;
	}
	for(i=0;i<SIZE;i++){
		if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1){
			printf("写入失败\n");
			fclose(fp);
		}
	}
}
void load(){
	FILE *fp;
	if(!(fp=fopen("student-list","rb"))){
	printf("不能打开student-list文件\n");
	return;
	}
	for(int i=0;i<SIZE;i++){
		fread(&stu[i],sizeof(struct student),1,fp);
	}
	for(i=0;i<SIZE;i++){
		printf("%s\t%d\t%s\n",stu[i].name,stu[i].age,stu[i].addr);
	}
}
void main(){
	int i;

/*	printf("请输入学生名、年龄、住址\n");
	for(i=0;i<SIZE;i++){
		scanf("%s %d %s",&stu[i].name,&stu[i].age,&stu[i].addr);
	}
	save();
	*/
	load();
	
}
