#include <graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include<time.h>
#include <iostream>
using namespace std;
#include<windows.h>
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
    char last_name[8];

};
struct student{    
    first_and_last_name name;
    char gender[4];
    char Date_of_birth[11];
    char address[50];
    char student_code[8];
    char email[15];
};
typedef  student SV; 
void init();
int mainloop(SV student[]);
void add_students_step1( SV student[], int students_need_add ); 
void add_students_step2( SV &sv ); 
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
	delay(3000); 
	cleardevice();
	

}
int mainloop(SV student[]){
	int x = 0;
	char *s = new char[5];
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
		setcolor (15);
		settextstyle(2,0,7);
		line(400,50,850,50);
		line(850,50,850,500);
		line(400,500,850,500);
		line(400,50,400,500);
		line(396,46,854,46);
		line(854,46,854,504);
		line(396,504,854,504);
		line(396,46,396,504);
		line(400,80,850,80);
		outtextxy(430,52,"Moi Chon Yeu Cau:");
		outtextxy(410,82,"1: Nhap Sinh Vien");
		outtextxy(410,112,"2: Doc Danh sach Sinh Vien Tu File");
		outtextxy(410,142,"3: Sap Xep Sinh Vien|");
		outtextxy(410,172,"4: Xoa Sinh Vien Theo Ten Hoac Ma Sinh Vien");
		outtextxy(410,202,"5: Tim Sinh Vien Theo Ten Hoac Ma Sinh Vien");
		outtextxy(410,232,"6: Cap Ma So Sinh Vien");
		outtextxy(410,262,"7: Cap Email");
		outtextxy(410,292,"8: In Danh Sach");
		outtextxy(410,322,"0: Thoat Chuong Trinh");
		outtextxy(450,520,"Vui Long Nhap Yeu Cau...");
    int key; // request code  
    //scanf("%d",&key);
    printf("\n");
    switch(key){
    	case 1: {
    		printf("\n\n                           Ban Da Chon Nhap Sinh Vien\n");
            printf("                           Nhap So Sinh Vien Can Them:");
            int students_need_add;
            scanf("%d",&students_need_add);
            while( students_need_add <= 0 ){
                printf("                           Vui Long Nhap Lai:");
                scanf("%d",&students_need_add);
            }
            system("cls");
            
            add_students_step1( student , students_need_add );
            system("color 0");
            printf("\n\n                                Ban Da Nhap Xong Thong Tin!");
            getch();
            check_innit = true;
            check_sort = false;
            check_provide_student_code=false;
			break;
		}
        case 2: {
        	check_innit=true;
            Read_in_file(student);
            check_sort = false;
            check_provide_student_code=false;
            getch();
            break;
        }
    	case 3: {		
            if( check_innit ){
            	    system("cls");
            	    printf("\n\n                                Ban Da Chon Sap Xep Danh Sach Sinh Vien\n");
                    check_sort = true;
                    quickSort_last_name_step1( student , 0 , total_number_of_students-1 );
               
			        quickSort_first_name_step1( student );
                    printf("\n\n\n                                Ban Da Sap Xep!");
                    getch();
                    break;
            }
        
            else {
            	    system("cls");
            	    system("color 06");
                    printf("\n\n                                Ban Chua Nhap Thong Tin Cua Hoc Sinh Nao\n");
                    getch();
                    break;
            }
      
	    }
    	case 4: {
            
            if( check_innit ){
            	    system("cls");
            	    system("color 06");
            	    printf("\n\n                                Ban Da Chon Xoa Sinh Vien\n");
                    delete_student( student );
                    getch();
                    break;
            }
            else {  
			        system("cls");
            	    system("color 06");
                    printf("\n\n                                Ban Chua Nhap Thong Tin Cua Hoc Sinh Nao\n");
                    getch();
                    break;

            }
        }
    	case 5: {
            if( check_innit ){
            	system("cls");
            	system("color 06");
            	printf("Ban Da Chon tim Sinh Vien\n");
                find_student(student);
                getch();
                break;
            }
            else {
            	    system("cls");
            	    system("color 06");
                     printf("\n\n                                Ban Chua Nhap Thong Tin Cua Hoc Sinh Nao\n");
                     getch();
                     break;

            }
        }
    	case 6: {
            if( check_sort ){
            	system("cls");
            	system("color 06");
                provide_student_code( student );
                printf("\n\n                                Ban Da Duoc Cap MA Sinh Vien");
                 check_provide_student_code = true;
                 getch();
			     break;
            }
            else {
            	system("cls");
            	system("color 06");
                printf("\n\n                                Ban Chua Sap Xep\n");
                getch();
                break;

            }
		}
    	case 7: {
            if( check_provide_student_code ){
            	system("cls");
            	system("color 06");
                printf("\n\n                                Ban Da Chon Cap Email\n\n\n");
                provide_email( student );
                printf("\n\n                                Da Cap Email!");
                getch();
			    break;
            }
            else {
            	system("cls");
            	system("color 06");
                printf("\n\n                                Ban Chua Cap Ma Sinh Vien");
                getch();
                break;

            }
		}
    	case 8: {
    		print_list_step1( student );
    		getch();
			break;
		}
    	case 0: {
        output_file( student );    
        printf("\n\n                                Hen Gap Lai !!!!");
        getch();
        return 0;

        }
        default: printf("Vui Long Nhap Lai Yeu Cau!\n");
        getch();
        
    }
    }
	
}
void add_students_step2( SV &sv){
	printf("Hay Nhap Ho Lot Cua Sinh Vien:"); fflush(stdin);
    gets(sv.name.first_name);
    printf("\nHay Nhap Ten Cua Sinh Vien:");
    gets(sv.name.last_name);
    printf("\nHay Nhap Gioi Tinh Cua Sinh Vien:"); gets(sv.gender);
    printf("\nHay Nhap Ngay Sinh Cua Sinh Vien:"); gets(sv.Date_of_birth);
    puts(sv.gender);
    printf("\nHay Nhap Dia Chi Cua Sinh Vien:");   gets(sv.address);
    printf("\n\n\n");
  
}
void add_students_step1( SV a[] , int students_need_add ){
    for(int i=0;i<students_need_add;i++){
        printf("Ban Hay Nhap Thong Tin Cua Sinh Vien: %d\n",total_number_of_students);
        add_students_step2(a[total_number_of_students]);
        total_number_of_students++;
        system("cls");

    }

}
void Filter_the_data_name(SV &sv,char name[]){
    int key1=0,key2=0;
    for(int i=strlen(name)-1;i>=0;i--){
        if(name[i]!=' '&&key1==0){
            key1=i;
        
        }
        if(name[i]==' '&&key2==0){
            key2=i;
        }
    }
    int j=0;
    strncpy(sv.name.first_name,name,key2+1);
    for(int i=key2+1;i<=key1;i++){
        sv.name.first_name[j]=name[i];
        j++;
    }


}
void Filter_the_data_address(SV &sv,char address[]){
    int key;
    for(int i=strlen(address)-1;i>=0;i--){
       if(address[i]!=' '){
        key=i;
        break;
       }
    }
    strncpy(sv.address,address,key+1);

}
void Read_information(SV &sv){
    char name[35];
    char address[50];
    fgets(name,34,p);
    puts(name);
    printf("%d",strlen(name));
    fgets(sv.gender,4,p);
    puts(sv.gender);
    printf("%d",strlen(sv.gender));
    fgets(sv.Date_of_birth,11,p);
    puts(sv.Date_of_birth);
    printf("%d",strlen(sv.Date_of_birth));
    fgets(address,50,p);
    //Filter_the_data_name(sv,name);
    //Filter_the_data_address(sv,address);
    getch();
}
void Read_in_file(SV student[]){
    p=fopen("input.txt","r");
    if(p==NULL) {
	       printf("\nFile Khoong Ton Tai!!!\n");
	   }
    else {
        printf("\nDang Doc File!!!\n");
        int n; // total_number_of_students_need_add
        fscanf(p,"%d\n",&n);
        for(int i=0; i<n; i++){
            Read_information(student[total_number_of_students]);
            fscanf(p,"\n");
            total_number_of_students++; 
        }
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
	
        printf("Day co Phai Sinh Vien Ban Can Xoa Hay Khong ? C/K:");
        char key; // request code
        scanf("%c",&key);
        if(key == 'c'||key == 'C'){
           for(int j = location_to_delete+1 ; j < total_number_of_students ; j++ ) student[j-1] = student[j];
           total_number_of_students--;
        }
        
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
    char data[50];
    printf("Hay Nhap Ma Sinh Vien Hoac Ho Va Ten Cua Sinh Vien Can tim: ");
    fflush(stdin);
    gets(data);
    if( check_sort ){
        check_find  = Binary_Search(student,data);


    }
    else {
        check_find = Linear_Search(student,data);
    }

    if(check_find == false){
         printf("\nKhong Co Sinh Vien Nay Trong Lop");
                

    }
    else {
         printf("Ho Va Ten Cua Sinh vien la: %s %s", student[location_to_delete].name.first_name , student[location_to_delete].name.last_name );
         printf("\nGioi Tinh Cua Sinh Vien La: %s", student[location_to_delete].gender );
         printf("\nNgay Sinh Cua Sinh Vien La: %s", student[location_to_delete].Date_of_birth );
         printf("\nDia Chi Cua Sinh Vien La: %s", student[location_to_delete].address );
         printf("\nEmail: %s\n", student[location_to_delete].email );
   
    }
        
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


