#include <winbgim.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include<time.h>
#include <windows.h>
#include <iostream>
#include <mmsystem.h>
#pragma comment (lib, "winmm.lib")


#define MAX 100
#define Length 1300
#define Width 1000
bool check_find = false;
int location_to_delete;
int total_number_of_students = 0;
bool check_innit = false;
bool check_sort = false;
bool check_provide_student_code = false;
FILE *p;
struct first_and_last_name{
    char first_name[25];
    char last_name[9];

};
struct student{    
    first_and_last_name name;
    char gender[5];
    char Date_of_birth[13];
    char address[50];
    char student_code[8];
    char email[15];
};
typedef  student SV; 
void init();
void showText(int x,int y,char *str);
void mainloop(SV student[]);
void add_students( SV student[] ); 
void quickSort_first_name_step2( SV student[] , int low , int high );  
int quickSort_first_name_step3( SV student[] , int low , int high );
void quickSort_first_name_step1( SV student[] );
int quickSort_last_name_step2( SV student[] , int low , int high );
void quickSort_last_name_step1( SV student[] , int low , int high );
void swap( SV &a , SV &b );  
void delete_student( SV student[] ); 
void find_student( SV student[] );
bool Linear_Search( SV student[] );
bool Binary_Search( SV student[] );
void provide_student_code( SV student[] );
void provide_email( SV student[] ); 
void print_list_step1( SV student[] ); 
void print_list_step2( SV sv );
bool check_data( char data[] );  
void output_file( SV student[] );
void Read_in_file(SV student[]);
void Read_information(SV &sv);
void Filter_the_data_name(SV &sv,char name[]);
void Filter_the_data_address(SV &sv,char address[]);
// method main
int main(){
	SV student[MAX];
//	init();
    mainloop(student);
	
   
}
void init(){
	initwindow (Length,Width);
	settextstyle(2,0,7);
	setbkcolor(2);
	line(50,45,1000,45);
	outtextxy(400,50,"PBL 1: DO AN LAP TRINH TINH TOAN");
	setcolor(7);
	line(50,350,1000,350);
	line(50,350,50,45);
	line(1000,350,1000,45);
	outtextxy(350,100,"De Tai: Xay Dung Chuong Trinh Quan Li Sinh Vien");
	setbkcolor(0);
	outtextxy(100,150,"Sinh Vien Thuc Hien:                                         Giao Vien Huong Dan:");
	outtextxy(100,200,">>Pham Cong Huy");
	outtextxy(100,250,">>Pham Van Tien Truong");
	outtextxy(430,200,">>Nguyen THi Minh Hy");
	line(47,45,47,353);
	line(48,353,1000,353);
	delay(3000); 
	closegraph();
	

}
void showText(int x,int y,char *str){
	int c = getcolor();
	int color = 0;
	setcolor(color);
	outtextxy(x+3,y,str);
	setcolor(c);
	delay(50);
}
void showTextBackground(int x,int y,char *str,int color){
	int bk = getbkcolor();
	setbkcolor(color);
	outtextxy(x,y,str);
	delay(200);
	setbkcolor(bk);
}
void mainloop(SV student[]){
	initwindow (800,600);
	setbkcolor(7);
	int key;
	//scanf("%d",&key);
	//if(key==1){
	//	Read_in_file(student);
	//	print_list_step1(student);
		
	//}
	
	int x = 0;
	char *s = new char[5];
	PlaySound (TEXT ("start.wav"), NULL, SND_FILENAME | SND_ASYNC);
	while (x <= 100){
		cleardevice();
		setcolor (10);settextstyle(4,0,5);outtextxy (60,200,"   Loading...");
		sprintf (s,"%d",x);
		setcolor (4);
		outtextxy (550,200,strcat(s,"%"));
		if (x == 100)
			delay (500);
		delay (20);
		x++;
	}
	
	cleardevice();
	while(true){
        x1:
        setbkcolor(7);
		clearmouseclick(WM_LBUTTONDOWN);
		while (!ismouseclick(WM_LBUTTONDOWN) || mousex() < 200 || mousey() > 600 || mousey() < 110 || mousex() > 580 ){
		settextstyle(1,0,4);
		showText(120,50,"Student Management");
		settextstyle(10,0,5);
		showText(220,130,"Add");
		showText(220,200,"Find");
		showText(220,270,"Delete");
		showText(220,340,"Print List");
		showText(220,410,"Sort");
		showText(220,480,"Exit");
	
	}
		clearmouseclick(WM_LBUTTONDOWN);
        if (mousey() <= 185){
		    PlaySound (TEXT ("beep.wav"), NULL, SND_FILENAME | SND_ASYNC);
        	showTextBackground(220,130,"Add",15);
		    setbkcolor(7);
		    cleardevice();
            check_innit = true;
            check_sort = false;
            check_provide_student_code=false;
            add_students(student);

        } else if(mousey() <= 255){
        	PlaySound (TEXT ("beep.wav"), NULL, SND_FILENAME | SND_ASYNC);
        	showTextBackground(220,200,"Find",15);
		    setbkcolor(7);
		    cleardevice();
		    clearmouseclick(WM_LBUTTONDOWN);
		    find_student( student );
		    
        	
		}else if(mousey() <= 325){
			PlaySound (TEXT ("beep.wav"), NULL, SND_FILENAME | SND_ASYNC);
			showTextBackground(220,270,"Delete",15);
		    setbkcolor(7);
		    cleardevice();
		    clearmouseclick(WM_LBUTTONDOWN);
		    delete_student(student);
		    
		}else if(mousey() <= 395){
			PlaySound (TEXT ("beep.wav"), NULL, SND_FILENAME | SND_ASYNC);
			showTextBackground(220,340,"Print List",15);
		    setbkcolor(7);
		    cleardevice();
		    clearmouseclick(WM_LBUTTONDOWN);
		    print_list_step1(student);
		}else if(mousey() <= 465){
			PlaySound (TEXT ("beep.wav"), NULL, SND_FILENAME | SND_ASYNC);
			showTextBackground(220,410,"Sort",15);
		    setbkcolor(7);
		    cleardevice();
		    if(check_innit==false){
		       showTextBackground(250,200,"Empty class",15);	
			}
			else {
				PlaySound (TEXT ("beep.wav"), NULL, SND_FILENAME | SND_ASYNC);
				quickSort_last_name_step1(student,total_number_of_students-1,0);
				quickSort_first_name_step1(student);
				showTextBackground(250,200,"Sort Success",15);
			    check_sort=true;
			    
		       }
		       delay(2000); 
		       cleardevice();
	    }
		else {
			PlaySound (TEXT ("beep.wav"), NULL, SND_FILENAME | SND_ASYNC);
			showTextBackground(220,480,"Exit",15);
		    setbkcolor(7);
		    cleardevice();
		    clearmouseclick(WM_LBUTTONDOWN);
		    output_file( student );
		    exit(0);
		    
        }

    }
	
}

void add_students( SV student[]){
		char str[2];
		str[1] = 0;
		char key=0;
	    clearmouseclick(WM_LBUTTONDOWN);
		settextstyle(1,0,3);
		setfillstyle(1,15);
		showText(50,50,"First Name:");
		showText(50,150,"Last Name:");
		showText(50,250,"Gender:");
		showText(50,350,"Date_of_birth:");
		showText(50,450,"Address:");
		bar(250,50,600,80);
		bar(250,150,600,180);
		bar(250,250,600,280);
		bar(300,350,650,380);
		bar(200,450,600,480);
		bool check=false;
		
	    while(key!=13){
			key= getch();
			str[0] = key;
			if(key!=13){
			strcat(student[total_number_of_students].name.first_name,str);
			outtextxy(250,50,student[total_number_of_students].name.first_name);
		}
	   }
	   outtextxy(250,100,student[total_number_of_students].name.first_name);
	   key=0;
	   while(key!=13){
			key= getch();
			str[0] = key;
			if(key!=13){
			strcat(student[total_number_of_students].name.last_name,str);
			outtextxy(250,150,student[total_number_of_students].name.last_name);
		}
	   }
	   
	   key=0;
	   while(key!=13){
			key= getch();
			str[0] = key;
			if(key!=13){
			strcat(student[total_number_of_students].gender,str);
			outtextxy(250,250,student[total_number_of_students].gender);
		}
	   }
	   key=0;
	   while(key!=13){
			key= getch();
			str[0] = key;
			if(key!=13){
			strcat(student[total_number_of_students].Date_of_birth,str);
			outtextxy(300,350,student[total_number_of_students].Date_of_birth);
		}
	   }
	   key=0;
	   while(key!=13){
			key= getch();
			str[0] = key;
			if(key!=13){
			strcat(student[total_number_of_students].address,str);
			outtextxy(200,450,student[total_number_of_students].address);
		}
	   }
	   total_number_of_students++;
	   delay(1000);
	   cleardevice();
	
	
  
}

void Filter_the_data_name(SV &sv,char name[]){
    int key1=0,key2=0;
    for(int i=strlen(name)-1;i>=0;i--){
        if(name[i]!=' '&&key1==0){
            key1=i;
        
        }
        if(name[i]==' '&&key2==0&&key1!=0){
            key2=i;
        }
    }
    int j=0;
    strncpy(sv.name.first_name,name,key2+1);
    for(int i=key2+1;i<=key1;i++){
        sv.name.last_name[j]=name[i];
        j++;
    }


}
void Read_in_file(SV student[]){
    p=fopen("input.txt","r");
    if(p==NULL) {
	       printf("\nFile Khoong Ton Tai!!!\n");
	   }
    else {
        printf("\nDang Doc File!!!\n");
            
            total_number_of_students++; 
    
        printf("\nDa Doc Xong File!!!\n");
        fclose(p);
    }
} 
void print_list_step1(SV student[]){
    printf(" _______________________________________________________________________________________________________________________________________________\n");
    printf("| STT |             Ho Va Ten           |Gioi Tinh|  Ngay Sinh |                      Dia Chi                     |Ma Sinh Vien|      Email     |\n");
    for(int i = 0 ; i < total_number_of_students ; i++ ){
          printf("| %3d |", i );
      print_list_step2( student[i] );
    }
    printf(" -----------------------------------------------------------------------------------------------------------------------------------------------");
}
void print_list_step2( SV sv ){
    char name[34];
    char b[2] = {' '};
    strcpy( name , sv.name.first_name );
    strcat( name , b );
    strcat( name ,sv.name.last_name );
    printf("%-33s|", name );
    printf("%-9s|", sv.gender );
    printf("%-12s|", sv.Date_of_birth );
    printf("%-50s|", sv.address );
    printf("%-12s|", sv.student_code ); 
    printf("%-16s|", sv.email );
    printf("\n");
}
bool check_data( char data[] ){
    if( data[0] >= '0' && data[0] <= '9' ) return true;
    return false;
}   
void delete_student( SV student[] ){
    find_student( student );
    if( check_find ){
	    cleardevice();
	    settextstyle(1,0,5);
        clearmouseclick(WM_LBUTTONDOWN);
        while(!ismouseclick(WM_LBUTTONDOWN) || mousex() < 200 || mousey() > 600 || mousey() < 110 || mousex() > 580){
        	showText(300,100,"Delete");
            showText(300,300,"Back");
	}
        if (mousey() <= 250){
           for(int j = location_to_delete+1 ; j < total_number_of_students ; j++ ) student[j-1] = student[j];
           total_number_of_students--;
       }
   
        cleardevice();
    }
    
}    
bool Linear_Search( SV student[] , char data[] ){
    int i = 0;
    char name[20];
    char b[2] = {' '};
    if( check_data(data) == false ){ 
        strcpy( name , student[i].name.first_name );
        strcat( name , b );
        strcat( name , student[i].name.last_name );
        while( i < total_number_of_students && stricmp(name,data) != 0 ) {
                 i++;
            strcpy( name , student[i].name.first_name );
            strcat( name , b );
            strcat( name , student[i].name.last_name ); 
        }
    }
    else {
        while( i < total_number_of_students && strcmp(student[i].student_code,data) != 0) i++;
    }
    location_to_delete = i;
    if( i == total_number_of_students ) return false;
    return true;

}
bool Binary_Search( SV student[] , char data[] ){
    char b[2] = {' '};
    int left = 0;
    int right = total_number_of_students - 1;
    int mid;
    if( check_data(data) ){
            while ( left <= right )
            {
                mid = ( left + right ) / 2;

                if ( stricmp(student[mid].student_code,data) == 0 ){
                    location_to_delete = mid;
                    return true;
                }
                if ( stricmp(student[mid].student_code,data) > 0 )
                    right = mid - 1; 
                else if ( stricmp(student[mid].student_code,data) < 0 )
                    left = mid + 1; 
            }
    }
    else {
        char name[100];
        while ( left <= right )
            {
                mid = ( left + right ) / 2;
                strcpy( name , student[mid].name.first_name );
                strcat( name , b );
                strcat( name , student[mid].name.last_name );
                if ( stricmp(name,data) == 0){
                    location_to_delete = mid;
                    return true; 
                }
                if ( stricmp(name,data) > 0)
                    right = mid - 1; 
                else if (stricmp(name,data) < 0)
                    left = mid + 1; 
            }
    }
    return false; 
}

void find_student( SV student[] ){
	fflush(stdin);
	settextstyle(1,0,3);
	showText(10,50,"Enter Name Or Student Code");
	bar(400,50,750,80);
    char data[50]={""};
    char str[2];
	str[1] = 0;
	char key=0;
	while(key!=13){
			key= getch();
			str[0] = key;
			if(key!=13){
			
			strcat(data,str);
			outtextxy(400,50,data);
		}
    }   
    if( check_sort ){
        check_find  = Binary_Search(student,data);


    }
    else {
        check_find = Linear_Search(student,data);
    }

    if(check_find == false){
    	PlaySound (TEXT ("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
         showText(280,200,"No Found");
         key=0;
         while(key!=13){
         	key=getch();
		 }
    }
    else {
    	cleardevice();
    	char b[2] = {' '};
    	char name[50]={""};
    	strcpy( name , student[location_to_delete].name.first_name );
        strcat( name , b );
        strcat( name , student[location_to_delete].name.last_name );
    	settextstyle(1,0,2);
    	key=0;
    	showText(10,2,"Name:");
    	showText(115,2,name);
    	showText(10,100,"Gender:");
    	showText(125,100,student[location_to_delete].gender);
    	showText(10,200,"Date of birth:");
    	showText(200,200,student[location_to_delete].Date_of_birth);
    	showText(10,300,"Address:");
    	showText(135,300,student[location_to_delete].address);
    	showText(10,400,"Sudent code:");
    	showText(160,400,student[location_to_delete].student_code);
    	showText(10,500,"Email:");
    	showText(150,500,student[location_to_delete].email);
         while(key!=13){
         	key=getch();
		 }
         
   
    
	}
    cleardevice();
    
        
}
      

void swap(SV &a,SV &b){
    SV c;    
    c = a;
    a = b;
    b = c;
}
int quickSort_last_name_step2( SV student[] , int low , int high )
{
    
    char pivot[10];
    strcpy( pivot, student[high].name.last_name ) ;
    int left = low;
    int right = high - 1;
    while(true){
        while( left <= right && stricmp(pivot,student[left].name.last_name) > 0 )
             left++;
        while(right >= left && stricmp(pivot,student[right].name.last_name) < 0)
             right--;
        if (left >= right) break;
        swap( student[left] , student[right] );
        left++;
        right--;
    }
    swap( student[left] , student[high] );
    return left;
}
void quickSort_last_name_step1( SV student[] , int low , int high )
{
    if (low < high)
    {  
        int pi = quickSort_last_name_step2( student, low, high);
        quickSort_last_name_step1( student , low , pi-1 );
        quickSort_last_name_step1( student , pi+1 , high );
    }
}

int quickSort_first_name_step3( SV student[] , int low , int high )
{
    char pivot[15];
    strcpy( pivot, student[0].name.first_name );

    int left = low;
    int right = high - 1;
    while(true){
        while( left <= right && stricmp( pivot, student[left].name.first_name ) > 0)
             left++;
        while(right >= left && stricmp( pivot , student[right].name.first_name ) < 0)
             right--;
        if (left >= right) break;
        swap(student[left], student[right]);
        left++;
        right--;
    }
    swap(student[left], student[high]);
    return left;
}
void quickSort_first_name_step2(SV student[],int low,int high){
    if(low<high){
        int pi=quickSort_first_name_step3(student,low,high);
        quickSort_first_name_step2(student,low,pi-1);
        quickSort_first_name_step2(student,pi+1,high);
    }
}
void quickSort_first_name_step1(SV student[]){
    int bien_trung_gian=0;
    char lastname[10];
    strcpy(lastname,student[0].name.last_name);
    for(int i = 1 ; i < total_number_of_students ; i++){
        if( stricmp(lastname,student[i].name.last_name) != 0 || i == total_number_of_students-1 )
        {
            quickSort_first_name_step2(student,bien_trung_gian,i-1);
            bien_trung_gian = i;  
            strcpy(lastname,student[i].name.last_name);
        }


    }
}
void provide_student_code(SV student[]){
    for(int i=0;i<total_number_of_students;i++){
        student[i].student_code[0]='1';
        student[i].student_code[1]='0';
        student[i].student_code[2]='0';
        student[i].student_code[3]='2';
        student[i].student_code[4]='2';
        char m='0';
        if(i<10){
            student[i].student_code[5]='0';
            student[i].student_code[6]='0';

            student[i].student_code[7]=m+i;
        }
        else if(i!=100&&i>=10) {
             student[i].student_code[5]=0;
             int z=i%10;
             student[i].student_code[6]=m+z;
             m=m-z;
             i=i/10;
             student[i].student_code[7]=m+i;

        }
        else {
            student[i].student_code[5]='1';
            student[i].student_code[6]='0';
            student[i].student_code[7]='0';
        }
    }

}
void provide_email(SV student[]){
    char b[11]="@gmail.com";
    for(int i=0;i<total_number_of_students;i++){

    
    strcpy(student[i].email,student[i].student_code);
    strcat(student[i].email, b);


    }
}
void output_file(SV student[]){
    FILE *fp;
    char filename[13]="dssvlop .txt";
    FILE *p;
    p=fopen("lop.txt","r");
    int n;
    char r='0';
    fscanf(p,"%d",&n);
    filename[7]=r+n+1;
    fclose(p);
    p=fopen("lop.txt","w");
    fprintf(p,"%d",n+1);
    fclose(p);
    fp=fopen(filename,"w");
    fprintf(fp,"%-4s%d\n\n","LOP:",n+1); 
    fprintf(fp,"%-145s\n"," ______________________________________________________________________________________________________________________________________________");
    fprintf(fp,"%-145s\n","| STT |             Ho Va Ten           |Gioi Tinh| Ngay  Sinh |                       Dia Chi                    |Ma Sinh Vien|    Email      |");
    for(int i=0;i<total_number_of_students;i++){
             fprintf(fp,"%c%2s%-3d%c",'|',"  ",i,'|');
             char name[34];
		     char b[2] = {' '};
		     strcpy( name , student[i].name.first_name );
		     strcat( name , b );
		     strcat( name ,student[i].name.last_name );
             fprintf(fp,"%-33s%c",name,'|');
             fprintf(fp,"%-9s%c",student[i].gender,'|');
             fprintf(fp,"%-12s%c",student[i].Date_of_birth,'|');
             fprintf(fp,"%-50s%c",student[i].address,'|');
             fprintf(fp,"%-12s%c",student[i].student_code,'|');
             fprintf(fp,"%-15s%c\n",student[i].email,'|');
        }
    fprintf(fp,"%-145s"," ----------------------------------------------------------------------------------------------------------------------------------------------");    
    fclose(fp);
}
/* Do An Quan Li Hoc Sinh */


