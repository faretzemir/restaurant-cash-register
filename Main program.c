#include <stdio.h>
#include <string.h>

int main(){

	FILE *fptr1, *fptr2;
	char item[1000], buffer[1000], *string[100], zero[10]="0", f, *sp, list[10000], list2[10000];
	float price[1000]={10.40,9.45}, Tprice[1000], GTprice=0, Dprice, GGTprice, change;
	int input, cd[100], p=0, x, r, s, t=0, code, Qt[1000], Q=0, R=0, add=2, dup=2, i, n=2, disc, cash;

	do{

	printf("WELCOME TO RESTAURANT MAC C - Main Menu\n");
	printf("[1] Add new food items\n[2] Take order\n");
	printf("Enter ITEM CODE (0 to Quit) :\n");
	scanf("%d", &input);

	if(input==0)
	{return 0;}

	else if(input==1)
	{


	fptr1 = fopen("Food.txt","r");
	f = fgetc(fptr1);

	while(f != EOF)
	{
	printf("%c", f);		
	f = fgetc(fptr1);
	}	

	fclose(fptr1);

	do{
		fptr1 = fopen("Food.txt","a+");
		printf("\nEnter a description (0 to Main Menu): \n");
		scanf("%s", item);
		string[dup] = strdup(item);
		dup++;

		x = strcmp(zero,item);
		if(x==0)
		break;

		printf("Enter a price: \n");
		scanf("%f", &price[n]);
		add++;
		sprintf(list,"\n%d\t\t%s\t\t%.2f",add, item, price[n]);
		n++;


		printf("\n%s\n", list);
		fputs(list, fptr1);
		fclose(fptr1);
		
		} while(x != 0);


	}

	

	else if(input==2)
	{
		do{
			fptr1 = fopen("Food.txt","r");
			r = fgetc(fptr1);

				while(r != EOF)
				{
					printf("%c", r);		
					r = fgetc(fptr1);
				}	

		fclose(fptr1);

				do{
					printf("\nEnter ITEM CODE (0 to Quit, 100 for Main Menu)\n");	
					scanf("%d", &code);
									
						if(code == 0)
						{

							printf("\nEnter Discount (PERCENT)\t\t:");	
							scanf("%d", &disc);	

							printf("\t\t\tINVOICE RESTAURANT MAC C\t\t\t\n");	
							printf("--------------------------------------------------------------------------------\n");			
							printf("ITEM CODE\tDESCRIPTION\tPRICE(RM)\tQUANTITY\tTOTAL(RM)\n");	
							
							for(R=0;R<add;R++)
							{
								GTprice = GTprice + Tprice[R];
								Dprice = GTprice * disc / 100;
								GGTprice = GTprice - Dprice;
							}

							for(R=0;R<add;R++)		
							printf("%d\t\t%s\t\t%.2f\t\t%d\t\t%.2f\n", cd[R], string[R], price[R], Qt[R], Tprice[R]);				
							
							printf("--------------------------------------------------------------------------------\n");
							printf("Subtotal before Discount\t\t %.2f\n", GTprice);
							printf("Discount %d(PERCENT)\t\t\t- %.2f\n", disc, Dprice);
							printf("--------------------------------------------------------------------------------\n");
							printf("TOTAL\t\t\t%.2f\n\n", GGTprice);
							printf("CASH TENDERED\t\t\t:");

							scanf("%d", &cash);
							if(cash<GGTprice)
							{
							printf("INSUFFICIENT CASH!");
							scanf("%d", &cash);
							}
							
							change = cash - GGTprice;
							printf("CHANGE\t\t\t: %.2f\n", change);
							printf("PRINTING OUT INVOICE\n");
							
							fptr2 = fopen("Invoice.txt", "a+");

							fprintf(fptr2,"\t\t\tINVOICE RESTAURANT MAC C\t\t\t\n");	
							fprintf(fptr2,"\n--------------------------------------------------------------------------------\n");			
							fprintf(fptr2,"\nITEM CODE\tDESCRIPTION\tPRICE(RM)\tQUANTITY\tTOTAL(RM)\n");	
							
							for(R=0;R<add;R++)		
							fprintf(fptr2,"%d\t\t%s\t\t%.2f\t\t%d\t\t%.2f\n", cd[R], string[R], price[R], Qt[R], Tprice[R]);				
							
							fprintf(fptr2,"--------------------------------------------------------------------------------\n");
							fprintf(fptr2,"Subtotal before Discount\t\t %.2f\n", GTprice);
							fprintf(fptr2,"Discount %d(PERCENT)\t\t\t- %.2f\n", disc, Dprice);
							fprintf(fptr2,"--------------------------------------------------------------------------------\n");
							fprintf(fptr2,"TOTAL\t\t\t%.2f\n\n", GGTprice);
							fprintf(fptr2,"CASH TENDERED\t\t\t:\t\t%d\n", cash);
							fprintf(fptr2,"CHANGE\t\t\t: %.2f\n", change);
							fclose(fptr2);
						}							

						else if(code <= add && code>0)
						{
								cd[code-1] = code;
		
								if(code == 1)
								{	code = cd[code-1];
									sp = buffer;
									sp ="BigM";
									string[0] = sp;}
								
								else if(code == 2)
								{	code = cd[code-1];
									sp = buffer;
									sp ="Cheeseburger";
									string[1] = sp;}

								Qt[code-1]++;
								t++;
								Tprice[code-1] = price[code-1] * Qt[code-1];

							
						}
						
						
						else if(code == 100)
						{break;}

						else if(code != 100 && code != 0)
						printf("ERROR, NO CODE!!");


					}while(code != 100);

		}while(code != 100 && code != 0);

	if(code==0)
	{break;}

	}
	
	else 
	{	printf("ERROR! NO CODE!\n");
		printf("TRY AGAIN!\n");
		scanf("%d", &input);
	}

}while(input!=0);


	return 0; 

}