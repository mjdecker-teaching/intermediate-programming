/**
 *  @file towers.cpp
 *
 *  Recurively solve towers of hanoi
 *
 *  @author Michael John Decker <mdecker6@kent.edu>
 */

#include <iostream>
#include <string>

static const int ERROR_STATUS = 1;
static const int NUM_DISC_POS = 1;

enum poles { left, right, middle };

class pole {
private:
    poles pole_pos;
public:
    pole() {};
    pole(poles x) : pole_pos(x) {}

    friend std::ostream& operator<<(std::ostream& out, const pole & apole) {
        switch (apole.pole_pos) {
            case left:   out << "Left";   break;
            case right:  out << "Right";  break;
            case middle: out << "Middle"; break;
        }
        return out;
    }
};


/**
 * move
 * @param num num disks to move
 * @param source source pole
 * @param auxilary auxilary pole
 * @param destination destination pole
 * @param depth recursive depth
 *
 * PRE:   num > 0
 * POST:  Prints out moves required to solve towers of hanoi problem
 *
 * Basic it can be broken down into sub-problems.
 * Moving disc N (and its stack) to destination is the same as:
 *  - moving disk n - 1 (and its stack) to auxilary
 *  - moving disk n to destination
 *  - moving disk n - 1 (and its stack) to destination
 *
 *  Example: move(3, Left, Middle, Right)
 *  
 *  move(3, Left, Middle, Right)
 *      move(2, Left, Right, Middle)
 *          move(1, Left, Middle, Right)
 *              disk 1 from Left to Right
 *          disk 2 from Left to Middle
 *          move(1, Right, Left, Middle)
 *              disk 1 from Right to Middle
 *      disk 3 from Left to Right
 *      move(2, Middle, Left, Right)
 *          move(1, Middle, Right, Left)
 *              disk 1 from Middle to Left
 *          disk 2 from Middle to Right
 *          move(1, Left, Middle, Right)
 *              disk 1 from Left to Right
 *
 */
void move(int num, pole source, pole auxilary, pole destination, int depth) {

    std::cout << std::string(depth, '\t') << "move(" << num << ", " << source << ", " << auxilary << ", " << destination << ")\n"; 

    int new_depth = depth + 1;

    if (num == 1) {

        std::cout << std::string(new_depth, '\t') << "disk " << num << " from " << source << " to " << destination << '\n';
        return;
    }

    move(num - 1, source, destination, auxilary, new_depth);
    std::cout << std::string(new_depth, '\t') << "disk " << num << " from " << source << " to " << destination << '\n';
    move(num - 1, auxilary, source, destination, new_depth);

}

int main(int argc, char * argv[]) {
 
    if(argc != 2) {

        std::cout << "towers num_discs\n";
        return ERROR_STATUS;

    }

    int num = 0;

    for(int i = 0; argv[NUM_DISC_POS][i] != '\0'; ++i) {

        num *= 10;
        num += argv[NUM_DISC_POS][i] - '0';

    }

    std::cout << "To solve the towers of hanoi with " << num 
              << " disks, make the following moves.\n";
    move(num, left, middle, right, 0);
    
    return 0;
}
