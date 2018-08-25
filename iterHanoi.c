/* tower.c

   Tower of Hanoi -- mechanical solution

   Arrange the three rods to form a triangle.

   Alternate between moving the smallest disk and making the only valid move
   which does not involve the smallest disk.

   The following rule will make sure that the tower of disks end up on the
   destination rod: if the number of disks in the puzzle is an odd number
   always move the smallest disk counter-clockwise around the triangle; if
   the number of disks in the puzzle is an even number always move the
   smallest disk clockwise around the triangle.
*/

#include <stdio.h>
#include <stdbool.h>
// returns number of disks in the destRod
int destinationCount (int array[], int numberOfElements)
{
	int count = 0, i;
    for ( i = 1; i <= numberOfElements; ++i )
        if ( array[i] == 3 )
            ++count;
    return count;
}

int main (void)
{ 
    int numberOfDisks, i, smallestDir, moveCount = 0;  
    bool everyOtherMove = false;
    int rodFrom, rodTo, disk;
    int topDisk[4];
    int temp;
 	printf ("\nTower of Hanoi puzzle\n");
    printf ("\nnumber of disks? ");
    scanf ("%i", &numberOfDisks);
    int rod[numberOfDisks + 1];
    // all disks start on rod 1
    for ( i = 1; i <= numberOfDisks; ++i )
        rod[i] = 1;
    // set direction to move smallest disk
    if ( (numberOfDisks & 1) == 0 ) // checking even or odd
        smallestDir = 1;
    else
        smallestDir = -1;    
    printf("\nsolution\n\n");
    do {
        ++moveCount;
        if ( ! everyOtherMove ) {
            // move smallest disk
            rodFrom = rod[1];
            rodTo = rodFrom + smallestDir;
            if ( rodTo > 3 )
                rodTo = 1;
            if ( rodTo < 1 )
                rodTo = 3;
            disk = 1;
        }
        else {
            // make only valid move not involving the smallest disk
            // find disk at the top of each rod
            for ( i = 1; i <= 3; ++i )
                topDisk[i] = numberOfDisks + 1;
            for ( i = numberOfDisks; i >= 1; --i )
                topDisk[rod[i]] = i;            
            // find which disk to move
            switch ( rod[1] )
            {
                case 1:
                    rodFrom = 2;
                    rodTo = 3;
                    break;
                case 2:
                    rodFrom = 1;
                    rodTo = 3;
                    break;
                case 3:
                    rodFrom = 1;
                    rodTo = 2;
                   break;
                default:
                    printf ("error");
                    break;
            }            
            if ( topDisk[rodFrom] > topDisk[rodTo] ) {
                // swap values
                temp = rodFrom;
                rodFrom = rodTo;
                rodTo = temp;            
            }
            disk = topDisk[rodFrom]; 
        }    
        printf ("%i: disk %i rod %c to rod %c\n", moveCount, disk, 
                 rodFrom + 64, rodTo + 64);
        // move disk
        rod[disk] = rodTo;
        // toggle everyOtherMove
        everyOtherMove = ! everyOtherMove;
    }
    while ( destinationCount (rod, numberOfDisks) != numberOfDisks );
    return 0;
}   

