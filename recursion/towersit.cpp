#include <iostream>


bool isEven(int disks);
int moves(int disks);
void MoveTower(int disks,int numberOfMovesToSolve,int src,int tmp,int dst);

//function prototype MoveTower
void MoveSingle(int src,int dst);
int whichDisk(int movement,int disks);
int patronNumber(int movement,int whichDisk, int disks);

int main(){
    int disks;
    int src,tmp,dst;
    int numberOfMovesToSolve;


    std::cout<<"Number of disks: ";
    std::cin>>disks;
    std::cout<<"Initial peg: ";
    std::cin>>src;
    std::cout<<"Temporal peg: ";
    std::cin>>tmp;
    std::cout<<"Destination peg: ";
    std::cin>>dst;

    numberOfMovesToSolve=moves(disks);

    MoveTower(disks, numberOfMovesToSolve, src, tmp, dst);

    return 0;
}

bool isEven(int disks)
{
    bool isEven;
    if(disks % 2 == 0) isEven=true;
    elseisEven=false;

    return isEven;
}

int moves(int disks)
{
    int moves = 0;
    for(int i = 1; i <= disks; ++i){
        moves = (moves * 2) + 1;
    }
    return moves;
}

void MoveTower(int disks, int numberOfMovesToSolve, int src, int tmp, int dst){
    if(!isEven(disks)){
        for(int movement=1;movement<=numberOfMovesToSolve;movement++){
            switch(patronNumber(movement,whichDisk(movement,disks),disks)){
            case 1:
                if(!isEven(whichDisk(movement,disks)))MoveSingle(src,dst);
                elseMoveSingle(src,tmp);
                break;
            case 2:
                if(!isEven(whichDisk(movement,disks)))MoveSingle(dst,tmp);
                else    MoveSingle(tmp,dst);
                break;
            case 3:
                if(!isEven(whichDisk(movement,disks)))MoveSingle(tmp,src);
                else    MoveSingle(dst,src);
                break;
            }//end switch
        }//end loop for
    }else{ //isEven
        for(int movement=1;movement<=numberOfMovesToSolve;movement++){
            switch(patronNumber(movement,whichDisk(movement,disks),disks)){
            case 1:
                if(!isEven(whichDisk(movement,disks)))MoveSingle(src,tmp);
                else    MoveSingle(src,dst);
                break;
            case 2:
                if(!isEven(whichDisk(movement,disks)))MoveSingle(tmp,dst);
                else    MoveSingle(dst,tmp);
                break;
            case 3:
                if(!isEven(whichDisk(movement,disks)))MoveSingle(dst,src);
                else    MoveSingle(tmp,src);
                break;
            }//end switch
        }//end loop for
    }//end if...else
}//end function MoveTower

void MoveSingle(int src,int dst){
    std::cout<<src<<"--->"<<dst<<'\n';
}//end function MoveSingle

int whichDisk(int movement,int disks){
    int whichDisk;
    int start=1;
    int increment=2;

    int movements=moves(disks);
    for(int i=1;i<=disks;i++){
        for(int j=start;j<=movements;j+=increment){
            if(movement==j){
                whichDisk=i;
            }//end if
        }//end inner loop
        start*=2;
        increment*=2;
    }//end outer for loop
    return whichDisk;
}//end function whichDisk

int patronNumber(int movement,int whichDisk,int disks){
    int patronNumber=0;
    int increment=2;
    int start=1;
    for(int i=1;i<=disks;i++){
        if(i==whichDisk){
            for(int j=start;j<=movement;j+=increment){
                patronNumber++;
                if(patronNumber==3&&j!=movement)patronNumber=0;
            }//end inner for
        }//end if
        start*=2;
        increment*=2;
    }//end for loop

    return patronNumber;
}//end patronNumber
