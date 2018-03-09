#include <stdio.h>
#include <conio.h>

typedef struct {
   unsigned int x; 	//BMP dosya özellikleri için//for bmp file properties
   unsigned int y;
} bilgi;
int main()
{
	int i;
	unsigned char cloud;
	int atlama=0;
	int syc1=0;
	int sos=0;
	int sos1=0;
	int f=0;
	char input[100];
	bilgi info;
	unsigned char color[2];
	int kirm=0;
	int yesil=0;
	int mavi=0;
	
	


	printf("dosya ismi:");
	scanf("%s",input);
	FILE *resim=fopen(input,"rb+");
	FILE *hist=fopen("HÝST.txt","w");
	

	while(resim==NULL)
	{
		printf("dosya bulunamadý");
		scanf("%s",input);
		resim=fopen(input,"rb+");
	}
	fseek(resim,18,SEEK_SET);//BMP DOSYASININ ÝLK 50 BYTE'NDAN RESÝM GENÝÞLÝK VE //Getting picture Width and length information from the first 50 bytes of BMP file
	fread(&info.x,4,1,resim);//YÜKSEKLÝK BÝLGÝLERÝ ALINIYOR
	fseek(resim,22,SEEK_SET);
	fread(&info.y,4,1,resim);
	printf("Genislik=%d\tyukseklik=%d\n",info.x,info.y);
	
		int a=54;
		int d=0;
		int z=0;
		int y=0;
		int m=0;
		int re=0;

	
	sos=(info.x*3);
	
	sos1=sos%4;    //BURADA RESÝMDEKÝ BÝR SATIRIN 4'ÜN KATI OLUP OLMADIÐINA BAKILIYOR//controlling image line lengths. (! line lenght = 4*x !)    

	atlama=4-sos1;//BÝR SATIRDAKÝ BOÞ BYTE LARI BULMAK VE BU BYTELARI ATLAMAK ÝÇÝN // this code find empty byte and The program skip empty byte
	
	system("pause");
	for(i=0;i<info.x*info.y*3;i++){
		fseek(resim,a,SEEK_SET);
		cloud= getc(resim);
		color[d]=cloud;
		a++;
		d++;
		y++;
		
		
		if(d==3){
			if(re==info.x){
			re=0;}
			
		if(sos1==0){
			printf("P(%3d-%3d)= %d %d %d\n",f+1,syc1+1,color[2],color[1],color[0]);
			if(color[0]>150){
				mavi++;
			}
			if(color[1]>150){
				yesil ++;
				
			}
			if(color[2]>150){
				kirm ++;//printf("kirmizi=%d",kirm);
			}
			}
		if(sos1>0){
			
			printf("P(%3d-%3d)= %d %d %d\n",f+1,syc1+1,color[2],color[1],color[0]);
			if(color[0]>150){
				mavi++;
			}
			if(color[1]>150){
				yesil ++;
				
			}
			if(color[2]>150){
				kirm ++;
			}		
			if(y==sos){
				a=a+atlama;
				y=0;	
			}
			}
			z++;
			re++;
			d=0;
			syc1++;
			
		}
		if(syc1==info.x){
			f++;
			syc1=0;
		}
		
		}
		fprintf(hist,"PÝXELLERDE BASKIN OLAN RGB DEGERLERÝ\nKIRMIZI=%d\nYEÞÝL=%d\nMAVÝ=%d",kirm,yesil,mavi);
		printf("RGB renk kodlarinin baskinlilarina gore\nkirmizi=%d\nyesil=%d\nmavi=%d",kirm,yesil,mavi);
		
		
		
		fclose(resim);
		fclose(hist);
}
	

	
	
	
	
	
	
	
	
	
	



