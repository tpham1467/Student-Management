#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
/* check_find kiem tra xem co tim thay sinh vien Khong
neu thay tra ve true nguoc lai tra ve false*/
bool check_find=false;
/* bien chot dung de giu vi tri phan tu can xoa */
int chot;
/* bien m dung de luu tru so sinh vien cos trong lop */
int m=0;
/* da_nhap dung de kiem tra xem da nhap du lieu ban dau chua
neu chua tra ve false nguoc lai tra ve true */
bool da_nhap=false;
/* kiem_tra_sap_xep dung de kiem tra xem danh sach da duoc sap xep chua 
neu chua tra ve false nguoc lai tra ve true */
bool kiem_tra_sap_xep=false;
/* kiem_tra_cap_ma_sinh_vien dung de kiem tra xem da cap ma sinh vien chua 
neu chua tra ve false nguoc lai tra ve true */
bool kiem_tra_cap_ma_sinh_vien=false;
/* kieu struct de luu tru ho_lot va ten cua sinh vien*/
struct ho_va_ten{
    char ho_lot[10];
    char ten[10];

};
/*  dung kieu struct de luu tru thong tin cua sinh vien */
struct Sinh_Vien{    
    ho_va_ten hovaten;
    char gioi_tinh[5];
    char ngay_sinh[11];
    char dia_chi[50];
    char ma_sinh_vien[10];
    char email[23];
};
typedef  Sinh_Vien SV; 
void them_sinh_vien_step1(SV a[],int so_sinh_vien_can_them); // ham them sinh vien step 1
void them_sinh_vien_step2(SV &sv); // ham them sinh vien step 2
void quickSort_ho_lot_step2(SV a[],int low, int high);  // sap xep danh sach theo ho lot dung thuat toan quickSort step 2
int quickSort_ho_lot_step3(SV a[],int low,int high); //  sap xep danh sach theo ho lot dung thuat toan quickSort step 3
void quickSort_ho_lot_step1(SV a[]);//  sap xep danh sach theo ho lot dung thuat toan quickSort step 1
void quickSort_ten_step1(SV a[], int low, int high);//  sap xep danh sach theo ten dung thuat toan quickSort step 1
void swap(SV &a,SV &b); // ham dung hoan doi vi tri 2 sinh vien
int quickSort_ten_step2(SV a[], int low, int high); //  sap xep danh sach theo ho lot dung thuat toan quickSort step 2
void xoa_sinh_vien(SV a[]); // ham dung de xoa mot sinh vien theo ten hoac ma sinh vien
void tim_sinh_vien(SV a[]);// ham dung de tim mot sinh vien theo ten hoac ma sinh vien
void cap_ma_sinh_vien(SV a[]);// ham dung de cap ma cho sinh vien
void cap_email(SV a[]); // ham dung de email co sinh vien
void in_danh_sach_step1(SV a[]); // ham in danh sach step 1 
void in_danh_sach_step2(SV sv);// ham in danh sach step 2
bool kiem_tra_Du_Lieu(char can_xoa[]);  // ham kiem tra du lieu dau vao xem nhap ten sinh vien hay ma sinh vien
void xuat_ra_file(SV a[]);// ham xuat danh sach ra file khi ket thuc chuong trinh
// ham main
int main(){
	SV a[100];
    while(true){
    system("cls");    
    printf("*************************************************\n");
    printf("*               Moi Chon Yeu Cau:                *\n");
    printf("*    1: Nhap Sinh Vien                           *\n");
    printf("*    2: Sap Xep Sinh Vien                        *\n");
    printf("*    3: Xoa Sinh Vien Theo Ten Hoac Ma Sinh Vien *\n");
    printf("*    4: Tim Sinh Vien Theo Ten Hoac Ma Sinh Vien *\n");
    printf("*    5: Cap Ma So Sinh Vien                      *\n");
    printf("*    6: Cap Email                                *\n");
    printf("*    7: In Danh Sach                             *\n");
    printf("*    0: Thoat Chuong Trinh                       *\n");
    printf("*                                                *\n");
    printf("*                                                *\n");
    printf("*************************************************\n\n\n");
    printf("Vui Long Nhap Yeu Cau:");
    int key; // ma yeu cau
    scanf("%d",&key);
    printf("\n");
    switch(key){
    	case 1: {
    		printf("Ban Da Chon Nhap Sinh Vien\n");
            printf("Nhap So Sinh Vien Can Them:");
            // so_sinh_vien_can_them de nhap so sinh vien maf ban can them
            int so_sinh_vien_can_them;
            scanf("%d",&so_sinh_vien_can_them);
            printf("\n");
            them_sinh_vien_step1(a,so_sinh_vien_can_them);
            da_nhap=true;
            printf("\n\nBan Da Nhap Xong Thong Tin!");
			break;
		}
    	case 2: {		
            if(da_nhap==true){
            	    printf("Ban Da Chon Sap Xep Danh Sach Sinh Vien\n");
                    kiem_tra_sap_xep=true;
                    quickSort_ten_step1(a,0,m-1);
                    quickSort_ho_lot_step1(a);
                    printf("\n\nBan Da Sap Xep!");
                    getch();
                    break;
            }
        
            else {
                    printf("Ban Chua Nhap Thong Tin Cua Hoc Sinh Nao\n");
                    getch();
                    break;
            }
      
	    }
    	case 3: {
            
            if(da_nhap==true){
            	    printf("Ban Da Chon Xoa Sinh Vien\n");
                    xoa_sinh_vien(a);
                    getch();
                    break;
            }
            else {
                    printf("Ban Chua Nhap Thong Tin Cua Hoc Sinh Nao\n");
                    getch();
                    break;

            }
        }
    	case 4: {
            if(da_nhap==true){
            	printf("Ban Da Chon tim Sinh Vien\n");
                    tim_sinh_vien(a);
                    getch();
                    break;
            }
            else {
                     printf("Ban Chua Nhap Thong Tin Cua Hoc Sinh Nao\n");
                     getch();
                     break;

            }
        }
    	case 5: {
            if(kiem_tra_sap_xep){
                 cap_ma_sinh_vien(a);
                 printf("Ban Da Duoc Cap MA Sinh Vien");
                 kiem_tra_cap_ma_sinh_vien=true;
                 getch();
			     break;
            }
            else {
                printf("Ban Chua Cap Ma Sinh Vien\n");
                getch();
                break;

            }
		}
    	case 6: {
            if(kiem_tra_cap_ma_sinh_vien){
                printf("Ban Da Chon Cap Email\n\n\n");
                cap_email(a);
                printf("Da Cap Email!");
                getch();
			    break;
            }
            else {
                printf("Ban Chua Cap Ma Sinh Vien");
                getch();
                break;

            }
		}
    	case 7: {
    		in_danh_sach_step1(a);
    		getch();
			break;
		}
    	case 0: {
        xuat_ra_file(a);    
        printf("Hen Gap Lai !!!!");
        getch();
        return 0;

        }
        default: printf("Vui Long Nhap Lai Yeu Cau!\n");
        getch();
        
    }
    }
	
   
}
void them_sinh_vien_step2(SV &sv){
	printf("Hay Nhap Ho Lot Cua Sinh Vien:"); fflush(stdin);
    gets(sv.hovaten.ho_lot);
    printf("\nHay Nhap Ten Cua Sinh Vien:");
    gets(sv.hovaten.ten);
    printf("\nHay Nhap Gioi Tinh Cua Sinh Vien:"); gets(sv.gioi_tinh);
    printf("\nHay Nhap Ngay Sinh Cua Sinh Vien:"); gets(sv.ngay_sinh);
    printf("\nHay Nhap Dia Chi Cua Sinh Vien:");   gets(sv.dia_chi);
    printf("\n\n\n");
}
void them_sinh_vien_step1(SV a[],int so_sinh_vien_can_them){
    for(int i=0;i<so_sinh_vien_can_them;i++){
        printf("Ban Hay Nhap Thong Tin Cua Sinh Vien: %d\n",m);
        them_sinh_vien_step2(a[m]);
        m++;

    }
}
void in_danh_sach_step1(SV a[]){
    printf(" ____________________________________________________________________________________________________________________\n");
    printf("| STT |       Ho Va Ten       | Gioi Tinh | Ngay Sinh |      Dia Chi     | Ma Sinh Vien |            Email           |\n");
    for(int i=0;i<m;i++){
      printf("| %3d |",i);
      in_danh_sach_step2(a[i]);
    }
    printf(" --------------------------------------------------------------------------------------------------------------------");
}
void in_danh_sach_step2(SV sv){
    printf("%10s %-12s|",sv.hovaten.ho_lot,sv.hovaten.ten);
    printf(" %-10s|",sv.gioi_tinh);
    printf(" %-10s|",sv.ngay_sinh);
    printf(" %-17s|",sv.dia_chi);
    printf(" %-13s|",sv.ma_sinh_vien);
    printf(" %-27s|",sv.email);
    printf("\n");
}
bool kiem_tra_Du_Lieu(char can_xoa[]){
    if(can_xoa[0]>='0'&&can_xoa[0]<='9') return true;
    else return false;
}
void xoa_sinh_vien(SV a[]){
    tim_sinh_vien(a);
    if(check_find==true){
	
        printf("Day co Phai Sinh Vien Ban Can Xoa Hay Khong ? C/K:");
        char key;
        scanf("%c",&key);
        if(key=='c'||key=='C'){
           for(int j=chot+1;j<m;j++) a[j-1]=a[j];
           m--;
        }
        
    }
    
}    

void tim_sinh_vien(SV a[]){
    char can_xoa[50];
    printf("Hay Nhap Ma Sinh Vien Hoac Ho Va Ten Cua Sinh Vien Can tim: ");
    fflush(stdin);
    gets(can_xoa);
    int i=0;
    char hovaten[20];
    /* thuc hien viec ghep ten va ho lot de tim kiem*/
    char b[2]={' '};
	strcpy(hovaten, a[0].hovaten.ho_lot);
    strcat(hovaten,b);
    strcat(hovaten, a[0].hovaten.ten);
    if(kiem_tra_Du_Lieu(can_xoa)==false){ 
          while(i<m&&strcmpi(hovaten,can_xoa)!=0) {
                 i++;
                strcpy(hovaten, a[i].hovaten.ho_lot);
                strcat(hovaten,b);
                strcat(hovaten, a[i].hovaten.ten); 
             }
    }
    else {
        while(i<m&&strcmpi(a[i].ma_sinh_vien,can_xoa)!=0) i++;
    }
    if(i==m&&i!=0){
        printf("\nKhong Co Sinh Vien Nay Trong Lop");
        check_find=false;

    }
    else {
        printf("Ho Va Ten Cua Sinh vien la: %s %s",a[i].hovaten.ho_lot,a[i].hovaten.ten);
        printf("\nGioi Tinh Cua Sinh Vien La: %s",a[i].gioi_tinh);
        printf("\nNgay Sinh Cua Sinh Vien La: %s",a[i].ngay_sinh);
        printf("\nDia Chi Cua Sinh Vien La: %s",a[i].dia_chi);
        printf("\nEmail: %s\n",a[i].email);
        check_find=true;
        chot=i;
    }
        
}
      

void swap(SV &a,SV &b){
    SV c;    
    c = a;
    a = b;
    b = c;
}
int quickSort_ten_step2(SV a[], int low, int high)
{
    
    char pivot =a[high].hovaten.ten[0];     // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right&&pivot>a[left].hovaten.ten[0])
             left++;
        while(right >= left&&pivot<a[right].hovaten.ten[0])
             right--;
        if (left >= right) break;
        swap(a[left], a[right]);
        left++;
        right--;
    }
    swap(a[left], a[high]);
    return left;
}
void quickSort_ten_step1(SV a[], int low, int high)
{
    if (low < high)
    {   // bien pi luu tru vi tri phan tu chia mang ra 2 mang con
        int pi=quickSort_ten_step2(a, low, high);
        quickSort_ten_step1(a,low,pi-1);
        quickSort_ten_step1(a,pi+1,high);
    }
}
void quickSort_ho_lot_step2(SV a[],int low,int high){
    if(low<high){
        // bien pi luu tru vi tri phan tu chia mang ra 2 mang con
        int pi=quickSort_ho_lot_step3(a,low,high);
        quickSort_ho_lot_step2(a,low,pi-1);
        quickSort_ho_lot_step2(a,pi+1,high);
    }
}
int quickSort_ho_lot_step3(SV a[], int low, int high)
{
    // pivot con phan tu cuoi lam chot
    char pivot =a[high].hovaten.ho_lot[0];     
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right&&pivot>a[left].hovaten.ho_lot[0])
             left++;
        while(right >= left&&pivot<a[right].hovaten.ho_lot[0])
             right--;
        if (left >= right) break;
        swap(a[left], a[right]);
        left++;
        right--;
    }
    swap(a[left], a[high]);
    return left;
}
void quickSort_ho_lot_step1(SV a[]){
    int bien_trung_gian=0;
    char b=a[0].hovaten.ten[0];
    for(int i=1;i<m;i++){
        if(b!=a[i].hovaten.ten[0])
        {
            quickSort_ho_lot_step2(a,bien_trung_gian,i-1);
            bien_trung_gian=i;  
            b=a[i].hovaten.ten[0];
        }


    }
}
void cap_ma_sinh_vien(SV a[]){
    for(int i=0;i<m;i++){
        a[i].ma_sinh_vien[0]='1';
        a[i].ma_sinh_vien[1]='0';
        a[i].ma_sinh_vien[2]='0';
        a[i].ma_sinh_vien[3]='2';
        a[i].ma_sinh_vien[4]='2';
        char m='0';
        if(i<10){
            a[i].ma_sinh_vien[5]='0';
            a[i].ma_sinh_vien[6]='0';

            a[i].ma_sinh_vien[7]=m+i;
        }
        else if(i!=100&&i>=10) {
             a[i].ma_sinh_vien[5]=0;
             int z=i%10;
             a[i].ma_sinh_vien[6]=m+z;
             m=m-z;
             i=i/10;
             a[i].ma_sinh_vien[7]=m+i;

        }
        else {
            a[i].ma_sinh_vien[5]='1';
            a[i].ma_sinh_vien[6]='0';
            a[i].ma_sinh_vien[7]='0';
        }
    }

}
void cap_email(SV a[]){
    char b[11]="@gmail.com";
    for(int i=0;i<m;i++){

    
    strcpy(a[i].email,a[i].ma_sinh_vien);
    strcat(a[i].email, b);


    }
}
void xuat_ra_file(SV a[]){
    FILE *fp;
    char filename[13]="dssvlop .txt";
    FILE *p;
    p=fopen("E:\\github\\lop.txt","r");
    int n;
    char r='0';
    fscanf(p,"%d",&n);
    filename[7]=r+n+1;
    fclose(p);
    p=fopen("E:\\github\\lop.txt","w");
    fprintf(p,"%d",n+1);
    fclose(p);
    fp=fopen(filename,"w");
    fprintf(fp,"%-4s%d\n\n","LOP:",n+1); 
    fprintf(fp,"%-118s\n"," ____________________________________________________________________________________________________________________");
    fprintf(fp,"%-118s\n","| STT |       Ho Va Ten       | Gioi Tinh | Ngay Sinh |      Dia Chi     | Ma Sinh Vien |            Email           |");
    for(int i=0;i<m;i++){
    	     fprintf(fp,"%c",'|');
             fprintf(fp,"%2s%-3d","  ",i);
             fprintf(fp,"%c",'|');
             fprintf(fp,"%10s%c%-12s%c",a[i].hovaten.ho_lot,' ',a[i].hovaten.ten,'|');
             fprintf(fp,"%3s%-8s%c","   ",a[i].gioi_tinh,'|');
             fprintf(fp,"%3s%-8s%c","   ",a[i].ngay_sinh,'|');
             fprintf(fp,"%5s%-13s%c","     ",a[i].dia_chi,'|');
             fprintf(fp,"%3s%-11s%c","   ",a[i].ma_sinh_vien,'|');
             fprintf(fp,"%5s%-23s%c\n","     ",a[i].email,'|');
        }
    fprintf(fp,"%-118s"," --------------------------------------------------------------------------------------------------------------------");    
    fclose(fp);
}
/* Do An Quan Li Hoc Sinh */


