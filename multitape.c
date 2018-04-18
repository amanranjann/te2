#include <stdio.h>
#include <stdlib.h>

void display(int no);
void sortPrograms(int no);

int size[15], tape[10][10]={0},tape_cnt;

void sortPrograms(int no)
{
	int i, j, temp;
	for (i = 0; i < no - 1; i++)
	{
		for (j = 0; j < no - i - 1; j++)
		{
			if (size[j + 1] < size[j])
			{
				temp = size[j];
				size[j] = size[j + 1];
				size[j + 1] = temp;
			}
		}
	}
	display(no);
}

void display(int no)
{
   int i;
	for ( i = 0; i < no; ++i)
	     printf("%d ", size[i]);
	printf("\n");
}

void display_tapes(int no)
{
   int i,j;
   for(i=0;i<tape_cnt;i++)
   {
      printf("Tape[%d] : ",i);
      for(j=0;j<10;j++)
      {
         if(tape[i][j]==0)
           break;
         printf(" %d",tape[i][j]);
      }
      printf("\n");
   }
}

void optStorage(int no)
{ 
   int i,j,col;
   i=j=col=0;
   while(i<no)
    {
        tape[j][col]=size[i];
        j++;
        if(j==tape_cnt)
         {
             col++;
             j=0;
         }
        i++;
    }
}

int main()
{
	int no,i;
 	printf("Enter no. of tape : ");
	scanf("%d", &tape_cnt);
	printf("Enter no. of programs: ");
	scanf("%d", &no);
	printf("Enter the lengths: ");
	for ( i = 0; i < no; ++i)
	   scanf("%d", &size[i]);
	printf("Original list is : ");
	display(no);
	printf("Sorted list is: ");
	sortPrograms(no);

	optStorage(no);
        printf("Tape contents : \n");
        display_tapes(no);

	return 0;
}
