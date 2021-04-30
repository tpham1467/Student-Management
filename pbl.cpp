#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
int m=0;
struct ho_va_ten{
    char ho_lot[10];
    char ten[10];

};
struct Sinh_Vien{     // dùng mang song song du luu thông tin sinh viên
    ho_va_ten hovaten;
    char gioi_tinh[5];
    char ngay_sinh[11];
    char dia_chi[50];
    char ma_sinh_vien[10];
    char email[23];
};
typedef  Sinh_Vien SV; 
void them_sinh_vien_buoc1(SV a[],int so_sinh_vien_can_them);
void them_sinh_vien_buoc2(SV &sv);
void quickSort_ho_lot(SV a[],int low, int high);
int tim_vi_tri_phan_tu_chot_ho_lot(SV a[],int low,int high);
void sap_xep_theo_ho_lot(SV a[]);
void quickSort_ten(SV a[], int low, int high);
void swap(SV &a,SV &b);
int tim_vi_tri_phan_tu_chot_ten(SV a[], int low, int high);
void xoa_sinh_vien(SV a[]);
void tim_sinh_vien(SV a[]);
void cap_ma_sinh_vien(SV a[]);
void cap_email(SV a[]);
void in_danh_sach_buoc1(SV a[]);
void in_danh_sach_buoc2(SV sv);
bool kiem_tra_Du_Lieu(char can_xoa[]);
void xuat_ra_file(SV a[]);

int main(){
	bool da_nhap=false;
	bool kiem_tra_sap_xep=false;
	bool kiem_tra_cap_ma_sinh_vien=false;
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
            int so_sinh_vien_can_them;
            scanf("%d",&so_sinh_vien_can_them);
            printf("\n");
            them_sinh_vien_buoc1(a,so_sinh_vien_can_them);
            da_nhap=true;
            printf("\n\nBan Da Nhap Xong Thong Tin!");
			break;
		}
    	case 2: {		
            if(da_nhap==true){
            	printf("Ban Da Chon Sap Xep Danh Sach Sinh Vien\n");
                    kiem_tra_sap_xep=true;
                    quickSort_ten(a,0,m-1);
                sap_xep_theo_ho_lot(a);
                    printf("\n\nBan Da Sap Xep!");
                    getch();
                    break;
        }
        
            else {
                    printf("Ban Chua Nhap Thong Tin Cua Hoc Sinh Nao\n");
                    getch();
                    break;
        }
      
		break;    }
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
    		in_danh_sach_buoc1(a);
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
void them_sinh_vien_buoc2(SV &sv){
	printf("Hay Nhap Ho Lot Cua Sinh Vien:"); fflush(stdin);
    gets(sv.hovaten.ho_lot);
    printf("\nHay Nhap Ten Cua Sinh Vien:");
    gets(sv.hovaten.ten);
    printf("\nHay Nhap Gioi Tinh Cua Sinh Vien:"); gets(sv.gioi_tinh);
    printf("\nHay Nhap Ngay Sinh Cua Sinh Vien:"); gets(sv.ngay_sinh);
    printf("\nHay Nhap Dia Chi Cua Sinh Vien:");   gets(sv.dia_chi);
    printf("\n\n\n");
}
void them_sinh_vien_buoc1(SV a[],int so_sinh_vien_can_them){
    for(int i=0;i<so_sinh_vien_can_them;i++){
        printf("Ban Hay Nhap Thong Tin Cua Sinh Vien: %d\n",m);
        them_sinh_vien_buoc2(a[m]);
        m++;

    }
}
void in_danh_sach_buoc1(SV a[]){
    printf(" ____________________________________________________________________________________________________________________\n");
    printf("| STT |       Ho Va Ten       | Gioi Tinh | Ngay Sinh |      Dia Chi     | Ma Sinh Vien |            Email           |\n");
    for(int i=0;i<m;i++){
      printf("| %3d |",i);
      in_danh_sach_buoc2(a[i]);
    }
    printf(" --------------------------------------------------------------------------------------------------------------------");
}
void in_danh_sach_buoc2(SV sv){
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
    char can_xoa[50];
    printf("Hay Nhap Ma Sinh Vien Hoac Ho Va Ten Cua Sinh Vien Can Xoa: ");
    fflush(stdin);
    gets(can_xoa);
    int i=0;
    char hovaten[20];
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
    }else {
        while(i<m&&strcmpi(a[i].ma_sinh_vien,can_xoa)!=0) i++;
    }
    if(i==m){
        printf("\nKhong Co Sinh Vien Nay Trong Lop");

    }
    else {
        printf("Ho Va Ten Cua Sinh vien la: %s %s",a[i].hovaten.ho_lot,a[i].hovaten.ten);
        printf("\nGioi Tinh Cua Sinh Vien La: %s",a[i].gioi_tinh);
        printf("\nNgay Sinh Cua Sinh Vien La: %s",a[i].ngay_sinh);
        printf("\nDia Chi Cua Sinh Vien La: %s",a[i].dia_chi);
        printf("\nEmail: %s",a[i].email);
        printf("Day co Phai Sinh Vien Ban Can Xoa Hay Khong ? C/K:");
        char key;
        scanf("%c",&key);
        if(key=='c'||key=='C'){
           for(int j=i+1;j<m;j++) a[j-1]=a[j];
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
    }else {
        while(i<m&&strcmpi(a[i].ma_sinh_vien,can_xoa)!=0) i++;
    }
    if(i==m){
        printf("\nKhong Co Sinh Vien Nay Trong Lop");

    }
    else {
        printf("Ho Va Ten Cua Sinh vien la: %s %s",a[i].hovaten.ho_lot,a[i].hovaten.ten);
        printf("\nGioi Tinh Cua Sinh Vien La: %s",a[i].gioi_tinh);
        printf("\nNgay Sinh Cua Sinh Vien La: %s",a[i].ngay_sinh);
        printf("\nDia Chi Cua Sinh Vien La: %s",a[i].dia_chi);
        printf("\nEmail: %s",a[i].email);
        }
        
         }

void swap(SV &a,SV &b){
    
    SV c = a;
    a = b;
    b = c;
}
int tim_vi_tri_phan_tu_chot_ten(SV a[], int low, int high)
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
void quickSort_ten(SV a[], int low, int high)
{
    if (low < high)
    {
        int pi = tim_vi_tri_phan_tu_chot_ten(a, low, high);
        quickSort_ten(a, low, pi - 1);
        quickSort_ten(a, pi + 1, high);
    }
}
void quickSort_ho_lot(SV a[],int low,int high){
    if(low<high){
        int pi=tim_vi_tri_phan_tu_chot_ho_lot(a,low,high);
        quickSort_ho_lot(a, low,pi-1);
        quickSort_ho_lot(a,pi+1,high);
    }
}
int tim_vi_tri_phan_tu_chot_ho_lot(SV a[], int low, int high)
{
    
    char pivot =a[high].hovaten.ho_lot[0];     // pivot
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
void sap_xep_theo_ho_lot(SV a[]){
    int bien_trung_gian=0;
    char b=a[0].hovaten.ten[0];
    for(int i=1;i<m;i++){
        if(b!=a[i].hovaten.ten[0])
        {
            quickSort_ho_lot(a,bien_trung_gian,i-1);
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
    p=fopen("E:\\lop.txt","r");
    int n;
    char r='0';
    fscanf(p,"%d",&n);
    filename[7]=r+n+1;
    fclose(p);
    p=fopen("E:\\lop.txt","w");
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


