#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
typedef struct ktbhn{
    long* ISBN;
	char* ktp_adi;
	int* basim_yili,cilt_no;
	char* yazar_adi;
	char* yazar_soyadi;
}abc,def;
typedef struct ID{
	 char* isim;
	 char* soyisim;
  	 long* TC;
   	 char* kk;
      }asd;
int main(){
asd dsa;
abc oku;
char ara[100];
long int iara[8];
char secim;
			oku.basim_yili=(int*)malloc(sizeof(int)*4);
			oku.cilt_no=sizeof(2);
			oku.ktp_adi=(char*)malloc(sizeof(char)*100);
	    	oku.yazar_adi=(char*)malloc(sizeof(char)*100);
	    	oku.yazar_soyadi=(char*)malloc(sizeof(char)*100);
	    	dsa.isim=(char*)malloc(sizeof(char)*100);
	    	dsa.soyisim=(char*)malloc(sizeof(char)*100);
	    	dsa.TC=(long int*)malloc(sizeof(long int)*12);
	    	oku.ISBN=(long int*)malloc(sizeof(long int)*12);
while(1){
	printf("\t\t***YAPMAK ISTEDIGINIZ ISLEMI SECINIZ***\n");
	printf("1-->KITAP EKLEME\n2-->KITAP ARAMA\n3-->KITAP ODUNC ALMA\n4-->KITAP IADESI\n5-->KITAP LISTESI\n6-->CIKIS\n");
	secim=getch();
	if(secim=='1'){
		abc oku;
		oku.ktp_adi=(char*)malloc(sizeof(char)*100);
		printf("---------------lutfen kitap adini giriniz-----------------\n");
		gets(oku.ktp_adi);
		oku.yazar_adi=(char*)malloc(sizeof(char)*100);
		printf("----------lutfen kitabin yazarinin adini giriniz----------\n");
		gets(oku.yazar_adi);
		oku.yazar_soyadi=(char*)malloc(sizeof(char)*100);
		printf("--------lutfen kitabin yazarinin soyismini giriniz---------\n");
		gets(oku.yazar_soyadi);
		oku.ISBN=(long int*)malloc(sizeof(long int)*12);
		printf("lutfen kitabin ISBN no'sunu giriniz:\n");
		scanf("%lu",&oku.ISBN);
		printf("lutfen kitabin cilt no'sunu giriniz:\n");
		oku.cilt_no=sizeof(2);
		scanf("%d",&oku.cilt_no);
		printf("lutfen kitap basým yilini giriniz:\n");
		oku.basim_yili=(int*)malloc(sizeof(int)*12);	
		scanf("%d",&oku.basim_yili);
		FILE*kutuphane=fopen("kütüphane.dat","a");
		fprintf(kutuphane,"%s %s %s %d %d %d\n",oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,oku.ISBN,oku.cilt_no,oku.basim_yili);
		fclose(kutuphane);
	}
	if(secim=='2'){
		char x;
		printf("lutfen kitabi arama seklini seciniz:\n");
		printf("1.kitap ismi ile\n2.kitap ISBN no'su ile\n3.yazar ismi ile\n4.yazar soyismi ile\n");
		x=getch();
		if(x=='1'){
		    char* sorgu;
		    sorgu=(char*)malloc(sizeof(char)*50);
		  	printf("aranan kitabin ismini giriniz:\n");
	    	gets(ara);
	    	FILE*kutuphane=fopen("kütüphane.dat","r");
	    	while(!feof(kutuphane)){
			fscanf(kutuphane,"%s %s %s %ld %d %d\n",oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,&oku.ISBN,&oku.cilt_no,&oku.basim_yili);
			if(strcmp(oku.ktp_adi,ara)==0){
				printf("\tKITAP ISMI=%s \n\tYAZAR ISMI=%s  \n\tYAZAR SOYADI=%s  \n\tISBN=%lu   \n\tCILT NO=%d	\n\tBASIM YILI=%d\n\n",oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,oku.ISBN,oku.cilt_no,oku.basim_yili);
		
				strcpy(sorgu,oku.ktp_adi);
			}
		}
			if(strcmp(sorgu,ara)!=0){
				printf("\t\t\tARADIGINIZ KITAP BULUNAMADI!!!!!\n\n");
			}
		fclose(kutuphane);
				
		}
		if(x=='2'){
		    long int* iara;
		    long int* sorgu;
		    sorgu=(long int*)malloc(sizeof(long int)*12);
		    iara=(long int*)malloc(sizeof(long int)*12);
			printf("aranan kitabin ISBN no'sunu giriniz:\n");
			scanf("%d",&iara);
			FILE*kutuphane=fopen("kütüphane.dat","r");
	    	while(!feof(kutuphane)){
			fscanf(kutuphane,"%s %s %s %d %d %d\n",oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,&oku.ISBN,&oku.cilt_no,&oku.basim_yili);
			if(iara==oku.ISBN){
			printf("\tKITAP ISMI=%s \n\tYAZAR ISMI=%s  \n\tYAZAR SOYADI=%s  \n\tISBN=%lu   \n\tCILT NO=%d	\n\tBASIM YILI=%d\n\n",oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,oku.ISBN,oku.cilt_no,oku.basim_yili);
			sorgu=oku.ISBN;
			}
			}
			if(sorgu!=iara){
				printf("\t\t\tARADIGINIZ KITAP BULUNAMADI!!!!!\n\n");
			}
			fclose(kutuphane);
		}
		if(x=='3'){
			char* sorgu;
		    sorgu=(char*)malloc(sizeof(char)*50);
			printf("aranan kitabin yazarinin ismini giriniz:\n");
	    	gets(ara);
	    	FILE*kutuphane=fopen("kütüphane.dat","r");
	    	while(!feof(kutuphane)){
			fscanf(kutuphane,"%s %s %s %d %d %d\n",oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,&oku.ISBN,&oku.cilt_no,&oku.basim_yili);
			if(strcmp(oku.yazar_adi,ara)==0){
			printf("\tKITAP ISMI=%s \n\tYAZAR ISMI=%s  \n\tYAZAR SOYADI=%s  \n\tISBN=%lu   \n\tCILT NO=%d	\n\tBASIM YILI=%d\n\n",oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,oku.ISBN,oku.cilt_no,oku.basim_yili);			
			strcpy(sorgu,oku.yazar_adi);
		}
	
		}
		
			if(strcmp(sorgu,ara)!=0){
				printf("\t\t\tARADIGINIZ KITAP BULUNAMADI!!!!!\n\n");
			}
		
		fclose(kutuphane);
		    
			}
			if(x=='4'){
			char* sorgu;
		    sorgu=(char*)malloc(sizeof(char)*50);
			printf("aranan kitabin yazarinin soyismini giriniz:\n");
	    	scanf("%s",ara);
	    	FILE*kutuphane=fopen("kütüphane.dat","r");
	    while(!feof(kutuphane)){
			fscanf(kutuphane,"%s %s %s %ld %d %d\n",oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,&oku.ISBN,&oku.cilt_no,&oku.basim_yili);
			if(strcmp(oku.yazar_soyadi,ara)==0){
				printf("\tKITAP ISMI=%s \n\tYAZAR ISMI=%s  \n\tYAZAR SOYADI=%s  \n\tISBN=%lu   \n\tCILT NO=%d	\n\tBASIM YILI=%d\n\n",oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,oku.ISBN,oku.cilt_no,oku.basim_yili);
				strcpy(sorgu,oku.yazar_soyadi);
			}
		}
			if(strcmp(sorgu,ara)!=0){
				printf("\t\t\tARADIGINIZ KITAP BULUNAMADI!!!!!\n\n");
			}
		fclose(kutuphane);
				
			}
	}
			if(secim=='3'){
			long *iara;
			iara=(long int*)malloc(sizeof(long int)*12);
		  	printf("aranan kitabin ISBN giriniz:\n");
	    	scanf("%d",&iara);
	    	FILE*kutuphane=fopen("kütüphane.dat","r+");
	    	FILE*yeni=fopen("yenik.dat","w");
	    	abc oku;
	    	asd dsa;
	    	oku.ktp_adi=(char*)malloc(sizeof(char)*100);
	    	oku.yazar_adi=(char*)malloc(sizeof(char)*100);
	    	oku.yazar_soyadi=(char*)malloc(sizeof(char)*100);
			oku.ISBN=(long int*)malloc(sizeof(long int)*12);
		    	while(!feof(kutuphane)){
			fscanf(kutuphane,"%s %s %s %d %d %d\n",oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,&oku.ISBN,&oku.cilt_no,&oku.basim_yili);
		if(iara==oku.ISBN){
			printf("\tKITAP ISMI=%s \n\tYAZAR ISMI=%s  \n\tYAZAR SOYADI=%s  \n\tISBN=%lu   \n\tCILT NO=%d	\n\tBASIM YILI=%d\n\n",oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,oku.ISBN,oku.cilt_no,oku.basim_yili);asd dsa;
			printf("\nlutfen isminizi ve soyisminizi giriniz\n");
			dsa.isim=(char*)malloc(sizeof(char)*100);
			gets(dsa.isim);
			dsa.soyisim=(char*)malloc(sizeof(char)*100);
			gets(dsa.soyisim);
			printf("lutfen okul numaranizi giriniz\n");
			dsa.TC=(long int*)malloc(sizeof(long int)*12);		
			scanf("%ld",&dsa.TC);
			FILE*kayit=fopen("ID.dat","a+");
			fprintf(kayit,"%s %s %ld    %s  %s  %s  %d  %d  %d\n",dsa.isim,dsa.soyisim,dsa.TC,oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,oku.ISBN,oku.cilt_no,oku.basim_yili);
		    fclose(kayit);	
		}
		if(iara!=oku.ISBN){
        	fprintf(yeni,"%s %s %s %d %d %d\n",oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,oku.ISBN,oku.cilt_no,oku.basim_yili);
		}
	
	}
	fclose(kutuphane);
		fclose(yeni);
	remove("kütüphane.dat");
rename("yenik.dat","kütüphane.dat");
	
}
if(secim=='4'){
	long int*iara;
	iara=(long int*)malloc(sizeof(long int)*12);
	printf("aranan kitabin ISBN giriniz:\n");
	scanf("%dl",&iara);
	FILE*kayit=fopen("ID.dat","r+");
	FILE*yeni=fopen("yeni.dat","w");
	FILE*kutuphane=fopen("kütüphane.dat","a+");
	abc oku;
	asd dsa;
			oku.basim_yili=(int*)malloc(sizeof(int)*12);
			oku.cilt_no=sizeof(2);
			oku.ktp_adi=(char*)malloc(sizeof(char)*100);
	    	oku.yazar_adi=(char*)malloc(sizeof(char)*100);
	    	oku.yazar_soyadi=(char*)malloc(sizeof(char)*100);
	    	dsa.isim=(char*)malloc(sizeof(char)*100);
	    	dsa.soyisim=(char*)malloc(sizeof(char)*100);
	    	dsa.TC=(long int*)malloc(sizeof(long int)*12);
	    	oku.ISBN=(long int*)malloc(sizeof(long int)*12);	

	while(!feof(kayit)){	
		fscanf(kayit,"%s %s %ld %s %s %s %ld %d %d",dsa.isim,dsa.soyisim,&dsa.TC,oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,&oku.ISBN,&oku.cilt_no,&oku.basim_yili);
		if(iara==oku.ISBN){
			printf("KULLANICI KIMLIGI=%s %s\nOKUL NO=%d\nALINAN KITAP\n\tKITAP ISMI=%s \n\tYAZAR ISMI=%s  \n\tYAZAR SOYADI=%s  \n\tISBN=%lu   \n\tCILT NO=%d	\n\tBASIM YILI=%d\n\n",dsa.isim,dsa.soyisim,dsa.TC,oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,oku.ISBN,oku.cilt_no,oku.basim_yili);
			fprintf(kutuphane,"%s %s %s %d %d %d\n",oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,oku.ISBN,oku.cilt_no,oku.basim_yili);
		fclose(kutuphane);
		break;
		}
		if(iara!=oku.ISBN){
			fprintf(yeni,"%s %s %ld  %s  %s  %s  %d  %d  %d\n",dsa.isim,dsa.soyisim,dsa.TC,oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,oku.ISBN,oku.cilt_no,oku.basim_yili);
		}
	}
	fclose(yeni);
	fclose(kayit);
	remove("ID.dat");
	rename("yeni.dat","ID.dat");	
}
if(secim=='5'){
	FILE*kutuphane=fopen("kütüphane.dat","r");
	printf("\tKitap Adi\t\t  Yazar Bilgisi\t\t\tISBN\t\t     Cilt no\t\tBasim YILI\n");
	printf("\t_________________________________________________________________________________________________________\n");
	while(!feof(kutuphane)){
	    fscanf(kutuphane,"%s %s %s %d %d %d\n",oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,&oku.ISBN,&oku.cilt_no,&oku.basim_yili);
		printf("\t%15s\t%15s %15s\t\t%ld\t\t%d\t\t%d\n",oku.ktp_adi,oku.yazar_adi,oku.yazar_soyadi,oku.ISBN,oku.cilt_no,oku.basim_yili);
		printf("\t__________________________________________________________________________________________________________\n");
		
}
fclose(kutuphane);
}
if(secim=='6')
break;
}
}