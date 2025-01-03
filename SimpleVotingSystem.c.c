#include<stdio.h>

// Function to check for a tie and sort the array in descending order
int tie (int a[],int n)
{
    // Sorting array in descending order using a nested loop
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n-1; j++)
        {
            if (a[i]<a[j])
            {
                // Swap elements if they are out of order
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    // Check for a tie: if the first two sorted elements are equal
    if (a[0]==a[1])
        return -1;// Indicate a tie


}

int main()
{
    // Prompt for voting options

    printf("Enter 1 to vote CON");
    printf("\nEnter 2 to vote BJP");
    printf("\nEnter 3 to vote ADP");
    printf("\nEnter any number to vote NOTA\n");

    int n,b[4]= {0},i;// Initialize vote counters for 4 options (CON, BJP, ADP, NOTA)


    // Input number of voters
    printf("\nEnter number of candidates : ");
    scanf("%d",&n);
    int a[n];

    // Start voting process
    printf("\nStart voting\n");

    for(i=0; i<n; i++)
    {
        // Input vote for each person
        printf("\nEnter vote for %d person : ",i+1);
        scanf("%d",&a[i]);
    }

    // Count votes for each option
    for (i=0; i<n; i++)
    {
        if (a[i]==1) b[0]++;// Vote for CON


        else if(a[i]==2) b[1]++; //Vote for BJP


        else if (a[i]==3) b[2]++;// Vote for ADP


        else b[3]++;// Vote for NOTA


    }

    // Display vote counts for each party
    printf("\nCON has got %d votes\n",b[0]);
    printf("\nBJP has got %d votes\n",b[1]);;
    printf("\nADP has got %d votes\n",b[2]);
    printf("\nNOTA has got %d votes\n",b[3]);

    // Store individual party vote counts
    int cong=b[0],bjp=b[1],adp=b[2],nota=b[3];

    // Check for a tie
    int s = tie(b,n);

    // If tie exists, display a tie message
    if (s==-1) printf("\nThere is a tie\n");


    else
    {
        // Determine and display the winner with the lead

        if (b[0]==cong) printf("\nCON is winner with the lead of %d votes\n",b[0]-b[1]);

        else if (b[0]==bjp) printf("\nBJP is winner with the lead of %d votes\n",b[0]-b[1]);

        else if (b[0]==adp) printf("\nADP is winner with the lead of %d votes\n",b[0]-b[1]);

        else if (b[0]==nota) printf("\nNOTA is winner with the lead of %d votes\n",b[0]-b[1]);
    }



}
