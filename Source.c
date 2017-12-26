#include <stdio.h>

void calculate_denominations(int amount, int n,int denomination[] )
{
    int i, j, k;
    int min_coins_required[30]={0};
    int table[30][30] = {0};
    int minimum;
    int denominationfrequency = 0;

    min_coins_required[0] = 0;

    //Calculate the change of amount
    for (i=1; i <= amount; i++)
    {
        minimum = 999;
        for (j = 0; j<n; j++)
        {
            if (denomination[j] <= i)
            {
                if (minimum > min_coins_required[i-denomination[j]]+1)
                {
                    minimum = min_coins_required[i-denomination[j]]+1;
                    for(k = 0; k < n; ++k)
                    {
                        table[i][k] = table[i-denomination[j]][k]; 
                    }
                    table[i][j]++;
                }
            }
        }
        min_coins_required[i] = minimum;
    }

    printf("Minimum coins required %d \n", min_coins_required[amount]);
    printf("Change given is \n");    
	for(int i = 0; i < n; ++i){
		if(table[amount][i]!=0){
		denominationfrequency = table[amount][i];
		while(table[amount][i]!=0){		
		printf("%d\n", denomination[i]);
		table[amount][i]=table[amount][i]-1;		
		}
		
		}
        
	}
}

void main()
{
    int n,i,j,k,l,amount;
    int denominations[30];
    
    printf("Enter the amount for which you need change ");//Input amount 
    scanf("%d",&amount);
    
    printf("Enter the number of  denominations ");//input number of deniminations
    scanf("%d",&n);

    printf("Enter the denominations seperated by space "); //input denominations   
    for(i=0;i<n;i++){
    	scanf("%d",&denominations[i]);  
    }

    calculate_denominations(amount,n,denominations);// call function 
};
