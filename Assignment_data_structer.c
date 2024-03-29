#include<stdio.h>
struct Product{
	int id,qty;
	char productName[20];
	float price,discount,total,payment;
};
void headedr(){
	printf("\n%12s%14s%13s%15s%15s%18s%17s","ID","Name","QTY","Price","Total","Discount","Payment");
}
void Input(){
	
}
int main(){
	struct Product pro[20];
	int n,i,op;
	do{
		printf("\n--------------->>> M E N U <<<---------------\n");
		printf(" 1. Input\n");
		printf(" 2. Output\n"),
		printf(" 3. Search\n");
		printf(" 4. Edit\n");
		printf(" 5. Delete\n");
		printf(" 6. Insert\n");
		printf(" 7. Sort\n");
		printf(" 8. Add\n");
		printf(" 9. Exit");
		printf(" Please choose option =");scanf("%d",&op);
		switch(op){
			case 1:{
				printf(" Input name of product : ");scanf("%d",&n);
				for(i=0;i<n;i++){
					printf(" Input id    : ");scanf("%d",&pro[i].id);
					printf(" Input Name  : ");fflush(stdin);gets(pro[i].productName);
					printf(" Input QTY   : ");scanf("%d",&pro[i].qty);
					printf(" Input Price : ");scanf("%f",&pro[i].price);
					pro[i].total=pro[i].price*pro[i].qty;
					pro[i].discount = (pro[i].total <=30) ? 10 :
						        (pro[i].total>30 && pro[i].total<=60) ? 20 : 30;
					pro[i].payment = (pro[i].total-(pro[i].total*pro[i].discount/100));
				}
			}break;
			case 2:{
				headedr();
				for(i=0;i<n;i++){
					printf("\n%12d%14s%13d%14.2f$%14.2f$%17.2f%%%16.2f$",pro[i].id,pro[i].productName,pro[i].qty,pro[i].price,pro[i].total,pro[i].discount,pro[i].payment);
				}
			}break;
			case 3:{
				int sID;
				int b=0;
				printf("Input Product id for search =");scanf("%d",&sID);
				for(i=0;i<n;i++){
					if(sID==pro[i].id){
						headedr();
						printf("\n%12d%14s%13d%14.2f$%14.2f$%17.2f%%%16.2f$",pro[i].id,pro[i].productName,pro[i].qty,pro[i].price,pro[i].total,pro[i].discount,pro[i].payment);
						b=1;
					}
				}
				if(b==0){
					printf("Product Search not found...!");
				}
			}break;
			case 4:{
				int sID;
				int b=0;
				printf("Input Product id for edit =");scanf("%d",&sID);
				for(i=0;i<n;i++){
					if(sID==pro[i].id){
						printf(" Input id    : ");scanf("%d",&pro[i].id);
						printf(" Input Name  : ");fflush(stdin);gets(pro[i].productName);
						printf(" Input QTY   : ");scanf("%d",&pro[i].qty);
						printf(" Input Price : ");scanf("%f",&pro[i].price);
						pro[i].total=pro[i].price*pro[i].qty;
						pro[i].discount = (pro[i].total <=30) ? 10 :
					        (pro[i].total>30 && pro[i].total<=60) ? 20 : 30;
						pro[i].payment = (pro[i].total-(pro[i].total*pro[i].discount/100));
						b=1;
					}
				}
				if(b==0){
					printf("Product search not found...!");
				}
			}break;
			case 5:{
				int sID;
				int b=0;
				printf("Input Product id for Delete =");scanf("%d",&sID);
				for(i=0;i<n;i++){
					if(sID==pro[i].id){
						pro[i]=pro[i+1];
						b=1;
					}
				}
				if(b==0){
					printf("Product search not found...!");
				}
			}break;
			case 6:{
				int sID;
				int b=0;
				printf("Input Product id for edit =");scanf("%d",&sID);
				for(i=0;i<n;i++){
					if(sID==pro[i].id){
						
						b=1;
					}
				}
				if(b==0){
					printf("Product search not found...!");
				}
			}break;
			case 7:{
				int j;
				struct Product temp;
				for(i=0;i<=n;i++){
					for(j=i+1;j<n;j++){
						if(pro[i]<pro[j]){
							temp=pro[i];
							pro[i]=pro[j];
							pro[j]=temp;
						}
					}
				}
			}break;
			case 8:{
				int m;
				printf(" Input number of product for add : ");scanf("%d",&m);
				for(i=n;i<=(n+m);i++){
					printf(" Input id    : ");scanf("%d",&pro[i].id);
					printf(" Input Name  : ");fflush(stdin);gets(pro[i].productName);
					printf(" Input QTY   : ");scanf("%d",&pro[i].qty);
					printf(" Input Price : ");scanf("%f",&pro[i].price);
					pro[i].total=pro[i].price*pro[i].qty;
					pro[i].discount = (pro[i].total <=30) ? 10 :
						        (pro[i].total>30 && pro[i].total<=60) ? 20 : 30;
					pro[i].payment = (pro[i].total-(pro[i].total*pro[i].discount/100));
				}
			}break;
		}
	}while(op!=9);
}