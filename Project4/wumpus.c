#include <stdio.h>
#include <string.h>
#include "graph.h"
#include <stdlib.h>
#include "GQueue.h"


int startGame(Vertex*, int, int);
void display(int, int, int);

queue_type* bottomless;
queue_type* bats;
queue_type* listV;

int main()
{
    Vertex* head;
    createGraph(&head);
    char parseString[1000] = "";
    int temp;
    int prevDoor,door = -1, door_counter;
    char* ptr;
    listV = queue_new();

    printf("Welcome to the Wumpus Cave Parser.\n");
    printf("Please enter your commands in the format:\n");
    printf("<number> ( <list of comma-separated numbers> )\n");
    printf("Each on their own line.\n");
    printf("Enter  0 (0)  when finished with the cave.\n");

    do
    {
        scanf("%d (%[^)])", &temp, parseString);
        printf("Cave room %d has exits: ", temp);

        if (temp > 0)
        {
            queue_enqueue(listV, temp);
            head = addVertex(&head, temp);
     
        }
        
        ptr = strtok(parseString, ",");
        door_counter = 0;

        while (ptr != NULL)
        {
            
            prevDoor = door;
            
            door = atoi(ptr);
            
            if (door_counter >= 1 && prevDoor == door)
            {
                ptr = strtok(NULL, ",");
                continue;
            }

            if (temp != 0)
            {
                if (searchVertex(&head, door) == NULL)
                {
                    queue_enqueue(listV, door);
                }
                head = addEdge(&head, temp, door);
            }
            printf("%d ", door);
            door_counter++;
            ptr = strtok(NULL, ",");
        }
        if (door_counter == 0)
            printf("No Exits!\n");
        else
        {
            printf("as exits\n");
        }

    } while (temp > 0);

    /*Adding Bottomless Pits*/
    printf("Enter the location(s) of the bottomless pit(s) in the form ( <list of comma-separated numbers> ).\n");
    printf("Enter (0) if none should be present.\n-2 ");
    scanf("%*c");
    scanf("(%[^)])", parseString);

    ptr = strtok(parseString, ",");
    bottomless = queue_new();
    while (ptr != NULL)
    {
        door = atoi(ptr);
        if (searchVertex(&head, door) == NULL)
        {
            ptr = strtok(NULL, ",");
            continue;
        }
         queue_enqueue(bottomless, door);
        ptr = strtok(NULL, ",");
    }
    

    /*Adding superbats*/
    printf("Enter the location(s) of the super bat(s) in the form ( <list of comma-separated numbers> ).\n");
    printf("Enter (0) if none should be present.\n-1 ");
    scanf("%*c");
    scanf("(%[^)])", parseString);

    ptr = strtok(parseString, ",");
    bats = queue_new();
    while (ptr != NULL)
    {
        door = atoi(ptr);
        if (searchVertex(&head, door) == NULL)
        {
            ptr = strtok(NULL, ",");
            continue;
        }
        queue_enqueue(bats, door);
        ptr = strtok(NULL, ",");
    }

    /*END of bats*/

    int hunt;
    int wump;
    printf("Please Enter the room that the Hunter begins in\n");
    scanf("%*c");
    scanf("%d", &hunt);

    while (searchVertex(&head, hunt) == NULL)
    {
        printf("Invalid Input! Try again.\n");
        scanf("%d", &hunt);
    }

    printf("Please Enter the room that the Wumpus begins in\n");
    scanf("%d", &wump);

    while (searchVertex(&head, wump) == NULL)
    {
        printf("Invalid Input! Try again.\n");
        scanf("%d", &wump);
    }

  
   

    if (check(&head, hunt, wump) <= 1)
    {
        printf("You are already dead!!\n\n");
        return 0;
    } 
    else if ((check(&head, hunt, wump) == 100000) && (check(&head, wump, hunt) == 100000))
    {
        printf("Neither player can get to one another. The game is closing down.\n");
        return -1;
    }
    else if (check(&head, wump, hunt) != 100000)
    {
        if (contains(bottomless, hunt) == 1)
        {
            printf("You entered a bottomless pit and died.\n");
            return freeVertices(&head);
        }
        printf("That's it!  Thank you for entering a cave!\n");
        printf("Starting Game!\n\n");
        startGame(head, wump, hunt);
    }
    else
    {
        
        printf("There is no way you can win. There is no path to the wumpus.\n");
        printf("The game is closing down.\n");

    }

    queue_delete(bottomless);
    queue_delete(listV);
    queue_delete(bats);

    return freeVertices(&head);
}

int startGame(Vertex* head, int wump, int hunt)
{
    int prevD;
    int distH = check(&head, wump, hunt);
    int distW = check(&head, wump, hunt);
    int answer = 0;

    Vertex* CH;
    Edge* tmpH;

    printf("Welcome to the wumpus's lair.\nSeriously though, someone should clean this place up.\n");
    
    while (contains(bats, hunt) == 1)
    {
       hunt = randomVal(listV);
       printf("You entered into a cave filled with super bats!\n");
       printf("You are being transported to cave %d\n", hunt);

       if (check(&head, hunt, wump) <= 1)
       {
           printf("You were killed by the wumpus!\nYou Lose!");
           return 1;

       }

       if (contains(bottomless, hunt) == 1)
       {
           printf("You entered a bottomless pit and died.\n");
           return 1;
       }
    }

    do {
        
        printf("You are in room %d, nearby rooms are ", hunt);
        int x;
        CH = searchVertex(&head, hunt);
        for (x = 0, tmpH = CH->head; x < CH->numE; tmpH = tmpH->next, x++)
        {
            printf("%d", tmpH->dest);
            if ((CH->numE - 1) == x)
            {
                printf(".\n");
            }
            else
            {
                printf(", ");
            }
        }

        printf("Which room do you want to enter?\n> ");
        scanf("%*c");
        scanf("%d", &answer);
        
        
        
        while ((answer != 0) && (searchEdge(&CH, answer) == NULL)) 
        {
            printf("Invalid response. Try again\n> ");
            scanf("%d", &answer);
        } 
        
        if (answer == 0)
        {
            distH = check(&head, wump, hunt);
            if (distH == 2)
            {
                printf("You have slain the wumpus!  O frabjous day! Callooh! Callay!\n");
                printf("You Win!\n");
                return 1;
            }

            printf("Your only arrow missed the wumpus! There is no other way to kill the wumpus so you surrender and die!\n");
            printf("You lose!\n");
            return -1;
        }

        while (contains(bats, answer) == 1)
        {
            answer = randomVal(listV);
            printf("You entered into a cave filled with super bats!\n");
            printf("You are being transported to cave %d\n", answer);

        }

        if (contains(bottomless, answer) == 1)
        {
            printf("You entered a bottomless pit and died.\n");
            return 1;
        }
        
        distH = check(&head, wump, answer);
        distW = check(&head, answer, wump);
        prevD = check(&head, wump, hunt);
        hunt = answer;

        display(distW, prevD, distH);




    } while (distW >= 2 );
}

void display(int distW, int prevD, int distH)
{
    if (distW <= 1)
    {
        printf("Ouch, the wumpus got you, not a pretty sight.\n");
        printf("You suck at this game!\n");
        printf("You already know where the wumpus is because you entered its position at the start of game.\n");
        printf("So how did you NOT win?\n");
        printf("You lose!\n");
    }
    else if (distH > prevD)
    {
        printf("You're getting colder\n");

        if (distH == 2)
        {
            printf("The smell of the wumpus is nearly unbearable.\n");
        }
        else if (distH == 3)
        {
            printf("You can smell the wumpus, but it not so bad. \n");
        }

    }
    else if (distH == prevD)
    {
        printf("You are neither warmer nor colder.\n");

        if (distH == 2)
        {
            printf("The smell of the wumpus is nearly unbearable.\n");
        }
        else if (distH == 3)
        {
            printf("You can smell the wumpus, but it not so bad. \n");
        }
    }
    else if (distH < prevD)
    {

        printf("You are getting warmer!\n");
        if (distH == 1)
        {
            printf("You are on fire!!! You should consider backing up.\n");
        }
        else if (distH == 2)
        {
            printf("The smell of the wumpus is nearly unbearable.\n");
        }
        else if (distH == 3)
        {
            printf("You can smell the wumpus, but it not so bad. \n");
        }
    }
    


    return;
}

