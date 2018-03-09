#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <locale.h>
main(){
	setlocale(LC_ALL,"Turkish"); 
	int secim;
	printf("\t\tLUTFEN SECIMINIZI YAPINIZ\n\t1-->Dosya kriptolama\n\t2-->Dosya kripto cozme\n");
	scanf("%d",&secim);
	if(secim==1){
	char dosyaismi[30],krip[30],anahtar[30];
    int kripto[100];
    int mtn[100];
    int a=0,i=0,size=0,tmp[100],sfr[100];
    printf("lutfen kriptolanmak istenen dosyanin tam ismini giriniz:\n");
    scanf("%s",dosyaismi);
    printf("lutfen olusturulacak kripto dosyasinin tam ismini giriniz:\n");
    scanf("%s",krip);
    printf("lutfen olusturulacak anahtar dosyasinin isminini giriniz:\n");
    scanf("%s",anahtar);
    FILE*metin=fopen(dosyaismi,"r");
	FILE*sifre=fopen(krip,"w+"); 
	FILE*sum=fopen(anahtar,"w+");
	while(!feof(metin)){
    fscanf(metin,"%c",&mtn[a]); 
    a++;
}
printf("%c  %d",mtn[0],a);
fclose(metin);

for(i=0;i<(a-1);i++){
   	 	tmp[i]=mtn[i]-mtn[i+1];
   	 	sfr[i]=mtn[i]+mtn[i+1];
   	 	fprintf(sum,"%c",sfr[i]);
   	 	fprintf(sifre,"%c",tmp[i]);
	} 
	 fclose(sifre);fclose(sum);
	 remove(dosyaismi);
	
}
if(secim==2){
	int a=0,b=0,size,i,coz;
	char anht[100],krp[100],dos[30],krr[30],anhtr[30];
	printf("lutfen cozumlenmek istenen dosyanin tam ismini giriniz:\n");
	scanf("%s",dos);
	printf("lutfen olusturulacak yeni dosyanin tam ismini giriniz:\n");
	scanf("%s",krr);
	printf("lutfen anahtar dosyasinin tam ismini giriniz:\n");
	scanf("%s",anhtr);
	FILE*cozum=fopen(krr,"w");
	FILE*sifre=fopen(dos,"r+"); 
	FILE*anahtar=fopen(anhtr,"r+");
	while(!feof(sifre)){
		fscanf(sifre,"%c",&krp[a]);
		a++;
	}
	
	while(!feof(anahtar)){
		fscanf(anahtar,"%c",&anht[b]);
		b++;
	}
	size=strlen(krp);
	printf("%d\n",a);
	
	for(i=0;i<a-1;i++)
	{
		coz=(anht[i]+krp[i]+256)/2;
		printf("%d",coz);
		fprintf(cozum,"%c",coz);
	}
	fclose(cozum);
	fclose(sifre);
	fclose(anahtar);
	remove(dos);
	remove(anhtr);

	
}
}






