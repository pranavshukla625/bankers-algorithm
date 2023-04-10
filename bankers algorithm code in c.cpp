#include <stdio.h>
int main()
{
 int n, r;
 printf("Enter the number of chefs: ");
 scanf("%d", &n);
 printf("Enter the maximum number of ingredients that each chef can claim: ");
 scanf("%d", &r);
 // Initialize the array to store the number of ingredients in each jar
 int jars[10];
 int i;
 printf("Enter the number of ingredients in each jar: \n");
 for(i = 0; i < 10; i++)
 {
 scanf("%d", &jars[i]);
 }
 // Initialize the array to keep track of the ingredients claimed by each chef
 int claims[100][100];
 int j;
 for(i = 0; i < n; i++)
 {
 for(j = 0; j < 100; j++)
 {
 claims[i][j] = 0;
 }
 }
 // Loop through the chefs and let them claim ingredients
 int deadlock = 0;
 int total_ingredients_claimed = 0;
 int max_iterations = n;
 while(max_iterations--) { // To prevent infinite loops
 int ingredients_claimed = 0;
 int j;
 for(i = 0; i < n; i++)
 {
 for(j = 0; j < 100; j++)
 {
 if(jars[j] > 0 && ingredients_claimed < r && claims[i][j] == 0)
 {
 claims[i][j] = 1;
 jars[j]--;
 ingredients_claimed++;
 total_ingredients_claimed++;
 }
 }
 if(ingredients_claimed == 0) // Deadlock prevention
 {
 printf("Deadlock occurred\n");
 deadlock = 1;
 break;
 }
 }
 if(deadlock == 1) // If deadlock occurred, break out of loop
 {
 break;
 }
 }
 // Print the final state of the jars and the claims
 printf("\nFinal state of the jars:\n");
 for(i = 0; i < 10; i++)
 {
 printf("%d ", jars[i]);
 }
 printf("\n\nFinal state of the claims:\n");
 for(i = 0; i < n; i++)
 {
 printf("Chef %d: ", i+1);
 for(j = 0; j < 100; j++)
 {
 printf("%d ", claims[i][j]);
 }
 printf("\n");
 }
 if(deadlock == 0)
 {
 printf("\nNo deadlock occurred. Total ingredients claimed = %d\n", total_ingredients_claimed);
 }
 return 0;
}
