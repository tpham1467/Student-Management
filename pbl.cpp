#include <winbgim.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include<time.h>
#include <windows.h>

#define MAX 100
#define Length 1600
#define Width 800

bool check_find = false;
int location_to_delete;
int total_number_of_students = 0;
bool check_innit = false;
bool check_sort = false;
bool check_provide_student_code = false;
bool check_provide_email = false;
FILE *p;
struct first_and_last_name{
	
    char first_name[25];
    char last_name[25];

};
struct student{    
    first_and_last_name name;
    char gender[10];
    char Date_of_birth[15];
    char address[50];
    char student_code[20];
    char email[35];
};
typedef  student SV;

void init();
void showText(int x,int y,char *str);
void showTextBackground(int x,int y,char *str,int color);

void mainloop(SV student[]);
void add_students( SV student[] ); 
void quickSort_last_name_step2( SV student[] , int low , int high );  
int partition( SV student[] , int low , int high,int flag );
void quickSort_last_name_step1( SV student[] );
void quickSort_first_name_step1( SV student[] , int low , int high );
void swap( SV &a , SV &b );  
void delete_student( SV student[] ); 
void find_student( SV student[] );
bool Linear_Search( SV student[] );
bool Binary_Search( SV student[] );
void provide_student_code( SV student[] );
void provide_email( SV student[] ); 
void print_list_step1( SV student[] ); 
void print_list_step2( SV sv ,int x );
bool check_data( char data[] );  
void output_file( SV student[] );
void Read_in_file(SV student[]);		
void Filter_the_data(char *p,char c);
// method main
int main(){
	SV student[MAX];
	init();
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
	outtextxy(550,600,"Press enter to continue");
	char key=0;
	 while(key!=13){
         	key=getch();
		 }
	closegraph();
	

}
void showText(int x,int y,char *str){
	int c = getcolor();
	int color = 0;
	setcolor(color);
	outtextxy(x+3,y,str);
	setcolor(c);
	delay(100);
}
void showTextBackground(int x,int y,char *str,int color){
	int bk = getbkcolor();
	setbkcolor(color-15);
	outtextxy(x,y,str);
	delay(50);
	setbkcolor(bk);
}
void mainloop(SV student[]){
	
	initwindow (800,600);
	setbkcolor(7);
	
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
		setbkcolor(0);
        setbkcolor(7);
		clearmouseclick(WM_LBUTTONDOWN);
		while (!ismouseclick(WM_LBUTTONDOWN) || mousex() < 200 || mousey() > 600 || mousey() < 20 || mousex() > 580 ){
		settextstyle(1,0,4);
		showText(120,10,"Student Management");
		settextstyle(10,0,5);
		showText(220,50,"Add");
		showText(220,120,"Find");
		showText(220,190,"Delete");
		showText(220,260,"Print List");
		showText(220,330,"Sort");
		showText(220,400,"Provide Student Code");
		showText(220,470,"Provide Email");
		showText(220,540,"Exit");
	
	}    
		clearmouseclick(WM_LBUTTONDOWN);
        if (mousey() <= 95){
		    PlaySound (TEXT ("beep.wav"), NULL, SND_FILENAME | SND_ASYNC);
        	showTextBackground(220,50,"Add",15);
		    cleardevice();
		    clearmouseclick(WM_LBUTTONDOWN);
		    while (!ismouseclick(WM_LBUTTONDOWN) || mousex() < 200 || mousey() > 600 || mousey() < 110 || mousex() > 580 ){
		    	showText(220,200,"Read From File");
		        showText(220,270,"Enter Directly Info");
		    }
		    if (mousey() <= 270){
		        PlaySound (TEXT ("beep.wav"), NULL, SND_FILENAME | SND_ASYNC);
		    	showTextBackground(220,200,"Read From File",15);
		    	Read_in_file(student);
			}else {
				PlaySound (TEXT ("beep.wav"), NULL, SND_FILENAME | SND_ASYNC);	
	            showTextBackground(220,270,"Enter Directly Info",15);
	            cleardevice();
	            add_students(student);
	           }  
            check_innit = true;
            check_sort = false;
            check_provide_student_code = false;
            check_provide_email = false;
            cleardevice();
            clearmouseclick(WM_LBUTTONDOWN);
        } else if(mousey() <= 165){
        	showTextBackground(220,120,"Find",15);
        	PlaySound (TEXT ("beep.wav"), NULL, SND_FILENAME | SND_ASYNC);
        	setbkcolor(7);
		    cleardevice();
        	if(check_innit==true){
			    find_student( student );
		   }
		   else {
		     	delay(300);
		   		PlaySound (TEXT ("error.wav"), NULL, SND_FILENAME | SND_ASYNC);	
		        showTextBackground(250,200,"Empty class",15);
		   }
		    delay(1000);
		    cleardevice();
		    clearmouseclick(WM_LBUTTONDOWN);
		    
        	
		}else if(mousey() <= 235){
			showTextBackground(220,190,"Delete",15);
			cleardevice();
			PlaySound (TEXT ("beep.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if(check_innit==true){
		    delete_student(student);
		    }
		    else {
		    	delay(300);
		    	PlaySound (TEXT ("error.wav"), NULL, SND_FILENAME | SND_ASYNC);	
		        showTextBackground(250,200,"Empty class",15);
		    	
			}
			delay(1000);
		    cleardevice();
		    clearmouseclick(WM_LBUTTONDOWN);
		    
		}else if(mousey() <= 305){
			showTextBackground(220,260,"Print List",15);
			cleardevice();
			if(check_innit==true){
					PlaySound (TEXT ("beep.wav"), NULL, SND_FILENAME | SND_ASYNC);
				    print_list_step1(student);
		    }else {
			    PlaySound (TEXT ("error.wav"), NULL, SND_FILENAME | SND_ASYNC);	
			    showTextBackground(250,200,"Empty class",15);
			}
		    cleardevice();
		    clearmouseclick(WM_LBUTTONDOWN);
		}else if(mousey() <= 375){
			    cleardevice();
			    showTextBackground(220,330,"Sort",15);
			    cleardevice();
				PlaySound (TEXT ("beep.wav"), NULL, SND_FILENAME | SND_ASYNC);
		    if(check_innit==false){
		       PlaySound (TEXT ("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
		       showTextBackground(250,200,"Empty class",15);
		       
			}
			else if(check_sort==false){
				quickSort_first_name_step1(student,0,total_number_of_students-1);
				quickSort_last_name_step1(student);
				showTextBackground(250,200,"Sort Success",15);
			    check_sort=true;
			    
			    
		       }
		    else if(check_sort==true){
		    	PlaySound (TEXT ("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
		    	showTextBackground(250,200,"Arranged",15);
		    	
			}   
		       delay(1000); 
		       cleardevice();
		       clearmouseclick(WM_LBUTTONDOWN);
	    }
	    else if(mousey() <= 445){
	    	PlaySound (TEXT ("beep.wav"), NULL, SND_FILENAME | SND_ASYNC);
	    	showTextBackground(220,400,"Provide Student Code",15);
	    	cleardevice();
	    	if(check_innit==false){
				PlaySound (TEXT ("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
		        showTextBackground(250,200,"Empty class",15);
		    }
	    	else if(check_provide_student_code == true){
	    		PlaySound (TEXT ("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
	    		showTextBackground(100,200,"Student Code Has Been Issued",15);
			}
			else if(check_sort == false){
				PlaySound (TEXT ("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
				showTextBackground(100,200,"Not Arranged",15);
			}else {
				showTextBackground(50,100,"Student Code has been issued successfully",15);
				provide_student_code( student );
				check_provide_student_code = true;
			}
			delay(1000);
			cleardevice();
		    clearmouseclick(WM_LBUTTONDOWN);
		}
		else if(mousey() <= 515){
			PlaySound (TEXT ("beep.wav"), NULL, SND_FILENAME | SND_ASYNC);
			cleardevice();
			showTextBackground(220,470,"Provide Email",15);
			cleardevice();
			if(check_innit==false){
				PlaySound (TEXT ("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
				PlaySound (TEXT ("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
		        showTextBackground(250,200,"Empty class",15);
				
			}else if(check_provide_email==true){
				PlaySound (TEXT ("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
				showTextBackground(100,200,"Email Has Been Issued",15);
				
	     	}
			else if(check_provide_student_code == false){
				PlaySound (TEXT ("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
				showTextBackground(100,200,"	",15);
				
			}
			else {
				showTextBackground(100,200,"Email Issued Successfully",15);
				provide_email( student ); 
				check_provide_email = true;
			} 
			delay(1000);
			cleardevice();
		    clearmouseclick(WM_LBUTTONDOWN);
		}
		else {
			PlaySound (TEXT ("beep.wav"), NULL, SND_FILENAME | SND_ASYNC);
			showTextBackground(220,540,"Exit",15);
		    setbkcolor(7);
		    cleardevice();
		    clearmouseclick(WM_LBUTTONDOWN);
		    output_file( student );
		    exit(0);
		    
        }

    }
	
}
void Filter_the_data(char *p,char c){
	for(int i=0;i<strlen(p);i++){
	     if(p[i]==c) p[i]=' ';
	}
	char string[70];
	int key;
	for(int i=strlen(p)-1;i>=0;i--){
		if(p[i]!=' ') { key=i;
		break; 
			
		}
	}
	if(key==strlen(p)-1) return;
	strncpy(string,p,key+1);
	strcpy(p,string);

}
void read_data_from_keyboard(char *p,int x,int y,int z,int w){
	char str[2];
	str[1] = 0;
	char key=0;
	int m=0;
	int r;
	bool check=false;
	bool check_full=false;
	while(key!=13){
			key= getch();
			if(key==8&&check_full==false){
				p[m]='?';
				m--;
	            char b[51]={""};
	            strncat(b,p,m+1);
	            bar(x,y,z,w);
	            outtextxy(x,y,b);
	            if(p[0]=='?') check_full=true;
			}
			else str[0] = key;
			if(key!=13&&key!=8){
			   for(int i=0;i<strlen(p);i++){
			   	if(p[i]=='?') {
				   p[i]=key;
				   check=true;
				   r=i;
				   if(i==strlen(p)-1) m=strlen(p)-1;
				   check_full=false;
				   break;
			    }
		    }
		    if(check==true){
		    	char b[51]={""};	
			    strncat(b,p,r+1);
			    bar(x,y,z,w);
			    outtextxy(x,y,b);
	    	    check=false;
			}
			else {
				str[0]=key;
				strcat(p,str);
				bar(x,y,z,w);
				outtextxy(x,y,p);
				m=strlen(p)-1;
			}
	   }
	   
	   }
	
} 
void add_students( SV student[]){
		settextstyle(1,0,3);
		setfillstyle(1,15);
		showText(50,50,"First Name:");
		showText(50,150,"Last Name:");
		showText(50,250,"Gender:");
		showText(50,350,"Date_of_birth:");
		showText(50,450,"Address:");
		bar(250,50,600,75);
		bar(250,150,600,175);
		bar(250,250,600,275);
		bar(300,350,650,375);
		bar(200,450,600,475);
		//first name
        read_data_from_keyboard(student[total_number_of_students].name.first_name,250,50,600,75);
        Filter_the_data(student[total_number_of_students].name.first_name,63);
        // last name
		read_data_from_keyboard(student[total_number_of_students].name.last_name,250,150,600,175);
		Filter_the_data(student[total_number_of_students].name.last_name,63);
		// gender
		read_data_from_keyboard(student[total_number_of_students].gender,250,250,600,275);
		Filter_the_data(student[total_number_of_students].gender,63);
		// date of birth
		read_data_from_keyboard(student[total_number_of_students].Date_of_birth,300,350,650,375);
		Filter_the_data(student[total_number_of_students].Date_of_birth,63);
		//address
		read_data_from_keyboard(student[total_number_of_students].address,200,450,600,475);
		Filter_the_data(student[total_number_of_students].address,63);
		
	    total_number_of_students++;
	    clearmouseclick(WM_LBUTTONDOWN);
	    while(!ismouseclick(WM_LBUTTONDOWN) || mousex() < 100   || mousey() < 400 || mousex() > 400){
			showText(150,550,"Back");
            showText(300,550,"Add");
            
	   }
	   if(mousex()<=275){
	   	showTextBackground(150,550,"Back",15);
	
	   	
	   }
	   else {
	   	showTextBackground(300,550,"Add",15);
        cleardevice();
	   	add_students(student);
	   	
	   }
	    
	   delay(300);
	   cleardevice();
	
	
  
}
void Read_in_file(SV student[]){
	cleardevice();
	settextstyle(1,0,3);
    showText(10,50,"Enter File Name:");
	bar(300,50,750,75);
    char data[50]={""};
    read_data_from_keyboard(data,300,50,750,75);
    Filter_the_data(data,63);
	p=fopen(data,"r");
    cleardevice();
    if(p==NULL) {
    	PlaySound (TEXT ("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
    	showTextBackground(250,200,"File Does Not Exist",15);
	   }
    else {
        char first_name[50];
	    char last_name[50];
	    char gender[50];
	    char d[50];
        char ns[50];
        int n=total_number_of_students;
        while( fscanf(p, "Last_Name: %s First_Name:%s Gender: %s Date_of_birth: %s Address: %s\n", student[n].name.last_name,student[n].name.first_name,student[n].gender,student[n].Date_of_birth,student[n].address) != EOF ){
		    Filter_the_data(student[n].name.first_name,95);
		    Filter_the_data(student[n].name.last_name,95);
		    Filter_the_data(student[n].address,95);
            total_number_of_students++;
			n=total_number_of_students;
        }
        showTextBackground(250,200,"Read Successfully",15);
        fclose(p);
    }
    delay(400);
} 
void print_list_step1(SV student[]){
	setbkcolor(0);
	cleardevice();
	setcolor(15);
	rectangle(5,5,1470,30+25*(total_number_of_students));
	rectangle(5,5,1470,30);
	line(50,5,50,30+25*(total_number_of_students));
	line(400,5,400,30+25*(total_number_of_students));
	line(500,5,500,30+25*(total_number_of_students));
   	line(700,5,700,30+25*(total_number_of_students));
   	line(1100,5,1100,30+25*(total_number_of_students));
   	line(1250,5,1250,30+25*(total_number_of_students));
   	settextstyle(2,0,7);
   	outtextxy(7,7,"Stt");
   	outtextxy(140,7,"Ho Va Ten");
   	outtextxy(415,7,"Gioi Tinh");
   	outtextxy(550,7,"Ngay sinh");
   	outtextxy(840,7,"Dia Chi");
   	outtextxy(1110,7,"Ma Sinh Vien");
   	outtextxy(1280,7,"Email");
   	outtextxy(550,30+25*(total_number_of_students)+40,"Press enter to continue");
   	int x=5;
   	char s[5]={""};
    for(int i = 0 ; i < total_number_of_students ; i++ ){
      print_list_step2( student[i],x);
      sprintf (s,"%d",i);
      outtextxy(7,x+25+2,s);
      line(5,x+25,1470,x+25);
      x+=25;
    }
    clearmouseclick(WM_LBUTTONDOWN);
    char key=0;
    while(key!=13){
         	key=getch();
		 }
	setbkcolor(7);
	setbkcolor(0);
	setbkcolor(7);
}
void print_list_step2( SV sv ,int x){
	 char name[50]={""};
	 char b[2] = {' '};
	 strcpy( name , sv.name.last_name );
     strcat( name , b );
     strcat( name , sv.name.first_name );
     outtextxy(70,x+25+2,name);
     outtextxy(415,x+25+2,sv.gender);
     outtextxy(550,x+25+2,sv.Date_of_birth);
     outtextxy(710,x+25+2,sv.address);
     outtextxy(1110,x+25+2,sv.student_code);
     outtextxy(1260,x+25+2,sv.email);
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
        	showTextBackground(300,100,"Delete",15);
           for(int j = location_to_delete+1 ; j < total_number_of_students ; j++ ) student[j-1] = student[j];
           total_number_of_students--;
       }
       else {
       	showTextBackground(300,300,"Back",15);
	   }
   
        cleardevice();
    }
    
}
bool Linear_Search( SV student[] , char data[] ){
    int i = 0;
    char name[50];
    char b[2] = {' '};
    if( check_data(data) == false ){ 
        strcpy( name , student[i].name.last_name );
        strcat( name , b );
        strcat( name , student[i].name.first_name );
     
        while( i < total_number_of_students && stricmp(name,data) != 0 ) {
            i++;      
            strcpy( name , student[i].name.last_name );
            strcat( name , b );
            strcat( name , student[i].name.first_name ); 
        }
    }
    else {
        while( i < total_number_of_students && strcmp(student[i].student_code,data) != 0) i++;
    }
 
    if( i == total_number_of_students ) return false;
    location_to_delete = i;
    return true;

}
bool Binary_Search( SV student[] , char data[] ){
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
           return false; 
    }else {
    	return Linear_Search(student,data);
    	
	}
}
void find_student( SV student[] ){
	fflush(stdin);
	settextstyle(1,0,3);
	showText(10,50,"Enter Name Or Student Code");
	bar(400,50,750,75);
    char data[50]={""};
    read_data_from_keyboard(data,400,50,750,75);
    Filter_the_data(data,63);
    if( check_sort ){
        check_find  = Binary_Search(student,data);
        


    }
    else {
        check_find = Linear_Search(student,data);
        
    }

    if(check_find == false){
    	PlaySound (TEXT ("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
         showText(280,200,"Not Find");
         delay(250);
    }
    else {
    	cleardevice();
    	char b[2] = {' '};
    	char name[50]={""};
    	strcpy( name , student[location_to_delete].name.last_name );
        strcat( name , b );
        strcat( name , student[location_to_delete].name.first_name );
    	settextstyle(1,0,2);
    	char key=0;
    	showText(10,2,"Name:");
    	showText(115,2,name);
    	showText(10,100,"Gender:");
    	showText(125,100,student[location_to_delete].gender);
    	showText(10,200,"Date of birth:");
    	showText(200,200,student[location_to_delete].Date_of_birth);
    	showText(10,300,"Address:");
    	showText(135,300,student[location_to_delete].address);
    	showText(10,400,"Student code:");
    	showText(200,400,student[location_to_delete].student_code);
    	showText(10,500,"Email:");
    	showText(100,500,student[location_to_delete].email);
    	showText(200,550,"Press enter to continue");
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
int partition( SV student[] , int low , int high ,int flag)
{
    
    char pivot[10];
    if(flag==1)
    strcpy( pivot, student[high].name.last_name ) ;
    else strcpy( pivot, student[high].name.first_name ) ;
    int left = low;
    int right = high - 1;
    while(true){
        if(flag==1){
	        while( left <= right && stricmp(pivot,student[left].name.last_name) > 0 )
	             left++;
	        while(right >= left && stricmp(pivot,student[right].name.last_name) < 0)
	             right--;
         }
         else {
         	while( left <= right && stricmp( pivot, student[left].name.first_name ) > 0)
             left++;
	        while(right >= left && stricmp( pivot , student[right].name.first_name ) < 0)
	             right--;
	    }
        if (left >= right) break;
        swap( student[left] , student[right] );
        left++;
        right--;
    }
    swap( student[left] , student[high] );
    return left;
}
void quickSort_first_name_step1( SV student[] , int low , int high )
{   
    if (low < high)
    {  
        int pi = partition( student, low, high,0);
        quickSort_first_name_step1( student , low , pi-1 );
        quickSort_first_name_step1( student , pi+1 , high );
    }
}
void quickSort_last_name_step2(SV student[],int low,int high){
    if(low<high){
        int pi=partition(student,low,high,1);
        quickSort_last_name_step2(student,low,pi-1);
        quickSort_last_name_step2(student,pi+1,high);
    }
}
void quickSort_last_name_step1(SV student[]){
    int bien_trung_gian=0;
    char firstname[10];
    strcpy(firstname,student[0].name.first_name);
    for(int i = 1 ; i < total_number_of_students ; i++){
        if( stricmp(firstname,student[i].name.first_name) != 0 || i == total_number_of_students-1 )
        {
            quickSort_last_name_step2(student,bien_trung_gian,i-1);
            bien_trung_gian = i;  
            strcpy(firstname,student[i].name.first_name);
        }


    }
}
void provide_student_code(SV student[]){
	int key=1022000;
    for(int i=0;i<total_number_of_students;i++){
          itoa(key,student[i].student_code,10);
          key++;
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
		     strcpy( name , student[i].name.last_name );
		     strcat( name , b );
		     strcat( name ,student[i].name.first_name );
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


